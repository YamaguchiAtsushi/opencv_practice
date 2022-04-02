#include <opencv2/opencv.hpp>

int main(int argc, char **argv){
    cv::Mat	src, dst1, dst2;

    src = cv::imread("/home/yamaguchi/opencv_practice/cpp/images/lena.jpeg", cv::IMREAD_GRAYSCALE);

    cv::equalizeHist(src, dst1);

    double gamma = 1.5;
    uchar lut[256];
    for(int i = 0; i < 256; i++){
        lut[i] = pow(i / 255.0, 1 / gamma) * 255.0;// i / 255.0 の.0 を書かないと真っ黒な画像になる
    }


    cv::LUT(src, cv::Mat(1, 256, CV_8UC1, lut), dst2);

    cv::imshow("原画像", src);
	cv::imshow("ヒストグラム平坦化", dst1);
	cv::imshow("ガンマ補正", dst2);

	cv::waitKey();

	return 0;
}