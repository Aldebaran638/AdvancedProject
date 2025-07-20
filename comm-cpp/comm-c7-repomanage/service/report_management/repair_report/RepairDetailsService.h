#pragma once
#ifndef _REPAIRDETAILS_SERVICE_
#define _REPAIRDETAILS_SERVICE_
#include "../../../domain/vo/repair_report/RepairDetailsVO.h"
#include "../../../domain/query/repair_report/RepairDetailsQuery.h"
#include "../../../domain/dto/repair_report/RepairDetailsDTO.h"
#include "../../../domain/do/repair_report/RepairDetailsDO.h"


/**
 * 示例服务实现，演示基础的示例服务实现
 */
class RepairDetailsService
{
public:
	// 分页查询所有数据
	RepairDetailsListPageDTO::Wrapper listAll(const RepairDetailsQuery::Wrapper& query);

	/*oatpp::List<RepairDetailsDTO::Wrapper>
		RepairDetailsService::listAllExport(const RepairDetailsQuery::Wrapper& query);*/
};

#endif // !_REPAIRDETAILS_SERVICE_

