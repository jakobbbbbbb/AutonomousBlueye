import cv2
import torch
from pathlib import Path
import numpy as np
import math
from collections import deque
from Guided_Filter import guided_filter
import warnings

# Ignoring source warning from Yolov5
warnings.filterwarnings("ignore", category=FutureWarning)
warnings.filterwarnings("ignore", category=DeprecationWarning)

# ==== CONFIG ====
#VIDEO_PATH = "/Users/jakobrudeovstaas/Desktop/Skole🎓/NTNU/Master thesis🎓/Object Detection/Shackle.mp4"
VIDEO_PATH = "/Users/jakobrudeovstaas/Desktop/Skole🎓/NTNU/Master thesis🎓/Object Detection/upward_inspection.mp4"
MODEL_PATH = "/Users/jakobrudeovstaas/Desktop/Skole🎓/NTNU/Master thesis🎓/Object Detection/mooring.pt"
IMG_SIZE = 640
CONF_THRES = 0.4
SKIP_FRAMES = 30
TARGET_CLASSES = ["MooringLine", "TransitionPiece"]

# ==== Load YOLOv5 Model ====
model = torch.hub.load('ultralytics/yolov5', 'custom', path=MODEL_PATH)
model.conf = CONF_THRES
model.iou = 0.20
model.classes = None
model.agnostic = False

# ==== Load Video ====
cap = cv2.VideoCapture(VIDEO_PATH)
paused = False

cv2.namedWindow("YOLOv5 Live", cv2.WINDOW_NORMAL)
cv2.resizeWindow("YOLOv5 Live", 1280, 720)
cv2.createTrackbar("Min Threshold", "YOLOv5 Live", 6, 255, lambda x: None)
cv2.createTrackbar("Max Threshold", "YOLOv5 Live", 9, 255, lambda x: None)

def on_trackbar(val):
    cap.set(cv2.CAP_PROP_POS_FRAMES, val)

total_frames = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
cv2.createTrackbar("Position", "YOLOv5 Live", 0, total_frames - 1, on_trackbar)

transition_detected = False
awaiting_cvi = False
awaiting_ascent_confirmation = False

while cap.isOpened():
    if not paused:
        ret, frame = cap.read()
        if not ret:
            print("End of video.")
            break

        results = model(frame, size=IMG_SIZE)
        detections = results.pandas().xyxy[0]

        for _, row in detections.iterrows():
            label = row['name']
            if label not in TARGET_CLASSES:
                continue
            if label == "MooringLine":
                print(f"Found label: {label}")
            xmin, ymin, xmax, ymax = map(int, [row['xmin'], row['ymin'], row['xmax'], row['ymax']])
            roi = frame[ymin:ymax, xmin:xmax]

            min_val = cv2.getTrackbarPos("Min Threshold", "YOLOv5 Live")
            max_val = cv2.getTrackbarPos("Max Threshold", "YOLOv5 Live")

            YCrCb = cv2.cvtColor(roi, cv2.COLOR_BGR2YCrCb)
            Y, Cr, Cb = cv2.split(YCrCb)

            clahe = cv2.createCLAHE(clipLimit=1.5, tileGridSize=(8, 8))
            Y_clahe = clahe.apply(Y)

            Y_guided = guided_filter(Y_clahe, radius=32, eps=0.6)

            kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (10, 10))
            Y_eroded = cv2.erode(Y_guided, kernel, iterations=1)
            Y_cleaned = cv2.morphologyEx(Y_eroded, cv2.MORPH_OPEN, kernel)

            edges = cv2.Canny(Y_cleaned, min_val, max_val)
            edges_bgr = cv2.cvtColor(edges, cv2.COLOR_GRAY2BGR)

            row_white_pixel_counts = np.sum(edges == 255, axis=1)
            average_width = np.mean(row_white_pixel_counts) if row_white_pixel_counts.size > 0 else 0

            y_coords, x_coords = np.where(edges == 255)
            if len(x_coords) > 0 and len(y_coords) > 0:
                frame[ymin:ymax, xmin:xmax] = edges_bgr
                points = np.column_stack((x_coords, y_coords))
                [vx, vy, x0, y0] = cv2.fitLine(points, cv2.DIST_L2, 0, 0.01, 0.01)
                vx, vy = float(vx), float(vy)
                x0, y0 = float(x0), float(y0)
                angle_deg = math.degrees(math.atan2(vy, vx)) - 90

                length = max(1000, int(math.sqrt(frame.shape[0]**2 + frame.shape[1]**2)))
                point1 = (int(x0 - vx * length), int(y0 - vy * length))
                point2 = (int(x0 + vx * length), int(y0 + vy * length))
                global_point1 = (point1[0] + xmin, point1[1] + ymin)
                global_point2 = (point2[0] + xmin, point2[1] + ymin)

                cv2.line(frame, global_point1, global_point2, (0, 255, 0), 2)
                cv2.rectangle(frame, (xmin, ymin), (xmax, ymax), (0, 255, 0), 2)

                mid_x = int(x0 + xmin)
                mid_y = int(y0 + ymin)
                cv2.circle(frame, (mid_x, mid_y), 5, (255, 0, 0), -1)
                cv2.putText(frame, f'Midpoint: ({mid_x}, {mid_y})', (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                cv2.putText(frame, f'Angle: {angle_deg:.2f} degrees', (10, 50), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                cv2.putText(frame, f'Width: {average_width:.2f} px', (10, 70), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 0), 2)

            
            if label == "TransitionPiece":
                if not transition_detected:
                    transition_detected = True
                    awaiting_cvi = True
                    paused = True
                    print("Transition Piece detected! Adjust the system for CVI. Press 'c' when done.")

        cv2.imshow("YOLOv5 Live", frame)
        cv2.setTrackbarPos("Position", "YOLOv5 Live", int(cap.get(cv2.CAP_PROP_POS_FRAMES)))

    key = cv2.waitKey(30) & 0xFF
    if key == 27:
        break
    elif key == ord(' '):
        paused = not paused
    elif key == 81:
        current = int(cap.get(cv2.CAP_PROP_POS_FRAMES))
        cap.set(cv2.CAP_PROP_POS_FRAMES, max(0, current - SKIP_FRAMES))
    elif key == 83:
        current = int(cap.get(cv2.CAP_PROP_POS_FRAMES))
        cap.set(cv2.CAP_PROP_POS_FRAMES, current + SKIP_FRAMES)
    elif key == ord('c') and awaiting_cvi:
        awaiting_cvi = False
        awaiting_ascent_confirmation = True
        print("CVI complete. Press 'a' to begin ascent.")
    elif key == ord('a') and awaiting_ascent_confirmation:
        awaiting_ascent_confirmation = False
        print("Ascent confirmed. Simulating ascent...")
        # You can simulate changing frames or behavior here.

cap.release()
cv2.destroyAllWindows()