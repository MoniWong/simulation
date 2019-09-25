#pragma once

#include <opencv2\opencv.hpp>

#ifdef DERAINER_EXPORTS
#include "../pbLoader/pbLoader.h"
#define EXPORTS_API __declspec(dllexport) 
#else
#define EXPORTS_API __declspec(dllimport)
#endif // DERAINER_EXPORTS

class EXPORTS_API derainer
{
private:
	derainer();
	derainer(derainer&); //????????
public:
	~derainer();
	static derainer* derainerCreator(const std::string& modelPath, const std::string& device);
	void run(cv::Mat& img);
#ifdef DERAINER_EXPORTS
private:
	pb::pbLoader* net;
#endif // DERAINER_EXPORTS
};
#undef EXPORTS_API