#pragma once
#ifndef _HOSUE_PAY_FEE_DAO_H_
#define _HOSUE_PAY_FEE_DAO_H_
#include "BaseDAO.h"
#include "HousePayFeeMapper.h"
#include "../../domain/dto/HouseFeeDTO.h"
#include "../../domain/do/house_pay_fee/HousePayFeeDO.h"
#include "../lib-oatpp/include/domain/vo/BaseJsonVO.h"
class HousePayFeeDAO : public BaseDAO
{
public:

	// 增加房屋缴费信息
	HouseInfoDO searchHouseInfo(const std::string & floor_num,const std::string & unit_num,const std::string & room_num,const std::string & community_id);
	FindCommunityDO findCommunityId(const string& config_id);
	DoubleJsonVO::Wrapper calcHouseFee(const CalcHousePayDTO::Wrapper& detail);
	CalcHouseFeeDO getHouseFeeCalcInfo(const std::string& community_id,const std::string& config_id,const std::string& fee_type);
	FeeTypeIdDO getFeeTypeCd(const std::string type);
	DoubleJsonVO::Wrapper calcDiscount(const CalcDiscountDTO::Wrapper& info);
	double calcTimeDiff(const std::string& start_time, const std::string& end_time);
	Int32JsonVO::Wrapper insertHouseFee(const AddPayFeeDO& payFee,const AddPayFeeConfigDO& payFeeConfig);


	// 删除房屋缴费信息
	Int32JsonVO::Wrapper deleteHouseFee(const std::string& id);


	// 修正房屋费用信息

	ModifyFeeInfoDO searchModifyInfo(const std::string& fee_id);
	Int32JsonVO::Wrapper modifyHoueFee(const  ModifyHouseFeeDTO::Wrapper& modifyInfo,const Float64& amount);

	//缴费
	StatusTimeDO searchFeeState(const string& fee_id);
	std::list<DiscountInfoDO> searchFeeDiscount(const string& config_id);
	Int32JsonVO::Wrapper insertPayFee(const  PaymentInfoDO & pay);

};
#endif // !_HOSUE_PAY_FEE_DAO_H_

