#include "stdafx.h"
#include "ApplyDiscountDAO.h"
#include"ApplyDiscountMapper.h"
#include <sstream>

inline std::string ApplyDiscountDAO::queryConditionBuilder(const ApplyDiscountQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->roomName) {

		sqlCondition << " AND `roomName`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->roomName.getValue(""));
	}
	if (query->applyType) {

		sqlCondition << " AND applyType=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->applyType.getValue(""));
	}
	if (query->state) {

		sqlCondition << " AND state=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->state.getValue(0));
	}
	return sqlCondition.str();
}

uint64_t ApplyDiscountDAO::count(const ApplyDiscountQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM sample ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<ApplyDiscountDO> ApplyDiscountDAO::selectWithPage(const ApplyDiscountQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT room_name,discount_id,apply_type,create_user_name,create_user_tel,start_time,end_time,in_use,return_way,return_amount FROM apply_room_discount ard LEFT JOIN fee_discount fd ON ard.ard_id = fd.ard_id";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY IFNULL(`room_name`, `discount_id`) DESC, `discount_name` DESC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	ApplyDiscountMapper mapper;
	return sqlSession->executeQuery<ApplyDiscountDO>(sql, mapper, params);
}

std::list<ApplyDiscountDO> ApplyDiscountDAO::selectByHouseName(const string& name)
{
	string sql = "SELECT room_name,discount_id,apply_type,create_user_name,create_user_tel,start_time,end_time,in_use,return_way,return_amount FROM apply_room_discount ard LEFT JOIN fee_discount fd ON ard.ard_id = fd.ard_id WHERE `name` LIKE CONCAT('%',?,'%')";
	ApplyDiscountMapper mapper;
	return sqlSession->executeQuery<ApplyDiscountDO>(sql, mapper, "%s", name);
}

std::list<ApplyDiscountDO> ApplyDiscountDAO::selectByType(std::string type)
{
	string sql = "SELECT room_name,discount_id,apply_type,create_user_name,create_user_tel,start_time,end_time,in_use,return_way,return_amount FROM apply_room_discount ard LEFT JOIN fee_discount fd ON ard.ard_id = fd.ard_id WHERE `type` = ?";
	ApplyDiscountMapper mapper;
	return sqlSession->executeQuery<ApplyDiscountDO>(sql, mapper, "%s", type);
}

std::list<ApplyDiscountDO> ApplyDiscountDAO::selectByState(std::string state)
{
	string sql = "SELECT room_name,discount_id,apply_type,create_user_name,create_user_tel,start_time,end_time,in_use,return_way,return_amount FROM apply_room_discount ard LEFT JOIN fee_discount fd ON ard.ard_id = fd.ard_id WHERE `state` = ?";
	ApplyDiscountMapper mapper;
	return sqlSession->executeQuery<ApplyDiscountDO>(sql, mapper, "%s", state);
}

int ApplyDiscountDAO::insert(const ApplyDiscountDO& iObj)
{
	string sql = "INSERT INTO `apply_room_discount` (ard_id,room_id,community_id,room_name,apply_type,create_user_name,create_user_tel,start_time,end_time,check_user_id,review_user_id,state,create_remark,check_remark,review_remark,create_time,status_cd,in_use,b_id,fee_id,return_way,return_amount) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s", iObj.getArdId(), iObj.getRoomId(), iObj.getCommunityId(), iObj.getRoomName(), iObj.getApplyType(), iObj.getCreateUserName(), iObj.getCreateUserTel(), iObj.getStartTime(), iObj.getEndTime(), iObj.getCheckUserId(), iObj.getState(), iObj.getCreateRemark(), iObj.getCheckRemark(), iObj.getReviewRemark(), iObj.getCreateTime(), iObj.getStatusCd(), iObj.getInUse(), iObj.getBId(), iObj.getFeeId(), iObj.getReturnAmount(), iObj.getReturnWay());
}

int ApplyDiscountDAO::update(const ApplyDiscountDO& uObj){
	string sql = "UPDATE `apply_room_discount` SET `start_time`=?, `end_time`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s", uObj.getStartTime(), uObj.getEndTime());
}
