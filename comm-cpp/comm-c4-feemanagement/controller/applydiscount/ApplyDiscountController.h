#ifndef _APPLYDISCOUNT_CONTROLLER_H
#define _APPLYDISCOUNT_CONTROLLER_H


#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/applydiscount/ApplyDiscountDTO.h"
#include "domain/query/applydiscount/ApplyDiscountQuery.h"
#include "domain/vo/applydiscount/ApplyDiscountVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ApplyDiscountController : public oatpp::web::server::api::ApiController {
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ApplyDiscountController);
public:
	// 1.定义优惠申请分页查询接口描述
	ENDPOINT_INFO(queryAll) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("discount.all.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ApplyDiscountPageJsonVO);

		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "room_name", ZH_WORDS_GETTER("apply-discount.all.room_name"), "1-1-2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "apply_type", ZH_WORDS_GETTER("apply-discount.all.apply_type"), "", true);
		API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("apply-discount.all.state"), "", true);
	}
	// 1.1定义跟踪记录查询接口处理
	ENDPOINT(API_M_GET, "/c4-applydiscount/query-all-applydiscount", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(applyDiscountQuery, ApplyDiscountQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(applyDiscountQuery));
	}
	// 2.定义添加优惠申请描述
	ENDPOINT_INFO(addApplyDiscount) {
		// 接口描述
		info->summary = ZH_WORDS_GETTER("discount.post.add");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 接口参数
		API_DEF_ADD_PAGE_PARAMS();
		// 接口返回参数
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 2.1定义优惠申请添加接口处理
	ENDPOINT(API_M_POST, "/c4-applydiscount/add-applyDiscount", addApplyDiscount, BODY_DTO(ApplyDiscountAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddAll(dto, authObject->getPayload()));
	}

	// 3.定义优惠申请修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("discount.all.modify"), modifyApplyDiscount, StringJsonVO::Wrapper);
	// 3.1定义优惠申请修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c4-applydiscount/all-modify-applydiscount", modifyApplyDiscount, BODY_DTO(ApplyDiscountDTO::Wrapper, dto), execModifyAll(dto, authObject->getPayload()));


private:
	// 分页查询优惠申请跟踪记录数据
	ApplyDiscountPageJsonVO::Wrapper execQueryAll(const ApplyDiscountQuery::Wrapper& query);

	//修改优惠申请状态
	StringJsonVO::Wrapper execModifyAll(const ApplyDiscountDTO::Wrapper& dto, const PayloadDTO& payload);

	// 添加跟踪记录
	StringJsonVO::Wrapper execAddAll(const ApplyDiscountAddDTO::Wrapper& addDto, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController)


#endif // _TRACKRECORDCONTROLLER_H_