#pragma once
#ifndef _CAR_QUERY_
#define _CAR_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CarQuery :public PageQuery
{
	DTO_INIT(CarQuery, PageQuery);
	// 车牌号
	DTO_FIELD(String, car_num);
	DTO_FIELD_INFO(car_num) {
		info->description = ZH_WORDS_GETTER("car.field.car_num");
	}
	/*// 车位编号
	DTO_FIELD(String, num);
	DTO_FIELD_INFO(num) {
		info->description = ZH_WORDS_GETTER("car.field.num");
	}
	// 车位状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("car.get.state"));
	API_DTO_FIELD_DEFAULT(String, lease_type, ZH_WORDS_GETTER("car.field.lease_type"));*/
};


#include OATPP_CODEGEN_END(DTO)
#endif
