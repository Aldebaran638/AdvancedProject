#ifndef _UNREPAIR_SERVICE_
#define _UNREPAIR_SERVICE_
//#include <list>  
#include "../../../domain/vo/repair_report/UnrepairVO/UnrepairVO.h"
#include "../../../domain/query/repair_report/UnrepairQuery/UnrepairQuery.h"
#include "../../../domain/dto/repair_report/Unrepair/UnrepairDTO.h"
#include "../../../domain/do/repair_report/UnrepairDO.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class UnrepairService
{
public:
	// 分页查询所有数据
	UnrepairPageDTO::Wrapper listAll(const UnrepairQuery::Wrapper& query);
};

#endif // !_UNREPAIR_SERVICE_

