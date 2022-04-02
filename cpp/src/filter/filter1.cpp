#include <opencv2/opencv.hpp>

int main(int argc, char **argv){
    cv::Mat src, dst1, dst2, dst3, dst4;

    src = cv::imread("/home/yamaguchi/opencv_practice/cpp/images/lena.jpeg");

    cv::blur(src, dst1, cv::Size(7, 7));

    cv::medianBlur(src, dst2, 7);

    cv::GaussianBlur(src, dst3, cv::Size(7, 7), 0.0);

    cv::bilateralFilter(src, dst4, 20, 200, 20);

    cv::imshow("原画像", src);
	cv::imshow("平均値フィルタ", dst1);
	cv::imshow("中央値フィルタ", dst2);
	cv::imshow("ガウシアンフィルタ", dst3);
	cv::imshow("バイラテラルフィルタ", dst4);

	cv::waitKey(); 
	return 0;
}