#include "stdafx.h"
#include "AnalysisArrearsDetailDAO.h"
#include "AnalysisArrearsMapper.h"
#include <sstream>

std::string AnalysisArrearsDetailDAO::virtualDetailBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlWith;
	sqlWith << "with detail as ( "
		<< "select f.floor_num fn, t.receivable_amount ra, t.cur_month_time cmt, "
		// added
		<< "br.built_up_area builtUpArea, concat(f.floor_num,'-',bu.unit_num,'-',br.room_num) roomName, "
		<< "rof.fee_name feeName, rof.end_time endTime, rof.deadline_time deadlineTime "

		<< "from f_floor f "
		<< "inner join pay_fee_detail_month t "
		// << "inner join building_room br on t.obj_id = br.room_id and br.status_cd = '0' "
		<< "inner join building_room br on br.status_cd = '0' "
		<< "inner join building_unit bu on br.unit_id = bu.unit_id and bu.status_cd = '0' "
		<< "inner join pay_fee pf on t.fee_id = pf.fee_id and pf.status_cd = '0' "
		// added
		<< "inner join report_owe_fee rof on br.room_id = rof.payer_obj_id "

		<< "where 1 = 1 "
		// added
		<< "and pf.fee_id = rof.fee_id "

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

std::string AnalysisArrearsDetailDAO::selectDetailBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlCondition;
	string currentTime = AnalysisArrearsDAO::getCurrentTime();
	// TODO: 修正传参

	// sqlCondition << "SELECT f.floor_num floor_num, "
	sqlCondition << "SELECT d.fn, d.roomName, d.builtUpArea, d.feeName, d.endTime, d.deadlineTime, "

		<< "( "
		<< "SELECT ifnull(SUM(ra), 0) "
		<< "FROM detail "
		<< "WHERE cmt <= ? "
		<< "AND fn = f.floor_num "
		<< ") oweAmount, ";
	SQLPARAMS_PUSH(params, "s", std::string, currentTime);

	sqlCondition << "( "
		<< "SELECT ifnull(SUM(ra), 0) "
		<< "FROM detail "
		<< "WHERE cmt <= ? "
		<< "AND cmt >= ? "
		<< "AND fn = f.floor_num "
		<< ") curOweAmount, ";
	SQLPARAMS_PUSH(params, "s", std::string, currentTime);
	SQLPARAMS_PUSH(params, "s", std::string, currentTime.substr(0, 4) + "-01-01 00:00:00");

	sqlCondition << "( "
		<< "SELECT ifnull(SUM(ra), 0) "
		<< "FROM detail "
		<< "WHERE cmt < ? "
		<< "AND fn = f.floor_num "
		<< ") preOweAmount ";
	SQLPARAMS_PUSH(params, "s", std::string, currentTime.substr(0, 4) + "-01-01 00:00:00");

	sqlCondition << "FROM detail d "
				 << "INNER JOIN f_floor f "
				 << "ON d.fn = f.floor_num ";
	sqlCondition << "WHERE 1 = 1 ";
	sqlCondition << AnalysisArrearsDAO::queryConditionBuilder(query, params);
	return sqlCondition.str();
}

std::list<AnalysisArrearsDO> AnalysisArrearsDetailDAO::selectDetailWithPage(const AnalysisArrearsQuery::Wrapper& query)
{
	SqlParams params;
	// 构建查询未收情况表的临时表
	string sql = virtualDetailBuilder(query, params);
	// 添加查询未收情况表的基本SQL语句
	sql += selectDetailBuilder(query, params);

	// 构建排序语句
	sql += " ORDER BY f.floor_num DESC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	AnalysisArrearsDetailMapper mapper;
	cout << sql << endl;
	return sqlSession->executeQuery<AnalysisArrearsDO>(sql, mapper, params);
}

uint64_t AnalysisArrearsDetailDAO::countDetail(const AnalysisArrearsQuery::Wrapper& query)
{
	SqlParams params;
	string sql = virtualDetailBuilder(query, params);
	sql += "SELECT COUNT(DISTINCT roomName) FROM detail ";
	// 执行查询
	cout << sql << endl;
	return sqlSession->executeQueryNumerical(sql, params);
}