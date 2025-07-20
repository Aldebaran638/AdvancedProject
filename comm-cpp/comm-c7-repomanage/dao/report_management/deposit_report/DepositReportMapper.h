#pragma once

#ifndef _DEPOSIT_REPORT_MAPPER_
#define _DEPOSIT_REPORT_MAPPER_

#include "Mapper.h"
#include "domain/do/deposit_report/DepositReportDO.h"

/**
 * 押金报表字段匹配映射
 */
class DepositReportMapper : public Mapper<DepositReportDO>
{
public:
    DepositReportDO mapper(ResultSet* resultSet) const override
    {
        DepositReportDO data;
        data.setFee_id(resultSet->getString(1));
        data.setFee_type_cd(resultSet->getString(2));
        data.setStart_time(resultSet->getString(3));
        data.setEnd_time(resultSet->getString(4));
        data.setCreate_time(resultSet->getString(5));
        data.setIncome_obj_id(resultSet->getString(6));
        data.setPayer_obj_id(resultSet->getString(7));
        data.setPay_state(resultSet->getString(8));
        data.setCommunity_id(resultSet->getString(9));
        data.setLocation_obj_name(resultSet->getString(10));
        data.setOwner_name(resultSet->getString(11));
        data.setConfig_name(resultSet->getString(12));
        data.setReceivable_amount(resultSet->getString(13));
        data.setReturn_state(resultSet->getString(14));
        return data;
    }
};

/**
 * 押金报表字段匹配映射-智能指针类型
// */
//class PtrDepositReportMapper : public Mapper<std::shared_ptr<DepositReportDO>>
//{
//public:
//    std::shared_ptr<DepositReportDO> mapper(ResultSet* resultSet) const override
//    {
//        auto data = std::make_shared<DepositReportDO>();
//        data.setFee_id(resultSet->getString(1));
//        data.setFee_type_cd(resultSet->getString(2));
//        data.setStart_time(resultSet->getString(3));
//        data.setEnd_time(resultSet->getString(4));
//        data.setCreate_time(resultSet->getString(5));
//        data.setIncome_obj_id(resultSet->getString(6));
//        data.setPayer_obj_id(resultSet->getString(7));
//        data.setPay_state(resultSet->getString(8));
//        data.setCommunity_id(resultSet->getString(9));
//        data.setLocation_obj_name(resultSet->getString(10));
//        data.setOwner_name(resultSet->getString(11));
//        data.setConfig_name(resultSet->getString(12));
//        data.setReceivable_amount(resultSet->getString(13));
//        data.setReturn_state(resultSet->getString(14));
//        return data;
//    }
//};

#endif // !_SAMPLE_MAPPER_