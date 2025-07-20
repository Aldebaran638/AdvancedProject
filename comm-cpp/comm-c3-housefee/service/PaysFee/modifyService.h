#pragma once
#include "domain/vo/vos/modifyVO.h"
#include "domain/query/querys/modifyQuery.h"
#include "domain/dto/dtos/modifyDTO.h"

class modifyService {
public:
	modifyPageDTO::Wrapper getById(const modifyQuery::Wrapper &query);
};