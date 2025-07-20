#pragma once
#ifndef _HOUSEFEECONTROLLER_H_
#define _HOUSEFEECONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/HouseFeeMgrVO.h"
#include "domain/dto/HouseFeeMgrDTO.h"
#include "domain/query/HouseFeeMgrQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class HouseFeeController :public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(HouseFeeController);
public://定义接口
	// 3.1 定义分页查询接口描述
	ENDPOINT_INFO(queryAll) 
	{
		//定义接口描述和响应格式
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("HouseFeeMgr.query.summary"), HouseFeeMgrPageJsonVO::Wrapper);

		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("HouseFeeMgr.field.communityId"), "2024022692080516", true);
		API_DEF_ADD_QUERY_PARAMS(String, "roomNum", ZH_WORDS_GETTER("HouseFeeMgr.field.roomNum"), "01-1-1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("HouseFeeMgr.field.status"), "2008001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerNameLike", ZH_WORDS_GETTER("HouseFeeMgr.field.ownerNameLike"), "kid", false);
	}
	// 3.2 定义分页查询接口处理
	ENDPOINT(API_M_GET, "/c3-housefeemgr/query-housefee-page", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, HouseFeeMgrQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

	// 3.1 定义获取房屋费用详情查询接口描述
	ENDPOINT_INFO(queryByFeeId)
	{
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("HouseFeeMgr.query-by-fee_id.summary"), HouseFeeMgrJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "fee_id", ZH_WORDS_GETTER("HouseFeeMgr.field.fee_id"), "902025051980230067", true);
	}
	// 3.2 定义ID查询接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/c3-housefeemgr/query-housefeedetail", queryByFeeId, QUERY(String, fee_id), execQueryByFeeId(fee_id));


	// 3.1 定义获取房屋费用项信息查询接口描述
	ENDPOINT_INFO(queryByRoomNum)
	{
		//定义接口描述和响应格式
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("HouseFeeMgr.query-by-roomNum.summary"), HouseFeeMgrPageJsonVO::Wrapper);

		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("HouseFeeMgr.field.communityId"), "2024022692080516", true);
		API_DEF_ADD_QUERY_PARAMS(String, "roomNum", ZH_WORDS_GETTER("HouseFeeMgr.field.roomNum"), "01-1-1", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("HouseFeeMgr.field.status"), "2008001", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "ownerNameLike", ZH_WORDS_GETTER("HouseFeeMgr.field.ownerNameLike"), "kid", false);
	}
	// 3.2 定义分页查询接口处理
	ENDPOINT(API_M_GET, "/c3-housefeemgr/query-housefeeitem", queryByRoomNum, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, HouseFeeMgrQueryByRoom, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryByRoomNum(query));
	}

private://定义接口执行函数
	HouseFeeMgrPageJsonVO::Wrapper execQueryAll(const HouseFeeMgrQuery::Wrapper& query);
	HouseFeeMgrJsonVO::Wrapper execQueryByFeeId(const String& id);
	HouseFeeMgrPageJsonVO::Wrapper execQueryByRoomNum(const HouseFeeMgrQueryByRoom::Wrapper& query);

};


#include OATPP_CODEGEN_END(ApiController)
#endif // !_HOUSEFEECONTROLLER_H_
