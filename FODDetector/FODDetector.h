#pragma once

#include <opencv2\opencv.hpp>
#include "../FOD/MyType.h"

#ifdef  FODDETECTOR_EXPORTS
#include "../pbLoader/pbLoader.h"
#  define EXPORTS_API __declspec(dllexport)  
#else  
#  define EXPORTS_API __declspec(dllimport)  
#endif //  FODDetector_EXPORTS

class EXPORTS_API FODDetector
{
private:
	FODDetector();
	FODDetector(FODDetector&);
public:
	~FODDetector();
	static FODDetector* FODDetectorCreater(const std::string& modelPath, const std::string& device);
	DetectResult run(const cv::Mat& inputImage, float NMS_thresh = 0.1, float CONF_thresh = 0.8);

private:
#ifdef FODDETECTOR_EXPORTS
	pb::pbLoader* net;
#endif
};

#undef EXPORTS_API

