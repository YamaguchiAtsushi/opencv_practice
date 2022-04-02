#include <opencv2/opencv.hpp>

int main(int argc, char **argv){
    cv::VideoCapture cap;

    cap.open(0);
    if(cap.isOpened() ==false){
        printf("camera not found");
    }
    int width = (int)cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int height = (int)cap.get(cv::CAP_PROP_FRAME_WIDTH);

    printf("image size %d %d\n", width, height);

    cv::Mat frame;

    while(cap.read(frame)){
    cv::imshow("win", frame);
    const int key = cv::waitKey(1);
    }


/*
    for(;;){
        cap >> frame;

        if(frame.empty() == true){
            break;
        }
        cv::imshow("input", frame);

        int key = cv::waitKey(30);

        if(key > 0){
            break;
        }
    }
*/
    return 0;
}


