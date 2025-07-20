#pragma once

#ifndef _CONTRACTPAYSERVICE_H_
#define _CONTRACTPAYSERVICE_H_


#include "../../domain/dto/contractpay/ContractpayDTO.h"
#include "../../domain/query/contractpay/ContractpayQuery.h"

class ContractpayService {
public:
	// 分页查询所有数据
	ContractpayPageDTO::Wrapper listAll(const ContractpayQuery::Wrapper& query);
	// 保存数据
	std::string saveData(const ContractpayAddDTO::Wrapper& dto);

	// 修改合同费用（建账时间，应开始和结束的时间）
	bool updateData(const ChangeContractcostDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(const CancelContractcostDTO::Wrapper& remove, const PayloadDTO& payload);
	// 保存数据
	std::string saveData(const ContractcostChargeDTO::Wrapper& dto);
	//合同缴费分页查询所有数据
	GetContractcostChargeRecordPageDTO::Wrapper listAll(const ContractpayRecordQuery::Wrapper& query);
	//通过id来查询合同缴费纪律详情数据
	ContractcostChargeRecordDTO::Wrapper getById(std::string id);
};


#endif // !CONTRACTPAYSERVICE_H_
