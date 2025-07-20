#include "stdafx.h"
#include "CommunitySpaceMgrService.h"
#include "../dao/CommunitySpaceMgrDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

CommunitySpaceMgrPageDTO::Wrapper CommunitySpaceMgrService::listAll(const CommunitySpaceMgrPageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = CommunitySpaceMgrPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	CommunitySpaceMgrDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<CommunitySpaceMgrDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (CommunitySpaceMgrDO sub : result)
	{
		auto dto = CommunitySpaceMgrDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, space_id, Space_Id, name, Name, start_time, Start_Time, end_time, End_Time,
			fee_money, Fee_Money, admin_name, Admin_Name, tel, Tel, state, State);
			//b_id, B_Id, community_id, Community_Id, , status_cd, Status_Cd, venue_id, Venue_Id);
		pages->addData(dto);
	}
	return pages;
}

CommunitySpaceTimeMgrPageDTO::Wrapper CommunitySpaceMgrService::listTime(const CommunitySpaceTimeMgrPageQuery::Wrapper& query) {
	auto pages = CommunitySpaceTimeMgrPageDTO::createShared();
	//pages->pageIndex = query->pageIndex;
	//pages->pageSize = query->pageSize;

	// 查询数据总条数
	CommunitySpaceMgrDAO dao;
	uint64_t count = dao.countTime(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<CommunitySpaceTimeMgrDO> result = dao.selectTimeWithPage(query);
	// 将DO转换成DTO
	for (CommunitySpaceTimeMgrDO sub : result)
	{
		auto dto = CommunitySpaceTimeMgrDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, space_id, Space_Id, hours, Hours, is_open, Is_Open, time_id , Time_Id);
			//, space_id, Space_Id, b_id, B_Id,status_cd, Status_Cd, community_id, Community_Id);
		pages->addData(dto);
	}
	return pages;
}

bool CommunitySpaceMgrService::updateTimeData(const CommunitySpaceTimeMgrDTO::Wrapper& dto)
{
	// 组装DO数据
	CommunitySpaceTimeMgrDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Space_Id, space_id, Hours, hours, Is_Open, is_open);
	// 设置修改人
	//data.setUpdateBy(dto->getPayload()->getUsername());
	// 设置修改时间
	data.setCreate_Time(SimpleDateTimeFormat::format());
	// 执行数据修改
	CommunitySpaceMgrDAO dao;
	return dao.update(data) == 1;
}


//CommunitySpaceTimeMgrPageDTO::Wrapper getTimeById(std::string id) {
//	// 查询数据
//	CommunitySpaceMgrDAO dao;
//	auto res = dao.selectTimeById(id);
//
//	// 没有查询到数据
//	if (!res)
//		return nullptr;
//
//	// 查询到数据转换成DTO
//	auto dto = SampleDTO::createShared();
//	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, id, Id, name, Name, sex, Sex, age, Age);
//	return dto;
//}
//SampleDTO::Wrapper SampleService::getById(std::string id)
//{
//	// 查询数据
//	SampleDAO dao;
//	auto res = dao.selectById(id);
//
//	// 没有查询到数据
//	if (!res)
//		return nullptr;
//
//	// 查询到数据转换成DTO
//	auto dto = SampleDTO::createShared();
//	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, id, Id, name, Name, sex, Sex, age, Age);
//	return dto;
//}