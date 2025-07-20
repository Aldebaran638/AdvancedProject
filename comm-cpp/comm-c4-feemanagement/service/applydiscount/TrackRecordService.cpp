#include "stdafx.h"
#include "TrackRecordService.h"
#include "../../dao/applydiscount/TrackRecordDAO.h"
#include "id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"


TrackRecordDTO::Wrapper TrackRecordService::getById(std::string id) {
	// 查询数据
	TrackRecordDAO dao;
	auto res = dao.getTrackRecordDetailById(id);

	// 没有查询到数据
	if (!res) {
		return nullptr;
	}

	// 查询到数据，转换为DTO对象
	auto dto = TrackRecordDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res,
		ardr_id, ArdrId, room_name, RoomName, create_user_name, CreateUserName, 
		create_time, CreateTime, state, State, is_true, IsTrue, remark, Remark); // 等效于 dto->ardr_id = res->getArdrId(); ……
	return dto;
}

std::string TrackRecordService::saveData(const TrackRecordADDDTO::Wrapper& dto) {
	// 组装DO数据
	TrackRecordDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RoomName, room_name, State, state, IsTrue, is_true, Remark, remark);

	// 生成雪花ID
	SnowFlake sf(1, 1);
	data.setArdrId(std::to_string(sf.nextId()));
	// 创建人
	data.setCreateUserName(dto->getPayload()->getUsername());
	data.setArdId(dto->getPayload()->getId());
	
	// 执行数据添加
	TrackRecordDAO dao;
	return dao.insert(data) == 1 ? data.getArdrId() : "";
}

bool TrackRecordService::deleteData(const oatpp::List<oatpp::String>& ids) {
	TrackRecordDAO dao;
	// 开启事务
	dao.getSqlSession()->beginTransaction();
	// 循环删除
	int row = 0;
	for (auto one : *ids.get()) {
		row += dao.deleteTrackRecordById(one.getValue({}));
	}
	// 判断是否全部删除成功
	if (row == ids->size()) {
		// 提交事务
		dao.getSqlSession()->commitTransaction();
		return true;
	}
	// 回滚事务
	dao.getSqlSession()->rollbackTransaction();
	return false;
}


// 通过ID删除数据
int TrackRecordService::removeData(const TrackRecordDeleteDTO::Wrapper& dto, const PayloadDTO& payload) {
	TrackRecordDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ArdrId, ardr_id);
	TrackRecordDAO dao;
	return dao.deleteTrackRecordById(data);
}
