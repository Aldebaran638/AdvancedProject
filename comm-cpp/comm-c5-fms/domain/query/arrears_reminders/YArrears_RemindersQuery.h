#pragma once
#ifndef _YARREARS_REMINDERSQUERY_H_
#define _YARREARS_REMINDERSQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class YArrears_RemindersQuery : public PageQuery
{
	DTO_INIT(YArrears_RemindersQuery, PageQuery);
	// 小区分片字段
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("payremind.field.community_id"));
	// 业主名称
	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("payremind.field.owner_name"));
	// 业主id
	API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("payremind.field.owner_id"));
	// 付费类型
	API_DTO_FIELD_DEFAULT(String, payer_obj_type, ZH_WORDS_GETTER("payremind.field.payer_obj_type"));
	// 付费对象
	API_DTO_FIELD_DEFAULT(String, payer_obj_name, ZH_WORDS_GETTER("payremind.field.payer_obj_name"));
	// 付费对象id
	API_DTO_FIELD_DEFAULT(String, payer_obj_id, ZH_WORDS_GETTER("payremind.field.payer_obj_id"));
	// 收费对象id
	API_DTO_FIELD_DEFAULT(String, config_id, ZH_WORDS_GETTER("payremind.field.config_id"));
	// 费用id
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("payremind.field.fee_id"));
	// 费用名称
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("payremind.field.fee_name"));
	// 催缴金额
	API_DTO_FIELD_DEFAULT(UInt64, amountd_owed, ZH_WORDS_GETTER("payremind.field.amountd_owed"));
	// 催缴方式
	API_DTO_FIELD_DEFAULT(String, callable_way, ZH_WORDS_GETTER("payremind.field.callable_way"));
	// 催缴人
	API_DTO_FIELD_DEFAULT(String, staff_id, ZH_WORDS_GETTER("payremind.field.staff_id"));
	// 处理人
	API_DTO_FIELD_DEFAULT(String, staff_name, ZH_WORDS_GETTER("payremind.field.staff_name"));
	// 状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("payremind.field.state"));
	// 说明
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("payremind.field.remark"));
	// 费用结束时间
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("payremind.field.start_time"));
	// 截止时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("payremind.field.end_time"));
	// 创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("payremind.field.create_time"));
	// 数据状态
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("payremind.field.status_cd"));
};

#include OATPP_CODEGEN_END(DTO)
#endif 