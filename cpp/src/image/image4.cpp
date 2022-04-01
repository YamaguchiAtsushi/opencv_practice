#include <opencv2/opencv.hpp>

int main(int argc, char **argv){
    cv::Mat	srcImage, dstImage;

    srcImage = cv::imread("/home/yamaguchi/opencv_practice/cpp/images/lena.jpeg");
    return 0;
    if (srcImage.empty() == true) {
		printf("image is empty\n");
	}
	cv::flip(srcImage, dstImage, 0);

	cv::imshow("original", srcImage);
	cv::imshow("shift", dstImage); 

	cv::imwrite("shift.jpg", dstImage);	
	cv::imwrite("shift.png", dstImage);	

	cv::waitKey(); 
    
    return 0;
}