#https://code-graffiti.com/opencv-corner-detection-in-python/
import cv2
import numpy as np
import matplotlib.pyplot as plt

chess_board = cv2.imread("image/chess.jpeg")
chess_board = cv2.cvtColor(chess_board,cv2.COLOR_BGR2RGB)

gray_chess_board = cv2.cvtColor(chess_board, cv2.COLOR_BGR2GRAY)

gray = np.float32(gray_chess_board)
dst = cv2.cornerHarris(src = gray, blockSize = 2, ksize = 3, k = 0.04)
dst = cv2.dilate(dst, None)
chess_board[dst > 0.01 * dst.max()] = [255, 0, 0]
plt.imshow(chess_board)
plt.show()