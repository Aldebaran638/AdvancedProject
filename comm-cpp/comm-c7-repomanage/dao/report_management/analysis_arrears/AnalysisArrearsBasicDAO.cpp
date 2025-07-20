#include "stdafx.h"
#include "AnalysisArrearsBasicDAO.h"
#include "AnalysisArrearsMapper.h"
#include <sstream>

std::string AnalysisArrearsBasicDAO::virtualBasicBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlWith;
	sqlWith << "with basic as ( "
		<< "select f.floor_num fn, t.receivable_amount ra, t.cur_month_time cmt "
		<< "from f_floor f "
		<< "inner join pay_fee_detail_month t "
		<< "inner join building_room br on t.obj_id = br.room_id and br.status_cd = '0' "
		<< "inner join building_unit bu on br.unit_id = bu.unit_id and bu.status_cd = '0' "
		<< "inner join pay_fee pf on t.fee_id = pf.fee_id and pf.status_cd = '0' "
		<< "where 1 = 1 "
		<< "and f.status_cd = '0' "
		<< "and bu.floor_id = f.floor_id "
		<< "and t.community_id = f.community_id "
		<< "and t.detail_id = '-1' ";
	// 构建查询条件
	if (query->feeType) {
		sqlWith << " AND pf.fee_type_cd = ? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->feeType.getValue(""));
	}
	sqlWith << AnalysisArrearsDAO::queryConditionBuilder(query, params);
	sqlWith << ") ";
	return sqlWith.str();
}

std::string AnalysisArrearsBasicDAO::selectBasicBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlCondition;
	string currentTime = AnalysisArrearsDAO::getCurrentTime();
	// TODO: 修正传参

	sqlCondition << "SELECT f.floor_num floor_num, "
		<< "( "
		<< "SELECT ifnull(SUM(ra), 0) "
		<< "FROM basic "
		<< "WHERE cmt <= ? "
		<< "AND fn = f.floor_num "
		<< ") oweAmount, ";
	SQLPARAMS_PUSH(params, "s", std::string, currentTime);

	sqlCondition << "( "
		<< "SELECT ifnull(SUM(ra), 0) "
		<< "FROM basic "
		<< "WHERE cmt <= ? "
		<< "AND cmt >= ? "
		<< "AND fn = f.floor_num "
		<< ") curOweAmount, ";
	SQLPARAMS_PUSH(params, "s", std::string, currentTime);
	// cout << currentTime.substr(0, 4) + "-01-01 00:00:00" << endl;
	SQLPARAMS_PUSH(params, "s", std::string, currentTime.substr(0, 4) + "-01-01 00:00:00");

	sqlCondition << "( "
		<< "SELECT ifnull(SUM(ra), 0) "
		<< "FROM basic "
		<< "WHERE cmt < ? "
		<< "AND fn = f.floor_num "
		<< ") preOweAmount ";
	SQLPARAMS_PUSH(params, "s", std::string, currentTime.substr(0, 4) + "-01-01 00:00:00");

	sqlCondition << "FROM f_floor f ";
	sqlCondition << "WHERE 1 = 1 ";
	sqlCondition << AnalysisArrearsDAO::queryConditionBuilder(query, params);
	return sqlCondition.str();
}

std::list<AnalysisArrearsDO> AnalysisArrearsBasicDAO::selectBasicWithPage(const AnalysisArrearsQuery::Wrapper& query)
{
	SqlParams params;
	// 构建查询未收情况表的临时表
	string sql = virtualBasicBuilder(query, params);
	// 添加查询未收情况表的基本SQL语句
	sql += selectBasicBuilder(query, params);

	// 构建排序语句
	sql += " ORDER BY floor_num DESC";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	AnalysisArrearsBasicMapper mapper;
	cout << sql << endl;
	return sqlSession->executeQuery<AnalysisArrearsDO>(sql, mapper, params);
}

uint64_t AnalysisArrearsBasicDAO::countBasic(const AnalysisArrearsQuery::Wrapper& query)
{
	SqlParams params;
	string sql = virtualBasicBuilder(query, params);
	sql += "SELECT COUNT(DISTINCT fn) FROM basic ";
	// 执行查询
	cout << sql << endl;
	return sqlSession->executeQueryNumerical(sql, params);
}