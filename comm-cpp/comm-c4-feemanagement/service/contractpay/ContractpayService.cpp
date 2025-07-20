#include "stdafx.h"
#include "ContractpayService.h"
#include "../../dao/contractpay/ContractpayDAO.h"
#include "../../domain/do/contractpay/ContractpayDO.h"
#include "id/SnowFlake.h"

ContractpayPageDTO::Wrapper ContractpayService::listAll(const ContractpayQuery::Wrapper& query) {
	// 构建返回对象
	auto pages = ContractpayPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ContractpayDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ContractpayDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ContractpayDO sub : result)
	{
		auto dto = ContractpayDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fee_name, FeeName, fee_flag, FeeFlag, fee_type_cd, FeeTypeCd, additional_amount, AdditionalAmount, 
			create_time, CreateTime, start_time, StartTime, end_time, EndTime, square_price, SquarePrice, state, State);
		pages->addData(dto);
	}
	return pages;
}

std::string ContractpayService::saveData(const ContractpayAddDTO::Wrapper& dto) {
	// 组装DO数据
	ContractpayDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PayerObjId, payer_obj_id, FeeName, fee_name, FeeFlag, fee_flag, FeeTypeCd, fee_type_cd, AdditionalAmount, additional_amount,
		StartTime, start_time, EndTime, end_time, SquarePrice, square_price, State, state);

	// 生成雪花ID
	SnowFlake sf(1, 1);
	data.setFeeId(std::to_string(sf.nextId()));
	// 设置创建人
	data.setUserId(dto->getPayload()->getUsername());

	// 执行数据添加
	ContractpayDAO dao;
	return dao.insert(data) == 1 ? data.getFeeId() : "";
}

//变更合同费用
bool ContractpayService::updateData(const ChangeContractcostDTO::Wrapper& dto)
{
	// 组装DO数据
	ContractpayDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CreateTime, create_time, StartTime, start_time, EndTime, end_time, FeeId, fee_id);
	//// 设置修改人
	//data.setUpdateBy(dto->getPayload()->getUsername());
	//// 设置修改时间
	//data.setUpdateTime(SimpleDateTimeFormat::format());
	// 执行数据修改
	ContractpayDAO dao;
	return dao.update(data) == 1;
}

//通过id来删除合同费用
bool ContractpayService::removeData(const CancelContractcostDTO::Wrapper& remove, const PayloadDTO& payload)
{
	ContractpayDAO dao;
	return dao.deleteById(remove->fee_id);
}

//缴纳合同费用
std::string ContractpayService::saveData(const ContractcostChargeDTO::Wrapper& dto) {
	// 组装DO数据
	ContractpayDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Remark, remark, Received, received, ChargeWay, chargeway, Cycle, chargecycle,Receivable, receivable,CashierName, cashier, FeeId,feeid);

	// 生成雪花ID
	SnowFlake sf(1, 1);
	data.setDetailId(std::to_string(sf.nextId()));
	// 生成雪花ID
	SnowFlake sfpoi(1, 2);
	//std::cout << sfpoi.nextId() << std::endl;
	data.setPayOrderId(std::to_string(sfpoi.nextId()));

	//std::cout << data.getPayOrderId() << std::endl;
	//// 设置创建人
	//data.setUserId(dto->getPayload()->getUsername());

	// 执行数据添加
	ContractpayDAO dao;
	return dao.insertcharge(data) == 1 ? data.getFeeId() : "";
}

//合同缴纳费用记录
GetContractcostChargeRecordPageDTO::Wrapper ContractpayService::listAll(const ContractpayRecordQuery::Wrapper& query) {
	// 构建返回对象
	auto pages = GetContractcostChargeRecordPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ContractpayDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ContractpayDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ContractpayDO sub : result)
	{
		auto dto = ContractcostDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,feeid,FeeId,feeobj,FeeName, chargeobj,ContractName, chargecycle, Cycle, receivable, Receivable, received, Received, chargeway, ChargeWay
		, coststarttime, StartTime, costendtime, EndTime, chargetime, CreateTime, cashier, CashierName, statu, StateCharge, remark, Remark, payer_obj_id, PayerObjId);
		pages->addData(dto);
	}
	return pages;
}
//通过id来查询缴纳合同费用详情
ContractcostChargeRecordDTO::Wrapper ContractpayService::getById(std::string id)
{
	// 查询数据
	ContractpayDAO dao;
	auto res = dao.selectById(id);

	// 没有查询到数据
	if (!res)
		return nullptr;

	// 查询到数据转换成DTO
	auto dto = ContractcostChargeRecordDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, feeid, FeeId);
	return dto;
}