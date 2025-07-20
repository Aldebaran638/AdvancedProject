#pragma once
#ifndef _HOUSEFEEMGRSERVICE_H_
#define _HOUSEFEEMGRSERVICE_H_
#include "domain/vo/HouseFeeMgrVO.h"
#include "domain/query/HouseFeeMgrQuery.h"
#include "domain/dto/HouseFeeMgrDTO.h"

class HouseFeeMgrService
{
public:
	// 分页查询所有数据
	HouseFeeMgrPageDTO::Wrapper listAll(const HouseFeeMgrQuery::Wrapper& query);
	// 通过ID查询单个数据
	HouseFeeMgrDTO::Wrapper getById(std::string id);
	// 通过房屋号查询单个数据
	HouseFeeMgrPageDTO::Wrapper listByRoomNum(const HouseFeeMgrQueryByRoom::Wrapper& query);
};

#endif // !_HOUSEFEEMGRSERVICE_H_
