#pragma once
#ifndef _CARPAYMENTSERVICE_H_
#define _CARPAYMENTSERVICE_H_
#include "../../domain/vo/carpayment/CarPaymentVO.h"
#include "../../domain/query/carpayment/CarPaymentQuery.h"
#include "../../domain/dto/carpayment/CarPaymentDTO.h"
class CarPaymentService
{
public:
	// 分页查询所有数据
	CarPaymentPageDTO::Wrapper listAll(const CarPaymentQuery::Wrapper& query);
	// 通过ID查询数据
	CarPaymentPageDTO::Wrapper getById(const CarPaymentQuery::Wrapper& query);
	// 保存数据
	std::string saveData(const CarPaymentDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const CarPaymentDTO::Wrapper& dto);
	// 通过ID删除数据
	//bool removeData(const CarPaymentDTO::Wrapper& dto);
	// 	// 通过ID删除数据
	//bool removeData(const oatpp::List<oatpp::String>& ids);
	 int removeData(const CarPaymentDeleteDTO::Wrapper& dto, const PayloadDTO& payload);
	// 缴纳费用
	bool payFee(const CarPaymentDTO::Wrapper& dto);
};

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class GetVehicleFeeService
{
public:
	// 通过ID查询单个数据
	GetVehicleFeeDTO::Wrapper getById(std::string id);
};

class GetPaymentRecordsService
{
public:
	// 分页查询所有数据
	GetPaymentRecordsPageDTO::Wrapper listAll(const GetPaymentRecordsQuery::Wrapper& query);
};

class GetPaymentDetailedRecordService
{
public:
	// 通过ID查询单个数据
	GetPaymentDetailedRecordDTO::Wrapper getById(std::string id);
};

class GetFeeModificationRecordsService
{
public:
	// 分页查询所有数据
	GetFeeModificationRecordsPageDTO::Wrapper listAll(const GetFeeModificationRecordsQuery::Wrapper& query);
};
#endif // _CarPayment_SERVICE_
