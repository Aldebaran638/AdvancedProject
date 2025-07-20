#pragma once
#ifndef _FEECONTROLLER_H_
#define _FEECONTROLLER_H_


#include "domain/vo/FeeMgrVO.h"
#include "domain/dto/FeeMgrDTO.h"
#include "domain/query/FeeMgrQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class FeeController :public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(FeeController);
public://定义接口
    // 3.1 定义分页查询接口描述
    ENDPOINT_INFO(queryAll)
    {
        //定义接口描述和响应格式
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("FeeMgr.query.summary"), FeeMgrPageJsonVO::Wrapper);

        // 定义分页查询参数描述
        API_DEF_ADD_PAGE_PARAMS();

        // 定义其他查询参数描述
       // API_DEF_ADD_QUERY_PARAMS(String, "discount_id", ZH_WORDS_GETTER("FeeMgr.field.discount_id"), "132025051652540020", false);
        API_DEF_ADD_QUERY_PARAMS(String, "discount_name", ZH_WORDS_GETTER("FeeMgr.field.discount_name"), "testBewater", false);
        API_DEF_ADD_QUERY_PARAMS(String, "discount_rule", ZH_WORDS_GETTER("FeeMgr.field.discount_rule"), "test", false);
        API_DEF_ADD_QUERY_PARAMS(String, "discount_type", ZH_WORDS_GETTER("FeeMgr.field.discount_type"), "weiyue", false);

        API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("FeeMgr.field.start_time"), "2024.1", false);
        API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("FeeMgr.field.end_time"), "2025.2", false);
        API_DEF_ADD_QUERY_PARAMS(String, "discount_end_time", ZH_WORDS_GETTER("FeeMgr.field.discount_end_time"), "2025.3", false);

    }
    // 3.2 定义分页查询接口处理
    ENDPOINT(API_M_GET, "/c3-expensesetting/query-discount-page", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // 解析查询参数为Query领域模型
        API_HANDLER_QUERY_PARAM(query, FeeMgrQuery, queryParams);
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execQueryAll(query));
    }

    



    // 3.1 定义新增接口描述
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("/FeeMgr/insert.post.summary"), additemlog, FeeMgrJsonVO::Wrapper);
    // 3.2 定义新增接口处理
    API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/c3-expensesetting/insert-discount", additemlog, BODY_DTO(FeeMgrAddDTO::Wrapper, dto), execAdditemlog(dto, authObject->getPayload()));

    // 3.1 定义删除接口描述
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("/FeeMgr/delete.delete.summary"), removeSample, FeeMgrJsonVO::Wrapper);
    // 3.2 定义删除接口处理
    API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c3-expensesetting/delete-discount", removeSample, BODY_DTO(FeeMgrDeleteDTO::Wrapper, dto), execRemoveitem(dto, authObject->getPayload()));

    //test:定义获取费用项基础信息接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("/FeeMgr/getFeeItemInfo.get.summary"), getFeeItemInfo, FeeMgrJsonVO::Wrapper);
	//test:定义获取费用项基础信息接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/c3-expensesetting/query-feeiteminfo", getFeeItemInfo, BODY_DTO(FeeMgrGetDTO::Wrapper, dto), execGetFeeItemInfo(dto, authObject->getPayload()));







private://定义接口执行函数
    FeeMgrPageJsonVO::Wrapper execQueryAll(const FeeMgrQuery::Wrapper& query);
    //FeeMgrJsonVO::Wrapper execQueryByFeeId(const String& id);

    // 3.3 新增数据
    FeeMgrJsonVO::Wrapper execAdditemlog(const FeeMgrAddDTO::Wrapper& dto, const PayloadDTO& payload);
    
    // 3.3 演示删除数据
    FeeMgrJsonVO::Wrapper execRemoveitem(const FeeMgrDeleteDTO::Wrapper& dto, const PayloadDTO& payload);

	//test:演示获取费用项基础信息
	FeeMgrJsonVO::Wrapper execGetFeeItemInfo(const FeeMgrGetDTO::Wrapper& dto, const PayloadDTO& payload);
};


#include OATPP_CODEGEN_END(ApiController)
#endif //