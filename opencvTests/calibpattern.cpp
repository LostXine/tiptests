#include "ocvcontrol.h"

#ifdef CALIB_PATT
#include <opencv2\opencv.hpp>

int main(int argc, char** argv)
{
	printf("---���ɱ궨��---\n������ÿ���������� ���� ����\n");
	if (argc < 4)
	{
		printf("����%d��̫��", argc);
		system("pause");
		return 0;
	}

	unsigned int width = atoi(argv[1]);
	unsigned int rows = atoi(argv[2]);
	unsigned int cols = atoi(argv[3]);

	printf("���%d��%d�У�ÿ�����̸�%d����.\n", rows, cols, width);

	//���ɱ궨��
	cv::Mat pat(rows*width, cols*width, CV_8UC1);
	for (int i = 0; i < rows*width; i++)
	{
		for (int j = 0; j < cols*width; j++)
		{
			pat.at<char>(i, j) = 255 * ((i / width) % 2 ^ (j / width) % 2);
		}
	}
	cv::imshow("pat", pat);
	cv::imwrite("calibpattern.png", pat);
	cv::waitKey();
	return 0;
}
#endif