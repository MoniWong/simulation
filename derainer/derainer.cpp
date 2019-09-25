#include "pch.h"
#include "derainer.h"

derainer::derainer()
{
	net = nullptr;
}

derainer::~derainer()
{
	if (net != nullptr) 
		delete net;
	
}

derainer* derainer::derainerCreator(const std::string& modelPath, const std::string& device)
{
	derainer* t = new derainer;
	t->net = pb::pbLoader::creatPbLoader(modelPath, device);
	if (t->net == nullptr || !t->net->addInput({ "input.1" }) || !t->net->addOutput({ "Add_76" }))
	{
		delete t;
		return nullptr;
	}
	//t->net->addInput({ "input.1" });
	//t->net->addInput({ "input.1" });
	//t->net->addOutput({ "Add_76" });
	return t;
}

void derainer::run(cv::Mat& input)
{
	cv::Mat img;
	cv::resize(input, img, cv::Size(240, 240));
	cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
	float* inputDT = new float[3 * 240 * 240];
	int idx = 0;
	for (int c=0; c<3; c++)
		for(int i=0; i<240; i++)
			for (int j = 0; j < 240; j++)
			{
				inputDT[idx] = float(img.at<cv::Vec3b>(i, j)[c])/255;
				++idx;
			}
	const std::vector<std::int64_t> input_dims = {1, 3, 240, 240};

	std::vector<void*> outputDT = net->run({ inputDT }, { input_dims }, { pb::INPUT_TYPE::PB_FLOAT });

	idx = 0;
	for (int c = 0; c < 3; ++c)
		for (int i = 0; i < 240; ++i)
			for (int j = 0; j < 240; ++j) {
				img.at<cv::Vec3b>(i, j)[c] = round(((float*)outputDT[0])[idx] * 255);
				++idx;
			}
	cv::cvtColor(img, img, cv::COLOR_RGB2BGR);
	cv::resize(img, input, input.size());
	delete[] inputDT;
	delete[] outputDT[0];
}