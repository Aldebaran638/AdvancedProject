#pragma once
#ifndef _REPAIRSETTINGQUERY_H_
#define _REPAIRSETTINGQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个获取报修设置的数据传输模型RepairSettingGetDetailQuery
 */
class RepairSettingGetQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(RepairSettingGetQuery, PageQuery);
	// 报修类型名称
	API_DTO_FIELD_DEFAULT(String, repair_type_name, ZH_WORDS_GETTER("repairsetting.repair-mysql.retypename"));
	// 派单方式 100 抢单 200 指派 300 轮训
	API_DTO_FIELD_DEFAULT(String, repair_way, ZH_WORDS_GETTER("repairsetting.repair-controller.way"));

	// 报修类型设置(新)
	API_DTO_FIELD_DEFAULT(String, repair_setting_type, "repair_setting_type");

	// 区域: public_area（非房屋T，房屋F)
	API_DTO_FIELD_DEFAULT(String, public_area, ZH_WORDS_GETTER("repairsetting.repair-controller.id"));
	// 是否回访 回访标识 001 都不回访 002 已评价不回访 003 都回访
	API_DTO_FIELD_DEFAULT(String, return_visit_flag, ZH_WORDS_GETTER("repairsetting.repair-controller.visit"));
	// 小区id，默认为111小区(2024022154856948)
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("repairsetting.repair-controller.cid"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRSETTINGQUERY_H_