#include "pch.h"
#include "pbLoader.h"

using namespace pb;

pbLoader::pbLoader()
{
	status = TF_NewStatus();
	errorCode = 完全正常;
	sess = nullptr;
	code = TF_OK;
	graph = nullptr;
}

void pbLoader::loadGraph(const char* modelPath, const char* device)
{
	graph = tf_utils::LoadGraph(modelPath, device);
	if (graph == nullptr)
		errorCode |= 无法打开图文件;
	else
		InitSession();
}

pbLoader* pbLoader::creatPbLoader(const std::string& modelPath, const std::string& device)
{
	pbLoader* t = new pbLoader;

	// 图加载
	t->loadGraph(modelPath.c_str(), device.c_str());
	if (t->GetErrorCode() == 0)
		return t;
	delete t;
	return nullptr;
}

std::vector<std::string> pb::pbLoader::getDeviceList()
{
	TF_Status* t_status = TF_NewStatus();
	TF_Graph* t_graph = TF_NewGraph();
	TF_SessionOptions* t_ops = TF_NewSessionOptions();
	TF_SetConfig(t_ops, "\x32\x02\x20\x01\x38\x01", 6, t_status);
	TF_Session* t_sess = TF_NewSession(t_graph, t_ops, t_status);
	TF_DeviceList* t_deviceList = TF_SessionListDevices(t_sess, t_status);
	std::vector<std::string> ans;
	int count = TF_DeviceListCount(t_deviceList);
	for (int i = 0;i < count;i++)
		ans.push_back(std::string(TF_DeviceListName(t_deviceList, i, t_status)));
	TF_DeleteDeviceList(t_deviceList);
	TF_DeleteSession(t_sess, t_status);
	TF_DeleteSessionOptions(t_ops);
	TF_DeleteGraph(t_graph);
	TF_DeleteStatus(t_status);
	return ans;
}

pbLoader::~pbLoader()
{
	DestroySession();
	tf_utils::DeleteGraph(graph);
	TF_DeleteStatus(status);
}

bool pbLoader::addInput(std::vector<std::string> ops_name)  // 输入节点查找
{	
	inputs_op.clear();
	for (auto &op_name : ops_name)
	{
		TF_Output op = { TF_GraphOperationByName(graph, op_name.c_str()), 0 };
		if (op.oper == nullptr) {
			errorCode |= 无法找到节点;
			return false;
		}
		inputs_op.push_back(op);
	}

	return true;
}

bool pbLoader::addOutput(std::vector<std::string> ops_name)
{
	outputs_op.clear();
	for (auto op_name : ops_name)
	{
		TF_Output op = { TF_GraphOperationByName(graph, op_name.c_str()), 0 };
		if (op.oper == nullptr) {
			errorCode |= 无法找到节点;
			return false;
		}
		outputs_op.push_back(op);
	}
	return true;
}

void pbLoader::InitSession()
{
	TF_SessionOptions* options = TF_NewSessionOptions();
	TF_SetConfig(options, "\x32\x02\x20\x01\x38\x01", 6, status);
	sess = TF_NewSession(graph, options, status);
	TF_DeleteSessionOptions(options);
	code = TF_GetCode(status);
	if (code != TF_OK)
	{
		errorCode |= session创建失败;
		sess = nullptr;
	}
}

void pbLoader::DestroySession()
{
	if (sess == nullptr) return;
	TF_CloseSession(sess, status);
	code = TF_GetCode(status);
	if (code != TF_OK)
	{
		errorCode |= session关闭失败;
		return;
	}
	TF_DeleteSession(sess, status);
	code = TF_GetCode(status);
	if (code != TF_OK)
	{
		errorCode |= session删除失败;
		return;
	}
	sess = nullptr;
}

int pbLoader::GetErrorCode()
{
	int t = errorCode;
	errorCode = 0;
	return t;
}

int pbLoader::GetTFCode()
{
	int t = code;
	code = TF_OK;
	return t;
}

std::vector<void*> pbLoader::run(std::vector<void*> inputs, std::vector<std::vector<std::int64_t>> inputs_dims, std::vector<INPUT_TYPE> inputs_type)
{
	std::vector<void*> result;
	if (inputs.size() != inputs_op.size() || inputs_dims.size() != inputs_op.size())
	{
		errorCode |= tensor尺寸错误;
		return result;
	}
		
	if (sess == nullptr)
	{
		errorCode |= 未创建session;
		return result;
	}
	std::vector<TF_Tensor*> input_tensors;
	std::vector<TF_Tensor*> output_tensors(outputs_op.size(), nullptr);
	for (int i = 0; i < inputs_op.size(); ++i)
	{
		TF_DataType td;
		switch (inputs_type[i])
		{
		case INPUT_TYPE::PB_FLOAT:
			td = TF_FLOAT;
			break;
		case INPUT_TYPE::PB_DOUBLE:
			td = TF_DOUBLE;
			break;
		case INPUT_TYPE::PB_INT32:
			td = TF_INT32;
			break;
		case INPUT_TYPE::PB_UINT8:
			td = TF_UINT8;
			break;
		case INPUT_TYPE::PB_INT16:
			td = TF_INT16;
			break;
		case INPUT_TYPE::PB_INT8:
			td = TF_INT8;
			break;
		}
		int64_t t = TF_DataTypeSize(td);
		for (auto d : inputs_dims[i])
			t *= d;
		TF_Tensor* input_tensor = tf_utils::CreateTensor(td,
			inputs_dims[i].data(), inputs_dims[i].size(),
			inputs[i], t);
		input_tensors.push_back(input_tensor);
	}

	code = tf_utils::RunSession(sess, inputs_op, input_tensors, outputs_op, output_tensors);

	if (code != TF_OK)
	{
		errorCode |= session运行失败;
		return result;
	}

	for (auto input_tensor : input_tensors)
		tf_utils::DeleteTensor(input_tensor);

	for (auto output_tensor : output_tensors)
	{
		size_t t_size = TF_TensorByteSize(output_tensor);
		void* t = new char[t_size];
		memcpy(t, TF_TensorData(output_tensor), t_size);
		result.push_back(t);
		tf_utils::DeleteTensor(output_tensor);
	}

	return result;
}
