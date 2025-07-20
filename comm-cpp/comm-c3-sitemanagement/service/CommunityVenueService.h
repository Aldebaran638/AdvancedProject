#pragma once



#ifndef _COMMUNITYVENUESERVICE_
#define _COMMUNITYVENUESERVICE_
#include "domain/vo/communityvenue/CommunityVenueVO.h"
#include "domain/query/communityvenue/CommunityVenueQuery.h"
#include "domain/dto/communityvenue/CommunityVenueModifyDTO.h"

class CommunityVenueService
{
public:
	// 分页查询所有数据
	CommunityVenuePageDTO::Wrapper listAll(const CommunityVenueQuery::Wrapper& query);
	// 通过ID查询单个数据
	CommunityVenueDTO::Wrapper getById(std::string id);
	// 保存数据
	std::string saveData(const CommunityVenueAddDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const CommunityVenueModifyDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(const oatpp::List<oatpp::String>& ids);
};

#endif