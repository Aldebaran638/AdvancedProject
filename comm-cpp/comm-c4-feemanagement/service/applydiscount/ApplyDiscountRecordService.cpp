#include "stdafx.h"
#include "ApplyDiscountRecordService.h"
#include "../../dao/applydiscount/ApplyDiscountRecordDAO.h"
#include "../../domain/do/applydiscount/RecordQueryDO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

// 分页查询所有数据
ApplyDiscountRecordPageDTO::Wrapper ApplyDiscountRecordService::listRecord(const ApplyDiscountRecordQuery::Wrapper& query) {
	// 构建返回对象
	auto pages = ApplyDiscountRecordPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ApplyDiscountRecordDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	// 将DO转换成DTO
	//list<ApplyRoomDiscountDO> res = dao.selectWithPage(query);
	//for (ApplyRoomDiscountDO sub : res)
	//{
	//	auto dto = ApplyDiscountRecordDTO::createShared();
	//	ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,  room_name, Room_name, create_user_name, Create_user_name, create_time, Create_time, state, State);
	//	pages->addData(dto);
	//}
	//list<ApplyRoomDiscountRecordDO> result = dao.selectWithRecordPage(query);
	//for (ApplyRoomDiscountRecordDO sub : result)
	//{
	//	auto dto = ApplyDiscountRecordDTO::createShared();
	//	ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ardr_id, Ardr_id, is_true, Is_true, remark, Remark);
	//	pages->addData(dto);
	//}
	list<RecordQueryDO> result = dao.selectWithPage(query);
	for (RecordQueryDO sub : result)
	{
		auto dto = ApplyDiscountRecordDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ardr_id, Ardr_id, room_name, Room_name, create_user_name, Create_user_name, create_time, Create_time, state, State, is_true, Is_true, remark, Remark);
		pages->addData(dto);
	}
	return pages;
}

// 修改优惠申请状态
bool ApplyDiscountRecordService::updateState(const ApplyDiscountStateDTO::Wrapper& dto) {
	// 组装DO数据
	ApplyRoomDiscountDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, State,state,Ard_id,ard_id);
	// 执行数据修改
	ApplyDiscountRecordDAO dao;
	return dao.updateState(data) == 1;
}

// 通过ID删除优惠申请项
bool ApplyDiscountRecordService::removeData(const ApplyDiscountDeleteDTO::Wrapper& id, const PayloadDTO& payload) {
	ApplyDiscountRecordDAO dao;
	return dao.deleteById(id->ard_id);
}
