#include "control.h"

#ifdef WRITE_XML

#include <opencv2\opencv.hpp>
#include <ostream>


int main()
{
	double data[] =
	{ 2772.72755, 0, 857.59619,
	0, 2787.18505, 694.20449,
	0, 0, 1
	};
	double range[] = { 8, 130 };

	double distor[] = { -0.11117, 0.10217, 0.01018, 0.01054 };


	cv::Mat kmat(3, 3, CV_64FC1, data);
	cv::Mat rmat(2, 1, CV_64FC1, range);
	cv::Mat distormat(4, 1, CV_64FC1, distor);
	std::cout << kmat << std::endl;
	cv::FileStorage fs;
	fs.open("info.xml", cv::FileStorage::WRITE);
	fs << "K" << kmat << "range" << rmat << "dist" << distormat;
	fs.release();
	return 0;
}

#endif