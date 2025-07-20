#pragma once

#ifndef _FEEMGRSERVICE_H_
#define _FEEMGRSERVICE_H_
#include "domain/vo/FeeMgrVO.h"
#include "domain/dto/FeeMgrDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class FeeMgrService
{
public:
	// 通过ID查询单个数据
	FeeMgrDTO::Wrapper getById (std::string id);
	// 保存数据
	std::string saveData(const FeeMgrAddDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(const oatpp::List<oatpp::String>& ids);
};

#endif 