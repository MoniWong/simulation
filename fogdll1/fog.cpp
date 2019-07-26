#include "pch.h"
/*#include <iostream>
#include <opencv2/opencv.hpp>



using namespace std;
using namespace cv;*/
#include "fog.h"

__declspec(dllexport) Mat fog(Mat srcImg, double beta)//srcImg为源图像，beta为0.01~0.99 修改雾浓度系数，越大雾越浓
{
	double xi = 1 - beta;

	int x = srcImg.rows;
	int y = srcImg.cols;
	Mat src_fogmask(x, y, CV_8UC3, Scalar(255, 255, 255));
	Mat fog_img(x, y, CV_8UC3);
	addWeighted(src_fogmask, beta, srcImg, xi, -1, fog_img);
	return fog_img;
}

