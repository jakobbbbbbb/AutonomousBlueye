import cv2
import numpy as np

def guided_filter(I, radius, eps):
    I = I.astype(np.float32) / 255.0 # normalized guidance image
    # Mean and correlation value
    I_mean = cv2.boxFilter(I, -1, (radius, radius))
    I_corr = cv2.boxFilter(I * I, -1, (radius, radius))
    # Variance
    I_var = I_corr - I_mean ** 2

    a = I_var / (I_var + eps)
    b = I_mean * (1 - a)

    a_mean = cv2.boxFilter(a, -1, (radius, radius))
    b_mean = cv2.boxFilter(b, -1, (radius, radius))

    q = a_mean * I + b_mean
    return (q * 255).astype(np.uint8)