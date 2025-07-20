#pragma once
#ifndef _MEMBER_DAO_
#define _MEMBER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/member/MemberDO.h"
#include "../../domain/query/member/MemberQuery.h"

/**
 * 示例表数据库操作实现
 */
class MemberDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const MemberQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const MemberQuery::Wrapper& query);
	// 分页查询数据
	std::list<MemberDO> selectWithPage(const MemberQuery::Wrapper& query);
	// 插入数据
	int insert(const MemberDO& iObj);
	// 修改数据
	int update(const MemberDO& uObj);
	// 通过ID删除数据
	int deleteById(std::string id);
};
#endif // !_SAMPLE_DAO_
