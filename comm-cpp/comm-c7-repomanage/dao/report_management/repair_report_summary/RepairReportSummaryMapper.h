#pragma once

#ifndef _REPAIR_REPORT_SUMMARY_MAPPER_
#define _REPAIR_REPORT_SUMMARY_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/repair_report_summary/RepairReportSummaryDO.h"

/**
 * ±¨ÐÞ»ã×Ü±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class RepairReportSummaryMapper : public Mapper<RepairReportSummaryDO>
{
public:
	RepairReportSummaryDO mapper(ResultSet* resultSet) const override
	{
		RepairReportSummaryDO data;


		data.setSummaryId(resultSet->getInt("summaryId"));
		data.setStaffId(resultSet->getString("staffId"));
		data.setStaffName(resultSet->getString("staffName"));
		data.setDeal(resultSet->getInt("deal"));
		data.setSendList(resultSet->getInt("sendList"));
		data.setTransferList(resultSet->getInt("transferList"));
		data.setChargeback(resultSet->getInt("chargeback"));
		data.setReturnVisit(resultSet->getInt("returnVisit"));
		data.setFinish(resultSet->getInt("finish"));
		data.setExamineValue(resultSet->getString("examineValue"));
		
		return data;
	}
};


#endif // !_REPAIR_REPORT_SUMMARY_MAPPER_
