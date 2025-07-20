#include "stdafx.h"
#include "PayFeeService.h"
#include "../dao/PayFeeDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "id/SnowFlake.h"

PayFeePageDTO::Wrapper PayFeeService::listAll(const PayFeeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = PayFeePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	PayFeeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<PayFeeDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (PayFeeDO sub : result)
	{
		auto dto = PayFeeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(
			dto,
			sub,
			config_id,
			Config_id,
			fee_type_cd,
			Fee_type_cd,
			fee_name,
			Fee_name,
			fee_flag,
			Fee_flag,
			payment_cd,
			Payment_cd,
			payment_cycle,
			Payment_cycle,
			//start_time,
			//Start_time,
			//end_time,
			//End_time,
			computing_formula,
			Computing_formula,
			square_price,
			Square_price,
			additional_amount,
			Additional_amount,
			deduct_from,
			Deduct_from
		)
		dto->validDate = sub.getStart_time() + " "  + sub.getEnd_time();
		pages->addData(dto);
	}
	return pages;
}


ChargeItemListDTO::Wrapper PayFeeService::listChargeItem(std::string community_id, std::string payType)
{
	// 构建返回对象
	auto itemLists = ChargeItemListDTO::createShared();
	itemLists->chargeItemList = oatpp::List<oatpp::Object<ChargeItemDTO>>::createShared();
	// 查询数据
	PayFeeDAO dao;
	list<ChargeItemDO> result = dao.selectByType(community_id, payType);

	for (ChargeItemDO sub : result)
	{
		auto dto = ChargeItemDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, config_id, Config_id, fee_type_cd, Fee_type_cd, chargeItem, ChargeItem);
		itemLists->chargeItemList->push_back(dto);
	}
	return itemLists;
}