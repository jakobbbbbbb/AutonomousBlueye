import cv2
import os

# This code is used to convert a mp4 video file to single frames

video_path = "/Users/jakobrudeovstaas/Desktop/Skole🎓/NTNU/Master thesis🎓/Blueye Pioneer/blueye_chain_follower/Video/autonomous_main_2.mp4"
output_dir = "frames"
os.makedirs(output_dir, exist_ok = True)

cap = cv2.VideoCapture(video_path)
frame_rate = 30
frame_count = 0

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break
    if frame_count % frame_rate == 0:
        frame_filename = os.path.join(output_dir, f"frame_{frame_count:04d}.jpg")
        cv2.imwrite(frame_filename, frame)
        
    frame_count += 1

cap.release()
print("Success!")