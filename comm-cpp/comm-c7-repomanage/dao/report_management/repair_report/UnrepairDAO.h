#ifndef _UNREPAIR_DAO_
#define _UNREPAIR_DAO_
#include "BaseDAO.h"
//#include <list>
#include "../../../domain/do/repair_report/UnrepairDO.h"
#include "../../../domain/query/repair_report/UnrepairQuery/UnrepairQuery.h"

class UnrepairDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const UnrepairQuery::Wrapper& query, SqlParams& params);
public:
	// 分页查询数据
	std::list<UnrepairDO> selectWithPage(const UnrepairQuery::Wrapper& query);
	// 统计数据条数
	uint64_t count(const UnrepairQuery::Wrapper& query);

};
#endif // !_UNREPAIR_DAO_