#pragma once
#ifndef CARPAYMENT_MAPPER_H_
#define CARPAYMENT_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/carpayment/CarPaymentDO.h"

/**
 * 示例表字段匹配映射
 */
class GetVehicleFeeMapper : public Mapper<GetVehicleFeeDO>
{
public:
	GetVehicleFeeDO mapper(ResultSet* resultSet) const override
	{
		GetVehicleFeeDO data;
		data.setFeeId(resultSet->getString(1));
		data.setFeeFlag(resultSet->getString(2));
		data.setFeeTypeCd(resultSet->getString(3));
		data.setValue(resultSet->getString(4));
		data.setFeeName(resultSet->getString(5));
		data.setState(resultSet->getString(6));
		data.setCreateTime(resultSet->getString(7));
		data.setStartTime(resultSet->getString(8)); // Was data.setr
		data.setEndTime(resultSet->getString(9));
		data.setBatchId(resultSet->getString(10));
		data.setOweAmount(resultSet->getDouble(11)); // Assuming Float64 in DO, getFloat64 from ResultSet
		data.setOwnerId(resultSet->getString(12));    // Added owner_id
		data.setOwnerName(resultSet->getString(13));   // Added index
		data.setLink(resultSet->getString(14));       // Added index
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrGetVehicleFeeMapper : public Mapper<PtrGetVehicleFeeDO>
{
public:
	PtrGetVehicleFeeDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<GetVehicleFeeDO>();
		data->setFeeId(resultSet->getString(1));
		data->setFeeFlag(resultSet->getString(2));
		data->setFeeTypeCd(resultSet->getString(3));
		data->setValue(resultSet->getString(4));
		data->setFeeName(resultSet->getString(5));
		data->setState(resultSet->getString(6));
		data->setCreateTime(resultSet->getString(7));
		data->setStartTime(resultSet->getString(8)); // Was data.setr
		data->setEndTime(resultSet->getString(9));
		data->setBatchId(resultSet->getString(10));
		data->setOweAmount(resultSet->getDouble(11)); // Assuming Float64 in DO, getFloat64 from ResultSet
		data->setOwnerName(resultSet->getString(12));   // Added index
		data->setLink(resultSet->getString(13));       // Added index
		data->setOwnerId(resultSet->getString(14));    // Added owner_id
		return data;
	}
};

/**
 * 示例表字段匹配映射
 */
class GetPaymentRecordsMapper : public Mapper<GetPaymentRecordsDO>
{
public:
	GetPaymentRecordsDO mapper(ResultSet* resultSet) const override
	{
		GetPaymentRecordsDO data;
		int col = 1;
		data.setFeeName(resultSet->getString(col++));
		data.setValue(resultSet->getString(col++));
		data.setCycle(resultSet->getDouble(col++)); // Or getDouble, getNumeric, etc.
		data.setReceivableAmount(resultSet->getDouble(col++));
		data.setReceivedAmount(resultSet->getDouble(col++));
		data.setCreateTime(resultSet->getString(col++));
		data.setPayFeeTime(resultSet->getString(col++));
		data.setCashierName(resultSet->getString(col++));
		data.setStatusCd(resultSet->getString(col++));
		data.setRemark(resultSet->getString(col++));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrGetPaymentRecordsMapper : public Mapper<PtrGetPaymentRecordsDO>
{
public:
	PtrGetPaymentRecordsDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<GetPaymentRecordsDO>();
		int col = 1;
		data->setFeeName(resultSet->getString(col++));
		data->setValue(resultSet->getString(col++));
		data->setCycle(resultSet->getDouble(col++)); // Or getDouble, getNumeric, etc.
		data->setReceivableAmount(resultSet->getDouble(col++));
		data->setReceivedAmount(resultSet->getDouble(col++));
		data->setCreateTime(resultSet->getString(col++));
		data->setPayFeeTime(resultSet->getString(col++));
		data->setCashierName(resultSet->getString(col++));
		data->setStatusCd(resultSet->getString(col++));
		data->setRemark(resultSet->getString(col++));
		return data;
	}
};

/**
 * 示例表字段匹配映射
 */
class GetPaymentDetailedRecordMapper : public Mapper<GetPaymentDetailedRecordDO>
{
public:
	GetPaymentDetailedRecordDO mapper(ResultSet* resultSet) const override
	{
		GetPaymentDetailedRecordDO data;
		int col = 1; // Start with column index 1

		data.setFeeId(resultSet->getString(col++));
		data.setCycle(resultSet->getDouble(col++)); // Or getDouble, getNumeric, etc.
		data.setReceivableAmount(resultSet->getDouble(col++));
		data.setReceivedAmount(resultSet->getDouble(col++));
		data.setPayFeeTime(resultSet->getString(col++));
		data.setCreateTime(resultSet->getString(col++));
		data.setDeadlineTime(resultSet->getString(col++));
		data.setCashierName(resultSet->getString(col++));
		data.setStatusCd(resultSet->getString(col++));
		data.setRemark(resultSet->getString(col++));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrGetPaymentDetailedRecordMapper : public Mapper<PtrGetPaymentDetailedRecordDO>
{
public:
	PtrGetPaymentDetailedRecordDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<GetPaymentDetailedRecordDO>();
		int col = 1;
		data->setFeeId(resultSet->getString(col++));
		data->setCycle(resultSet->getDouble(col++)); // Or getDouble, getNumeric, etc.
		data->setReceivableAmount(resultSet->getDouble(col++));
		data->setReceivedAmount(resultSet->getDouble(col++));
		data->setPayFeeTime(resultSet->getString(col++));
		data->setCreateTime(resultSet->getString(col++));
		data->setDeadlineTime(resultSet->getString(col++));
		data->setCashierName(resultSet->getString(col++));
		data->setStatusCd(resultSet->getString(col++));
		data->setRemark(resultSet->getString(col++));
		return data;
	}
};

/**
 * 示例表字段匹配映射
 */
class GetFeeModificationRecordsMapper : public Mapper<GetFeeModificationRecordsDO>
{
public:
	GetFeeModificationRecordsDO mapper(ResultSet* resultSet) const override
	{
		GetFeeModificationRecordsDO data;
		data.setFeeName(resultSet->getString(1));
		data.setCreateTime(resultSet->getString(2));
		data.setStartTime(resultSet->getString(3));
		data.setCreateUserName(resultSet->getString(4));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrGetFeeModificationRecordsMapper : public Mapper<PtrGetFeeModificationRecordsDO>
{
public:
	PtrGetFeeModificationRecordsDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<GetFeeModificationRecordsDO>();
		data->setFeeName(resultSet->getString(1));
		data->setCreateTime(resultSet->getString(2));
		data->setStartTime(resultSet->getString(3));
		data->setCreateUserName(resultSet->getString(4));
		return data;
	}
};
class PayFeeMapper : public Mapper<Pay_FeeDO>
{
public:
    Pay_FeeDO mapper(ResultSet* resultSet) const override
    {

        Pay_FeeDO data;
        data.setFeeName(resultSet->getString(1));       // fee_name
        data.setFeeFlag(resultSet->getString(2));       // fee_flag
        data.setFeeTypeCd(resultSet->getString(3));     // fee_type_cd
        data.setAmount(resultSet->getDouble(4));        // amount
        data.setCreateTime(resultSet->getString(5));    // create_time
        data.setRecePeriod(resultSet->getString(6));    // rece_period
        data.setDescription(resultSet->getString(7));   // description
        data.setState(resultSet->getString(8));         // state
        return data;
    }
};
class PayFeeConfigMapper : public Mapper<Pay_Fee_ConfigDO>
{
public:
    Pay_Fee_ConfigDO mapper(ResultSet* resultSet) const override
    {
        Pay_Fee_ConfigDO data;
        data.setConfigId(resultSet->getString(1));
        data.setBId(resultSet->getString(2));
        data.setCommunityId(resultSet->getString(3));
        data.setFeeTypeCd(resultSet->getString(4));
        data.setSquarePrice(resultSet->getDouble(5));
        data.setAdditionalAmount(resultSet->getDouble(6));
        data.setCreateTime(resultSet->getString(7));
        data.setStatusCd(resultSet->getString(8));
        data.setIsDefault(resultSet->getString(9));
        data.setStartTime(resultSet->getString(10));
        data.setEndTime(resultSet->getString(11));
        data.setFeeFlag(resultSet->getString(12));
        data.setFeeName(resultSet->getString(13));
        data.setComputingFormula(resultSet->getString(14));
        data.setBillType(resultSet->getString(15));
        data.setPaymentCycle(resultSet->getString(16));
        data.setPaymentCd(resultSet->getString(17));
        data.setComputingFormulaText(resultSet->getString(18));
        data.setDeductFrom(resultSet->getString(19));
        data.setPayOnline(resultSet->getString(20));
        data.setScale(resultSet->getString(21));
        data.setDecimalPlace(resultSet->getInt(22));
        data.setUnits(resultSet->getString(23));
        data.setPrepaymentPeriod(resultSet->getString(24));
        return data;
    }
};
class BusinessPayFeeMapper : public Mapper<Business_Pay_FeeDO>
{
public:
    Business_Pay_FeeDO mapper(ResultSet* resultSet) const override
    {
        Business_Pay_FeeDO data;
        data.setFeeId(resultSet->getString(1));
        data.setBId(resultSet->getString(2));
        data.setFeeTypeCd(resultSet->getString(3));
        data.setCommunityId(resultSet->getString(4));
        data.setPayerObjId(resultSet->getString(5));
        data.setIncomeObjId(resultSet->getString(6));
        data.setStartTime(resultSet->getString(7));
        data.setEndTime(resultSet->getString(8));
        data.setAmount(resultSet->getDouble(9));
        data.setUserId(resultSet->getString(10));
        data.setCreateTime(resultSet->getString(11));
        data.setOperate(resultSet->getString(12));
        data.setFeeFlag(resultSet->getString(13));
        data.setState(resultSet->getString(14));
        data.setConfigId(resultSet->getString(15));
        data.setPayerObjType(resultSet->getString(16));
        data.setBatchId(resultSet->getString(17));
        return data;
    }
};
class BusinessPayFeeConfigMapper : public Mapper<Business_Pay_Fee_ConfigDO>
{
public:
    Business_Pay_Fee_ConfigDO mapper(ResultSet* resultSet) const override
    {
        Business_Pay_Fee_ConfigDO data;
        data.setConfigId(resultSet->getString(1));
        data.setBId(resultSet->getString(2));
        data.setCommunityId(resultSet->getString(3));
        data.setFeeTypeCd(resultSet->getString(4));
        data.setSquarePrice(resultSet->getDouble(5));
        data.setAdditionalAmount(resultSet->getDouble(6));
        data.setCreateTime(resultSet->getString(7));
        data.setOperate(resultSet->getString(8));
        data.setIsDefault(resultSet->getString(9));
        data.setStartTime(resultSet->getString(10));
        data.setEndTime(resultSet->getString(11));
        data.setFeeFlag(resultSet->getString(12));
        data.setFeeName(resultSet->getString(13));
        data.setComputingFormula(resultSet->getString(14));
        data.setBillType(resultSet->getString(15));
        data.setPaymentCycle(resultSet->getString(16));
        data.setPaymentCd(resultSet->getString(17));
        data.setComputingFormulaText(resultSet->getString(18));
        data.setDeductFrom(resultSet->getString(19));
        data.setUnits(resultSet->getString(20));
        data.setDecimalPlace(resultSet->getInt(21));
        data.setScale(resultSet->getString(22));
        data.setPayOnline(resultSet->getString(23));
        data.setPrepaymentPeriod(resultSet->getString(24));
        return data;
    }
};
class ReportOweFeeMapper : public Mapper<Report_Owe_FeeDO>
{
public:
    Report_Owe_FeeDO mapper(ResultSet* resultSet) const override
    {
        Report_Owe_FeeDO data;
        data.setOweId(resultSet->getString(1));
        data.setConfigId(resultSet->getString(2));
        data.setConfigName(resultSet->getString(3));
        data.setFeeId(resultSet->getString(4));
        data.setFeeName(resultSet->getString(5));
        data.setAmountOwed(resultSet->getDouble(6));
        data.setOwnerId(resultSet->getString(7));
        data.setOwnerName(resultSet->getString(8));
        data.setOwnerTel(resultSet->getString(9));
        data.setPayerObjId(resultSet->getString(10));
        data.setPayerObjName(resultSet->getString(11));
        data.setPayerObjType(resultSet->getString(12));
        data.setCommunityId(resultSet->getString(13));
        data.setCreateTime(resultSet->getString(14));
        data.setUpdateTime(resultSet->getString(15));
        data.setEndTime(resultSet->getString(16));
        data.setDeadlineTime(resultSet->getString(17));
        return data;
    }
};



class PtrPayFeeMapper : public Mapper<PtrPay_FeeDO>
{
public:
    PtrPay_FeeDO mapper(ResultSet* resultSet) const override
    {
        auto data = std::make_shared<Pay_FeeDO>();
        data->setFeeId(resultSet->getString(1));
        data->setBId(resultSet->getString(2));
        data->setFeeTypeCd(resultSet->getString(3));
        data->setCommunityId(resultSet->getString(4));
        data->setPayerObjId(resultSet->getString(5));
        data->setIncomeObjId(resultSet->getString(6));
        data->setStartTime(resultSet->getString(7));
        data->setEndTime(resultSet->getString(8));
        data->setAmount(resultSet->getDouble(9));
        data->setUserId(resultSet->getString(10));
        data->setCreateTime(resultSet->getString(11));
        data->setStatusCd(resultSet->getString(12));
        data->setFeeFlag(resultSet->getString(13));
        data->setState(resultSet->getString(14));
        data->setConfigId(resultSet->getString(15));
        data->setPayerObjType(resultSet->getString(16));
        data->setBatchId(resultSet->getString(17));
       
        return data;
    }
};
class PtrPayFeeConfigMapper : public Mapper<PtrPay_Fee_ConfigDO>
{
public:
    PtrPay_Fee_ConfigDO mapper(ResultSet* resultSet) const override
    {
        auto data = std::make_shared<Pay_Fee_ConfigDO>();
        data->setConfigId(resultSet->getString(1));
        data->setBId(resultSet->getString(2));
        data->setCommunityId(resultSet->getString(3));
        data->setFeeTypeCd(resultSet->getString(4));
        data->setSquarePrice(resultSet->getDouble(5));
        data->setAdditionalAmount(resultSet->getDouble(6));
        data->setCreateTime(resultSet->getString(7));
        data->setStatusCd(resultSet->getString(8));
        data->setIsDefault(resultSet->getString(9));
        data->setStartTime(resultSet->getString(10));
        data->setEndTime(resultSet->getString(11));
        data->setFeeFlag(resultSet->getString(12));
        data->setFeeName(resultSet->getString(13));
        data->setComputingFormula(resultSet->getString(14));
        data->setBillType(resultSet->getString(15));
        data->setPaymentCycle(resultSet->getString(16));
        data->setPaymentCd(resultSet->getString(17));
        data->setComputingFormulaText(resultSet->getString(18));
        data->setDeductFrom(resultSet->getString(19));
        data->setPayOnline(resultSet->getString(20));
        data->setScale(resultSet->getString(21));
        data->setDecimalPlace(resultSet->getInt(22));
        data->setUnits(resultSet->getString(23));
        data->setPrepaymentPeriod(resultSet->getString(24));
        return data;
    }
};
class PtrBusinessPayFeeMapper : public Mapper<PtrBusiness_Pay_FeeDO>
{
public:
    PtrBusiness_Pay_FeeDO mapper(ResultSet* resultSet) const override
    {
        auto data = std::make_shared<Business_Pay_FeeDO>();
        data->setFeeId(resultSet->getString(1));
        data->setBId(resultSet->getString(2));
        data->setFeeTypeCd(resultSet->getString(3));
        data->setCommunityId(resultSet->getString(4));
        data->setPayerObjId(resultSet->getString(5));
        data->setIncomeObjId(resultSet->getString(6));
        data->setStartTime(resultSet->getString(7));
        data->setEndTime(resultSet->getString(8));
        data->setAmount(resultSet->getDouble(9));
        data->setUserId(resultSet->getString(10));
        data->setCreateTime(resultSet->getString(11));
        data->setOperate(resultSet->getString(12));
        data->setFeeFlag(resultSet->getString(13));
        data->setState(resultSet->getString(14));
        data->setConfigId(resultSet->getString(15));
        data->setPayerObjType(resultSet->getString(16));
        data->setBatchId(resultSet->getString(17));
        return data;
    }
};
class PtrBusinessPayFeeConfigMapper : public Mapper<PtrBusiness_Pay_Fee_ConfigDO>
{
public:
    PtrBusiness_Pay_Fee_ConfigDO mapper(ResultSet* resultSet) const override
    {
        auto data = std::make_shared<Business_Pay_Fee_ConfigDO>();
        data->setConfigId(resultSet->getString(1));
        data->setBId(resultSet->getString(2));
        data->setCommunityId(resultSet->getString(3));
        data->setFeeTypeCd(resultSet->getString(4));
        data->setSquarePrice(resultSet->getDouble(5));
        data->setAdditionalAmount(resultSet->getDouble(6));
        data->setCreateTime(resultSet->getString(7));
        data->setOperate(resultSet->getString(8));
        data->setIsDefault(resultSet->getString(9));
        data->setStartTime(resultSet->getString(10));
        data->setEndTime(resultSet->getString(11));
        data->setFeeFlag(resultSet->getString(12));
        data->setFeeName(resultSet->getString(13));
        data->setComputingFormula(resultSet->getString(14));
        data->setBillType(resultSet->getString(15));
        data->setPaymentCycle(resultSet->getString(16));
        data->setPaymentCd(resultSet->getString(17));
        data->setComputingFormulaText(resultSet->getString(18));
        data->setDeductFrom(resultSet->getString(19));
        data->setUnits(resultSet->getString(20));
        data->setDecimalPlace(resultSet->getInt(21));
        data->setScale(resultSet->getString(22));
        data->setPayOnline(resultSet->getString(23));
        data->setPrepaymentPeriod(resultSet->getString(24));
        return data;
    }
};
class PtrReportOweFeeMapper : public Mapper<PtrReport_Owe_FeeDO>
{
public:
    PtrReport_Owe_FeeDO mapper(ResultSet* resultSet) const override
    {
        auto data = std::make_shared<Report_Owe_FeeDO>();
        data->setOweId(resultSet->getString(1));
        data->setConfigId(resultSet->getString(2));
        data->setConfigName(resultSet->getString(3));
        data->setFeeId(resultSet->getString(4));
        data->setFeeName(resultSet->getString(5));
        data->setAmountOwed(resultSet->getDouble(6));
        data->setOwnerId(resultSet->getString(7));
        data->setOwnerName(resultSet->getString(8));
        data->setOwnerTel(resultSet->getString(9));
        data->setPayerObjId(resultSet->getString(10));
        data->setPayerObjName(resultSet->getString(11));
        data->setPayerObjType(resultSet->getString(12));
        data->setCommunityId(resultSet->getString(13));
        data->setCreateTime(resultSet->getString(14));
        data->setUpdateTime(resultSet->getString(15));
        data->setEndTime(resultSet->getString(16));
        data->setDeadlineTime(resultSet->getString(17));
        return data;
    }
};
#endif //