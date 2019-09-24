#pragma once

#include <opencv2\opencv.hpp>

#ifdef  DEHAZER_EXPORTS
#include "../pbLoader/pbLoader.h"
#  define EXPORTS_API __declspec(dllexport)  
#else  
#  define EXPORTS_API __declspec(dllimport)  
#endif //  DEHAZER_EXPORTS

class EXPORTS_API dehazer
{
private:
	dehazer();
	dehazer(dehazer&);
public:
	~dehazer();
	static dehazer* dehazerCreater(const std::string& modelPath, const std::string& device);
	void run(cv::Mat& img);

private:
#ifdef  DEHAZER_EXPORTS
	pb::pbLoader* net;
#endif
};

#undef EXPORTS_API