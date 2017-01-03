#include "control.h"

#ifdef IMSHOW_TEST
#include <opencv2\opencv.hpp>

int main()
{
	cv::Mat img(50, 200, CV_8U, cv::Scalar(255));
	cv::imshow("test",img);
	return cv::waitKey();
}
#endif