#pragma once

#ifndef _REPAIRTODOQUERY_H_
#define  _REPAIRTODOQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个报修待办分页查询信息的数据传输模型
 */
class RepairToDoQuery : public PageQuery
{
	DTO_INIT(RepairToDoQuery, PageQuery);

	//维修师傅id
	DTO_FIELD(String, staff_id);
	DTO_FIELD_INFO(staff_id) {
		info->description = ZH_WORDS_GETTER("repairtodo.query.staff_id");
	}

	// 工单
	DTO_FIELD(String, repair_id);
	DTO_FIELD_INFO(repair_id) {
		info->description = ZH_WORDS_GETTER("repairtodo.query.repair_id");
	}

	// 报修人
	DTO_FIELD(String, repair_name);
	DTO_FIELD_INFO(repair_name) {
		info->description = ZH_WORDS_GETTER("repairtodo.query.repair_name");
	}

	// 报修类型
	DTO_FIELD(String, repair_type_name);
	DTO_FIELD_INFO(repair_type_name) {
		info->description = ZH_WORDS_GETTER("repairtodo.query.repair_type_name");
	}

	// 报修状态
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("repairtodo.query.state");
	}

	// 电话
	DTO_FIELD(String, tel);
	DTO_FIELD_INFO(tel) {
		info->description = ZH_WORDS_GETTER("repairtodo.query.tel");
	}

	// 小区ID
	DTO_FIELD(String, community_id);
	DTO_FIELD_INFO(community_id) {
		info->description = ZH_WORDS_GETTER("repairtodo.query.community_id");
	}

	// 报修类型ID
	DTO_FIELD(String, repair_type);
	DTO_FIELD_INFO(repair_type) {
		info->description = ZH_WORDS_GETTER("repairtodo.query.repair_type");
	}

};

class RepairToDoRepairTypeQuery :public PageQuery {
	DTO_INIT(RepairToDoRepairTypeQuery, PageQuery);

	// 小区ID
	DTO_FIELD(String, community_id);
	DTO_FIELD_INFO(community_id) {
		info->description = ZH_WORDS_GETTER("repairtodo.query.community_id");
	}

};

class RepairToDoStaffNameQuery :public PageQuery {
	DTO_INIT(RepairToDoStaffNameQuery, PageQuery);

	// 报修类型ID
	DTO_FIELD(String, repair_type);
	DTO_FIELD_INFO(repair_type) {
		info->description = ZH_WORDS_GETTER("repairtodo.query.repair_type");
	}

};



#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRTODOQUERY_H_