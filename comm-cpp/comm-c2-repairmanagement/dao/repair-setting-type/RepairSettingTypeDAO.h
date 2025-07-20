#pragma once
#ifndef _RepairSettingDAO_H_
#define _RepairSettingDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/repair-setting-type/RepairSettingTypeDO.h"
#include "../../domain/query/repair-setting-type/RepairSettingTypeQuery.h"

/**
 * 报修列表数据库操作实现
 */
class RepairSettingDAO : public BaseDAO
{
private:
	//************************************
	// Method:      RepairSettingQueryBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const RepairSettingGetDetailQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string RepairSettingTypeQuery_r_repair_setting_Builder(const RepairSettingGetQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t RepairSettingTypecount(const RepairSettingGetQuery::Wrapper& query);
	// 分页查询数据
	std::list<RepairSettingDO> RepairSettingTypeSelect_r_repair_setting_WithPage(const RepairSettingGetQuery::Wrapper& query);
	// 插入数据
	int RepairSettingTypeAdd_r_repair_setting(const RepairSettingDO& iObj);
	// 修改数据
	int RepairSettingTypeModify_r_repair_setting(const RepairSettingDO& uObj);
	// 通过ID删除数据
	int RepairSettingTypeDelete_r_repair_setting_ById(std::string id);
};
#endif // !_RepairSettingDAO_H_
