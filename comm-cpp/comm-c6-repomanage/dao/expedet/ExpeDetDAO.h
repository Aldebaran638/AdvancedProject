#pragma once


#ifndef _EXPEDET_DAO_
#define _EXPEDET_DAO_
#include "BaseDAO.h"
#include "../../domain/query/expedet/ExpeDetQuery.h"
#include "../../domain/do/expedet/ExpeDetDO.h"

/**
 * 房屋费用明细数据库操作实现
 */
class ExpedetBuildingFeeDetailDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const ExpedetBuildingFeeDetailQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const ExpedetBuildingFeeDetailQuery::Wrapper& query);
	// 分页查询数据
	std::list<ExpedetBuildingFeeDetailDO> selectWithPage(const ExpedetBuildingFeeDetailQuery::Wrapper& query);
};

/**
 * 业主费用明细数据库操作实现
 */
class ExpedetOwnerFeeDetailDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const ExpedetOwnerFeeDetailQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const ExpedetOwnerFeeDetailQuery::Wrapper& query);
	// 分页查询数据
	std::list<ExpedetOwnerFeeDetailDO> selectWithPage(const ExpedetOwnerFeeDetailQuery::Wrapper& query);
};

/**
 * 合同费用明细数据库操作实现
 */
class ExpedetContractFeeDetailDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const ExpedetContractFeeDetailQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const ExpedetContractFeeDetailQuery::Wrapper& query);
	// 分页查询数据
	std::list<ExpedetContractFeeDetailDO> selectWithPage(const ExpedetContractFeeDetailQuery::Wrapper& query);
};

/**
 * 车辆费用明细数据库操作实现
 */
class ExpedetCarFeeDetailDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const ExpedetCarFeeDetailQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const ExpedetCarFeeDetailQuery::Wrapper& query);
	// 分页查询数据
	std::list<ExpedetCarFeeDetailDO> selectWithPage(const ExpedetCarFeeDetailQuery::Wrapper& query);
};


#endif