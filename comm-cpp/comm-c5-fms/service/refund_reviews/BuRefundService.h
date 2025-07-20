#pragma once
#ifndef _BUREFUNDSERVICE_H_
#define _BUREFUNDSERVICE_H_

#include "Macros.h"
#include "../../dao/refund_reviews/BuRefundMapper.h"
#include "../../dao/refund_reviews/BuRefundDAO.h"
#include "../../domain/dto/refund_reviews/BuRefundDTO.h"
#include "../../domain/do/refund_reviews/BuRefundDO.h"
#include <iostream>


class BuRefundService
{
public:
	std::list<BuRefundDTO::Wrapper> getDtoData();
};



#endif // !_BUREFUNDSERVICE_H_