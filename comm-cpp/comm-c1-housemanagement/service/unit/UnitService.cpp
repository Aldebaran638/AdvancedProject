#include "stdafx.h"
#include "UnitService.h"
#include "../../dao/unit/UnitDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

// 保存单元数据
std::string  UnitService::saveData(const UnitAddDTO::Wrapper& dto) {
	//组装DO数据
	UnitDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, UnitNum, unit_num, LayerCount, layer_count, Lift, lift,
		Remark, remark, UnitArea, unit_area);
	//生成ID
	UuidFacade uf;
	std::string uuid = uf.genUuid();
	if (uuid.size() > 30) {
		uuid = uuid.substr(0, 30);
	}
	data.setUnitId(uuid);
	//生成创建时间
	data.setCreateTime(SimpleDateTimeFormat::format("%Y-%m-%d %H:%M:%S"));
	//对前端没有的数据作初始化处理
	data.setBId("0");
	data.setFloorId("0");
	data.setUserId("0");
	data.setStatusCd("1");		//1表示失效
	//执行DAO层操作，写入数据
	UnitDAO dao;
	return dao.insert(data) == 1 ? data.getUnitId() : "insert failed!";
}

// 修改单元数据
bool UnitService::updateData(const UnitDTO::Wrapper& dto) {
	// 组装DO数据
	UnitDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, UnitId,unit_id,BId, b_id, UnitNum, unit_num, FloorId, floor_id, LayerCount, layer_count, Lift, lift,
		UserId, user_id, Remark, remark, CreateTime,create_time,StatusCd, status_cd, UnitArea, unit_area);
	// 执行数据修改
	UnitDAO dao;
	return dao.update(data) == 1;
}

// 修改全部单元数据
bool UnitService::updateAllData(const UnitDTO::Wrapper& dto) {
	// 组装DO数据
	UnitDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, UnitId, unit_id, BId, b_id, UnitNum, unit_num, FloorId, floor_id, LayerCount, layer_count, Lift, lift,
		UserId, user_id, Remark, remark, CreateTime, create_time, StatusCd, status_cd, UnitArea, unit_area);
	// 执行数据修改
	UnitDAO dao;
	return dao.update_all(data) == 1;
}

// 通过ID删除单元数据
bool UnitService::removeData(const oatpp::List<oatpp::String>& ids) {
	UnitDAO dao;
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

UnitPageDTO::Wrapper UnitService::listUnit(const UnitQuery::Wrapper& query)
{
	auto pages = UnitPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	UnitDAO dao;
	uint64_t count = dao.count(query);
	pages->total = count;
	pages->calcPages();
	list<UnitDO> result = dao.selectUnit(query);
	for (UnitDO sub : result)
	{
		auto dto = UnitDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, unit_num, UnitNum, layer_count, LayerCount, lift, Lift, remark, Remark, unit_area, UnitArea);
		pages->addData(dto);
	}
	return pages;
}

UnitPageDTO::Wrapper UnitService::listCommunityUnit(const UnitQuery::Wrapper& query)
{
	auto pages = UnitPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	UnitDAO dao;
	uint64_t count = dao.countCommunityUnit(query);
	pages->total = count;
	pages->calcPages();
	list<UnitDO> result = dao.selectCommunityUnit(query);
	for (UnitDO sub : result)
	{
		auto dto = UnitDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, unit_num, UnitNum, layer_count, LayerCount, lift, Lift, remark, Remark, unit_area, UnitArea, floor_num, FloorNum);
		pages->addData(dto);
	}
	return pages;
}
