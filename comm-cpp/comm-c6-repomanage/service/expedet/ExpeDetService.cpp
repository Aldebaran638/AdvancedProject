#include "stdafx.h"
#include "ExpeDetService.h"
#include "../../dao/expedet/ExpeDetDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"



BuildingExpedetPageDTO::Wrapper ExpedetBuildingFeeDetailService::listAll(const ExpedetBuildingFeeDetailQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = BuildingExpedetPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ExpedetBuildingFeeDetailDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ExpedetBuildingFeeDetailDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ExpedetBuildingFeeDetailDO sub : result)
	{
		auto dto = BuildingExpedetDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, room_name, Room_name, name, Name, qianfei, Qianfei, shishou, Shishou, wuye, Wuye, yajin, Yajin, tingche, Tingche, meiqi, Meiqi);

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, qunuan, Qunuan, weixiu, Weixiu, fuwu, Fuwu, qita, Qita, shuifei, Shuifei, dianfei, Dianfei, zujin, Zujin, gongtan, Gongtan);

		pages->addData(dto);
	}
	return pages;
}


OwnerExpedetPageDTO::Wrapper ExpedetOwnerFeeDetailService::listAll(const ExpedetOwnerFeeDetailQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = OwnerExpedetPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ExpedetOwnerFeeDetailDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ExpedetOwnerFeeDetailDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ExpedetOwnerFeeDetailDO sub : result)
	{
		auto dto = OwnerExpedetDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, room_name, Room_name, qianfei, Qianfei, shishou, Shishou, wuye, Wuye, yajin, Yajin, tingche, Tingche, meiqi, Meiqi);

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, qunuan, Qunuan, weixiu, Weixiu, fuwu, Fuwu, qita, Qita, shuifei, Shuifei, dianfei, Dianfei, zujin, Zujin, gongtan, Gongtan);

		pages->addData(dto);
	}
	return pages;
}

ContractExpedetPageDTO::Wrapper ExpedetContractFeeDetailService::listAll(const ExpedetContractFeeDetailQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ContractExpedetPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ExpedetContractFeeDetailDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ExpedetContractFeeDetailDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ExpedetContractFeeDetailDO sub : result)
	{
		auto dto = ContractExpedetDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, contract_name, Contract_name, name, Name, qianfei, Qianfei, shishou, Shishou, wuye, Wuye, yajin, Yajin, tingche, Tingche, meiqi, Meiqi);

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, qunuan, Qunuan, weixiu, Weixiu, fuwu, Fuwu, qita, Qita, shuifei, Shuifei, dianfei, Dianfei, zujin, Zujin, gongtan, Gongtan);

		pages->addData(dto);
	}
	return pages;
}

CarExpedetPageDTO::Wrapper ExpedetCarFeeDetailService::listAll(const ExpedetCarFeeDetailQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = CarExpedetPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ExpedetCarFeeDetailDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ExpedetCarFeeDetailDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ExpedetCarFeeDetailDO sub : result)
	{
		auto dto = CarExpedetDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, car_num, Car_num, name, Name, qianfei, Qianfei, shishou, Shishou, wuye, Wuye, yajin, Yajin, tingche, Tingche, meiqi, Meiqi);

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, qunuan, Qunuan, weixiu, Weixiu, fuwu, Fuwu, qita, Qita, shuifei, Shuifei, dianfei, Dianfei, zujin, Zujin, gongtan, Gongtan);

		pages->addData(dto);
	}
	return pages;
}
