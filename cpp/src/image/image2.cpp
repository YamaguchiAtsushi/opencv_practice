#include <opencv2/opencv.hpp>

int main(int argc, char **argv){
    cv::Mat image1, image2;

	image1 = cv::imread("/home/yamaguchi/opencv_practice/cpp/images/apple.jpeg");
	image2 = cv::imread("/home/yamaguchi/opencv_practice/cpp/images/banana.jpeg");
    
    if (image1.empty() == true || image2.empty() == true) {
		printf("image is empty\n");
	}

    cv::imshow("apple", image1);
	cv::imshow("banana", image2);

    cv::waitKey();

    cv::destroyWindow("apple");

    cv::waitKey();

    return 0;
}