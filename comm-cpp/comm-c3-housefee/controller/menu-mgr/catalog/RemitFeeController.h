#pragma once
#ifndef _REMITFEECONTROLLER_H_
#define _REMITFEECONTROLLER_H_
#include "../../../domain/dto/dtos/RemitFeeDTO.h"
#include "../../../domain/query/querys/RemitFeeQuery.h"
#include "../../../domain/vo/vos/RemitFeeVO.h"
#include "domain/vo/BaseJsonVO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)


class RemitFeeController :public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(RemitFeeController);
public://定义接口
	ENDPOINT_INFO(queryRecord) {

		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("menu-catalog.record.summary"), RemitFeePageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "detail_id", ZH_WORDS_GETTER("record.get.detail_id"), "912025053026800053", false);


		//  receipt_id: 费用项
		API_DEF_ADD_QUERY_PARAMS(String, "receipt_id", ZH_WORDS_GETTER("record.get.receipt_id"), "租房", false);
		//pay_obj: 收费对象
		API_DEF_ADD_QUERY_PARAMS(String, "pay_obj", ZH_WORDS_GETTER("record.get.pay_obj"), "1-1-101", false);
		//cycle : 周期
		API_DEF_ADD_QUERY_PARAMS(Float64, "cycle", ZH_WORDS_GETTER("record.get.cycle"), 1.00 , false);
		//receivable_amount : 应收费用
		//API_DEF_ADD_QUERY_PARAMS(Float64, "receivable_amount", ZH_WORDS_GETTER("record.get.receivable_amount"), 2650.0, false);	//amount : 实收费用
		//API_DEF_ADD_QUERY_PARAMS(Float64, "amount", ZH_WORDS_GETTER("record.get.amount"), 2650.0,false);
		API_DEF_ADD_QUERY_PARAMS(String, "receive_received", ZH_WORDS_GETTER("record.get.receive_received"), "现金", false);

		//pay_path : 缴费方式
		API_DEF_ADD_QUERY_PARAMS(String, "pay_path", ZH_WORDS_GETTER("record.get.pay_path"), "现金", false);

		API_DEF_ADD_QUERY_PARAMS(String, "pay_period", ZH_WORDS_GETTER("record.get.pay_period"), "现金", false);

		//pay_time : 缴费时间
		API_DEF_ADD_QUERY_PARAMS(String, "pay_time", ZH_WORDS_GETTER("record.get.pay_time"), "2025-05-30 08:42:39", false);
		//receive_id : 收银员
		API_DEF_ADD_QUERY_PARAMS(String, "receive_id", ZH_WORDS_GETTER("record.get.receive_id"), "YF物业", false);
		//status_cd : 状态
		API_DEF_ADD_QUERY_PARAMS(String, "status_cd", ZH_WORDS_GETTER("record.get.status_cd"), "0", false);
		//remark : 备注
		API_DEF_ADD_QUERY_PARAMS(String, "remark", ZH_WORDS_GETTER("record.get.remark"), "", false);
		//opt : 操作
		API_DEF_ADD_QUERY_PARAMS(String, "opt", ZH_WORDS_GETTER("record.get.opt"), "Y", false);



	}

	ENDPOINT(API_M_GET, "/c3-housefeemgr/query-paymentrecord-page", queryRecord, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_QUERY_PARAM(query, RemitFeeQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryRecord(query));
	}
	//API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/record", queryRecord, execQueryRecord(QUERY, authObject->getPayload());


private://定义接口执行函数
	// 3.3 演示分页查询数据
	RemitFeePageJsonVO::Wrapper execQueryRecord(const RemitFeeQuery::Wrapper& query);
	

};

#include OATPP_CODEGEN_END(ApiController)


#endif