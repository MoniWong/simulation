#include "pch.h"
#include "dehazer.h"

dehazer::dehazer()
{
	net = nullptr;
}

dehazer::~dehazer()
{
	if (net != nullptr)
		delete net;
}

dehazer* dehazer::dehazerCreater(const std::string& modelPath, const std::string& device)
{
	dehazer* t = new dehazer;
	t->net = pb::pbLoader::creatPbLoader(modelPath, device);
	if (t->net == nullptr || !t->net->addInput({ "0" }) || !t->net->addOutput({ "Relu_5" })) {
		delete t;
		return nullptr;
	}
	return t;
}

void dehazer::run(cv::Mat& img0)
{
	cv::Mat img;
	cv::resize(img0, img, cv::Size(1920, 1080));
	//cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
	float* input_data = new float[3 * 1080 * 1920];
	int idx = 0;
	for (int c = 0; c < 3; ++c)
		for (int i = 0; i < 1080; ++i)
			for (int j = 0; j < 1920; ++j) {
				input_data[idx] = float(img.at<cv::Vec3b>(i, j)[c]) / 255;
				++idx;
			}
	const std::vector<std::int64_t> input_dims = { 1, 3, 1080, 1920 };

	std::vector<void*> output_data = net->run({ input_data }, { input_dims }, { pb::INPUT_TYPE::PB_FLOAT });

	idx = 0;
	for (int c = 0; c < 3; ++c)
		for (int i = 0; i < 1080; ++i)
			for (int j = 0; j < 1920; ++j) {
				img.at<cv::Vec3b>(i, j)[c] = round(((float*)output_data[0])[idx] * 255);
				++idx;
			}

	//cv::cvtColor(img, img, cv::COLOR_RGB2BGR);
	cv::resize(img, img0, img0.size());
	delete[] input_data;
	delete[] output_data[0];
}
