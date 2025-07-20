#include "stdafx.h"
#include "RepairWorkerService.h"
#include "../../dao/repair-worker/RepairWorkerDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "../../../lib-common/include/id/SnowFlake.h"

RepairWorkerPageDTO::Wrapper RepairWorkerService::listAll(const RepairWorkerQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = RepairWorkerPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	RepairWorkerDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<RepairWorkerQueryDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (RepairWorkerQueryDO sub : result)
	{
		auto dto = RepairWorkerQueryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, staff_id ,StaffId ,staff_name, StaffName, repair_type_name, RepairTypeName
			, state, State, state_txt, StateTxt, remark, Remark,create_time,CreateTime);
		pages->addData(dto);
	}
	return pages;
}

bool RepairWorkerService::updateData(const RepairWorkerModifyDTO::Wrapper& dto)
{
	// 组装DO数据
	RepairWorkerModifyDO data;
	data.setStaffId(dto->staff_id.getValue({})); 
	data.setRemark(dto->remark.getValue({})); 
	data.setState(dto->state.getValue({}));
	data.setCommunityId(dto->community_id.getValue({}));
	data.setRepairTypeName(dto->repair_type_name.getValue({}));
	// 执行数据修改
	RepairWorkerDAO dao;
	return dao.update(data) == 1;
}

bool RepairWorkerService::removeData(const oatpp::List<oatpp::String>& ids)
{
	RepairWorkerDAO dao;
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

std::string RepairWorkerService::saveData(const RepairWorkerAddDTO::Wrapper& dto)
{
	// 组装DO数据
	RepairWorkerAddDO data;
	/*ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, OrgName, org_name, StaffName, staff_name,
		RepairTypeName, repair_type_name，CommunityId, community_id);*/
	data.setOrgName(dto->org_name.getValue({}));
	data.setStaffName(dto->staff_name.getValue({}));
	data.setRepairTypeName(dto->repair_type_name.getValue({}));;
	data.setCommunityId(dto->community_id.getValue({}));;
	// 生成ID
	SnowFlake sf(1,1);
	data.setTypeUserId(std::to_string(sf.nextId()));
	// 设置创建时间
	data.setCreateTime(SimpleDateTimeFormat::format());
	// 执行数据添加
	RepairWorkerDAO dao;
	if (dao.isDuplicate(data.getRepairTypeName(), data.getStaffName(), data.getCommunityId(), data.getOrgName())) { // 需要将 orgName 传递给 isDuplicate
		return ""; // 如果重复，直接返回空字符串，表示添加失败或已存在
	}
	return dao.insert(data) == 1 ? data.getTypeUserId() : "";
}