#https://code-graffiti.com/opencv-detecting-chessboard-and-circle-grid-patterns-in-python/
import cv2
import matplotlib.pyplot as plt

flat_chess_board = cv2.imread("image/chess.png")
flat_chess_board = cv2.cvtColor(flat_chess_board, cv2.COLOR_BGR2GRAY)

found, corners = cv2.findChessboardCorners(flat_chess_board, (7, 7))


if found:
    print("find the corners")
else:
    print("did not find corners")


flat_chess_copy = flat_chess_board.copy()
cv2.drawChessboardCorners(flat_chess_copy, (7, 7), corners, found)

plt.imshow(flat_chess_copy)
plt.show()