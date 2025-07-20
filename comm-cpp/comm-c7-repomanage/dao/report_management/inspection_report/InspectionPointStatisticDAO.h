#pragma
#ifndef _INSPECTION_POINT_STATISTIC_DAO_H_
#define _INSPECTION_POINT_STATISTIC_DAO_H_
#include "BaseDAO.h"
//InspectionPointStatisticDAO
#include "domain/query/inspection_report/InspectionPointStatisticQuery.h"
#include "domain/do/inspection_report/InspectionPointStatisticDO.h"
/**
 * 巡检统计表数据库操作实现
 */
class InspectionPointStatisticDAO : public BaseDAO
{
private:
	//************************************
// Method:      queryConditionBuilder
// FullName:    InspectionPointStatisticDAO::queryConditionBuilder
// Access:      private 
// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
// Parameter:   const InspectionPointStatisticQuery::Wrapper& query 查询数据对象
// Parameter:   SqlParams& params 存放查询数据的参数对象
// Description: 查询条件构建器，根据InspectionPointStatisticQuery对象动态构建查询条件相关参数
//************************************
	inline std::string queryConditionBuilder(); // 获取纯条件模板
	inline std::string queryConditionBuilder(const InspectionPointStatisticQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const InspectionPointStatisticQuery::Wrapper& query);
	// 分页查询数据
	std::list<InspectionPointStatisticDO> selectWithPage(const InspectionPointStatisticQuery::Wrapper& query);
	//导出所有
	std::list<InspectionPointStatisticDO> listAllDO();

};
#endif // !_INSPECTION_POINT_STATISTIC_DAO_H_
