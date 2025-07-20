#pragma once
#ifndef _REPAIRSETTINGTYPECONTROLLER_H_
#define _REPAIRSETTINGTYPECONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "../../domain/query/repair-setting-type/RepairSettingTypeQuery.h"
#include "../../domain/vo/repair-setting-type/RepairSettingTypeVO.h"
#include "../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class RepairSettingController : public oatpp::web::server::api::ApiController
{
	//定义维修设置类型控制器访问入口
	API_ACCESS_DECLARE(RepairSettingController);
public://定义接口
	// 定义查询所有用户信息接口端点描述
	ENDPOINT_INFO(RepairSettingGetQueryAll) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repairsetting.repair-controller.get"), RepairSettingGetPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义类型名称查询参数描述
		
		// 小区名称
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("repairsetting.repair-controller.coid"), ZH_WORDS_GETTER("repairsetting.repair-controller.cid"), true);
		// 类型名称
		API_DEF_ADD_QUERY_PARAMS(String, "repair_type_name", ZH_WORDS_GETTER("repairsetting.repair-controller.outtypename"), ZH_WORDS_GETTER("repairsetting.repair-controller.typename"), false);
		// 派单方式 100 抢单 200 指派 300 轮训
		API_DEF_ADD_QUERY_PARAMS(String, "repair_way", ZH_WORDS_GETTER("repairsetting.repair-controller.outway"), ZH_WORDS_GETTER("repairsetting.repair-controller.way"), false);
		// 报修类型设置
		API_DEF_ADD_QUERY_PARAMS(String, "repair_setting_type", ZH_WORDS_GETTER("repairsetting.repair-controller.outset"), ZH_WORDS_GETTER("repairsetting.repair-controller.set"), false);
		// 区域
		API_DEF_ADD_QUERY_PARAMS(String, "public_area", ZH_WORDS_GETTER("repairsetting.repair-controller.outid"), ZH_WORDS_GETTER("repairsetting.repair-controller.id"), false);
		// 是否回访 回访标识 001 都不回访 002 已评价不回访 003 都回访
		API_DEF_ADD_QUERY_PARAMS(String, "return_visit_flag", ZH_WORDS_GETTER("repairsetting.repair-controller.outvisit"), ZH_WORDS_GETTER("repairsetting.repair-controller.visit"), false);
	}
	// 定义查询所有用户信息接口端点处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/comm-c2-repairsetting/repair-setting/repair-setting-type/query", RepairSettingGetQueryAll, RepairSettingGetQuery, RepairSettingTypeQueryAll(query));

	// 定义添加报修设置描述
	ENDPOINT_INFO(RepairSettingAdd) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repairsetting.repair-controller.add"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 定义添加报修设置处理
	ENDPOINT(API_M_POST, "/comm-c2-repairsetting/repair-setting/repair-setting-type/add", RepairSettingAdd, BODY_DTO(RepairSettingAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(RepairSettingTypeAdd(dto, authObject->getPayload()));
	}

	// 定义修改报修接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("repairsetting.repair-controller.modify"), RepairSettingModify, StringJsonVO::Wrapper);

	// 定义修改报修接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-repairsetting/repair-setting/repair-setting-type/modify", RepairSettingModify, BODY_DTO(RepairSettingModifyDTO::Wrapper, dto), RepairSettingTypeModify(dto, authObject->getPayload()));

	// 定义删除报修接口处理
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("repairsetting.repair-controller.delete"), removeRepairSettingType, ListJsonVO<String>::Wrapper);
	// 定义删除报修接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/comm-c2-repairsetting/repair-setting/repair-setting-type/delete", removeRepairSettingType, BODY_DTO(List<String>, ids), RepairSettingTypeDelete(ids));

private:
	//定义维修设置类型接口执行函数

	// 查询所有
	RepairSettingGetPageJsonVO::Wrapper RepairSettingTypeQueryAll(const RepairSettingGetQuery::Wrapper& userQuery);
	// 修改用户信息
	StringJsonVO::Wrapper RepairSettingTypeAdd(const RepairSettingAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改报修数据
	StringJsonVO::Wrapper RepairSettingTypeModify(const RepairSettingModifyDTO::Wrapper& dto, const PayloadDTO& payload);
	//声明维修设置类型执行函数
	ListJsonVO<String>::Wrapper RepairSettingTypeDelete(const List<String>& ids);
};	


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _REPAIRSETTINGTYPECONTROLLER_H_