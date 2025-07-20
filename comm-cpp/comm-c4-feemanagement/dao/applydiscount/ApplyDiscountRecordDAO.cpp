#include "stdafx.h"
#include "ApplyDiscountRecordDAO.h"
#include "ApplyRoomDiscountMapper.h"
#include "ApplyRoomDiscountRecordMapper.h"
#include "RecordQueryMapper.h"
#include <sstream>
#include "../../domain/query/applydiscount/ApplyDiscountQuery.h"

std::string ApplyDiscountRecordDAO::queryConditionBuilder(const ApplyDiscountRecordQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1 ";
	if (query->ard_id) {
		sqlCondition << "AND `ardr`.ard_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->ard_id.getValue(""));
	}

	return sqlCondition.str();
}

uint64_t ApplyDiscountRecordDAO::count(const ApplyDiscountRecordQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM apply_room_discount_record ardr";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	//cout << sql << endl;
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

//std::list<ApplyRoomDiscountRecordDO> ApplyDiscountRecordDAO::selectWithRecordPage(const ApplyDiscountRecordQuery::Wrapper& query) {
//	SqlParams params;
//	string sql = "SELECT ardr_id,is_true,remark FROM apply_room_discount_record ";
//	// 构建查询条件
//	sql += queryConditionBuilder(query, params);
//	// 构建排序语句
//	sql += " ORDER BY IFNULL(`create_time`) DESC";
//	// 构建分页条件
//	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
//
//	// 执行查询
//	ApplyRoomDiscountRecordMapper mapper;
//	return sqlSession->executeQuery<ApplyRoomDiscountRecordDO>(sql, mapper, params);
//}
//
//std::list<ApplyRoomDiscountDO> ApplyDiscountRecordDAO::selectWithPage(const ApplyDiscountRecordQuery::Wrapper& query)
//{
//	SqlParams params;
//	string sql = "SELECT room_name,create_user_name,create_time,state FROM apply_room_discount ";
//	// 构建查询条件
//	sql += queryConditionBuilder(query, params);
//	// 构建排序语句
//	sql += " ORDER BY IFNULL(`create_time`) DESC";
//	// 构建分页条件
//	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
//
//	// 执行查询
//	ApplyRoomDiscountMapper mapper;
//	return sqlSession->executeQuery<ApplyRoomDiscountDO>(sql, mapper, params);
//}

std::list<RecordQueryDO> ApplyDiscountRecordDAO::selectWithPage(const ApplyDiscountRecordQuery::Wrapper& query) {
	SqlParams params;
	string sql = "SELECT ardr_id,room_name,ardr.create_user_name,ardr.create_time,ardr.state,is_true,remark FROM apply_room_discount ard JOIN apply_room_discount_record ardr ON ard.ard_id=ardr.ard_id ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY IFNULL(`ardr`.create_time,ardr_id) DESC";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	cout << sql << endl;
	// 执行查询
	RecordQueryMapper mapper;
	return sqlSession->executeQuery<RecordQueryDO>(sql, mapper, params);
}

int ApplyDiscountRecordDAO::updateState(const ApplyRoomDiscountDO & uObj)
{
	string sql = "UPDATE `apply_room_discount` SET `state`=? WHERE `ard_id`=?";
	cout << sql << endl;
	cout << uObj.getState() << "	" << uObj.getArd_id() << endl;
	auto res=sqlSession->executeUpdate(sql, "%s%s", uObj.getState(), uObj.getArd_id());
	cout << res << endl;
	return res;
}

int ApplyDiscountRecordDAO::deleteById(std::string id)
{
	string sql = "DELETE FROM `apply_room_discount` WHERE `ard_id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}