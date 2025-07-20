#pragma once
#ifndef _EXPESUMMAPPER_H_
#define _EXPESUMMAPPER_H_
#include "domain/do/expesum/ExpeSumDO.h"

// 楼栋费率子映射器
class BuildingRateMapper : public Mapper<BuildingRateDO> {
public:
    BuildingRateDO mapper(ResultSet* resultSet) const override {
        BuildingRateDO data;
        //data.setBuildingName(resultSet->getString("buildName"));
        data.setCurReceivableFee(resultSet->getDouble("curReceivableFee"));
        data.setCurReceivedFee(resultSet->getDouble("curReceivedFee"));
        data.setBuildRate(resultSet->getDouble("buildRate"));
        data.setFeeTypes(resultSet->getString("name"));
        data.setFeeRoomCount(resultSet->getDouble("feeRoomCount"));
        data.setOweRoomCount(resultSet->getDouble("oweRoomCount"));
        data.setBuildingName(resultSet->getString("buildname"));  // 数据库字段名映射
        data.setStartDate(resultSet->getString("start_date"));
        data.setEndDate(resultSet->getString("end_date"));
        data.setOwnerName(resultSet->getString("owner_name"));
        data.setOwnerNumber(resultSet->getString("owner_tel"));
        data.setCommunityId(resultSet->getString("community_id"));
        data.setRoomNum(resultSet->getString("room_num"));
        data.setStartDate(resultSet->getString("start_date"));
        data.setEndDate(resultSet->getString("end_date"));
        return data;
    }
};


class PtrBuildingRateMapper : public Mapper<PtrBuildingRateDO> {
public:
    PtrBuildingRateDO mapper(ResultSet* resultSet) const override {
        auto data = std::make_shared<BuildingRateDO>();
        //data->setBuildingId(resultSet->getString("floorId"));  // 数据库字段名映射
        data->setCurReceivableFee(resultSet->getDouble("curReceivableFee"));
        data->setCurReceivedFee(resultSet->getDouble("curReceivedFee"));
        data->setBuildRate(resultSet->getDouble("rate_value"));
        data->setFeeTypes(resultSet->getString("name"));
        data->setFeeRoomCount(resultSet->getDouble("feeRoomCount"));
        data->setOweRoomCount(resultSet->getDouble("oweRoomCount"));
        /*data->setFeeTypes(resultSet->getString("rate_type"));
        data->setStartDate(resultSet->getString("start_date"));
        data->setEndDate(resultSet->getString("end_date"));*/
        return data;
    }
};




// 费用项费率子映射器
class FeeItemRateMapper : public Mapper<FeeItemRateDO> {
public:
    FeeItemRateDO mapper(ResultSet* resultSet) const override {
        FeeItemRateDO data;
        data.setCurReceivableFee(resultSet->getDouble("curReceivableFee"));
        data.setCurReceivedFee(resultSet->getDouble("curReceivedFee"));
        data.setItemRate(resultSet->getDouble("itemRate"));
        data.setFeeTypes(resultSet->getString("name"));
        data.setFeeRoomCount(resultSet->getDouble("feeRoomCount"));
        data.setOweRoomCount(resultSet->getDouble("oweRoomCount"));
        data.setBuildingName(resultSet->getString("buildname"));  // 数据库字段名映射
        data.setStartDate(resultSet->getString("start_date"));
        data.setEndDate(resultSet->getString("end_date"));
        data.setOwnerName(resultSet->getString("owner_name"));
        data.setOwnerNumber(resultSet->getString("owner_tel"));
        data.setCommunityId(resultSet->getString("community_id"));
        data.setRoomNum(resultSet->getString("room_num"));
        data.setStartDate(resultSet->getString("start_date"));
        data.setEndDate(resultSet->getString("end_date"));
        return data;
    }
};
//
class PtrFeeItemRateMapper : public Mapper<PtrFeeItemRateDO> {
public:
    PtrFeeItemRateDO mapper(ResultSet* resultSet) const override {
        auto data = std::make_shared<FeeItemRateDO>();
        data->setCurReceivableFee(resultSet->getDouble("curReceivableFee"));
        data->setCurReceivedFee(resultSet->getDouble("curReceivedFee"));
        data->setItemRate(resultSet->getDouble("itemRate"));
        data->setFeeTypes(resultSet->getString("name"));
        data->setFeeRoomCount(resultSet->getDouble("feeRoomCount"));
        data->setOweRoomCount(resultSet->getDouble("oweRoomCount"));
        //data->setBuildingId(resultSet->getString("building_id"));  // 数据库字段名映射
        //data->getRateValue(resultSet->getDouble("rate_value"));
        //data->setFeeTypes(resultSet->getString("rate_type"));
        //data->setStartDate(resultSet->getString("start_date"));
        //data->setEndDate(resultSet->getString("end_date"));
        return data;
    }
};



/*           费用汇总-2         */
/**
*费用汇总表字段匹配映射
*/
class ExpeSumMapper : public Mapper<ExpeSumDO>
{
public:
    ExpeSumDO mapper(ResultSet* resultSet) const override
    {
        ExpeSumDO data;
        data.setTotalRoomCount(resultSet->getInt("totalRoomCount"));
        data.setFeeRoomCount(resultSet->getInt("feeRoomCount"));
        data.setOweRoomCount(resultSet->getInt("oweRoomCount"));
        data.setHisOweFee(resultSet->getDouble("hisOweFee"));
        data.setCurOweFee(resultSet->getDouble("curOweFee"));
        data.setCurReceivableFee(resultSet->getDouble("curReceivableFee"));
        data.setCurReceivedFee(resultSet->getDouble("curReceivedFee"));
        data.setHisReceivedFee(resultSet->getDouble("hisReceivedFee"));
        data.setPreReceivedFee(resultSet->getDouble("preReceivedFee"));
        return data;
    }
};

/**
 * 费用汇总表字段匹配映射-创建智能指针对象
 */
class PtrExpeSumMapper : public Mapper<PtrExpeSumDO>
{
public:
    PtrExpeSumDO mapper(ResultSet* resultSet) const override
    {
        auto data = std::make_shared<ExpeSumDO>();
        data->setTotalRoomCount(resultSet->getInt("totalRoomCount"));
        data->setFeeRoomCount(resultSet->getInt("feeRoomCount"));
        data->setOweRoomCount(resultSet->getInt("oweRoomCount"));
        data->setHisOweFee(resultSet->getDouble("hisOweFee"));
        data->setCurOweFee(resultSet->getDouble("curOweFee"));
        data->setCurReceivableFee(resultSet->getDouble("curReceivableFee"));
        data->setCurReceivedFee(resultSet->getDouble("curReceivedFee"));
        data->setHisReceivedFee(resultSet->getDouble("hisReceivedFee"));
        data->setPreReceivedFee(resultSet->getDouble("preReceivedFee"));
        return data;
    }
};


#endif
