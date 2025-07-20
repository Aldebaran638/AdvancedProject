#pragma once
#ifndef _YYYCDISTYPESSERVICE_
#define _YYYCDISTYPESSERVICE_
#include "domain/vo/discount_types/YyycDisTypesVO.h"
#include "domain/query/discount_types/YyycDisTypesQuery.h"
#include "domain/dto/discount_types/YyycDisTypesDTO.h"

class YyycDisTypesService
{
public:
	// 修改数据
	bool updateData(const YyycDisTypesDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(const oatpp::List<oatpp::String>& ids);
};

#endif
