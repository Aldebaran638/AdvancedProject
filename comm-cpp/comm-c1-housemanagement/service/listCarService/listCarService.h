#pragma once

#ifndef _SELECTCAR_SERVICE_
#define _SELECTCAR_SERVICE_

#include "domain/vo/car/CarVO.h"
#include "domain/query/car/CarQuery.h"
#include "domain/dto/car/CarDTO.h"

class listCarService
{
public:
	// 分页查询所有数据
	CarPageDTO::Wrapper listAll(const CarQuery::Wrapper& query);
};


#endif 


