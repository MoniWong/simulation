#pragma once

#ifdef QT_CORE_LIB

#include <QtCore>
//#include <..\fodScan\function\function.h>

struct Info {
	QString name;
	QString ip;
	QString password;
	QString account;
	QString port;
	QString COM;
	QString BaudRate;
	QString DataBits;
	QString Parity;
	QString StopBits;
	QString FlowControl;
	int photo_time;
	QString scene;
	bool flag;

	//FOD_SCAN* Fod_scan;
};

Q_DECLARE_METATYPE(Info)

struct DetectorInfo {
	QString detectorname;
	QString hardware;
	QString pbmodel;
	double confidencethreshold;
	double restrainthreshold;
	bool isdehaze;
	bool isderain;
	bool isload;
};

Q_DECLARE_METATYPE(DetectorInfo)

//Q_DECLARE_OPAQUE_POINTER(DetectorInfo*)

#endif // QT_CORE_LIB

struct DetectResult {
	std::vector<std::vector<float>> boxes_data; //ymin, xmin, ymax, xmax
	std::vector<int> classes_data;
	std::vector<float> scores_data;
	int num_detections;
	DetectResult() { num_detections = 0; };
};

#ifdef QT_CORE_LIB

Q_DECLARE_METATYPE(DetectResult)

#endif // QT_CORE_LIB