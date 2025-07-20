#pragma once
#ifndef _OERPAYDETCONTROLLER_H_
#define _OERPAYDETCONTROLLER_H_

#include "domain/GlobalInclude.h"
#include "domain/dto/oerpaydet/OerPayDetDTO.h"
#include "domain/vo/oerpaydet/OerPayDetVO.h"
#include "domain/query/orepaydet/OerPayDetQuery.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * 示例控制器，演示基础接口的使用
 */
class OerPayDetController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(OerPayDetController);
public:

	//  定义分页查询接口描述
	ENDPOINT_INFO(queryAll) {
		//定义接口描述和响应格式
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("oerpaydet-catalog.get.summary"), OerPayDetPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "feeCategory", ZH_WORDS_GETTER("oerpaydet-catalog.field.feeCategory"), "Parking fee", false); //收费大类
		API_DEF_ADD_QUERY_PARAMS(String, "feeItem", ZH_WORDS_GETTER("oerpaydet-catalog.field.feeItem"), "fee", false);                 //收费项目
		API_DEF_ADD_QUERY_PARAMS(String, "roomNumber", ZH_WORDS_GETTER("oerpaydet-catalog.field.roomNumber"), "810", false);           //房屋编号
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("oerpaydet-catalog.field.ownerName"), "zhao shangfei", false);   //业主名称
		API_DEF_ADD_QUERY_PARAMS(String, "year", ZH_WORDS_GETTER("oerpaydet-catalog.field.year"), "2025", false);                      //年份
	}
	//  定义分页查询接口处理
	ENDPOINT(API_M_GET, "/reportmanage/oerpaydet-catalog-query", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, OerPayDetQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(query));
	}


	// 定义导出接口描述
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("oerpaydet-catalog.export.summary"), exportSample, StringJsonVO::Wrapper);
	// 定义导出接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/oerpaydet-catalog", exportSample, BODY_DTO(SampleDTO::Wrapper, dto), execModifySample(dto, authObject->getPayload()));


	// 3.1 定义导出接口描述
	ENDPOINT_INFO(exportSample) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("oerpaydet-export.export.summary"), Void);
		// 定义导出接口参数描述
		API_DEF_ADD_PAGE_PARAMS();

		// 定义其他导出参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("oerpaydet-catalog.field.ownerName"), "zhao shangfei", false);  //业主名称
		API_DEF_ADD_QUERY_PARAMS(String, "roomNumber", ZH_WORDS_GETTER("oerpaydet-catalog.field.roomNumber"), "810", false);          //房屋编号
		API_DEF_ADD_QUERY_PARAMS(String, "feeItem", ZH_WORDS_GETTER("oerpaydet-catalog.field.feeItem"), "Parking fee", false);        //收费项目

		// 各月缴费金额 
		API_DEF_ADD_QUERY_PARAMS(String, "month1", ZH_WORDS_GETTER("oerpaydet-export.field.month1"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month2", ZH_WORDS_GETTER("oerpaydet-export.field.month2"), "2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month3", ZH_WORDS_GETTER("oerpaydet-export.field.month3"), "3", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month4", ZH_WORDS_GETTER("oerpaydet-export.field.month4"), "4", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month5", ZH_WORDS_GETTER("oerpaydet-export.field.month5"), "5", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month6", ZH_WORDS_GETTER("oerpaydet-export.field.month6"), "6", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month7", ZH_WORDS_GETTER("oerpaydet-export.field.month7"), "7", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month8", ZH_WORDS_GETTER("oerpaydet-export.field.month8"), "8", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month9", ZH_WORDS_GETTER("oerpaydet-export.field.month9"), "9", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month10", ZH_WORDS_GETTER("oerpaydet-export.field.month10"), "10", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month11", ZH_WORDS_GETTER("oerpaydet-export.field.month11"), "11", false);
		API_DEF_ADD_QUERY_PARAMS(String, "month12", ZH_WORDS_GETTER("oerpaydet-export.field.month12"), "12", false);

		API_DEF_ADD_QUERY_PARAMS(Float64, "totalAmount", ZH_WORDS_GETTER("oerpaydet-export.field.total"), 30.12, false);             // 合计
		API_DEF_ADD_QUERY_PARAMS(Float64, "receivable", ZH_WORDS_GETTER("oerpaydet-export.field.receivable"), 30.00, false);         // 应收
		API_DEF_ADD_QUERY_PARAMS(Float64, "prepaid", ZH_WORDS_GETTER("oerpaydet-export.field.prepaid"), 30.00, false);               // 预收
	}
	// 3.2 定义导出接口处理
	ENDPOINT(API_M_GET, "/reportmanage/oerpaydet-export", exportSample, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析导出参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, ExportSampleQuery, queryParams);
		// 呼叫执行函数响应结果
		return execExportSample(query);
	}

private:  //定义接口执行函数 
	// 3.3 演示分页查询数据
	OerPayDetPageJsonVO::Wrapper execQueryAll(const OerPayDetQuery::Wrapper& query);

	std::shared_ptr<OutgoingResponse> execExportSample(const ExportSampleQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif