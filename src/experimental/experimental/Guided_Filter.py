import cv2
import numpy as np

def guided_filter(I, p, radius, eps):
    I = I.astype(np.float32) / 255.0 # normalized guidance image
    p = p.astype(np.float32) / 255 # normalized input image
    # Mean value
    I_mean = cv2.boxFilter(I, -1, (radius, radius))
    p_mean = cv2.boxFilter(p, -1, (radius, radius))
    # Correlation value
    I_corr = cv2.boxFilter(I * I, -1, (radius, radius))
    Ip_corr = cv2.boxFilter(I * p, -1, (radius, radius))
    # Variance value
    I_var = I_corr - I_mean * I_mean
    # Covariance value
    Ip_cov = Ip_corr - I_mean * p_mean

    a = Ip_cov / (I_var + eps)
    b = p_mean - a * I_mean

    a_mean = cv2.boxFilter(a, -1, (radius, radius))
    b_mean = cv2.boxFilter(b, -1, (radius, radius))

    q = a_mean * I + b_mean
    return (q * 255).astype(np.uint8)