#include <opencv2/opencv.hpp>

int main(int argc, char **argv){
    cv::Mat image1, image2, image3, image4;

    image1 = cv::imread("/home/yamaguchi/opencv_practice/cpp/images/lena.jpeg", cv::IMREAD_COLOR);
    image2 = cv::imread("/home/yamaguchi/opencv_practice/cpp/images/lena.jpeg", cv::IMREAD_GRAYSCALE);
    image3 = cv::imread("/home/yamaguchi/opencv_practice/cpp/images/lena.jpeg", cv::IMREAD_REDUCED_COLOR_2);
    image4 = cv::imread("/home/yamaguchi/opencv_practice/cpp/images/lena.jpeg", cv::IMREAD_REDUCED_COLOR_4);

    if(image1.empty() == true){
        printf("image is empty");
    }

    cv::imshow("COLOR", image1);
	cv::imshow("GRAYSCALE", image2);
	cv::imshow("REDUCED_COLOR_2", image3);
	cv::imshow("REDUCED_COLOR_4", image4);

    cv::waitKey();

    return 0;
}