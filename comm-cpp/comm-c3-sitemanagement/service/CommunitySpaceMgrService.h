#pragma once

#include "domain/vo/CommunitySpaceMgrVO.h"
#include "domain/query/CommunitySpaceMgrQuery.h"
#include "domain/dto/CommunitySpaceMgrDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class CommunitySpaceMgrService
{
public:
	// 分页查询所有数据
	CommunitySpaceMgrPageDTO::Wrapper listAll(const CommunitySpaceMgrPageQuery::Wrapper& query);
	CommunitySpaceTimeMgrPageDTO::Wrapper listTime(const CommunitySpaceTimeMgrPageQuery::Wrapper& query);
	// 通过ID查询单个数据
	//CommunitySpaceTimeMgrPageDTO::Wrapper getTimeById(std::string id);
	// 修改数据
	bool updateTimeData(const CommunitySpaceTimeMgrDTO::Wrapper& dto);
	
};



