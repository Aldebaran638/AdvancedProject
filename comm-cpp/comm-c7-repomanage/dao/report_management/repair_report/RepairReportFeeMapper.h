#pragma once

#ifndef _REPAIRREPORTFEE_MAPPER_
#define _REPAIRREPORTFEE_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/repair_report/RepairReportFeeDO.h"

/**
 * RepairReportFee表字段匹配映射
 */
class RepairReportFeeMapper : public Mapper<RepairReportFeeDO>
{
public:
    RepairReportFeeDO mapper(ResultSet* resultSet) const override
    {
        RepairReportFeeDO data;
        data.setRepairId(resultSet->getString(1));
        data.setRepairName(resultSet->getString(2));
        data.setTel(resultSet->getString(3));
        data.setCreateTime(resultSet->getString(4));
        data.setRepairLocation(resultSet->getString(5));//在Mapper里第5列取出来的就是 repair_obj_type，然后装到 repairLocation
        data.setMaintenanceType(resultSet->getString(6));
        data.setRepairFee(resultSet->getString(7));
        return data;
    }
};

/**
 * RepairReportFee表字段匹配映射-智能指针
 */
class PtrRepairReportFeeMapper : public Mapper<PtrRepairReportFeeDO>
{
public:
    PtrRepairReportFeeDO mapper(ResultSet* resultSet) const override
    {
        auto data = std::make_shared<RepairReportFeeDO>();
        data->setRepairId(resultSet->getString(1));
        data->setRepairName(resultSet->getString(2));
        data->setTel(resultSet->getString(3));
        data->setCreateTime(resultSet->getString(4));
        data->setRepairLocation(resultSet->getString(5));
        data->setMaintenanceType(resultSet->getString(6));
        data->setRepairFee(resultSet->getString(7));
        return data;
    }
};

#endif // !_REPAIRREPORTFEE_MAPPER_
#pragma once
