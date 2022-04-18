#https://code-graffiti.com/opencv-edge-detection-in-python/
import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread("image/dog.jpeg")

med_val = np.median(img)
lower = int(max(0, 0.7 * med_val))
upper = int(min(255, 1.3 * med_val))

blurred_img = cv2.blur(img, ksize=(5, 5))

edges = cv2.Canny(image = blurred_img, threshold1 = lower, threshold2 = upper)

plt.imshow(edges)
plt.show()