#pragma once
#ifndef _FORCEBACKDAO_H_
#define _FORCEBACKDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/force-back/ForceBackDO.h"
#include "../../domain/query/force-back/ForceBackQuery.h"

/**
 * 示例表数据库操作实现
 */
class ForceBackDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const ForceBackQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数  r_repair_pool rp表
	uint64_t ForceBack_count(const ForceBackQuery::Wrapper& query);
	// 分页查询数据 r_repair_pool表、r_repair_setting表、t_dict表
	std::list<ForceBackDO> ForceBack_selectWithPage(const ForceBackQuery::Wrapper& query);
	// 插入数据 
	//int ForceBack_insert(const ForceBackDO& iObj);
	// 修改数据 r_repair_pool表
	int ForceBack_update(const ForceBackDO& uObj);
	//修改数据 r_repair_user表
	int ForceBack_update_Context(const ForceBackDO& uObj);
	//强制回单-需要用料-查询库存
	ForceBackDO select_resource_by_res_id_user_id(const std::string ResId, const std::string UserId);
	//强制回单-需要用料-插入使用记录
	int insert_resource_store_use_record_finish(const ForceBackDO& iObj);
	//强制回单-需要用料-更新仓库库存
	int update_user_storehouse_finish(const ForceBackDO& uObj);
	//查询repair_user数据 供插入使用
	PtrForceBackDO selectRepairUserData(std::string RepairId);
	//插入数据 repair_user表
	int insert_repair_user(const ForceBackDO& iObj);
};
#endif // !_FORCEBACKDAO_H_
