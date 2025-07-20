#pragma once

#ifndef _RMREMINDERSCONTROLLER_H_
#define _RMREMINDERSCONTROLLER_H_


#include "domain/vo/arrears_reminders/ExRmremindersVO.h"
#include "domain/dto/arrears_reminders/ExRmremindersDTO.h"

#include "domain/vo/BaseJsonVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class RmremindersController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	API_ACCESS_DECLARE(RmremindersController);

public:  // 定义接口
	
	// 3.1 定义删除接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("axing.delete"), removeSample, ListJsonVO<String>::Wrapper);
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c5-feemanage/payremind/delete-payremind", removeSample, BODY_DTO(List<String>, ids), execRemoveSample(ids));
	 
	//1.1描述导出催缴信息 
	ENDPOINT_INFO(downloadOweIn) {
		//ui的显示
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("axing.payremind"), Void);
		//参数的描述
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("axing.download.summary"), "payremind.xlsx", false);
		//加凭证
		API_DEF_ADD_AUTH();
	}
	//1.2描述端点
	ENDPOINT(API_M_GET, "/c5-feemanage/payremind/download-payremind", downloadOweIn, QUERY(String, filename), API_HANDLER_AUTH_PARAME) {
		return downloadPayRemind(filename);
	}

	
private:  // 定义接口执行函数

	// 3.3 演示删除数据
	ListJsonVO<String>::Wrapper execRemoveSample(const List<String>& ids);
	//1.导出催缴信息excle文件
	std::shared_ptr<OutgoingResponse> downloadPayRemind(const String& filename);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_