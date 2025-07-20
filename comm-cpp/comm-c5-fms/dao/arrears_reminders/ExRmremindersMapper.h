#pragma once
#ifndef _EXRMREMINDERS_MAPPER_
#define _EXRMREMINDERS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/arrears_reminders/ExRmremindersDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ExRmremindersMapper : public Mapper<ExRmremindersDO>
{
public:
	ExRmremindersDO mapper(ResultSet* resultSet) const override
	{
		ExRmremindersDO data;
		data.setOfc_id(resultSet->getString(1));
		data.setOwner_name(resultSet->getString(2));
		data.setPayer_obj_name(resultSet->getString(3));
		data.setFee_name(resultSet->getString(4));
		data.setAmountd_owed(resultSet->getString(5));
		data.setStart_time(resultSet->getString(6));
		//data.setEnd_time(resultSet->getString(7));
		data.setCallable_way(resultSet->getString(7));
		data.setStaff_name(resultSet->getString(8));
		data.setState(resultSet->getString(9));
		data.setRemark(resultSet->getString(10));
		data.setCreate_time(resultSet->getString(11));
		return data;
	}
};
#endif // !_EXRMREMINDERS_MAPPER_