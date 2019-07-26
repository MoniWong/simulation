#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>



using namespace std;
using namespace cv;

#pragma once
__declspec(dllexport) Mat fog(Mat srcImg, double beta);
