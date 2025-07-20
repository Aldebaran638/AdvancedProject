#pragma once
#include "domain/vo/vos/RemitFeeVO.h"
#include "domain/query/querys/RemitFeeQuery.h"
#include "domain/dto/dtos/RemitFeeDTO.h"

class RemitFeeService {
public:
	//分页查询所有数据
	RemitFeePageDTO::Wrapper listAll(const RemitFeeQuery::Wrapper& query);
	

};