/*
 Copyright Zero One Star. All rights reserved.

 @Author: KBchulan
 @Date: 2025/5/20

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef DATASTATCONTROLLER_H
#define DATASTATCONTROLLER_H

#include "oatpp-swagger/Types.hpp"

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/datastat/DataStatQuery.h"
#include "domain/dto/datastat/DataStatDTO.h"
#include "domain/vo/datastat/DataStatVO.h"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 数据统计控制器：费用类，工单类，出入类，其他统计
 */
class DatastatController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(DatastatController);

public:
    // 费用统计查询接口
    ENDPOINT_INFO(queryExpenseStat) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.get.expense"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(ExpenseStatPageJsonVO);

        API_DEF_ADD_PAGE_PARAMS();
        API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("datastat.field.startDate"), "2023-01-01", false);
        API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("datastat.field.endDate"), "2023-09-30", false);
        API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("datastat.field.communityId"), "12345678", true);
        API_DEF_ADD_QUERY_PARAMS(String, "communityName", ZH_WORDS_GETTER("datastat.field.communityName"), "aaaa", false);
    }
    ENDPOINT(API_M_GET, "/c6-repomanage/datastat/expenseQuery", queryExpenseStat, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(query, ExpenseStatQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryExpenseStat(query));
    }

    // 工单统计查询接口
    ENDPOINT_INFO(queryWorkOrderStat) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.get.workOrder"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(WorkOrderStatPageJsonVO);

        API_DEF_ADD_PAGE_PARAMS();
        API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("datastat.field.startDate"), "2023-01-01", false);
        API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("datastat.field.endDate"), "2023-09-30", false);
        API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("datastat.field.communityId"), "12345678", true);
        API_DEF_ADD_QUERY_PARAMS(String, "communityName", ZH_WORDS_GETTER("datastat.field.communityName"), "aaaa", false);
    }
    ENDPOINT(API_M_GET, "/c6-repomanage/datastat/workOrderQuery", queryWorkOrderStat, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(query, WorkOrderStatQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryWorkOrderStat(query));
    }

    // 出入统计查询接口
    ENDPOINT_INFO(queryAccessStat) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.get.access"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(AccessStatPageJsonVO);

        API_DEF_ADD_PAGE_PARAMS();
        API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("datastat.field.startDate"), "2023-01-01", false);
        API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("datastat.field.endDate"), "2023-09-30", false);
        API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("datastat.field.communityId"), "12345678", true);
        API_DEF_ADD_QUERY_PARAMS(String, "communityName", ZH_WORDS_GETTER("datastat.field.communityName"), "aaaa", false);
    }
    ENDPOINT(API_M_GET, "/c6-repomanage/datastat/accessQuery", queryAccessStat, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(query, AccessStatQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryAccessStat(query));
    }

    // 其他统计查询接口
    ENDPOINT_INFO(queryOtherStat) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.get.other"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(OtherStatPageJsonVO);

        API_DEF_ADD_PAGE_PARAMS();
        API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("datastat.field.startDate"), "2023-01-01", false);
        API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("datastat.field.endDate"), "2023-09-30", false);
        API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("datastat.field.communityId"), "12345678", true);
        API_DEF_ADD_QUERY_PARAMS(String, "communityName", ZH_WORDS_GETTER("datastat.field.communityName"), "aaaa", false);
    }
    ENDPOINT(API_M_GET, "/c6-repomanage/datastat/otherQuery", queryOtherStat, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(query, OtherStatQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryOtherStat(query));
    }

    /*              数据统计-2          */        
	//定义查询实收统计接口端点描述
	ENDPOINT_INFO(queryShishou) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.query-shishou.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DataStatShishouPageVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("datastat.field.community"), "ccc", false);
		API_DEF_ADD_QUERY_PARAMS(String, "begintime", ZH_WORDS_GETTER("datastat.field.begintime"), "2022-2-2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endtime", ZH_WORDS_GETTER("datastat.field.endtime"), "2022-2-2", false);
	}
	//定义查询实收统计接口端点处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/c6-repomanage/datastat/receiptsQuery", queryShishou, DataStatALLSearchQuery, executeQueryShishou(query));

	//定义实收明细接口端点描述
	ENDPOINT_INFO(queryShishouDetail) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.query-shishou-detail.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DataStatShishouDetailPageVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("datastat.field.community"), "ccc", false);
		API_DEF_ADD_QUERY_PARAMS(String, "begintime", ZH_WORDS_GETTER("datastat.field.begintime"), "2022-2-2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endtime", ZH_WORDS_GETTER("datastat.field.endtime"), "2022-2-2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "house", ZH_WORDS_GETTER("datastat.field.house"), "one_unit", false);
		API_DEF_ADD_QUERY_PARAMS(String, "host", ZH_WORDS_GETTER("datastat.field.host"), "lucy", false);
		API_DEF_ADD_QUERY_PARAMS(String, "phone", ZH_WORDS_GETTER("datastat.field.phone"), "134888888", false);
	}
	//定义实收查询接口端点描述
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/c6-repomanage/datastat/receiptsDetailQuery", queryShishouDetail, DataStatDetailSearchQuery, executeQueryShishouDetail(query));

	//定义查询实收统计接口端点描述
	ENDPOINT_INFO(queryMethod) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.query-method.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DataStatMethodVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("datastat.field.community"), "ccc", false);
		API_DEF_ADD_QUERY_PARAMS(String, "begintime", ZH_WORDS_GETTER("datastat.field.begintime"), "2022-2-2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endtime", ZH_WORDS_GETTER("datastat.field.endtime"), "2022-2-2", false);
	}
	//处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/c6-repomanage/datastat/methodQuery", queryMethod, DataStatALLSearchQuery, executeQueryMethod(query));

	//定义查询实收统计接口端点描述
	ENDPOINT_INFO(queryQianfei) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.query-qianfei.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DataStatQianfeiPageVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("datastat.field.community"), "ccc", false);
		API_DEF_ADD_QUERY_PARAMS(String, "begintime", ZH_WORDS_GETTER("datastat.field.begintime"), "2022-2-2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "endtime", ZH_WORDS_GETTER("datastat.field.endtime"), "2022-2-2", false);
	}
	//处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/c6-repomanage/datastat/arrearsQuery", queryQianfei, DataStatALLSearchQuery, executeQueryQianfei(query));

	//Excel导出业主明细
	//定义导出实收明细接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("datastat.export.summary2"), exportShishouDetail, Void);
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/receiptsDetailExport", exportShishouDetail, QUERIES(QueryParams, queryDetail), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(DetailQuery, oatpp::Object<DataStatDetailSearchQuery>, queryDetail);
		// 呼叫执行函数响应结果
		return executeExportShishouDetail(DetailQuery);
	}

	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("datastat.export.summary1"), exportShishou, Void);
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/receiptsExport", exportShishou, QUERIES(QueryParams, queryDetail), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(ShishouQuery, oatpp::Object<DataStatALLSearchQuery>, queryDetail);
		// 呼叫执行函数响应结果
		return executeExportShishou(ShishouQuery);
	}

	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("datastat.export.summary3"), exportMethod, Void);
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/methodExport", exportMethod, QUERIES(QueryParams, queryDetail), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(MethodQuery, oatpp::Object<DataStatALLSearchQuery>, queryDetail);
		// 呼叫执行函数响应结果
		return executeExportMethod(MethodQuery);
	}

	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("datastat.export.summary4"), exportQianfei, Void);
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/arrearsExport", exportQianfei, QUERIES(QueryParams, queryDetail), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(QianfeiQuery, oatpp::Object<DataStatALLSearchQuery>, queryDetail);
		// 呼叫执行函数响应结果
		return executeExportQianfei(QianfeiQuery);
	}
	/*              数据统计-3            */
	//定义欠费明细方式接口描述
	ENDPOINT_INFO(queryFeeDetaile) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.field.module1.module_name"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DataStatFeeDetailPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "room_name", ZH_WORDS_GETTER("datastat.field.module1.room_name"), "1001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("datastat.field.module1.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("datastat.field.module1.link"), "", false);
	}
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/feeDetaileQuery", queryFeeDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, DatastatFeeDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryFeeDetaile(userQuery));
	}


	//定义导出欠费明细描述
	ENDPOINT_INFO(exportFeeDetaile) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("datastat.export.module1"), oatpp::Void);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "room_name", ZH_WORDS_GETTER("datastat.field.module1.room_name"), "1001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("datastat.field.module1.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("datastat.field.module1.link"), "", false);
	}
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/feeDetaileExport", exportFeeDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, DatastatFeeDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		return execExportFeeDetaile(userQuery);
	}



	//定义收缴情况方式接口描述
	ENDPOINT_INFO(queryChargeDetaile) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.field.module2.module_name"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DatastatChargeDetailPageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "fee_name", ZH_WORDS_GETTER("datastat.field.module2.fee_name"), ZH_WORDS_GETTER("datastat.field.module1.wuye"), true);

	}
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/chargeDetaileQuery", queryChargeDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(userQuery, DatastatChargeDetailQuery, queryParams);
		API_HANDLER_RESP_VO(executeQueryChargeDetaile(userQuery));
	}


	//定义导出收缴情况描述
	ENDPOINT_INFO(exportChargeDetaile) {

		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("datastat.export.module2"), oatpp::Void);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "fee_name", ZH_WORDS_GETTER("datastat.field.module2.fee_name"), ZH_WORDS_GETTER("datastat.field.module1.wuye"), true);
	}
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/chargeDetaileExport", exportChargeDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(userQuery, DatastatChargeDetailQuery, queryParams);
		return execExportChargeDetaile(userQuery);
	}



	//定义月实收明细方式接口描述
	ENDPOINT_INFO(queryMonthDetaile) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.field.module3.module_name"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DatastatMonthDetailPageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "fee_name", ZH_WORDS_GETTER("datastat.field.module3.fee_name"), ZH_WORDS_GETTER("datastat.field.module1.wuye"), true);
		API_DEF_ADD_QUERY_PARAMS(String, "building", ZH_WORDS_GETTER("datastat.field.module3.building"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("datastat.field.module3.start_time"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("datastat.field.module3.end_time"), "", false);

	}
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/monthDetaileQuery", queryMonthDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(userQuery, DatastatMonthDetailQuery, queryParams);
		API_HANDLER_RESP_VO(executeQueryMonthDetaile(userQuery));
	}

	//定义导出月实收明描述
	ENDPOINT_INFO(exportMonthDetaile) {

		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("datastat.export.module3"), oatpp::Void);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "fee_name", ZH_WORDS_GETTER("datastat.field.module3.fee_name"), ZH_WORDS_GETTER("datastat.field.module1.wuye"), true);
		API_DEF_ADD_QUERY_PARAMS(String, "building", ZH_WORDS_GETTER("datastat.field.module3.building"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("datastat.field.module3.start_time"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("datastat.field.module3.end_time"), "", false);
	}
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/monthDetaileExport", exportMonthDetaile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(userQuery, DatastatMonthDetailQuery, queryParams);
		return execExportMonthDetaile(userQuery);
	}



	//定义月欠费明细方式接口描述
	ENDPOINT_INFO(queryMonthFee) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("datastat.field.module4.module_name"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DatastatMonthFeePageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "fee_name", ZH_WORDS_GETTER("datastat.field.module4.fee_name"), ZH_WORDS_GETTER("datastat.field.module1.wuye"), true);
		API_DEF_ADD_QUERY_PARAMS(String, "building", ZH_WORDS_GETTER("datastat.field.module4.building"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("datastat.field.module4.start_time"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("datastat.field.module4.end_time"), "", false);

	}
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/monthFeeQuery", queryMonthFee, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(userQuery, DatastatMonthFeeQuery, queryParams);
		API_HANDLER_RESP_VO(executeQueryMonthFee(userQuery));
	}

	//定义导出月欠费明细描述
	ENDPOINT_INFO(exportMonthFee) {

		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("datastat.export.module4"), oatpp::Void);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "fee_name", ZH_WORDS_GETTER("datastat.field.module4.fee_name"), ZH_WORDS_GETTER("datastat.field.module1.wuye"), true);
		API_DEF_ADD_QUERY_PARAMS(String, "building", ZH_WORDS_GETTER("datastat.field.module4.building"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("datastat.field.module4.start_time"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("datastat.field.module4.end_time"), "", false);
	}
	//处理
	ENDPOINT(API_M_GET, "/c6-repomanage/datastat/monthFeeExport", exportMonthFee, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(userQuery, DatastatMonthFeeQuery, queryParams);
		return execExportMonthFee(userQuery);
	}
private:
    // 查询费用统计数据
    ExpenseStatPageJsonVO::Wrapper execQueryExpenseStat(const ExpenseStatQuery::Wrapper& query);

    // 查询工单统计数据
    WorkOrderStatPageJsonVO::Wrapper execQueryWorkOrderStat(const WorkOrderStatQuery::Wrapper& query);

    // 查询出入统计数据
    AccessStatPageJsonVO::Wrapper execQueryAccessStat(const AccessStatQuery::Wrapper& query);

    // 查询其他统计数据
    OtherStatPageJsonVO::Wrapper execQueryOtherStat(const OtherStatQuery::Wrapper& query);
    /*          数据统计-2      */        
	//实收统计
	DataStatShishouPageVO::Wrapper executeQueryShishou(const oatpp::Object<DataStatALLSearchQuery>& query);

	//收款方式
	DataStatMethodVO::Wrapper executeQueryMethod(const oatpp::Object<DataStatALLSearchQuery>& query);

	//欠费统计
	DataStatQianfeiPageVO::Wrapper executeQueryQianfei(const oatpp::Object<DataStatALLSearchQuery>& query);

	//实收明细
	DataStatShishouDetailPageVO::Wrapper executeQueryShishouDetail(const DataStatDetailSearchQuery::Wrapper& query);

	//导出实收明细函数
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> executeExportShishouDetail(const DataStatDetailSearchQuery::Wrapper& query);

	//导出实收
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> executeExportShishou(const DataStatALLSearchQuery::Wrapper& query);

	//导出方式统计
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> executeExportMethod(const DataStatALLSearchQuery::Wrapper& query);

	//导出欠费
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> executeExportQianfei(const DataStatALLSearchQuery::Wrapper& query);


	/*              数据统计-3            */
	//欠费明细
	DataStatFeeDetailPageJsonVO::Wrapper executeQueryFeeDetaile(const oatpp::Object<DatastatFeeDetailQuery>& query);

	//导出欠费明细
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportFeeDetaile(const DatastatFeeDetailQuery::Wrapper& query);

	//收缴情况
	DatastatChargeDetailPageJsonVO::Wrapper executeQueryChargeDetaile(const oatpp::Object<DatastatChargeDetailQuery>& query);

	//导出收缴情况
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportChargeDetaile(const DatastatChargeDetailQuery::Wrapper& query);

	//月实收明细
	DatastatMonthDetailPageJsonVO::Wrapper executeQueryMonthDetaile(const oatpp::Object<DatastatMonthDetailQuery>& query);

	//导出月实收明细
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportMonthDetaile(const DatastatMonthDetailQuery::Wrapper& query);

	//月欠费明细
	DatastatMonthFeePageJsonVO::Wrapper executeQueryMonthFee(const oatpp::Object<DatastatMonthFeeQuery>& query);

	//导出月欠费明细
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportMonthFee(const DatastatMonthFeeQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !DATASTATCONTROLLER_H