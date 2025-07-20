#pragma once
#ifndef _FEERATECONTROLLER_H_
#define _FEERATECONTROLLER_H_  // 宏定义防止重复包含^[1][4]^

#include "domain/vo/expesum/ExpeSumVO.h"
#include "domain/dto/expesum/ExpeSumDTO.h"
#include "domain/query/expesum/ExpeSumQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class FeeRateController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(FeeRateController);  // 控制器访问入口声明^[6]^
public:
    //============== 楼栋收费率接口 ==============
    // 分页查询接口描述
    ENDPOINT_INFO(queryBuildingRates) {
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("test.inf1"), BuildingRatePageJsonVO::Wrapper);
        info->summary = ZH_WORDS_GETTER("test.inf1");
        // info->addSecurityRequirement("BearerAuth");


        API_DEF_ADD_PAGE_PARAMS();  // 继承分页参数^[6]^
        API_DEF_ADD_QUERY_PARAMS(String, "buildingName", ZH_WORDS_GETTER("fee-summary.buildingName"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("fee-summary.startDate"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("fee-summary.endDate"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("fee-summary.ownerName"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "ownerNumber", ZH_WORDS_GETTER("fee-summary.ownerPhone"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "communityIds", ZH_WORDS_GETTER("fee-summary.communityIds"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "feeTypes", ZH_WORDS_GETTER("fee-summary.feeTypes"), ZH_WORDS_GETTER("test.manager"), false);

        API_DEF_ADD_QUERY_PARAMS(String, "roomNum", ZH_WORDS_GETTER("fee-summary.roomIds"), "", false);

    }
    // 分页查询接口处理
    ENDPOINT(API_M_GET, "/c6-repomanage/expesum/buildingRates", queryBuildingRates, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
    {
        API_HANDLER_QUERY_PARAM(query, BuildingRateQuery, params);

        API_HANDLER_RESP_VO(execQueryBuildingRates(query));
    }

    //============== 费用项收费率接口 ==============
    ENDPOINT_INFO(queryFeeItemRates) {
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("test.inf2"), FeeItemRatePageJsonVO::Wrapper);
        info->summary = ZH_WORDS_GETTER("test.inf2");
        // info->addSecurityRequirement("BearerAuth");

        API_DEF_ADD_PAGE_PARAMS();  // 继承分页参数^[6]^
        API_DEF_ADD_QUERY_PARAMS(String, "buildingName", ZH_WORDS_GETTER("fee-summary.buildingName"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("fee-summary.startDate"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("fee-summary.endDate"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("fee-summary.ownerName"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "ownerNumber", ZH_WORDS_GETTER("fee-summary.ownerPhone"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "communityIds", ZH_WORDS_GETTER("fee-summary.communityIds"), "", false);

        API_DEF_ADD_QUERY_PARAMS(String, "feeTypes", ZH_WORDS_GETTER("fee-summary.feeTypes"), ZH_WORDS_GETTER("test.manager"), false);

        API_DEF_ADD_QUERY_PARAMS(String, "roomNum", ZH_WORDS_GETTER("fee-summary.roomIds"), "", false);

    }
    ENDPOINT(API_M_GET, "/c6-repomanage/expesum/feeItemRates", queryFeeItemRates, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
    {
        API_HANDLER_QUERY_PARAM(query, FeeItemRateQuery, params);

        API_HANDLER_RESP_VO(execQueryFeeItemRates(query));
    }

private:
    // 业务处理函数声明
    BuildingRatePageJsonVO::Wrapper execQueryBuildingRates(const BuildingRateQuery::Wrapper& query);
    FeeItemRatePageJsonVO::Wrapper execQueryFeeItemRates(const FeeItemRateQuery::Wrapper& query);
};




/*           费用汇总-2         */
/**
* 费用汇总控制器
*/
class ExpeSumController : public oatpp::web::server::api::ApiController {
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ExpeSumController);
public:
	//定义查询接口描述
	ENDPOINT_INFO(queryExpesum)
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expesum.searchsum"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ExpeSumJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "timeBegin", ZH_WORDS_GETTER("expesum.timebegin"), "2025.5.1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "timeEnd", ZH_WORDS_GETTER("expesum.timeend"), "2025.5.31", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("expesum.ownerName"), "abc", false);
		API_DEF_ADD_QUERY_PARAMS(String, "buildNumber", ZH_WORDS_GETTER("expesum.buildNumber"), "1234", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerPhone", ZH_WORDS_GETTER("expesum.ownerPhone"), "12345", false);

	}
	// 定义查询接口
	ENDPOINT(API_M_GET, "/c6-repomanage/expesum/expesumQuery", queryExpesum, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		//解析查询参数
		API_HANDLER_QUERY_PARAM(query, ExpeSumQuery, params);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryExpeSum(query));
	}

	//定义导出费用汇总表描述
	ENDPOINT_INFO(exportExpesum)
	{
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("expesum.export"), Void);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "timeBegin", ZH_WORDS_GETTER("expesum.timebegin"), "2025.5.1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "timeEnd", ZH_WORDS_GETTER("expesum.timeend"), "2025.5.31", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerName", ZH_WORDS_GETTER("expesum.ownerName"), "abc", false);
		API_DEF_ADD_QUERY_PARAMS(String, "buildNumber", ZH_WORDS_GETTER("expesum.buildNumber"), "1234", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerPhone", ZH_WORDS_GETTER("expesum.ownerPhone"), "12345", false);

	}
	//定义导出接口
	ENDPOINT(API_M_GET, "/c6-repomanage/expesum/expesumExport", exportExpesum, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_QUERY_PARAM(exportQuery, ExpeSumQuery, queryParams);
		return execExportExpeSum(exportQuery);
	}


private:
	//定义接口执行函数
	ExpeSumJsonVO::Wrapper execQueryExpeSum(const ExpeSumQuery::Wrapper& query);
	std::shared_ptr<OutgoingResponse> execExportExpeSum(const ExpeSumQuery::Wrapper& query);
};


#include OATPP_CODEGEN_END(ApiController)
#endif // !_FEERATECONTROLLER_H_