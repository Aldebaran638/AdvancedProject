#pragma once
#ifndef _OWEINFORMATIONDAO_H_
#define _OWEINFORMATIONDAO_H_
#include "../../domain/do/arrears_information/OweInformationDo.h"
#include "../../domain/query/arrears_information/OweInformationQuery.h"
#include "BaseDAO.h"
#include <list>
class OweInformationDAO : BaseDAO
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
	inline std::string queryConditionBuilder(const OweInformationQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const OweInformationQuery::Wrapper& query);
	//条件和分页查询
	std::list<OweInformationDo> selectWithPage(const OweInformationQuery::Wrapper& query);
	//查询excle要导出的数据
	std::list<OweInformationDo> getAll();
};
#endif // !_OWEINFORMATIONDAO_H_
