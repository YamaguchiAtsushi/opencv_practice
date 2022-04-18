#https://code-graffiti.com/opencv-corner-detection-in-python/
import cv2
import numpy as np
import matplotlib.pyplot as plt

chess_board = cv2.imread("image/chess.jpeg")
chess_board = cv2.cvtColor(chess_board,cv2.COLOR_BGR2RGB)
gray_chess_board = cv2.cvtColor(chess_board, cv2.COLOR_BGR2GRAY)

corners = cv2.goodFeaturesToTrack(gray_chess_board, 250, 0.01, 10)
corners = np.int0(corners)
for i in corners:
    x, y = i.ravel()
    cv2.circle(chess_board, (x, y), 3, 255, 1)

plt.imshow(chess_board)
plt.show()