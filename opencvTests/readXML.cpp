#include "ocvcontrol.h"

#ifdef READ_XML
#include <opencv2\opencv.hpp>
#include <ostream>


int main()
{
	cv::FileStorage fs;
	fs.open("info.xml", cv::FileStorage::READ);
	if (fs.isOpened())
	{
		cv::Mat tp;
		fs["K"] >> tp;
		if (tp.empty())
		{
			std::cout<<"Read Failed"<<std::endl;
		}
		else
		{
			std::cout << tp;
		}
		fs.release();
	}
	std::cin.ignore();
	return 0;
}
#endif