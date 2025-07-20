#include "stdafx.h"
#include "ApplyDiscountService.h"
#include "../../dao/applydiscount/ApplyDiscountDAO.h"
#include "id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"

ApplyDiscountPageDTO::Wrapper ApplyDiscountService::listAll(const ApplyDiscountQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ApplyDiscountPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ApplyDiscountDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ApplyDiscountDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ApplyDiscountDO sub : result)
	{
		auto dto = ApplyDiscountDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, roomName, RoomName, applyType, ApplyType,
			createUserName, CreateUserName,
			startTime, StartTime,
			endTime, EndTime,
			createRemark, CreateRemark,
			roomId, RoomId,
			roomName, RoomName,
			communityId, CommunityId,
			ardId, ArdId,
			discountId, DiscountId,
			checkUserId, CheckUserId,
			reviewUserId, ReviewUserId,
			state, State,
			checkRemark, CheckRemark,
			createTime, CreateTime,
			statusCd, StatusCd,
			inUse, InUse,
			bId, BId,
			feeId, FeeId,
			returnWay, ReturnWay,
			returnAmount, ReturnAmount);
		pages->addData(dto);
	}
	return pages;
}

std::string ApplyDiscountService::saveData(const ApplyDiscountAddDTO::Wrapper& dto)
{
	// 组装DO数据
	ApplyDiscountDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RoomName, roomName,
		ApplyType, applyType,
		CreateUserName, createUserName,
		StartTime, startTime,
		EndTime, endTime,
		CreateRemark, createRemark

	);
	// 生成雪花ID
	SnowFlake sf(1, 1);
	data.setArdId("83" + std::to_string(sf.nextId() % 10000000000000000));
	data.setBId(std::to_string(sf.nextId() % 1000000000000000000));
	data.setCreateTime(SimpleDateTimeFormat::format());
	
	// 设置创建人
	data.setCreateUserName(dto->getPayload()->getUsername());
	// 设置创建时间
	data.setCreateTime(SimpleDateTimeFormat::format());
	// 执行数据添加
	ApplyDiscountDAO dao;
	return dao.insert(data) == 1 ? data.getArdId() : "";
}

bool ApplyDiscountService::updateData(const ApplyDiscountDTO::Wrapper& dto)
{
	// 组装DO数据
	ApplyDiscountDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RoomName, roomName,
		ApplyType, applyType,
		CreateUserName, createUserName,
		StartTime, startTime,
		EndTime, endTime,
		CreateRemark, createRemark,
		RoomId, roomId,
		CommunityId, communityId,
		ArdId, ardId,
		DiscountId, discountId,
		CheckUserId, checkUserId,
		ReviewUserId, reviewUserId,
		State, state,
		CheckRemark, checkRemark,
		CreateTime, createTime,
		StatusCd, statusCd,
		InUse, inUse,
		BId, bId,
		FeeId, feeId,
		ReturnWay, returnWay,
		ReturnAmount, returnAmount

	);

	// 执行数据修改
	ApplyDiscountDAO dao;
	return dao.update(data) == 1;
}
