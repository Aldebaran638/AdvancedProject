#include "stdafx.h"
#include "RainDisTypesService.h"
#include "../../dao/discount_types/RainDisTypesDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

RainDisTypesPageDTO::Wrapper RainDisTypesService::listAll(const RainDisTypesQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = RainDisTypesPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	RainDisTypesDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<RainDisTypesDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (RainDisTypesDO sub : result)
	{
		auto dto = RainDisTypesDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, apply_type, ApplyType, type_name, TypeName, type_desc, TypeDesc);
		pages->addData(dto);
	}


	return pages;
}


RainDisTypesPageDTO::Wrapper RainDisTypesService::getByTypeName(std::string name)
{
	// 构建返回对象
	auto pages = RainDisTypesPageDTO::createShared();

	RainDisTypesDAO dao;
	list<RainDisTypesDO> result = dao.selectByName(name);
	// 将DO转换成DTO
	for (RainDisTypesDO sub : result)
	{
		auto dto = RainDisTypesDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, apply_type, ApplyType, type_name, TypeName, type_desc, TypeDesc);
		pages->addData(dto);
	}


	return pages;
}


std::string RainDisTypesService::saveData(const RainDisTypesAddDTO::Wrapper& dto)
{
	// 组装DO数据
	RainDisTypesDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, TypeName, type_name, TypeDesc, type_desc);
	// 生成ID
	UuidFacade uf;
	data.setApplyType(uf.genUuid().substr(0, 30));
	// 设置创建时间
	data.setCreateTime(SimpleDateTimeFormat::format());
	// 执行数据添加
	RainDisTypesDAO dao;
	return dao.insert(data) == 1 ? data.getApplyType() : "";
}