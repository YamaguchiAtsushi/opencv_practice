#include <opencv2/opencv.hpp>

int main(int argc, char **argv){
    std::vector<std::string> files{ "apple", "banana", "lena"};

    cv::Mat	image;
    while(1){
        for (int i = 0; i < files.size(); i++) {

            image = cv::imread("/home/yamaguchi/opencv_practice/cpp/images/" + files[i] + ".jpeg");

            if (image.empty() == true) {
                printf("image is empty\n");
            }

            cv::imshow("image", image);

            cv::waitKey(500);
        }
    }
            return 0;
}