#pragma once
#ifndef _PAYREMAINQUBUMAPPER_H_
#define _PAYREMAINQUBUMAPPER_H_
#include "../../domain/do/arrears_reminders/PayRemainBuDO.h"
#include "Mapper.h"
class PayRemainQuBUMapper : public Mapper<PayRemainBuDO>
{
public:
    PayRemainBuDO mapper(ResultSet* res) const override
    {
        PayRemainBuDO data;
        int index = 1; // ÁÐË÷Òý

        data.setOfc_Id(res->getInt64(index++));
        data.setOwner_Name(res->getString(index++));
        
        data.setPayer_Obj_Name(res->getString(index++));
        
        data.setFee_Name(res->getString(index++));
       
        data.setAmountd_Owed(res->getInt64(index++));
        data.setStart_Time(res->getString(index++));
        data.setCallable_Way(res->getString(index++));
        
        data.setStaff_Name(res->getString(index++));
        data.setState(res->getString(index++));
       
        data.setRemark(res->getString(index++));
        data.setCreate_Time(res->getString(index++));
        

        return data;
    }
};
#endif // !_PAYREMAINQUBUMAPPER_H_
