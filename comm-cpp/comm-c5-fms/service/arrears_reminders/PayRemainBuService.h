#pragma once
#ifndef _PAYREMAINBUSERVICE_H_
#define _PAYREMAINBUSERVICE_H_
#include "Macros.h"
#include "../../dao/arrears_reminders/PayRemainBuMapper.h"
#include "../../dao/arrears_reminders/PayRemainBuDAO.h"
#include "../../domain/query/arrears_reminders/PayRemainBuQuery.h"
#include "../../domain/dto/arrears_reminders/PayRemainBuDTO.h"
#include "../../domain/dto/arrears_reminders/PayRemainQuBuDTO.h"
#include "../../domain/do/arrears_reminders/PayRemainBuDO.h"
#include <iostream>


class PayRemainBuService
{
public:
	// 分页查询所有数据
	PayRemainQuBuPageDTO::Wrapper listALL(const PayRemainBuQuery::Wrapper& query);
	// 增加数据
	std::string saveData(const PayRemainBuDTO::Wrapper& dto);
};



#endif // !_PAYREMAINBUSERVICE_H_