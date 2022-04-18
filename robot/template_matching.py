import cv2
import numpy as np
import matplotlib.pyplot as plt

"""
full_img = cv2.imread("image/template.png")
#print(full_img)
full_img = cv2.cvtColor(full_img, cv2.COLOR_BGR2RGB)
plt.imshow(full_img)
plt.show()
"""
import cv2
import numpy as np
 
cap = cv2.VideoCapture(0)
 
while(cap.get(cv2.CAP_PROP_FPS) == 0):
    cap.release()
    cap = cv2.VideoCapture(0)
 
cap.set(3, 320)
cap.set(4, 240)
cap.set(5, 15.0)
 
print(cap.get(3))
print(cap.get(4))
print(cap.get(5))
 
grid_x = (25, 115, 205, 295)
grid_y = (45, 95, 145, 195)
 
fourcc = cv2.VideoWriter_fourcc(*"XVID")
out = cv2.VideoWriter('output.avi', fourcc, 15.0, (320,240))
 
while(True):
    res_100 = "???"
    res_200 = "???"
    res_300 = "???"
    text ="???"
 
    # Capture frame-by-frame
    ret, frame = cap.read()
    
    img = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
 
    for temp_num in [100, 200, 300]:
        temp = cv2.imread("temp" + str(temp_num) + ".png", 0)
        result = cv2.matchTemplate(img, temp, cv2.TM_CCOEFF_NORMED)
        min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)
 
        if max_val > 0.8:
            b = 0
            g = 0
            r = 0
        
            if temp_num == 100:
                b = 255
            if temp_num == 200:
                g = 255
            if temp_num == 300:
                r = 255
 
            top_left = max_loc
            w, h = temp.shape[::-1]
            bottom_right = (top_left[0] + w, top_left[1] + h)
 
            res_x = []
            res_y = []
 
            for i in [0, 1, 2]:
                if top_left[0] >= grid_x[i] and top_left[0] < grid_x[i + 1]:
                    if (i + 1 in res_x) == False:
                        res_x.append(i + 1)
                    for n in [0, 1, 2]:
                        if top_left[1] >= grid_y[n] and top_left[1] < grid_y[n + 1]:
                            if (n + 1 in res_y) == False:
                                res_y.append(n + 1)
 
                                #print("temp" + str(temp_num) + ".png = " + str(res_x[0]) + "-" + str(res_y[0]))
 
                                if temp_num == 100:
                                    res_100 = str(res_x[0]) + "-" + str(res_y[0])
                                if temp_num == 200:
                                    res_200 = str(res_x[0]) + "-" + str(res_y[0])
                                if temp_num == 300:
                                    res_300 = str(res_x[0]) + "-" + str(res_y[0])
 
                                text = str(res_x[0]) + "-" + str(res_y[0]) + "(" + str("{:.3}".format(max_val)) + ")"
 
            cv2.rectangle(frame, top_left, bottom_right, (b, g, r), 2)
            cv2.putText(frame, text, (top_left[0] - 5, top_left[1] - 5), cv2.FONT_HERSHEY_PLAIN, 0.8, (b, g, r), 1, cv2.LINE_AA)
 
    # Display the resulting frame
    # write the frame
    out.write(frame)
 
    cv2.imshow("frame", frame)
 

# When everything done, release the capture
cap.release()
out.release()
cv2.destroyAllWindows()
