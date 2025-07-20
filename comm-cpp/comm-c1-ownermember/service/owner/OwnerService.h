#pragma once
#ifndef _OWNER_SERVICE_
#define _OWNER_SERVICE_
#include "domain/vo/owner/OwnerVO.h"
//#include "domain/query/owner/OwnerQuery.h"
#include "domain/dto/owner/OwnerDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class OwnerService
{
public:
	// 通过ID查询单个数据
	OwnerDTO::Wrapper getById(std::string id);
};

#endif

