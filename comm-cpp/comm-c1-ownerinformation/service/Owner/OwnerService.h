#pragma once

#ifndef _OWNER_SERVICE_
#define _OWNER_SERVICE_
#include "domain/vo/owner/OwnerVo.h"
#include "domain/query/owner/OwnerListQuery.h"
#include "domain/dto/owner/OwnerDTO.h"

/**
 * 服务实现
 */
class OwnerService
{
public:
	// 分页查询所有数据
	OwnerPageDTO::Wrapper listAll(const OwnerListQuery::Wrapper& query);
	// 通过ID查询单个数据
	//OwnerDTO::Wrapper getById(std::string id);
	// 保存数据
	std::string saveData(const OwnerAddDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const OwnerDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(const oatpp::List<oatpp::String>& ids);
};

#endif 


