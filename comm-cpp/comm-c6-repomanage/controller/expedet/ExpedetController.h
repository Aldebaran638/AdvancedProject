#pragma once
#ifndef _TESTCONTROLLER_H_
#define _TESTCONTROLLER_H_

#include "../../domain/GlobalInclude.h"
#include "../../domain/vo/expedet/ExpeDetVO.h"
#include "../../domain/query/expedet/ExpeDetQuery.h"
#include "../../domain/dto/expedet/ExpeDetDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ExpedetController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(ExpedetController);
public: // 定义接口

	//房屋明细接口——————————————————————

	//定义房屋明细方式接口描述
	ENDPOINT_INFO(queryBuildingDetail) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expedet.get.buildingSummery"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(BuildingExpedetPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("expedet.field.query.startTime"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("expedet.field.query.endTime"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "room_name", ZH_WORDS_GETTER("expedet.field.query.HourseID"), "1001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expedet.field.query.ProprietorName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("expedet.field.query.PhoneNumber"), "", false);
	}
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/expedet/buildingFeeDetaileQuery", queryBuildingDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ExpedetBuildingFeeDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryBuildingFeeDetaile(userQuery));
	}

	//定义导出房屋明细接口
	ENDPOINT_INFO(exportBuildingFeeDetaile) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("expedet.export.page1"), oatpp::Void);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "room_name", ZH_WORDS_GETTER("expedet.field.module1.HourseID"), "1001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expedet.field.module1.ProprietorName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("expedet.field.module1.PhoneNumber"), "", false);
	}
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/expedet/buildingFeeDetaileExport", exportBuildingFeeDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ExpedetBuildingFeeDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		return execExportBuildingFeeDetaile(userQuery);
	}


	//业主明细接口————————————————————————

	//定义业主明细方式接口描述
	ENDPOINT_INFO(queryOwnerDetail) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expedet.get.ownerSummery"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(OwnerExpedetPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("expedet.field.query.startTime"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("expedet.field.query.endTime"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "room_name", ZH_WORDS_GETTER("expedet.field.query.HourseID"), "1001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expedet.field.query.ProprietorName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("expedet.field.query.PhoneNumber"), "", false);
	}
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/expedet/ownerFeeDetaileQuery", queryOwnerDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ExpedetOwnerFeeDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryOwnerFeeDetaile(userQuery));
	}

	//定义导出业主明细接口
	ENDPOINT_INFO(exportOwnerFeeDetaile) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("expedet.export.page2"), oatpp::Void);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expedet.field.module1.ProprietorName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "room_name", ZH_WORDS_GETTER("expedet.field.module1.HourseID"), "1001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("expedet.field.module1.PhoneNumber"), "", false);
	}
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/expedet/ownerFeeDetaileExport", exportOwnerFeeDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ExpedetOwnerFeeDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		return execExportOwnerFeeDetaile(userQuery);
	}

	//合同明细接口————————————————————————

	//定义合同明细方式接口描述
	ENDPOINT_INFO(queryContractDetail) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expedet.get.contractSummery"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractExpedetPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("expedet.field.query.startTime"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("expedet.field.query.endTime"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "contract_name", ZH_WORDS_GETTER("expedet.field.query.ContractName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expedet.field.query.ProprietorName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("expedet.field.query.PhoneNumber"), "", false);
	}
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/expedet/contractFeeDetaileQuery", queryContractDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ExpedetContractFeeDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryContractFeeDetaile(userQuery));
	}

	//定义导出合同明细接口
	ENDPOINT_INFO(exportContractFeeDetaile) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("expedet.export.page3"), oatpp::Void);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "contract_name", ZH_WORDS_GETTER("expedet.field.module1.ContractName"), "119", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expedet.field.module1.ProprietorName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("expedet.field.module1.PhoneNumber"), "", false);
	}
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/expedet/contractFeeDetaileExport", exportContractFeeDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ExpedetContractFeeDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		return execExportContractFeeDetaile(userQuery);
	}




	//车辆明细接口——————————————————————————

	//定义车辆明细方式接口描述
	ENDPOINT_INFO(queryCarDetail) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expedet.get.carSummery"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CarExpedetPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("expedet.field.query.startTime"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("expedet.field.query.endTime"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "car_num", ZH_WORDS_GETTER("expedet.field.query.PlateNumber"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expedet.field.query.ProprietorName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("expedet.field.query.PhoneNumber"), "", false);
	}
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/expedet/carFeeDetaileQuery", queryCarDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ExpedetCarFeeDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryCarFeeDetaile(userQuery));
	}

	//定义导出车辆明细接口
	ENDPOINT_INFO(exportCarFeeDetaile) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("expedet.export.page4"), oatpp::Void);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "car_num", ZH_WORDS_GETTER("expedet.field.module1.PlateNumber"), "A123119", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expedet.field.module1.ProprietorName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("expedet.field.module1.PhoneNumber"), "", false);
	}
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/expedet/carFeeDetaileExport", exportCarFeeDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ExpedetCarFeeDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		return execExportCarFeeDetaile(userQuery);
	}

private: //定义接口执行函数

	//房屋明细
	BuildingExpedetPageJsonVO::Wrapper executeQueryBuildingFeeDetaile(const oatpp::Object<ExpedetBuildingFeeDetailQuery>& query);
	//导出房屋明细
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportBuildingFeeDetaile(const ExpedetBuildingFeeDetailQuery::Wrapper& query);

	//业主明细
	OwnerExpedetPageJsonVO::Wrapper executeQueryOwnerFeeDetaile(const oatpp::Object<ExpedetOwnerFeeDetailQuery>& query);
	//导出业主明细
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportOwnerFeeDetaile(const ExpedetOwnerFeeDetailQuery::Wrapper& query);

	//合同明细
	ContractExpedetPageJsonVO::Wrapper executeQueryContractFeeDetaile(const oatpp::Object<ExpedetContractFeeDetailQuery>& query);
	//导出合同明细
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportContractFeeDetaile(const ExpedetContractFeeDetailQuery::Wrapper& query);

	//车辆明细
	CarExpedetPageJsonVO::Wrapper executeQueryCarFeeDetaile(const oatpp::Object<ExpedetCarFeeDetailQuery>& query);
	//导出合同明细
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportCarFeeDetaile(const ExpedetCarFeeDetailQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)

#endif


