#pragma once

#ifndef _SPACE_SERVICE_
#define _SPACE_SERVICE_
#include "domain/vo/SpaceVO.h"
#include "domain/dto/SpaceDTO.h"

/**
 * 场地服务实现，添加、修改、删除等功能
 */
class SpaceService
{
public:
	// 添加场地数据
	std::string addSpace(const SpaceAddDTO::Wrapper& dto);
	// 修改数据
	bool updateSpace(const SpaceUpdateDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeSpace(const oatpp::List<oatpp::String>& ids);
};

#endif // !_SPACE_SERVICE_

