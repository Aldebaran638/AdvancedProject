#pragma once

#include "BaseDAO.h"
#include "../domain/do/CommunitySpaceMgrDO.h"
#include "../domain/query/CommunitySpaceMgrQuery.h"

/**
 * 示例表数据库操作实现
 */
class CommunitySpaceMgrDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const CommunitySpaceMgrPageQuery::Wrapper& query, SqlParams& params);
	inline std::string queryConditionTimeBuilder(const CommunitySpaceTimeMgrPageQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const CommunitySpaceMgrPageQuery::Wrapper& query);
	uint64_t countTime(const CommunitySpaceTimeMgrPageQuery::Wrapper& query);
	// 分页查询数据
	std::list<CommunitySpaceMgrDO> selectWithPage(const CommunitySpaceMgrPageQuery::Wrapper& query);
	// 查询时间
	//std::list<CommunitySpaceTimeMgrDO> selectTimeById(std::string id);
	std::list<CommunitySpaceTimeMgrDO> selectTimeWithPage(const CommunitySpaceTimeMgrPageQuery::Wrapper& query);
	// 修改数据
	int update(const CommunitySpaceTimeMgrDO& uObj);
};
