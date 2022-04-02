#include <opencv2/opencv.hpp>

int main(int argc, char **argv){
    cv::Mat	src, dst1, dst2, dst3, dst4;

    src = cv::imread("/home/yamaguchi/opencv_practice/cpp/images/lena.jpeg", cv::IMREAD_GRAYSCALE);
    
    cv::threshold(src, dst1, 140, 255, cv::THRESH_BINARY);
    cv::threshold(src, dst2, 0, 255, cv::THRESH_OTSU);
    cv::dilate(dst2, dst3, cv::Mat());
    cv::erode(dst2, dst4, cv::Mat());

    cv::imshow("原画像", src);
	cv::imshow("2値化処理", dst1);
	cv::imshow("2値化処理（大津の方法）", dst2);
	cv::imshow("膨張処理", dst3);
	cv::imshow("収縮処理", dst4);

	cv::waitKey();

	return 0;
}