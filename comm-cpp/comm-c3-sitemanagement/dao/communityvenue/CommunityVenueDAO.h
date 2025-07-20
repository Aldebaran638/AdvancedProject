#pragma once


#ifndef _COMMUNITYVENUE_DAO_
#define _COMMUNITYVENUE_DAO_

#include "BaseDAO.h"
#include "domain/do/communityvenue/CommunityVenueDO.h"
#include "domain/query/communityvenue/CommunityVenueQuery.h"

class CommunityVenueDAO : public BaseDAO {
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
	inline std::string queryConditionBuilder(const CommunityVenueQuery::Wrapper& query, SqlParams& params);


public:
	uint64_t count(const CommunityVenueQuery::Wrapper& query);
	std::list<CommunityVenueDO> selectWithPage(const CommunityVenueQuery::Wrapper& query);
	std::list<CommunityVenueDO> selectByName(const std::string& name);
	PtrCommunityVenueDO selectById(const std::string& id);
	int insert(const CommunityVenueDO& obj);
	int update(const CommunityVenueDO& obj);
	int deleteById(const std::string& id);
};

#endif//!_CommunityVenue_DAO_