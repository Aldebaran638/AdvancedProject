#include "stdafx.h"
#include "../../service/house_pay_fee/HousePayFeeService.h"
#include "HousePayFeeController.h"



Int32JsonVO::Wrapper HousePayFeeController::execAddHouseFee(const AddHouseFeeDTO::Wrapper& houseFee, const std::shared_ptr<PayloadDTO> payload) {

	HousePayFeeService service;

	
	auto ans = service.addHousePayFee(houseFee, payload);
	if (ans->data == 0)
		ans->message = u8"房屋费用创建失败";
	else
		ans->message = u8"房屋费用创建成功";
	return ans;
}


Int32JsonVO::Wrapper HousePayFeeController::execDelHouseFee(const HouseFeeIdDTO::Wrapper& delInfo, const std::shared_ptr<PayloadDTO> payload)
{
	
	HousePayFeeService service;
	return  service.removeHousePayFee(delInfo);
	//return Int32JsonVO::createShared();
}

Int32JsonVO::Wrapper HousePayFeeController::execModifyHouseFee(const ModifyHouseFeeDTO::Wrapper& modifyInfo, const std::shared_ptr<PayloadDTO> payload)
{
	HousePayFeeService service;
	return service.modifyHousePayFee(modifyInfo);
}

Int32JsonVO::Wrapper HousePayFeeController::execPayFee(const PayFeeDTO::Wrapper& pay, const std::shared_ptr<PayloadDTO> payload)
{
	HousePayFeeService service;
	return service.payHouseFee(pay,payload);
}
