#include "stdafx.h"
#include "SpaceService.h"
#include "../../dao/space/SpaceDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "id/SnowFlake.h"

// 添加场地数据
std::string SpaceService::addSpace(const SpaceAddDTO::Wrapper& dto)
{
	// 组装SpaceDO数据
	SpaceDO spaceData;
	ZO_STAR_DOMAIN_DTO_TO_DO(spaceData, dto, Name, name, FeeMoney, feeMoney, AdminName, adminName, Tel, tel, State, state);
	
	// 生成ID
	SnowFlake sf(1, 1);
	std::string newId = std::to_string(sf.nextId());
	spaceData.setSpaceId(newId);
	//设置预约开始时间 TODO
	spaceData.setStartTime("00:00");
	// 设置预约结束时间 TODO
	spaceData.setEndTime("23:59");
	// 设置小区ID TODO
	spaceData.setCommunityId("2023052267100146");
	// 设置创建时间
	spaceData.setCreateTime(SimpleDateTimeFormat::format());
	// 设置数据状态
	spaceData.setStatusCd("0");
	// 设置场馆ID TODO
	spaceData.setVenueId("102024021960463520");

	// 执行数据添加
	SpaceDAO dao;
	return dao.insert(spaceData) == 1 ? spaceData.getSpaceId() : "";
}

// 修改场地
bool SpaceService::updateSpace(const SpaceUpdateDTO::Wrapper& dto)
{
	// 组装SpaceDO数据
	SpaceDO spaceData;
	ZO_STAR_DOMAIN_DTO_TO_DO(spaceData, dto, Name, name, FeeMoney, feeMoney, AdminName, adminName, Tel, tel, State, state, SpaceId, spaceId);
	// 执行数据修改
	SpaceDAO dao;
	return dao.update(spaceData) == 1;
}

// 删除场地
bool SpaceService::removeSpace(const oatpp::List<oatpp::String>& ids)
{
	SpaceDAO dao;
	// 开启事务
	dao.getSqlSession()->beginTransaction();
	// 循环删除
	int rows = 0;
	for (auto one : *ids.get())
	{
		rows += dao.deleteById(one.getValue({}));
	}
	// 判断是否全部删除成功
	if (rows == ids->size()) {
		// 提交事务
		dao.getSqlSession()->commitTransaction();
		return true;
	}
	// 回滚事务
	dao.getSqlSession()->rollbackTransaction();
	return false;
}
