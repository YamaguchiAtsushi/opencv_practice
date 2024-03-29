# -*- coding: utf-8 -*-
import numpy as np
import cv2
if __name__ == '__main__':
    cap = cv2.VideoCapture(0)
    # 追跡する枠の座標とサイズ
    x = 200
    y = 200
    w = 200
    h = 200
    track_window = (x, y, w, h)
    # フレームの取得(frameにはカラーの静止画が格納されている)
    ret,frame = cap.read()
    #cv2.imshow('SHOW MEANSHIFT IMAGE', frame)

    # 追跡する枠を決定(roiにはtrack_window部分の切り抜きが格納されている)
    roi = frame[y:y+h, x:x+w]
    #cv2.imshow('SHOW MEANSHIFT IMAGE', roi)

    # 追跡する枠の内部を切り抜いてHSV変換
    hsv_roi =  cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)
    ## マスク画像の生成
    img_mask = cv2.inRange(hsv_roi, np.array((0., 60.,32.)), np.array((180.,255.,255.)))
    ## 正規化するためのヒストグラムの生成 
    roi_hist = cv2.calcHist([hsv_roi], [0], img_mask, [180], [0,180])
    ## ノルム正規化
    cv2.normalize(roi_hist, roi_hist, 0, 255, cv2.NORM_MINMAX)
    term_crit = ( cv2.TERM_CRITERIA_EPS | cv2.TERM_CRITERIA_COUNT, 10, 1 )
    while(True):
        ret, frame = cap.read()
        if ret == True:
            # フレームをHSV変換する
            hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
            # 上で計算したヒストグラムを特徴量として、画像の類似度を求める
            dst = cv2.calcBackProject([hsv],[0],roi_hist,[0,180], 1)
            # 物体検出する
            ret, track_window = cv2.meanShift(dst, track_window, term_crit)
            #ret, track_window = cv2.CamShift(dst, track_window, term_crit)

            # 物体検出で取得した座標を元のフレームで囲う
            x,y,w,h = track_window
            img_dst = cv2.rectangle(frame, (x,y), (x+w, y+h), 255, 2)
            cv2.imshow('SHOW MEANSHIFT IMAGE', img_dst)
            # qを押したら終了。
            k = cv2.waitKey(1)
            if k == ord('q'):
                break
        else:
            break