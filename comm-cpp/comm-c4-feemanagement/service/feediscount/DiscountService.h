#ifndef _DISCOUNT_SERVICE_H_
#define _DISCOUNT_SERVICE_H_

#include "domain/vo/feediscount/DiscountVo.h"
#include "domain/query/feediscount/DiscountQuery.h"
#include "domain/dto/feediscount/DiscountDto.h"
#include "dao/feediscount/DiscountDao.h"

class DiscountService {
private:
	DiscountDAO dao;

public:
	string saveData(const DiscountAddDTO::Wrapper& dto, const PayloadDTO& payload);
	int deleteDate(const DiscountDeleteDTO::Wrapper& dto, const PayloadDTO& payload);
	string updateData(const DiscountChangeDTO::Wrapper& dto, const PayloadDTO& payload);
	DiscountPageDTO::Wrapper listAll(const DiscountQuery::Wrapper& query);
};

#endif
