#include "stdafx.h"
#include "controller/feediscount/DiscountController.h"
#include "domain/query/feediscount/DiscountQuery.h"
#include "domain/vo/feediscount/DiscountVo.h"
#include "service/feediscount/DiscountService.h"

/*
{
  "discount_name": "111",
  "discount_type": "111",
  "discount_desc": "111",
  "spec_name": [
	"第一条规格名称","第二条规格名称"
  ],
  "spec_value": [
	"第一条规格值","第二条规格值"
  ]
}
*/

StringJsonVO::Wrapper DiscountController::execAddDiscount(const DiscountAddDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto jvo = StringJsonVO::createShared();

	//非空校验
	if (!dto->discount_name || !dto->discount_type || !dto->discount_desc) {
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	DiscountService service;
	string id = service.saveData(dto, payload);

	if (id != "") {
		jvo->success(String(id));
	}
	else {
		jvo->fail(String(id));
	}

	return jvo;
}

StringJsonVO::Wrapper DiscountController::execModifyDiscount(const DiscountChangeDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto jvo = StringJsonVO::createShared();

	//非空校验
	if (!dto->discount_name || !dto->discount_type || !dto->discount_desc) {
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	DiscountService service;
	string id = service.updateData(dto, payload);

	if (id != "") {
		jvo->success(String(id));
	}
	else {
		jvo->fail(String(id));
	}

	return jvo;
}

StringJsonVO::Wrapper DiscountController::execDeleteDiscount(const DiscountDeleteDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto jvo = StringJsonVO::createShared();
	if (!dto->discount_id) {
		jvo->fail(String("need discount_id"));
		return jvo;
	}
	DiscountService ser;
	ser.deleteDate(dto, payload);
	jvo->success(String("delete success"));
	return jvo;
}

DiscountPageJsonVO::Wrapper DiscountController::execQueryDiscount(const DiscountQuery::Wrapper& query) {
	DiscountService ser;
	auto result = ser.listAll(query);
	auto jvo = DiscountPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}