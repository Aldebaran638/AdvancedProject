#ifndef PAYDETCONTROLLER_H
#define PAYDETCONTROLLER_H

// /c6-repomanage/paydet/paydetQuery
#include "domain/vo/BaseJsonVO.h"
#include "domain/do/paydet/PayDetDO.h"
#include "domain/dto/paydet/PayDetDTO.h"
#include "domain/vo/paydet/PayDetVO.h"
#include "domain/query/paydet/PayDetQuery.h"
#include "APIHelper.h"
#include "Macros.h" 
#include "ServerInfo.h"
#include OATPP_CODEGEN_BEGIN(ApiController)
using namespace oatpp;

/**
 * 缴费明细控制器：获取缴费明细列表、获取缴费明细列表
 */

class PaydetController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(PaydetController);

public:
	// 获取缴费明细接口描述
	ENDPOINT_INFO(queryGetPayDet) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("paydet.list1"));  // 接口标题
		API_DEF_ADD_AUTH();  // 启用接口认证
		API_DEF_ADD_RSP_JSON_WRAPPER(GetPaydetJsonVO);

		API_DEF_ADD_PAGE_PARAMS();
		// 缴费开始时间
		API_DEF_ADD_QUERY_PARAMS(String, "paymentStartTime", ZH_WORDS_GETTER("paydet.paymentStartTime"), "", false);
		// 缴费结束时间
		API_DEF_ADD_QUERY_PARAMS(String, "paymentEndTime", ZH_WORDS_GETTER("paydet.paymentEndTime"), "", false);
		// 选择支付方式
		API_DEF_ADD_QUERY_PARAMS(String, "paymentMethod", ZH_WORDS_GETTER("paydet.payMethod.paymentMethod"), "", false);
		// 选择费用状态
		API_DEF_ADD_QUERY_PARAMS(String, "expenseStatus", ZH_WORDS_GETTER("paydet.feeSituation.expenseStatus"), "", false);
		// 房屋编号或者车牌号
		API_DEF_ADD_QUERY_PARAMS(String, "houseOrPlateNumber", ZH_WORDS_GETTER("paydet.houseOrPlateNumber"), "", false);
		// 选择费用类型
		API_DEF_ADD_QUERY_PARAMS(String, "expenseType", ZH_WORDS_GETTER("paydet.expenseType.type"), "", false);
		// 选择收费项
		API_DEF_ADD_QUERY_PARAMS(String, "chargeItem", ZH_WORDS_GETTER("paydet.chargeItem"), "", false);
		// 收费开始时间
		API_DEF_ADD_QUERY_PARAMS(String, "chargeStartTime", ZH_WORDS_GETTER("paydet.chargeStartTime"), "", false);
		// 收费结束时间
		API_DEF_ADD_QUERY_PARAMS(String, "chargeEndTime", ZH_WORDS_GETTER("paydet.chargeEndTime"), "", false);
	}
	// 处理
	ENDPOINT(API_M_GET, "c6-repomanage/paydet/paydetQuery", queryGetPayDet, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(query, GetPaydetQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryGetPaydet(query));
	}

	// 导出缴费明细
	ENDPOINT_INFO(exportGetPayDet) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("paydet.list2"));
		API_DEF_ADD_AUTH();  // 启用接口认证
		API_DEF_ADD_PAGE_PARAMS();
		// 缴费开始时间
		API_DEF_ADD_QUERY_PARAMS(String, "paymentStartTime", ZH_WORDS_GETTER("paydet.paymentStartTime"), "", false);
		// 缴费结束时间
		API_DEF_ADD_QUERY_PARAMS(String, "paymentEndTime", ZH_WORDS_GETTER("paydet.paymentEndTime"), "", false);
		// 选择支付方式
		API_DEF_ADD_QUERY_PARAMS(String, "paymentMethod", ZH_WORDS_GETTER("paydet.payMethod.paymentMethod"), "", false);
		// 选择费用状态
		API_DEF_ADD_QUERY_PARAMS(String, "expenseStatus", ZH_WORDS_GETTER("paydet.feeSituation.expenseStatus"), "", false);
		// 房屋编号或者车牌号
		API_DEF_ADD_QUERY_PARAMS(String, "houseOrPlateNumber", ZH_WORDS_GETTER("paydet.houseOrPlateNumber"), "", false);
		// 选择费用类型
		API_DEF_ADD_QUERY_PARAMS(String, "expenseType", ZH_WORDS_GETTER("paydet.expenseType.type"), "", false);
		// 选择收费项
		API_DEF_ADD_QUERY_PARAMS(String, "chargeItem", ZH_WORDS_GETTER("paydet.chargeItem"), "", false);
		// 收费开始时间
		API_DEF_ADD_QUERY_PARAMS(String, "chargeStartTime", ZH_WORDS_GETTER("paydet.chargeStartTime"), "", false);
		// 收费结束时间
		API_DEF_ADD_QUERY_PARAMS(String, "chargeEndTime", ZH_WORDS_GETTER("paydet.chargeEndTime"), "", false);
	}

	// 处理
	ENDPOINT(API_M_GET, "c6-repomanage/paydet/paydetExport", exportGetPayDet, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(query, GetPaydetQuery, queryParams);
		return execExportPaydet(query);
	}

private:
	//缴费明细
	PayDetPageJsonVO::Wrapper execQueryGetPaydet(const oatpp::Object<GetPaydetQuery>& query);

	//导出缴费明细
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> PaydetController::execExportPaydet(const GetPaydetQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !PAYDETCONTROLLER_H
