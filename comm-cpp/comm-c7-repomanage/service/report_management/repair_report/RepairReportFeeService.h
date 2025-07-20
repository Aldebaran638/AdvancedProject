#pragma once
#ifndef _REPAIR_REPORT_FEE_SERVICE_
#define _REPAIR_REPORT_FEE_SERVICE_

#include "../../../domain/vo/repair_report/RepairReportFeeVO.h"
#include "../../../domain/query/repair_report/RepairReportFeeQuery.h"
#include "../../../domain/dto/repair_report/RepairReportFeeDTO.h"

/**
 * @brief 报修费用服务层接口定义
 *
 * 该接口负责定义报修费用模块的服务层操作，包含增删改查等功能。
 */
class RepairReportFeeService
{
public:
    RepairReportFeePageDTO::Wrapper listAll(const RepairReportFeeQuery::Wrapper& query);
};

#endif // !_REPAIR_REPORT_FEE_SERVICE_