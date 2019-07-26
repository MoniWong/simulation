#pragma once

#include <opencv2/opencv.hpp>
#include "MyType.h"
#include <vector>

using namespace std;

class Detector
{
private:
	Detector();

public:
	Detector(std::string modelPath, const char* device);
	~Detector();

	void InitSession();
	void DestroySession();

	int GetErrorCode();
	int GetTFCode();
	vector<string> GetGPU();

	DetectResult Detect(const cv::Mat& inputImage, float NMS_thresh, float CONF_thresh);

private:
	int errorCode;
	TF_Code code;

	TF_Graph* graph;
	TF_Status* status;
	TF_Session* sess;
	std::vector<TF_Output> inputs_op;
	std::vector<TF_Output> outputs_op;

};