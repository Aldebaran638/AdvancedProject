#pragma once
#ifndef _CARPAYMENT_CONTROLLER_
#define _CARPAYMENT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/carpayment/CarPaymentDTO.h"
#include "../../domain/query/carpayment/CarPaymentQuery.h"
#include "../../domain/vo/carpayment/CarPaymentVO.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class CarPaymentController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(CarPaymentController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryCarPayment) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("carpayment.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CarPaymentPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "payer_obj_id", ZH_WORDS_GETTER("carpayment.field.payer_obj_id"), "", true);
		
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c4-carpayment/query-carpayment", queryCarPayment, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, CarPaymentQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryCarPayment(userQuery));
	}

	

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addCarPayment) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("carpayment.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/c4-carpayment/add-carpayment", addCarPayment, BODY_DTO(CarPaymentDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddCarPayment(dto, authObject->getPayload()));
	}

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("carpayment.put.summary"), modifyCarPayment, StringJsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c4-carpayment/modify-carpayment", modifyCarPayment, BODY_DTO(CarPaymentDTO::Wrapper, dto), execModifyCarPayment(dto, authObject->getPayload()));

	/*/ 3.1 定义删除接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("carpayment.delete.summary"), removeCarPayment, ListJsonVO<String>::Wrapper);
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/carpayment", removeCarPayment, BODY_DTO(CarPaymentDTO::Wrapper, dto), execRemoveCarPayment(dto, authObject->getPayload()));
	

	// 删除场地接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("carpayment.delete.summary"), removeCarPayment, ListJsonVO<String>::Wrapper);
	// 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c4-carpayment/remove-carpayment", removeCarPayment, BODY_DTO(List<String>, ids), execRemoveCarPayment(ids));
	*/
	//删除折扣
	ENDPOINT_INFO(removeCarPayment) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("carpayment.delete.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT("DELETE", "/c4-carpayment/remove-carpayment", removeCarPayment, BODY_DTO(CarPaymentDeleteDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execRemoveCarPayment(dto, authObject->getPayload()));
	}

	// 3.1 定义缴费接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("fee.put.summary"), payCarPayment, StringJsonVO::Wrapper);
	// 3.2 定义缴费接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c4-carpayment/paycarpayment", payCarPayment, BODY_DTO(CarPaymentDTO::Wrapper, dto), execPayCarPayment(dto, authObject->getPayload()));

	// GetVehicleFee Methods
	ENDPOINT_INFO(queryGetVehicleFeeById) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("GetVehicleFee.query-all.summary"), GetVehicleFeeJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "fee_id", ZH_WORDS_GETTER("fee.fee_id.summary"), "902025052512670021", false);
	}
	// 3.2 定义ID查询接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/c4-carpayment/query-get-vehiclefee", queryGetVehicleFeeById, QUERY(String, fee_id), execQueryGetVehicleFeeById(fee_id));

	// GetPaymentRecords Methods
	ENDPOINT_INFO(queryGetPaymentRecords) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("GetPaymentRecords.query-all.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetPaymentRecordsPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		// 费用项
		API_DEF_ADD_QUERY_PARAMS(String, "fee_name", ZH_WORDS_GETTER("fee.feeName.summary"), "parking fee", false);
		// 费用标识
		API_DEF_ADD_QUERY_PARAMS(String, "value", ZH_WORDS_GETTER("usr.fee.value"), "value", false);
		// 建账时间
		API_DEF_ADD_QUERY_PARAMS(String, "creat_time", ZH_WORDS_GETTER("time.filed.creatTime"), "2025-05-04 00:00:00", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c4-carpayment/query-get-payment-records", queryGetPaymentRecords, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, GetPaymentRecordsQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryGetPaymentRecords(userQuery));
	}

	// GetPaymentDetailedRecord Methods
	// 3.1 定义ID查询接口描述
	ENDPOINT_INFO(queryGetPaymentDetailedRecordById) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("GetPaymentDetailedRecord.query-all.summary"), GetPaymentDetailedRecordJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "detail_id", ZH_WORDS_GETTER("fee.fee_id.summary"), "902025052512670021", false);
	}
	// 3.2 定义ID查询接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/c4-carpayment/query-get-paymentdetailed-recordes", queryGetPaymentDetailedRecordById, QUERY(String, detail_id), execQueryGetPaymentDetailedRecordById(detail_id));

	// GetFeeModificationRecords Methods
	ENDPOINT_INFO(queryGetFeeModificationRecords) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("GetPaymentDetailedRecord.query-all.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetFeeModificationRecordsPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "fee_name", ZH_WORDS_GETTER("fee.feeName.summary"), "parking fee", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c4-carpayment/query-get-modification-records", queryGetFeeModificationRecords, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, GetFeeModificationRecordsQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryGetFeeModificationRecords(userQuery));
	}
private:
	// 3.3 演示分页查询数据
	CarPaymentPageJsonVO::Wrapper execQueryCarPayment(const CarPaymentQuery::Wrapper& query);
	// 3.3 演示新增数据
	StringJsonVO::Wrapper execAddCarPayment(const CarPaymentDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 演示修改数据
	StringJsonVO::Wrapper execModifyCarPayment(const CarPaymentDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 演示删除数据
	//StringJsonVO::Wrapper execRemoveCarPayment(const CarPaymentDTO::Wrapper& dto, const PayloadDTO& payload);
	//ListJsonVO<String>::Wrapper execRemoveCarPayment(const List<String>& ids);
	// 3.3 演示删除数据
	StringJsonVO::Wrapper execRemoveCarPayment(const CarPaymentDeleteDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 演示缴费数据
	StringJsonVO::Wrapper execPayCarPayment(const CarPaymentDTO::Wrapper& dto, const PayloadDTO& payload);

	// 获取费用修改记录处理实现
	GetFeeModificationRecordsPageJsonVO::Wrapper execQueryGetFeeModificationRecords(const GetFeeModificationRecordsQuery::Wrapper& query);

	// 获取缴费详细记录实现
	GetPaymentDetailedRecordJsonVO::Wrapper execQueryGetPaymentDetailedRecordById(const String& id);

	// 获取缴费记录
	GetPaymentRecordsPageJsonVO::Wrapper execQueryGetPaymentRecords(const GetPaymentRecordsQuery::Wrapper& query);

	// 获取车辆费用详情实现
	GetVehicleFeeJsonVO::Wrapper execQueryGetVehicleFeeById(const String& id);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
