#pragma once

#ifndef _REPAIRTODOCONTROLLER_H_
#define _REPAIRTODOCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/repair-todo/RepairToDoQuery.h"
#include "domain/vo/repair-todo/RepairToDoVO.h"
#include "domain/dto/repair-todo/RepairToDoDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class RepairToDoController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(RepairToDoController);
public:

	//  修改报修状态——》暂停
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("repairtodo.modify.suspend"), modifyStateToSuspend, StringJsonVO::Wrapper);
	//  定义报修待办改单处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-repairsetting/repair-to-do/modify-state-suspend", modifyStateToSuspend, BODY_DTO(RepairToDoUpdateToSuspendDTO::Wrapper, dto), executeModifyStateToSuspend(dto));


	// 定义获取待办单列表信息接口端点描述
	ENDPOINT_INFO(queryAll) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repairtodo.field.query-all"), RepairToDoPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 小区编号
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("repairtodo.field.community_id"), ZH_WORDS_GETTER("repairtodo.field.community_id_default"), true);
		// 维修人员Id
		API_DEF_ADD_QUERY_PARAMS(String, "staff_id", ZH_WORDS_GETTER("repairtodo.field.staff_id"), ZH_WORDS_GETTER("repairtodo.field.staff_id_default"), true);

		// 报修待办工单id
		API_DEF_ADD_QUERY_PARAMS(String, "repair_id", ZH_WORDS_GETTER("repairtodo.field.repair_id"), ZH_WORDS_GETTER("repairtodo.field.repair_id_default"), false);
		//获取待办报修人姓名
		API_DEF_ADD_QUERY_PARAMS(String, "repair_name", ZH_WORDS_GETTER("repairtodo.field.repair_name"), ZH_WORDS_GETTER("repairtodo.field.repair_name_default"),false);
	    //获取待办报修人电话
		 API_DEF_ADD_QUERY_PARAMS(String, "tel", ZH_WORDS_GETTER("repairtodo.field.tel"), ZH_WORDS_GETTER("repairtodo.field.tel_default"),false);
		//获取待办报修类型
		 API_DEF_ADD_QUERY_PARAMS(String, "repair_type_name", ZH_WORDS_GETTER("repairtodo.field.repair_type_name"), ZH_WORDS_GETTER("repairtodo.field.repair_type_name_default"),false);
		//获取待办报修状态
		 API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("repairtodo.field.state"), ZH_WORDS_GETTER("repairtodo.field.state_default"), false);
	}
	// 定义查询所有用户信息接口端点处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/comm-c2-repairsetting/repair-to-do/query-all", queryAll, RepairToDoQuery, execQueryAll(query));

	// 定义查询该小区维修类型端点描述
	ENDPOINT_INFO(queryAllRepairType) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repairtodo.field.query-all-repair-type"), RepairToDoQueryAllRepairTypePageJsonVO::Wrapper);
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("repairtodo.field.community_id"), ZH_WORDS_GETTER("repairtodo.field.community_id_default"), true);
	}
	// 定义查询该小区维修类型接口端点处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/comm-c2-repairsetting/repair-to-do/query-all-repair-type", queryAllRepairType, RepairToDoRepairTypeQuery, execQueryAllRepairType(query));

	// 定义获取所有报修师傅接口端点描述
	ENDPOINT_INFO(queryAllStaff) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repairtodo.field.query-all-staff"), RepairToDoQueryAllStaffPageJsonVO::Wrapper);
		API_DEF_ADD_QUERY_PARAMS(String, "repair_type", ZH_WORDS_GETTER("repairtodo.field.repair_type"), ZH_WORDS_GETTER("repairtodo.field.repair_type_default"), true);
	}
	// 定义查询所有用户信息接口端点处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/comm-c2-repairsetting/repair-to-do/query-all-staff", queryAllStaff, RepairToDoStaffNameQuery, execQueryAllStaffByRepairType(query));

	
	//  定义报修待办改单接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("repairtodo.field.modify"), modifyrepairtodo, StringJsonVO::Wrapper);
	//  定义报修待办改单处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-repairsetting/repair-to-do/modify", modifyrepairtodo, BODY_DTO(RepairToDoUpdateDTO::Wrapper, dto), execModify(dto));

	// 定义报修待办退单接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("repairtodo.field.delete"), removeRepairToDo, StringJsonVO::Wrapper);
	// 定义报修待办退单接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-repairsetting/repair-to-do/delete", removeRepairToDo, BODY_DTO(RepairToDoUpdateToRemoveDTO::Wrapper, dto), execRemove(dto));

	// 定义报修待办办结接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("repairtodo.field.finish"), modifyStateToFinish, StringJsonVO::Wrapper);
	// 定义报修待办办结接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/comm-c2-repairsetting/repair-to-do/finish", modifyStateToFinish, BODY_DTO(RepairToDoUpdateToFinishDTO::Wrapper, dto), executeModifyStateToFinish(dto));


private:


	// 报修待办分页查询执行
	RepairToDoPageJsonVO::Wrapper execQueryAll(const RepairToDoQuery::Wrapper& Query);
	// 报修类型查询执行
	RepairToDoQueryAllRepairTypePageJsonVO::Wrapper execQueryAllRepairType(const RepairToDoRepairTypeQuery::Wrapper& Query);
	// 报修师傅查询执行
	RepairToDoQueryAllStaffPageJsonVO::Wrapper execQueryAllStaffByRepairType(const RepairToDoStaffNameQuery::Wrapper& Query);

	// 修改报修状态——》暂停
	StringJsonVO::Wrapper executeModifyStateToSuspend(const RepairToDoUpdateToSuspendDTO::Wrapper& dto);
	// 报修待办转单处理执行
	StringJsonVO::Wrapper execModify(const  RepairToDoUpdateDTO::Wrapper& dto);
	//报修待办退单处理执行
	StringJsonVO::Wrapper execRemove(const RepairToDoUpdateToRemoveDTO::Wrapper& dto);


	// 修改报修状态——》办结
	StringJsonVO::Wrapper executeModifyStateToFinish(const RepairToDoUpdateToFinishDTO::Wrapper& dto);

};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // ! _REPAIRTODOCONTROLLER_H_