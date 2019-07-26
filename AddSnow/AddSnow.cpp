// AddSnow.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include "framework.h"
#include "AddSnow.h"

#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;



// 这是导出变量的一个示例
//ADDSNOW_API Mat nAddSnow;

// 这是导出函数的一个示例。
cv::Mat addSnow(cv::Mat oriImg, double ext)
{
	int vol = ceil(ext * 10000.0);
	int c = oriImg.cols;
	int r = oriImg.rows;
	if (!oriImg.data)
	{
		cout << "输入图片为空" << endl;
		return cv::Mat::zeros(2,2, CV_8UC3);
	}

	//cv::namedWindow("原图", CV_WINDOW_NORMAL);
	//cv::namedWindow("下雪图", CV_WINDOW_NORMAL);

	for (int k = 0; k < vol; k++)
	{
		int i = random(1,c-10);
		int j = random(1,r-10);
		if (oriImg.channels() == 1) {
			oriImg.at<uchar>(j, i) = 255;
			if (i < (int)oriImg.cols)
				oriImg.at<uchar>(j + 1, i) = 255;
			if (j < (int)oriImg.rows)
				oriImg.at<uchar>(j, i + 1) = 255;
			if (i < (int)oriImg.cols && j < (int)oriImg.rows)
				oriImg.at<uchar>(j + 1, i + 1) = 255;
		}
		else if (oriImg.channels() == 3) {
			if (i < (int)oriImg.cols - 1) {
				oriImg.at<cv::Vec3b>(j + 1, i)[0] = 255;
				oriImg.at<cv::Vec3b>(j + 1, i)[1] = 255;
				oriImg.at<cv::Vec3b>(j + 1, i)[2] = 255;
			}				
			if (j < (int)oriImg.rows - 1) {
				oriImg.at<cv::Vec3b>(j, i + 1)[0] = 255;
				oriImg.at<cv::Vec3b>(j, i + 1)[1] = 255;
				oriImg.at<cv::Vec3b>(j, i + 1)[2] = 255;
			}				
			if (i < (int)oriImg.cols - 1 && j < (int)oriImg.rows - 1) {
				oriImg.at<cv::Vec3b>(j + 1, i + 1)[0] = 255;
				oriImg.at<cv::Vec3b>(j + 1, i + 1)[1] = 255;
				oriImg.at<cv::Vec3b>(j + 1, i + 1)[2] = 255;
			}				
		}
	}
	return oriImg;
}

// 这是已导出类的构造函数。
//CAddSnow::CAddSnow()
//{
//    return;
//}

