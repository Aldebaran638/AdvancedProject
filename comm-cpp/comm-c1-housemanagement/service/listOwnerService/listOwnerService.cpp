#include "stdafx.h"
#include "listOwnerService.h"
#include "../../dao/selectOwner/selectOwnerDAO.h"


OwnerPageDTO::Wrapper listOwnerService::listAll(const OwnerQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = OwnerPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	selectOwnerDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<OwnerDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (OwnerDO sub : result)
	{
		auto dto = OwnerDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, owner_id,Owner_id,name,Name, file_real_name, File_real_name,sex,Sex,id_card,Id_card,link,Link,address,Address, house_num, House_num, car_number, Car_number, member_num, Member_num, complaint_num, Complaint_num, repair_num, Repair_num, amount_owed, Amount_owed, contract_num, Contract_num, access_control_key, Access_control_key);
		pages->addData(dto);
	}
	return pages;
}