#pragma once

#ifndef APPLYDISCOUNTSERVICE_H_
#define APPLYDISCOUNTSERVICE_H_


#include "domain/dto/applydiscount/ApplyDiscountDTO.h"
#include "domain/query/applydiscount/ApplyDiscountQuery.h"
#include "domain/vo/applydiscount/ApplyDiscountVO.h"

// 服务实现
class ApplyDiscountService {
public:
	// 分页查询所有数据
	ApplyDiscountPageDTO::Wrapper listAll(const ApplyDiscountQuery::Wrapper& query);
	// 保存数据
	std::string saveData(const ApplyDiscountAddDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const ApplyDiscountDTO::Wrapper& dto);
};


#endif // !TRACKRECORDSERVICE_H_
