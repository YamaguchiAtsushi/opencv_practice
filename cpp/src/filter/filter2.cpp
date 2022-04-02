#include <opencv2/opencv.hpp>

int main(int argc, char **argv){
    cv::Mat src, dst1, dst2, dst3, dst4, dst5, dst6;

    src = cv::imread("/home/yamaguchi/opencv_practice/cpp/images/lena.jpeg");

    cv::Laplacian(src, dst1, -1);

    cv::Sobel(src, dst2, -1, 1, 0);
    cv::Sobel(src, dst3, -1, 0, 1);

    cv::Canny(src, dst4, 60.0, 150.0);

    cv::imshow("原画像", src);
	cv::imshow("ラプラシアンフィルタ", dst1);
	cv::imshow("Sobelフィルタ x方向", dst2);
	cv::imshow("Sobelフィルタ y方向", dst3);
	cv::imshow("Cannyフィルタ", dst4);
	
	cv::waitKey();

	return 0;

}