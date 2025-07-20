#include "stdafx.h"
#include "FloorService.h"
#include "../../dao/floor/FloorDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "domain/do/floor/FloorDO.h"


//分页查询数据
FloorPageDTO::Wrapper FloorService::listAll(const FloorQuery::Wrapper& query) {
	//构建返回对象
	auto pages = FloorPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	FloorDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<FloorDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (FloorDO sub : result)
	{
		auto dto = FloorDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, floor_id, Floor_id, b_id, B_id, floor_num, Floor_num, name, Name, user_id, User_id, remark, Remark, community_id, Community_id);
		pages->addData(dto);
	}
	return pages;
}

FloorDTO::Wrapper FloorService::getById(std::string floor_id) {
	//查询数据
	FloorDAO dao;
	auto res = dao.selectById(floor_id);

	//没有查询到数据
	if (!res) {
		return nullptr;
	}

	//查询到数据转换成DTO
	auto dto = FloorDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, floor_id, Floor_id, b_id, B_id, floor_num, Floor_num, name, Name, user_id, User_id, remark, Remark, community_id, Community_id);
	return dto;

}


std::string FloorService::saveData(const FloorAddDTO::Wrapper& dto)
{
	// 组装DO数据
	FloorDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, B_id, b_id, Floor_num, floor_num, Name, name, User_id, user_id, Remark, remark,Create_time,create_time, Community_id, community_id, Status_cd, status_cd, Floor_area,floor_area,Seq,seq);
	// 生成ID
	UuidFacade uf;
	std::string uuid = uf.genUuid();
	if (uuid.size() > 30) {
		uuid = uuid.substr(0, 30);
	}
	data.setFloor_id(uuid);
	// 设置创建时间
	//data.setCreate_time(SimpleDateTimeFormat::format());
	data.setCreate_time(SimpleDateTimeFormat::format("%Y-%m-%d %H:%M:%S"));
	// 执行数据添加
	FloorDAO dao;
	return dao.insert(data) == 1 ? data.getFloor_id() : "";
}

// 修改数据
bool FloorService::updateData(const FloorDTO::Wrapper& dto) {
	//组装DO数据
	FloorDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Floor_id, floor_id, B_id, b_id, Floor_num, floor_num, Name, name, User_id, user_id, Remark, remark, Create_time, create_time, Community_id, community_id, Status_cd, status_cd, Floor_area, floor_area, Seq, seq);
	//执行数据修改
	FloorDAO dao;
	return dao.update(data) == 1;


}