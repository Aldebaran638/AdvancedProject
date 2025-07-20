#include "stdafx.h"
#include "OwnerPaymentService.h"
#include "../../../domain/do/owner_payment/OwnerPaymentDO.h"
#include "../../../dao/report_management/owner_payment/OwnerPaymentDAO.h"


OwnerPaymentPageDTO::Wrapper OwnerPaymentService::listOwnerPayment(const OwnerPaymentQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = OwnerPaymentPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// 查询数据总条数
	OwnerPaymentDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
		pages->calcPages();
		list<OwnerPaymentDO> result = dao.selectWithPage(query);
		// 将DO转换成DTO
		for (OwnerPaymentDO sub : result)
		{
			auto dto = OwnerPaymentDetailDTO::createShared(); 
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ownerName, OwnerName, roomName, RoomName, configName, ConfigName,
				 totalAmount, TotalAmount, receivableAmount, ReceivableAmount, receivedAmount, ReceivedAmount);
			dto->pfMonth = [&sub]() -> oatpp::List<oatpp::Float64> {
				auto result = oatpp::List<oatpp::Float64>::createShared();
				//result->push_back(sub.getPfMonth1() ? oatpp::Float64(sub.getPfMonth1()) : oatpp::Float64(0.0f));
				result->push_back(oatpp::Float64(sub.getPfMonth1()));
				result->push_back(oatpp::Float64(sub.getPfMonth2()));
				result->push_back(oatpp::Float64(sub.getPfMonth3()));
				result->push_back(oatpp::Float64(sub.getPfMonth4()));
				result->push_back(oatpp::Float64(sub.getPfMonth5()));
				result->push_back(oatpp::Float64(sub.getPfMonth6()));
				result->push_back(oatpp::Float64(sub.getPfMonth7()));
				result->push_back(oatpp::Float64(sub.getPfMonth8()));
				result->push_back(oatpp::Float64(sub.getPfMonth9()));
				result->push_back(oatpp::Float64(sub.getPfMonth10()));
				result->push_back(oatpp::Float64(sub.getPfMonth11()));
				result->push_back(oatpp::Float64(sub.getPfMonth12()));
				return result;
				}();
			pages->addData(dto);
		}
		return pages;
}

std::list<OwnerPaymentDO> OwnerPaymentService::listAllExport()
{
	OwnerPaymentDAO dao;
	return dao.listAllDO();
}

OwnerPaymentFeeTypeListDTO::Wrapper OwnerPaymentService::listFeeTypeList(const OwnerPaymentListQuery::Wrapper& query)
{
	// 构建返回对象
	auto page = OwnerPaymentFeeTypeListDTO::createShared();
	// 查询数据总条数
	OwnerPaymentDAO dao;

	list<OwnerPaymentDO> result = dao.selectFeeTypeList(query);
	// 将DO转换成DTO
	for (OwnerPaymentDO sub : result)
	{
		auto dto = OwnerPaymentFeeTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,feeTypeName, FeeTypeName, feeTypeCd, FeeTypeCd);
		page->addData(dto);
	}
	return page;
}

OwnerPaymentConfigNameListDTO::Wrapper OwnerPaymentService::listConfigNametList(const OwnerPaymentListQuery::Wrapper& query)
{
	// 构建返回对象
	auto page = OwnerPaymentConfigNameListDTO::createShared();
	// 查询数据总条数
	OwnerPaymentDAO dao;

	list<OwnerPaymentDO> result = dao.selectConfigNametList(query);
	// 将DO转换成DTO
	for (OwnerPaymentDO sub : result)
	{
		auto dto = OwnerPaymentConfigNameDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, configName, ConfigName, configId, ConfigId);
		page->addData(dto);
	}
	return page;
}

