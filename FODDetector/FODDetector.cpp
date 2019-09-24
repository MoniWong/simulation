#include "pch.h"
#include "FODDetector.h"

FODDetector::FODDetector()
{
	net = nullptr;
}

FODDetector::~FODDetector()
{
	if (net != nullptr)
		delete net;
}

FODDetector* FODDetector::FODDetectorCreater(const std::string& modelPath, const std::string& device)
{
	FODDetector* t = new FODDetector;
	t->net = pb::pbLoader::creatPbLoader(modelPath, device);
	if (t->net == nullptr) {
		delete t;
		return nullptr;
	}
	t->net->addInput({ "image_tensor" });
	t->net->addOutput({ "detection_boxes", "detection_scores", "detection_classes", "num_detections" });
	return t;
}

DetectResult FODDetector::run(const cv::Mat& inputImage, float NMS_thresh, float CONF_thresh)
{
	DetectResult result;
	const std::vector<std::int64_t> input_dims = { 1, inputImage.rows, inputImage.cols, inputImage.channels() };
	std::vector<void*> output_data = net->run({ inputImage.data }, { input_dims }, { pb::INPUT_TYPE::PB_UINT8 });

	auto boxes_data = static_cast<float*>(output_data[0]);
	auto scores_data = static_cast<float*>(output_data[1]);
	auto classes_data = static_cast<float*>(output_data[2]);
	auto num_detections_data = (int)round(*static_cast<float*>(output_data[3]));
	bool* flags = new bool[num_detections_data];
	memset(flags, 0, num_detections_data * sizeof(bool));
	float* areas = new float[num_detections_data];
	memset(areas, 0, num_detections_data * sizeof(float));

	// NMS
	for (int i = 0; i < num_detections_data; i++)
	{
		if (scores_data[i] < CONF_thresh) continue; //置信度太低
		float ymin = boxes_data[i * 4];
		float xmin = boxes_data[i * 4 + 1];
		float ymax = boxes_data[i * 4 + 2];
		float xmax = boxes_data[i * 4 + 3];
		areas[i] = (ymax - ymin) * (xmax - xmin);
		flags[i] = true;
		for (int j = 0; j < i; j++)
		{
			if (!flags[j]) continue; //不被选择的框
			float yymin = std::max(ymin, boxes_data[j * 4]);
			float xxmin = std::max(xmin, boxes_data[j * 4 + 1]);
			float yymax = std::min(ymax, boxes_data[j * 4 + 2]);
			float xxmax = std::min(xmax, boxes_data[j * 4 + 3]);
			float inter = std::max((float)0, xxmax - xxmin) * std::max((float)0, yymax - yymin);
			if (inter / (areas[i] + areas[j] - inter) < NMS_thresh) continue; //不重叠，不影响
			if (scores_data[i] > scores_data[j]) //换框
			{
				flags[j] = false;
				break;
			}
			flags[i] = false; // 废弃这个框
			break;
		}
	}

	// 设置result
	for (int i = 0; i < num_detections_data; i++)
		if (flags[i])
		{
			result.num_detections++;
			result.boxes_data.push_back({ boxes_data[i * 4], boxes_data[i * 4 + 1], boxes_data[i * 4 + 2], boxes_data[i * 4 + 3] });
			result.classes_data.push_back((int)classes_data[i]);
			result.scores_data.push_back(scores_data[i]);
		}

	delete[] areas;
	delete[] flags;
	for (auto& o : output_data)
		delete[] o;
	return result;
}
