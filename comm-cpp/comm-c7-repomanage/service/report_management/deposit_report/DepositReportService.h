#ifndef _DEPOSIT_REPORT_SERVICE_
#define _DEPOSIT_REPORT_SERVICE_
#include "domain/vo/deposit_report/DepositReportVO.h"
#include "domain/query/deposit_report/DepositReportQuery.h"
#include "domain/dto/deposit_report/DepositReportDTO.h"
#include "dao/report_management/deposit_report/DepositReportDAO.h"

/**
 * 押金报表服务实现，演示服务实现
 */
class DepositReportService
{
public:
	// 分页查询所有数据
	DepositReportPageDTO::Wrapper listAll(const DepositReportQuery::Wrapper& query);
	// 根据社区ID查询押金报表数据
	DepositReportPageDTO::Wrapper listByCommunityId(const oatpp::String& community_id);
};

#endif // !_DEPOSIT_REPORT_SERVICE_