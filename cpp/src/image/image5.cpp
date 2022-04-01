#include <opencv2/opencv.hpp>

int main(int argc, char **argv){
    cv::Mat image;

    image = cv::imread("/home/yamaguchi/opencv_practice/cpp/images/lena.jpeg");

    if(image.empty() == true){
        printf("image is empty\n");
    }

    cv::imshow("original", image);

    cv::imwrite("default.jpeg", image);

    std::vector<int> params(2);
    params[0] = cv::IMWRITE_JPEG_QUALITY;

    params[1] = 0;
    cv::imwrite("0.jpeg", image, params);

    params[1] = 10;
    cv::imwrite("10.jpeg", image, params);

    params[1] = 50;
    cv::imwrite("50.jpeg", image, params);

    params[1] = 95;
    cv::imwrite("95.jpeg", image, params);

    params[1] = 100;
    cv::imwrite("100.jpeg", image, params);

    cv::waitKey();

    return 0;
}