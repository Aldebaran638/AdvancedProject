#pragma once
#ifndef _OWEINFORMATIONMAPPER_H_
#define _OWEINFORMATIONMAPPER_H_
#include "../../domain/do/arrears_information/OweInformationDo.h"
#include "Mapper.h"
class OweInformationMapper : public Mapper<OweInformationDo>
{
public:
	OweInformationDo mapper(ResultSet* res) const override
	{
		OweInformationDo data;
		data.setOwe_Id(res->getInt(1));
		data.setPayer_Obj_Name(res->getString(2));
		data.setOwner_Name(res->getString(3));
		data.setOwner_Tel(res->getString(4));
		data.setCreate_Time(res->getString(5));
		data.setDeadline_Time(res->getString(6));
		data.setBill_Amount_Owed(res->getInt(7));
		data.setFee_End_Time(res->getString(8));
		return data;
	}
};
#endif // !_OWEINFORMATIONMAPPER_H_
