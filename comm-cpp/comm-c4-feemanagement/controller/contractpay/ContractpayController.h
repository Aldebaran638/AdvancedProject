#pragma once

#ifndef _CONTRACTPAYCONTROLLER_H_
#define _CONTRACTPAYCONTROLLER_H_


#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/contractpay/ContractpayDTO.h"
#include "domain/query/contractpay/ContractpayQuery.h"
#include "domain/vo/contractpay/ContractpayVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ContractpayController : public oatpp::web::server::api::ApiController {
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ContractpayController);
public: // 定义接口
	// 1.获取合同费用列表
	// 查询接口描述
	ENDPOINT_INFO(queryContractpay) {
		// 接口描述
		info->summary = ZH_WORDS_GETTER("contractpay.get.query");
		// 添加安全认证
		info->addSecurityRequirement("bearer_auth"); 
		// 接口参数
		API_DEF_ADD_PAGE_PARAMS();
		// 接口返回参数
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractpayPageJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "payer_obj_id", ZH_WORDS_GETTER("contractpay.newfield.payer_obj_id"), "", true);
	}
	// 查询接口端点
	ENDPOINT(API_M_GET, "/c4-contractpay/contractpay-query", queryContractpay, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(query, ContractpayQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryContractpay(query));
	}

	// 2.1.创建合同费用接口描述
	ENDPOINT_INFO(addContractpay) {
		// 接口描述
		info->summary = ZH_WORDS_GETTER("contractpay.post.add");
		info->addSecurityRequirement("bearer_auth"); // 添加安全认证, 否则会报错
		// 接口返回参数
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 2.2 创建合同费用接口端点
	ENDPOINT(API_M_POST, "/c4-contractpay/contractpay-add", addContractpay, BODY_DTO(ContractpayAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddContractpay(dto, authObject->getPayload()));
	}

	 //3.1 创建变更合同费用接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("contractpay.put.modify"), modifyContractpay, StringJsonVO::Wrapper);
	// 3.2 定义变更合同费用接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c4-contractpay/contractpay-modify", modifyContractpay, BODY_DTO(ChangeContractcostDTO::Wrapper, dto), execModifyContractpay(dto, authObject->getPayload()));
	
	// 4.1定义取消合同费用接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("contractpay.delete.remove"), removeContractpay, StringJsonVO::Wrapper);
	// 4.2定义取消合同费用接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/contractpay/contractpay-remove", removeContractpay, BODY_DTO(CancelContractcostDTO::Wrapper, remove), execRemoveContractpay(remove, authObject->getPayload()));

	// 5.1 创建缴纳合同费用接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("contractpay.put.charge"), chargeContractpay, StringJsonVO::Wrapper);
	// 5.2 定义缴纳合同费用接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c4-contractpay/contractpay-charge", chargeContractpay, BODY_DTO(ContractcostChargeDTO::Wrapper, dto), execChargeContractpay(dto, authObject->getPayload()));

	// 6.1查询接口描述
	ENDPOINT_INFO(queryContractpayRecord) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contractpay.get.queryRecordPage"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetContractcostChargeRecordPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		/*API_DEF_ADD_QUERY_PARAMS(String, "start-time", ZH_WORDS_GETTER("contractpay.get.start"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end-time", ZH_WORDS_GETTER("contractpay.get.end"), "", false);*/
		API_DEF_ADD_QUERY_PARAMS(String, "payer_obj_id", ZH_WORDS_GETTER("contractpay.newfield.payer_obj_id"), "", true);
	}
	// 6.2查询接口端点
	ENDPOINT(API_M_GET, "/c4-contractpay/contractpay-query-page", queryContractpayRecord, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(query, ContractpayRecordQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryContractpayRecord(query));
	}

	//// 7.1 定义获取缴费记录详情接口描述
	//ENDPOINT_INFO(queryContractpayRecordDetail) {
	//	// 定义通用描述
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("contractpay.get.queryRecordDetailPage"), ContractcostChargeRecordJsonVO::Wrapper);
	//	// 定义参数描述
	//	API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("contractpay.get.id"), "", false);
	//}
	//// 7.2 定义获取缴费记录详情接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/contractpay/contractpay-contract-record", queryContractpayRecordDetail, QUERY(String, id), execQueryContractpayRecordDetail(id));

	// 7.1 定义ID查询接口描述
	ENDPOINT_INFO(queryContractpayRecordDetail) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("contractpay.get.id"), ContractcostChargeRecordJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "cost-id", ZH_WORDS_GETTER("sample.charge.costid"), "", false);
	}
	// 7.2 定义ID查询接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/c4-contractpay/contractpay-contract-record", queryContractpayRecordDetail, QUERY(String, id), execQueryContractpayRecordDetail(id));

private: // 定义接口执行函数
	// 1.获取合同费用列表
	ContractpayPageJsonVO::Wrapper execQueryContractpay(const ContractpayQuery::Wrapper& query);
	// 2.创建合同费用
	StringJsonVO::Wrapper execAddContractpay(const ContractpayAddDTO::Wrapper& dto, const PayloadDTO& payload);
	//3.变更合同费用
	StringJsonVO::Wrapper execModifyContractpay(const ChangeContractcostDTO::Wrapper& dto, const PayloadDTO& payload);
	//4.取消合同费用
	StringJsonVO::Wrapper execRemoveContractpay(const CancelContractcostDTO::Wrapper& remove, const PayloadDTO& payload);
	//5.缴纳合同费用
	StringJsonVO::Wrapper execChargeContractpay(const ContractcostChargeDTO::Wrapper& dto, const PayloadDTO& payload);
	//6.获取缴费记录分页查询
	GetContractcostChargeRecordPageJsonVO::Wrapper execQueryContractpayRecord(const ContractpayRecordQuery::Wrapper& query);
	//7.获取缴费记录详情
	ContractcostChargeRecordJsonVO::Wrapper execQueryContractpayRecordDetail(const String &id);
};

#include OATPP_CODEGEN_END(ApiController)


#endif // !_CONTRACTPAYCONTROLLER_H_
