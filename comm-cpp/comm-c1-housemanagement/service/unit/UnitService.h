#pragma once

#ifndef _UNIT_SERVICE_
#define _UNIT_SERVICE_

#include "domain/vo/UnitVO/UnitVO.h"
#include "domain/query/UnitQuery/UnitQuery.h"
#include "domain/dto/UnitDTO/UnitDTO.h"

class UnitService {
public:
	// 保存单元数据
	std::string saveData(const UnitAddDTO::Wrapper& dto);
	// 修改单元数据
	bool updateData(const UnitDTO::Wrapper& dto);
	// 修改全部单元数据
	bool updateAllData(const UnitDTO::Wrapper& dto);
	// 通过ID删除单元数据，支持批量
	bool removeData(const oatpp::List<oatpp::String>& ids);

	UnitPageDTO::Wrapper listUnit(const UnitQuery::Wrapper& query);
	UnitPageDTO::Wrapper listCommunityUnit(const UnitQuery::Wrapper& query);
};

#endif
