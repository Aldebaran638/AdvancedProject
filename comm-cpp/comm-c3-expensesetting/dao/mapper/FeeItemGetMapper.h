#pragma once
#ifndef _FEE_ITEM__GETMAPPER_
#define _FEE_ITEM_GET_MAPPER_

#include "Mapper.h"
#include "../../domain/do/FeeItem/FeeItemDo.h"

/**
 * 费用项表字段匹配映射
 */
class FeeItemGetMapper : public Mapper<FeeItemDO>
{
public:
    FeeItemDO mapper(ResultSet* resultSet) const override
    {
        FeeItemDO data;
        data.setConfig_id(resultSet->getString(1));
        data.setFee_type_cd(resultSet->getString(2));
        data.setFee_name(resultSet->getString(3));
        data.setFee_flag(resultSet->getString(4));
        data.setPayment_cd(resultSet->getString(5));
        data.setPayment_cycle(resultSet->getString(6));
        data.setStart_time(resultSet->getString(7));
        data.setEnd_time(resultSet->getString(8));
        data.setSquare_price(resultSet->getString(9));
        data.setAdditional_amount(resultSet->getString(10));
        data.setDeduct_from(resultSet->getString(11));
        data.setPay_online(resultSet->getString(12));
        data.setScale(resultSet->getString(13));
        data.setDecimal_place(resultSet->getInt(14));
        data.setOperate(resultSet->getString(15));
        data.setCommunity_id(resultSet->getString(16));
        data.setCreate_Time(resultSet->getString(17));
        data.setUser_Id(resultSet->getString(18));
        data.setName(resultSet->getString(19));
        return data;
    }
};

/**
 * 费用项表字段匹配映射 - 创建智能指针对象
 */
class PtrFeeItemGETMapper : public Mapper<PtrFeeItemDO>
{
public:
    PtrFeeItemDO mapper(ResultSet* resultSet) const override
    {
        auto data = std::make_shared<FeeItemDO>();
        data->setConfig_id(resultSet->getString(1));
        data->setFee_type_cd(resultSet->getString(2));
        data->setFee_name(resultSet->getString(3));
        data->setFee_flag(resultSet->getString(4));
        data->setPayment_cd(resultSet->getString(5));
        data->setPayment_cycle(resultSet->getString(6));
        data->setStart_time(resultSet->getString(7));
        data->setEnd_time(resultSet->getString(8));
        data->setSquare_price(resultSet->getString(9));
        data->setAdditional_amount(resultSet->getString(10));
        data->setDeduct_from(resultSet->getString(11));
        data->setPay_online(resultSet->getString(12));
        data->setScale(resultSet->getString(13));
        data->setDecimal_place(resultSet->getInt(14));
        data->setOperate(resultSet->getString(15));
        data->setCommunity_id(resultSet->getString(16));
        data->setCreate_Time(resultSet->getString(17));
        data->setUser_Id(resultSet->getString(18));
        return data;
    }
};

#endif // !_FEE_ITEM_MAPPER_
