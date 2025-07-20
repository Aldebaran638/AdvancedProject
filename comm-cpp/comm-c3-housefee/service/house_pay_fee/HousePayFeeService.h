#pragma once
#pragma once
#ifndef  _HOUSE_PAY_FEE_SERVICES_H_
#define _HOUSE_PAY_FEE_SERVICES_H_
#include "ApiHelper.h"

#include  "../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../../domain/GlobalInclude.h"
#include "../../domain/dto/HouseFeeDTO.h"

class HousePayFeeService
{
public:

	Int32JsonVO::Wrapper addHousePayFee(const AddHouseFeeDTO::Wrapper& houseFee, const std::shared_ptr<PayloadDTO> payload);
	int  checkDateRange(const std::string& date1, const std::string& date2);
	
	//删除pay_fee和pay_fee_batch的数据
	Int32JsonVO::Wrapper removeHousePayFee(const HouseFeeIdDTO::Wrapper& delInfo);

	Int32JsonVO::Wrapper modifyHousePayFee(const ModifyHouseFeeDTO::Wrapper& modifyInfo);

	Int32JsonVO::Wrapper payHouseFee(const PayFeeDTO::Wrapper& pay, const std::shared_ptr<PayloadDTO> payload);
};

#endif// ! _HOUSE_PAY_FEE_SERVICES_H_
