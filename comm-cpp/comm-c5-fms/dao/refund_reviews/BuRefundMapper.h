#pragma once
#ifndef _BUREFUNDMAPPER_H_
#define _BUREFUNDMAPPER_H_
#include "../../domain/do/refund_reviews/BuRefundDO.h"
#include "Mapper.h"
class BuRefundMapper : public Mapper<BuRefundDO>
{
public:
	BuRefundDO mapper(ResultSet* res) const override
	{
		BuRefundDO data;
		data.setReturn_Fee_Id(res->getString(1));
		data.setB_Id(res->getString(2));
		data.setFee_Type_Cd(res->getString(3));
		data.setFee_Id(res->getString(4));
		data.setCycles(res->getString(5));
		data.setReceived_Amount(res->getInt(6));
		data.setCreate_Time(res->getString(7));
		data.setReason(res->getString(8));
		data.setApply_Person_Name(res->getString(9));
		data.setState(res->getString(10));
		data.setAudit_Person_Name(res->getString(11));
		data.setStatus_Cd(res->getString(12));
		return data;
	}
};
#endif // !_BUREFUNDMAPPER_H_
