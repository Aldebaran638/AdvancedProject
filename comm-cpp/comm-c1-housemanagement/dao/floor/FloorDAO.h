#pragma

#ifndef _FLOOR_DAO_
#define _FLOOR_DAO_
#include "BaseDAO.h"
#include "../../domain/do/floor/FloorDO.h"
#include "../../domain/query/floor/FloorQuery.h"

class FloorDAO :public BaseDAO {
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
	inline std::string queryConditionBuilder(const FloorQuery::Wrapper& query, SqlParams& params);

public:
	//统计数据条数
	uint64_t count(const FloorQuery::Wrapper& query);
	//分页查询数据
	std::list<FloorDO> selectWithPage(const FloorQuery::Wrapper& query);
	//通过楼ID查询数据
	std::shared_ptr<FloorDO> selectById(std::string id);
	//通过前端传入的参数查询数据
	std::shared_ptr<FloorDO> selectByData(const FloorQuery::Wrapper& query);

	/*//通过楼编号查询数据
	std::shared_ptr<FloorDO> selectByNum(const FloorQuery::Wrapper& query);
	//通过业务ID查询数据
	std::shared_ptr<FloorDO> selectB_id(const FloorQuery::Wrapper& query);
	//通过小区楼名称查询数据
	std::shared_ptr<FloorDO> selectName(const FloorQuery::Wrapper& query);
	//通过用户ID查询数据
	std::shared_ptr<FloorDO> selectUserId(const FloorQuery::Wrapper& query);
	//通过小区ID查询数据
	std::shared_ptr<FloorDO> selectCommunityId(const FloorQuery::Wrapper& query);*/

	//插入楼栋数据
	int insert(const FloorDO& iObj);
	// 修改楼栋数据
	int update(const FloorDO& uObj);
	// 通过ID删除楼栋数据
	int deleteById(std::string id);


};



#endif