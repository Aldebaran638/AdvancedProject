#pragma once

#ifndef _SELECTOWNER_DAO_
#define _SELECTOWNER_DAO_
#include "BaseDAO.h"

#include "../../domain/do/owner/OwnerDO.h"
#include "../../domain/query/owner/OwnerQuery.h"


class selectOwnerDAO : public BaseDAO
{
private:
	
	inline std::string queryConditionBuilder(const OwnerQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const OwnerQuery::Wrapper& query);
	// 分页查询数据
	std::list<OwnerDO> selectWithPage(const OwnerQuery::Wrapper& query);
	std::list<OwnerDO> selectByName(const string& name);
};

#endif





