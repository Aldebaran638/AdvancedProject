#pragma once

#ifndef APPLYDISCOUNTDAO_H
#define APPLYDISCOUNTDAO_H


#include "BaseDAO.h"
#include "../../domain/do/applydiscount/ApplyDiscountDO.h"
#include "../../domain/query/applydiscount/ApplyDiscountQuery.h"

//获取优惠申请列表（条件+分页）
//添加优惠申请
//修改优惠申请
class ApplyDiscountDAO : public BaseDAO {
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
	inline std::string queryConditionBuilder(const ApplyDiscountQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const ApplyDiscountQuery::Wrapper& query);
	// 分页查询优惠申请
	std::list<ApplyDiscountDO> selectWithPage(const ApplyDiscountQuery::Wrapper& query);
	// 通过房名查询数据
	std::list<ApplyDiscountDO> selectByHouseName(const string& name);
	// 通过申请类型查询数据
	std::list<ApplyDiscountDO> selectByType(std::string type);
	// 通过状态查询数据
	std::list<ApplyDiscountDO> selectByState(std::string state);
	// 插入数据
	int insert(const ApplyDiscountDO& iObj);
	// 修改数据
	int update(const ApplyDiscountDO& uObj);
};


#endif
