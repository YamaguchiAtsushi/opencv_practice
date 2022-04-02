#include <opencv2/opencv.hpp>
 
int main(void)
{
	// 画像を格納するオブジェクトを宣言する
	cv::Mat	src, dst1, dst2, dst3, dst4, dst5;
 
	// 画像ファイルから画像データを読み込む
	src = cv::imread("/home/yamaguchi/opencv_practice/cpp/images/lena.jpeg", cv::IMREAD_COLOR);
 
	if (src.empty() == true) {
		// 画像データが読み込めなかったときは終了する
		return 0;
	}
 
	// 非写実的レンダリング
	float sigma_s = 60.0;		// 0～200
	float sigma_r = 0.07;		// 0～1
	float shade_factor = 0.02;	// 0～0.1
	std::cout << "鉛筆画風 処理中..." << std::endl;
	cv::pencilSketch(src, dst1, dst2, sigma_s, sigma_r, shade_factor);
 
	sigma_s = 60.0;	// 0～200
	sigma_r = 0.5;	// 0～1
	std::cout << "スタライズ 処理中..." << std::endl;
	cv::stylization(src, dst3, sigma_s, sigma_r);
 
	sigma_s = 10.0;	// 0～200
	sigma_r = 0.15;	// 0～1
	std::cout << "細部強調 処理中..." << std::endl;
	cv::detailEnhance(src, dst4, sigma_s, sigma_r);
 
	sigma_s = 60.0;	// 0～200
	sigma_r = 0.4;	// 0～1
	std::cout << "エッジ保存平滑化 処理中..." << std::endl;
	cv::edgePreservingFilter(src, dst5, 1, sigma_s, sigma_r);
 
	// ウィンドウに画像を表示する
	cv::imshow("原画像", src);
	cv::imshow("鉛筆画風（モノクロ）", dst1);
	cv::imshow("鉛筆画風（カラー）", dst2);
	cv::imshow("スタライズ", dst3);
	cv::imshow("細部強調", dst4);
	cv::imshow("エッジ保存平滑化", dst5);
 
	// 何かキーが押されるまで待つ
	cv::waitKey();
 
	return 0;
}