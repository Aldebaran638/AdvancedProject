#pragma once
#ifndef _HOUSEFEEMGRDAO_H_
#define _HOUSEFEEMGRDAO_H_
#include "BaseDAO.h"
#include "../domain/do/HouseFeeMgrDO.h"
#include "../domain/query/HouseFeeMgrQuery.h"

class HouseFeeMgrDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const HouseFeeMgrQuery::Wrapper& query, SqlParams& params);
	inline std::string queryConditionBuilder2(const HouseFeeMgrQueryByRoom::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const HouseFeeMgrQuery::Wrapper& query);
	uint64_t count2(const HouseFeeMgrQueryByRoom::Wrapper& query);
	// 分页查询数据
	std::list<HouseFeeMgrDO> selectWithPage(const HouseFeeMgrQuery::Wrapper& query);
	// 通过费用id查询数据
	PtrHouseFeeMgrDO selectById(std::string id);
	// 通过房屋号查询数据
	std::list<HouseFeeMgrDO> selectByOwnerNum(const HouseFeeMgrQueryByRoom::Wrapper& query);
};


#endif // !_HOUSEFEEMGRDAO_H_
