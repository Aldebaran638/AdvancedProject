#pragma once
#ifndef _BUREFUNDDAO_H_
#define _BUREFUNDDAO_H_
#include "../../domain/do/refund_reviews/BuRefundDO.h"
#include "BaseDAO.h"
#include <list>
class BuRefundDAO : BaseDAO
{
public:
	std::list<BuRefundDO> getAll();
};
#endif // !_BUREFUNDDAO_H_
