#pragma once
#ifndef _DETAIL_SERVICE_
#define  _DETAIL_SERVICE_

#include "domain/vo/vos/detailVO.h"
#include "domain/query/querys/detailQuery.h"
#include "domain/dto/dtos/detailDTO.h"

class detailService
{
public:
	detailDTO::Wrapper getById(std::string id);
};
#endif // !_DETAIL_SERVICE_
