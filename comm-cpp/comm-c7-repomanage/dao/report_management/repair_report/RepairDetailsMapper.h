#pragma once
#ifndef _REPAIRDETAILS_MAPPER_
#define _REPAIRDETAILS_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/repair_report/RepairDetailsDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class RepairDetailsMapper : public Mapper<RepairDetailsDO>
{
public:
	RepairDetailsDO mapper(ResultSet* resultSet) const override
	{
		RepairDetailsDO data;
		data.setWorkOrderId(resultSet->getString(1));
		data.setRepairType(resultSet->getString(2));
		data.setRequesterName(resultSet->getString(3));
		data.setRequestLocation(resultSet->getString(4));
		data.setRequesterTelephone(resultSet->getString(5));
		data.setWorkOrderStatus(resultSet->getString(6));
		data.setRequestTime(resultSet->getString(7));
		data.setPreviousProcessor(resultSet->getString(8));
		data.setCurrentProcessor(resultSet->getString(9));
		data.setDispatchingTime(resultSet->getString(10));
		data.setHandleTime(resultSet->getString(11));
		data.setProcessorStatus(resultSet->getString(12));
		data.setRequestContent(resultSet->getString(13));
		return data;
	}
};

class PtrRepairDetailsMapper : public Mapper<PtrRepairDetailsDO>
{
public:
	PtrRepairDetailsDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<RepairDetailsDO>();
		data->setWorkOrderId(resultSet->getString(1));
		data->setRepairType(resultSet->getString(2));
		data->setRequesterName(resultSet->getString(3));
		data->setRequestLocation(resultSet->getString(4));
		data->setRequesterTelephone(resultSet->getString(5));
		data->setWorkOrderStatus(resultSet->getString(6));
		data->setRequestTime(resultSet->getString(7));
		data->setPreviousProcessor(resultSet->getString(8));
		data->setCurrentProcessor(resultSet->getString(9));
		data->setDispatchingTime(resultSet->getString(10));
		data->setHandleTime(resultSet->getString(11));
		data->setProcessorStatus(resultSet->getString(12));
		data->setRequestContent(resultSet->getString(13));
		return data;
	}
};

#endif // !_REPAIRDETAILS_MAPPER_