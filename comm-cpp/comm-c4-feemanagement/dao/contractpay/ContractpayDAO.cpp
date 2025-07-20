#include "stdafx.h"
#include "ContractpayDAO.h"
#include "ContractpayMapper.h"
#include "tool.h"

inline std::string ContractpayDAO::queryConditionBuilder(const ContractpayQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1 ";
	if (query->payer_obj_id) {
		sqlCondition << "AND payer_obj_id = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->payer_obj_id.getValue(""));
	}
	return sqlCondition.str();
}

inline std::string ContractpayDAO::queryConditionBuilder(const ContractpayRecordQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1 ";
	if (query->payer_obj_id) {
		sqlCondition << "AND payer_obj_id = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->payer_obj_id.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t ContractpayDAO::count(const ContractpayQuery::Wrapper& query) {
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM pay_fee pf JOIN pay_fee_config pfc ON pf.config_id = pfc.config_id AND pf.status_cd = '0' AND pfc.status_cd = '0' ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<ContractpayDO> ContractpayDAO::selectWithPage(const ContractpayQuery::Wrapper& query) {
	SqlParams params;
	string sql = "SELECT pfc.fee_name, pf.fee_flag, pf.fee_type_cd, pfc.additional_amount, pf.create_time, pf.start_time, pf.end_time, pfc.square_price, pf.state FROM pay_fee pf JOIN pay_fee_config pfc ON pf.config_id = pfc.config_id AND pf.status_cd = '0' AND pfc.status_cd = '0' ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句                             
	sql += " ORDER BY pf.create_time DESC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	ContractpayMapper mapper;
	return sqlSession->executeQuery<ContractpayDO>(sql, mapper, params);
}

int ContractpayDAO::insert(const ContractpayDO& iObj) {
	string sql = "INSERT INTO pay_fee (fee_id, b_id, fee_type_cd, community_id, payer_obj_id, income_obj_id, start_time, end_time, amount, user_id, fee_flag, state, config_id, payer_obj_type, batch_id, status_cd) SELECT ? AS fee_id, pfc.b_id, pfc.fee_type_cd, pfc.community_id, ? AS payer_obj_id, ? AS income_obj_id, ? AS start_time, ? AS end_time, ? AS amount, ? AS user_id, pfc.fee_flag, ? AS state, pfc.config_id, ? AS payer_obj_type, ? AS batch_id, ? FROM pay_fee_config pfc WHERE pfc.config_id = (SELECT config_id FROM (SELECT config_id FROM pay_fee WHERE payer_obj_id = ? ORDER BY create_time DESC LIMIT 1) AS subq) ";

	// 便于测试时查看sql是否异常
	std::string formattedSql = formatSql(
		sql,
		"%s%s%s%s%s%d%s%s%s%s%s%s",
		iObj.getFeeId(),
		iObj.getPayerObjId(),
		iObj.getIncomeObjId(),
		iObj.getStartTime(),
		iObj.getEndTime(),
		iObj.getAmount(), 
		iObj.getUserId(),
		iObj.getState(),
		iObj.getPayerObjType(),
		iObj.getBatchId(),
		iObj.getStatusCd(),
		iObj.getPayerObjId()
	);

	return sqlSession->executeUpdate(formattedSql);


}

//通过id来对合同费用进行更改
int ContractpayDAO::update(const ContractpayDO& uObj)
{
	/*string sql = "UPDATE `sample` SET `name`=?, `sex`=?, `age`=?, `update_by`=?, `update_time`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%s%s%s", uObj.getName(), uObj.getSex(), uObj.getAge(), uObj.getUpdateBy(), uObj.getUpdateTime(), uObj.getId());*/
	string sql = "UPDATE `pay_fee` SET `create_time`=?, `start_time`=?, `end_time`=? WHERE `fee_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s", uObj.getCreateTime(), uObj.getStartTime(), uObj.getEndTime(), uObj.getFeeId());
}

//通过id来删除合同费用
// 通过ID删除数据
int ContractpayDAO::deleteById(std::string id)
{
	string sql = "DELETE FROM `pay_fee` WHERE `fee_id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}

//插入缴纳合同费用记录
int ContractpayDAO::insertcharge(const ContractpayDO& iObj) {
	//string sql = "INSERT INTO pay_fee_detail "
	//	"(detail_id, b_id,fee_id, fee_type_cd, community_id, payer_obj_id, income_obj_id, start_time, end_time, amount, user_id, fee_flag, state, config_id, payer_obj_type, batch_id, status_cd) "
	//	"SELECT ? AS fee_id, pfc.b_id, pfc.fee_type_cd, pfc.community_id, ? AS payer_obj_id, ? AS income_obj_id, ? AS start_time, ? AS end_time, ? AS amount, ? AS user_id, pfc.fee_flag, ? AS state, pfc.config_id, ? AS payer_obj_type, ? AS batch_id, ? "
	//	"FROM pay_fee_config pfc WHERE pfc.config_id = (SELECT config_id FROM (SELECT config_id FROM pay_fee_detail WHERE payer_obj_id = ? ORDER BY create_time DESC LIMIT 1) AS subq) ";

	//// 便于测试时查看sql是否异常
	//std::string formattedSql = formatSql(
	//	sql,
	//	"%s%s%s%s%s%f%s%s%s%s%s%s",
	//	iObj.getDetailId().c_str(),
	//	iObj.getFeeId().c_str(),
	//	iObj.getPayerObjId().c_str(),
	//	iObj.getIncomeObjId().c_str(),
	//	iObj.getStartTime().c_str(),
	//	iObj.getEndTime().c_str(),
	//	iObj.getAmount(),
	//	iObj.getUserId().c_str(),
	//	iObj.getState().c_str(),
	//	iObj.getPayerObjType().c_str(),
	//	iObj.getBatchId().c_str(),
	//	iObj.getStatusCd().c_str(),
	//	iObj.getPayerObjId().c_str()
	//);

	//return sqlSession->executeUpdate(formattedSql);

	//需要填入的字段 cycles received_amount prime_rate remark 生成的id detail_id
	string sql = "INSERT INTO pay_fee_detail (detail_id, b_id, fee_id, community_id, cycles, receivable_amount, received_amount, prime_rate, remark, create_time, status_cd, state, start_time, end_time, payable_amount, pay_order_id, cashier_id, cashier_name) SELECT ? AS detail_id,b_id, fee_id,community_id, ? AS cycles,? AS receivable_amount, ? AS received_amount, ? AS prime_rate, ? AS remark, create_time,status_cd , ? AS state,start_time,end_time,? AS payable_amount, ? AS pay_order_id, user_id, ? AS cashier_name FROM pay_fee WHERE fee_id=?";

	//// 便于测试时查看sql是否异常
	//std::string formattedSql = formatSql(
	//	sql,
	//	"%s%s%s%s%s%s",
	//	iObj.getDetailId(),
	//	iObj.getCycle(),
	//	iObj.getReceived(),
	//	iObj.getChargeWay(),
	//	iObj.getRemark(),
	//	iObj.getFeeId()
	//);

	//return sqlSession->executeUpdate(formattedSql);
	/*std::cout << iObj.getDetailId() << std::endl;
	std::cout << iObj.getCycle() << std::endl;
	std::cout << iObj.getReceivable() << std::endl;
	std::cout << iObj.getReceived() << std::endl;
	std::cout << iObj.getChargeWay() << std::endl;
	std::cout << iObj.getRemark() << std::endl;
	std::cout << iObj.getReceivable() << std::endl;
	std::cout << iObj.getPayOrderId() << std::endl;
	std::cout << iObj.getCashierName() << std::endl;
	std::cout << iObj.getFeeId() << std::endl;*/

	return sqlSession->executeUpdate(sql,"%s%s%s%s%s%s%s%s%s%s%s" , iObj.getDetailId(), iObj.getCycle(), iObj.getReceivable(), iObj.getReceived(), iObj.getChargeWay(), iObj.getRemark(),iObj.getStateCharge(), iObj.getReceivable(), iObj.getPayOrderId(), iObj.getCashierName(), iObj.getFeeId());

}

uint64_t ContractpayDAO::count(const ContractpayRecordQuery::Wrapper& query) {
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM pay_fee pf JOIN pay_fee_detail pfd ON pf.fee_id = pfd.fee_id AND pf.state='2009001' AND pfd.status_cd = '0' ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<ContractpayDO> ContractpayDAO::selectWithPage(const ContractpayRecordQuery::Wrapper& query) {
	SqlParams params;
	string sql = "SELECT pf.fee_id,pfc.fee_name,c.contract_name,pfd.cycles,pfd.receivable_amount,pfd.received_amount,pfd.prime_rate,pfd.start_time,pfd.end_time,pfd.create_time,pfd.cashier_name,pfd.status_cd,pfd.remark,pf.payer_obj_id FROM pay_fee pf JOIN pay_fee_config pfc ON pf.config_id = pfc.config_id JOIN pay_fee_detail pfd ON pfd.fee_id = pf.fee_id JOIN contract c ON pf.payer_obj_id=c.contract_id ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句                             
	sql += " ORDER BY pf.create_time DESC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	ContractpayRecordMapper mapper;
	return sqlSession->executeQuery<ContractpayDO>(sql, mapper, params);
}

PtrContractpayDO ContractpayDAO::selectById(std::string id)
{
	string sql = "SELECT config_id FROM pay_fee_config WHERE `id`=?";
	PtrContractpayMapper mapper;
	return sqlSession->executeQueryOne<PtrContractpayDO>(sql, mapper, "%s", id);
}