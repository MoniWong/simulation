#pragma once
#include <QtCore>
#include <opencv2\opencv.hpp>
#include <opencv2\core.hpp>


struct Info {
	QString name;
	cv::Mat Pic;
};

Q_DECLARE_METATYPE(Info)
