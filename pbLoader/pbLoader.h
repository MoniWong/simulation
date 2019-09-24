#pragma once

#include "pbLoaderErrorCode.h"
#include <string>
#include <vector>

#ifdef  PBLOADER_EXPORTS
#include "tf_utils.hpp"
#  define EXPORTS_API __declspec(dllexport)  
#else  
#  define EXPORTS_API __declspec(dllimport)  
#endif //  PBLOADER_EXPORTS

namespace pb {
	enum INPUT_TYPE {
		PB_FLOAT = 1,
		PB_DOUBLE = 2,
		PB_INT32 = 3,  // Int32 tensors are always in 'host' memory.
		PB_UINT8 = 4,
		PB_INT16 = 5,
		PB_INT8 = 6
	};


	class EXPORTS_API pbLoader
	{
	private:
		pbLoader();
		pbLoader(pbLoader&);
		void loadGraph(const char* modelPath, const char* device);

	public:
		static pbLoader* creatPbLoader(const std::string& modelPath, const std::string& device);
		static std::vector<std::string> getDeviceList();
		~pbLoader();

		bool addInput(std::vector<std::string> ops_name);
		bool addOutput(std::vector<std::string> ops_name);

		int GetErrorCode();
		int GetTFCode();

		std::vector<void*> run(std::vector<void*> inputs, std::vector<std::vector<std::int64_t>> inputs_dims, std::vector<INPUT_TYPE> inputs_type);

#ifdef  PBLOADER_EXPORTS
	private:
		void InitSession();
		void DestroySession();
		int errorCode;
		TF_Code code;

		TF_Graph* graph;
		TF_Status* status;
		TF_Session* sess;
		std::vector<TF_Output> inputs_op;
		std::vector<TF_Output> outputs_op;
#endif
	};
}

#undef EXPORTS_API