#include "pch.h"
#include "framework.h"
#include "addRain.h"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <cstdlib>
#include <ctime>
#include <math.h>


#define random(a,b) (rand()%(b-a+1)+a)


//cv::Mat addRain(cv::Mat oriImg)
//{
//	int r = oriImg.rows;
//	int c = oriImg.cols;
//	hugeRain hrain("..\\Data\\point_light_database\\");
//	cv::Mat rain = hrain.initMask("..\\Data\\point_light_database\\");
//	//随机在大图中截取出来雨掩膜
//	srand((unsigned)time(NULL));
//	int startX = random(1, 10000 - c);
//	int startY = random(1, 10000 - r);
//	for (int i = 0; i < c; i++)
//	{
//		for (int j = 0; j < r; j++)
//		{
//			oriImg.at<cv::Vec3b>(i, j) = oriImg.at<cv::Vec3b>(i, j) + rain.at<cv::Vec3b>(startX + i, startY + j);
//		}
//	}
//	return oriImg;
//}


std::vector<int> getRandList(int num, int upBound)
{
	std::vector<int> rdVec;
	//srand((unsigned)time(NULL));
	for (int i = 0; i < num; i++)
	{
		int rd = rand() % (upBound + 1);
		rdVec.push_back(rd);
	}
	return rdVec;
}

int whether(int a, int b) 
{
	if ((a + b) < 255) { return (a + b); }
	else { return 255; }
}

cv::Mat addRain(cv::Mat oriImg, double alpha, std::string dtbpath)
{
	//alpha = (int)alpha * 1000;
	
	int r = oriImg.rows;
	int c = oriImg.cols;
	//准备读入数据库
	int numPics = 3700;
	int selectPics = (int)ceil(numPics * alpha);

	srand((unsigned)time(NULL));
	std::vector<int> xList = getRandList(selectPics, c);
	srand((unsigned)time(NULL) + 1000);
	std::vector<int> yList = getRandList(selectPics, r);
	std::vector<int> idx = getRandList(selectPics, numPics - 1);
	for (int k = 0; k < selectPics; k++) {
		char t_c[256];
		sprintf_s(t_c, "%s/%04d.png", dtbpath.c_str(), idx[k]);
		std::string picName(t_c);
		cv::Mat patch = cv::imread(picName, CV_8SC3);
		int pC = patch.cols;
		int pR = patch.rows;
		int x = xList[k];
		int y = yList[k];
		if ((y + pR < r)&&(x + pC < c)) {
			for (int i = 0; i < pR; i++) {
				for (int j = 0; j < pC; j++) {
					oriImg.at<cv::Vec3b>(y + i, x + j)[0] = whether(oriImg.at<cv::Vec3b>(y + i, x + j)[0], patch.at<cv::Vec3b>(i, j)[0]);
					oriImg.at<cv::Vec3b>(y + i, x + j)[1] = whether(oriImg.at<cv::Vec3b>(y + i, x + j)[1], patch.at<cv::Vec3b>(i, j)[1]);
					oriImg.at<cv::Vec3b>(y + i, x + j)[2] = whether(oriImg.at<cv::Vec3b>(y + i, x + j)[2], patch.at<cv::Vec3b>(i, j)[2]);
					
				}
			}
		}
		else if ((y + pR < r) && (x + pC >= c)) {
			for (int i = 0; i < pR; i++) {
				for (int j = 0; j < c - x; j++) {
					oriImg.at<cv::Vec3b>(y + i, x + j)[0] = whether(oriImg.at<cv::Vec3b>(y + i, x + j)[0], patch.at<cv::Vec3b>(i, j)[0]);
					oriImg.at<cv::Vec3b>(y + i, x + j)[1] = whether(oriImg.at<cv::Vec3b>(y + i, x + j)[1], patch.at<cv::Vec3b>(i, j)[1]);
					oriImg.at<cv::Vec3b>(y + i, x + j)[2] = whether(oriImg.at<cv::Vec3b>(y + i, x + j)[2], patch.at<cv::Vec3b>(i, j)[2]);
				}
			}
		}
		else if ((y + pR >= r) && (x + pC < c)) {
			for (int i = 0; i < r - y; i++) {
				for (int j = 0; j < pC; j++) {
					oriImg.at<cv::Vec3b>(y + i, x + j)[0] = whether(oriImg.at<cv::Vec3b>(y + i, x + j)[0], patch.at<cv::Vec3b>(i, j)[0]);
					oriImg.at<cv::Vec3b>(y + i, x + j)[1] = whether(oriImg.at<cv::Vec3b>(y + i, x + j)[1], patch.at<cv::Vec3b>(i, j)[1]);
					oriImg.at<cv::Vec3b>(y + i, x + j)[2] = whether(oriImg.at<cv::Vec3b>(y + i, x + j)[2], patch.at<cv::Vec3b>(i, j)[2]);
				}
			}
		}
		else {
			for (int i = 0; i < r - y; i++) {
				for (int j = 0; j < c - x; j++) {
					oriImg.at<cv::Vec3b>(y + i, x + j)[0] = whether(oriImg.at<cv::Vec3b>(y + i, x + j)[0], patch.at<cv::Vec3b>(i, j)[0]);
					oriImg.at<cv::Vec3b>(y + i, x + j)[1] = whether(oriImg.at<cv::Vec3b>(y + i, x + j)[1], patch.at<cv::Vec3b>(i, j)[1]);
					oriImg.at<cv::Vec3b>(y + i, x + j)[2] = whether(oriImg.at<cv::Vec3b>(y + i, x + j)[2], patch.at<cv::Vec3b>(i, j)[2]);
				}
			}
		}
	}
	return oriImg;
}