
#pragma once
#ifndef _CARPAYMENT_DAO_
#define _CARPAYMENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/carpayment/CarPaymentDO.h"
#include "../../domain/query/carpayment/CarPaymentQuery.h"
#include "../../domain/dto/carpayment/CarPaymentDTO.h"
class CarPaymentDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    CarPaymentDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const CarPaymentQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据CarPaymentQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const CarPaymentQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const CarPaymentQuery::Wrapper& query);
	// 分页查询数据
	std::list<Pay_FeeDO> selectWithPage(const CarPaymentQuery::Wrapper& query);
	/*/ 通过ID查询车辆费用数据
	std::list<Pay_FeeDO> selectById(const string& id);
	*/
	// 插入车辆费用数据
	int insert(const Pay_FeeDO& iObj);
	/*
	int insert(const Pay_Fee_ConfigDO& iObj);
	
	int insert(const Business_Pay_FeeDO& iObj);
	int insert(const Business_Pay_Fee_ConfigDO& iObj);
	int insert(const Report_Owe_FeeDO& iObj);
	*/
	// 修改车辆费用数据
	int update(const Pay_FeeDO& uObj);
	/*
	int update(const Pay_Fee_ConfigDO& uObj);
	int update(const Business_Pay_FeeDO& iObj);
	int update(const Business_Pay_Fee_ConfigDO& iObj);
	int update(const Report_Owe_FeeDO& iObj);
	*/
	int update(const PtrReport_Owe_FeeDO& iObj);
	
	// 通过ID删除三个表中的车辆费用数据
	//int deleteByIds(const CarPaymentDTO::Wrapper& dto);
	// 通过ID删除欠费表中的车辆费用数据
	//int deleteOweByIds(const CarPaymentDTO::Wrapper& dto);
	// 缴纳车辆费用
	//int payfee(const Pay_Fee_ConfigDO& uObj);
	int deleteById(std::string id);
	PtrPay_FeeDO queryPayFeeById(const std::string& feeId);
	PtrPay_Fee_ConfigDO queryPayFeeConfigById(const std::string& configId);
	PtrReport_Owe_FeeDO queryOweFeeById(const std::string& oweId);
};
class GetVehicleFeeDAO : public BaseDAO 
{
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
public:
	// 通过缴费ID查询数据
	PtrGetVehicleFeeDO selectById(std::string id);
};

class GetPaymentRecordsDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const GetPaymentRecordsQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const GetPaymentRecordsQuery::Wrapper& query);
	// 分页查询数据
	std::list<GetPaymentRecordsDO> selectWithPage(const GetPaymentRecordsQuery::Wrapper& query);
};

class GetPaymentDetailedRecordDAO : public BaseDAO
{
public:
	// 通过缴费ID查询数据
	PtrGetPaymentDetailedRecordDO selectById(std::string id);
};

class GetFeeModificationRecordsDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const GetFeeModificationRecordsQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const GetFeeModificationRecordsQuery::Wrapper& query);
	// 分页查询数据
	std::list<GetFeeModificationRecordsDO> selectWithPage(const GetFeeModificationRecordsQuery::Wrapper& query);
};
#endif // CARPAYMENT_DAO_H