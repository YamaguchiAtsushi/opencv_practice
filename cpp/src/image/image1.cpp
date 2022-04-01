#include <opencv2/opencv.hpp>

int main(int argc, char **argv){
	cv::Mat	image;

	image = cv::imread("/home/yamaguchi/opencv_practice/cpp/images/lena.jpeg");

	if (image.empty() == true) {
        printf("image is empty\n");
	}
	cv::imshow("image", image);
	cv::waitKey();
	return 0;
}