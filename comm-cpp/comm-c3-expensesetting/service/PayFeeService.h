#pragma once 

#ifndef _PAYFEE_SERVICE_
#define _PAYFEE_SERVICE_
#include "domain/vo/PayFeeVO.h"
#include "domain/query/PayFeeQuery.h"
#include "domain/dto/PayFeeDTO.h"

class PayFeeService
{
public:
	// 分页查询所有费用项
	PayFeePageDTO::Wrapper listAll(const PayFeeQuery::Wrapper& query);
	// 通过费用类型查询所有费用项目
	ChargeItemListDTO::Wrapper listChargeItem(std::string community_id, std::string payType);
};




#endif
