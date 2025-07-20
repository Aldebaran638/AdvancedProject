#pragma once

#ifndef _CONTRACTPAYDAO_H_
#define _CONTRACTPAYDAO_H_


#include "BaseDAO.h"
#include "../../domain/do/contractpay/ContractpayDO.h"
#include "../../domain/query/contractpay/ContractpayQuery.h"

// contract数据库操作实现
class ContractpayDAO : public BaseDAO {
	inline std::string queryConditionBuilder(const ContractpayQuery::Wrapper& query, SqlParams& params);
	inline std::string queryConditionBuilder(const ContractpayRecordQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const ContractpayQuery::Wrapper& query);
	// 分页查询数据
	std::list<ContractpayDO> selectWithPage(const ContractpayQuery::Wrapper& query);
	// 插入数据
	int insert(const ContractpayDO& iObj);

	//更改合同
	int update(const ContractpayDO& uObj);
	// 通过ID删除数据
	int deleteById(std::string id);
	// 增加缴纳合同费用记录
	int insertcharge(const ContractpayDO& iObj);
	// 统计数据条数
	uint64_t count(const ContractpayRecordQuery::Wrapper& query);
	// 分页查询数据
	std::list<ContractpayDO> selectWithPage(const ContractpayRecordQuery::Wrapper& query);
	//通过id来查询缴纳合同费用详情数据
	// 通过ID查询数据
	PtrContractpayDO selectById(std::string id);
};



#endif // !_CONTRACTPAYDAO_H_
