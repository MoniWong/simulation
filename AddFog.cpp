#include "Detector.h"

Detector::Detector(std::string modelPath, const char* device)
{
	// 基本初始化
	status = TF_NewStatus();
	errorCode = 完全正常;

	// 图加载
	graph = tf_utils::LoadGraph(modelPath.c_str(), device);
	if (graph == nullptr) errorCode += 无法打开图文件;
	
	// 节点查找
	TF_Output input_op = { TF_GraphOperationByName(graph, "image_tensor"), 0 };
	if (input_op.oper == nullptr) errorCode += 无法找到节点image_tensor;
	TF_Output boxes_op = { TF_GraphOperationByName(graph, "detection_boxes"), 0 };
	if (boxes_op.oper == nullptr) errorCode += 无法找到节点detection_boxes;
	TF_Output scores_op = { TF_GraphOperationByName(graph, "detection_scores"), 0 };
	if (scores_op.oper == nullptr) errorCode += 无法找到节点detection_scores;
	TF_Output classes_op = { TF_GraphOperationByName(graph, "detection_classes"), 0 };
	if (classes_op.oper == nullptr) errorCode += 无法找到节点detection_classes;
	TF_Output num_detections_op = { TF_GraphOperationByName(graph, "num_detections"), 0 };
	if (num_detections_op.oper == nullptr) errorCode += 无法找到节点num_detections;
	inputs_op = { input_op };
	outputs_op = { boxes_op, scores_op, classes_op, num_detections_op };

	sess = nullptr;
	code = TF_OK;
	InitSession();
}

Detector::~Detector()
{
	DestroySession();
	tf_utils::DeleteGraph(graph);
	TF_DeleteStatus(status);
}

void Detector::InitSession()
{
	TF_SessionOptions* options = TF_NewSessionOptions();
	//TF_SetConfig(options, "\x32\x02\x20\x01\x38\x01", 6, status);
	sess = TF_NewSession(graph, options, status);
	TF_DeleteSessionOptions(options);
	code = TF_GetCode(status);
	if (code != TF_OK)
	{
		errorCode += session创建失败;
		sess = nullptr;
	}
}

void Detector::DestroySession()
{
	if (sess == nullptr) return;
	TF_CloseSession(sess, status);
	code = TF_GetCode(status);
	if (code != TF_OK)
	{
		errorCode += session关闭失败;
		return;
	}
	TF_DeleteSession(sess, status);
	code = TF_GetCode(status);
	if (code != TF_OK)
	{
		errorCode += session删除失败;
		return;
	}
	sess = nullptr;
}

int Detector::GetErrorCode()
{
	int t = errorCode;
	errorCode = 0;
	return t;
}

int Detector::GetTFCode()
{
	int t = code;
	code = TF_OK;
	return t;
}

vector<string> Detector::GetGPU()
{
	vector<string> ans;
	if (sess == nullptr) return ans;
	TF_DeviceList* deviceList = TF_SessionListDevices(sess, status);
	int deviceNum = TF_DeviceListCount(deviceList);
	for (int i = 0; i < deviceNum; i++)
	{
		ans.push_back(TF_DeviceListName(deviceList, i, status));
	}
	return ans;
}

DetectResult Detector::Detect(const cv::Mat& inputImage, float NMS_thresh = 0.1, float CONF_thresh = 0.8)
{
	DetectResult result;
	if (sess == nullptr)
	{
		errorCode += 未创建session;
		return result;
	}
	if (inputImage.channels() != 3)
	{
		errorCode += 图像不为三通道;
		return result;
	}
	const std::vector<std::int64_t> input_dims = { 1, inputImage.rows, inputImage.cols, inputImage.channels() };
	TF_Tensor* input_tensor = tf_utils::CreateTensor(TF_UINT8,
		input_dims.data(), input_dims.size(),
		inputImage.data, (size_t)inputImage.rows * inputImage.cols * inputImage.channels() * sizeof(uchar));

	std::vector<TF_Tensor*> input_tensors = { input_tensor };
	std::vector<TF_Tensor*> output_tensors = { nullptr, nullptr, nullptr, nullptr };

	code = tf_utils::RunSession(sess, inputs_op, input_tensors, outputs_op, output_tensors);
	if (code != TF_OK)
	{
		errorCode += session运行失败;
		return result;
	}

	auto boxes_data = static_cast<float*>(TF_TensorData(output_tensors[0]));
	auto scores_data = static_cast<float*>(TF_TensorData(output_tensors[1]));
	auto classes_data = static_cast<float*>(TF_TensorData(output_tensors[2]));
	auto num_detections_data = (int)round(*static_cast<float*>(TF_TensorData(output_tensors[3])));
	bool* flags = new bool[num_detections_data];
	memset(flags, 0, num_detections_data * sizeof(bool));
	float* areas = new float[num_detections_data];
	memset(areas, 0, num_detections_data * sizeof(float));
	// NMS
	for (int i = 0; i < num_detections_data; i++)
	{
		float ymin = boxes_data[i * 4];
		float xmin = boxes_data[i * 4 + 1];
		float ymax = boxes_data[i * 4 + 2];
		float xmax = boxes_data[i * 4 + 3];
		areas[i] = (ymax - ymin) * (xmax - xmin);
		if (scores_data[i] < CONF_thresh) continue; //置信度太低
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
			result.boxes_data.push_back({boxes_data[i * 4], boxes_data[i * 4 + 1], boxes_data[i * 4 + 2], boxes_data[i * 4 + 3]});
			result.classes_data.push_back((int)classes_data[i]);
			result.scores_data.push_back(scores_data[i]);
		}

	delete[] areas;
	delete[] flags;
	tf_utils::DeleteTensor(input_tensor);
	for (auto output_tensor : output_tensors)
		tf_utils::DeleteTensor(output_tensor);

	return result;
}
