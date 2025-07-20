#include "stdafx.h"
#include "MemberDAO.h"
#include "MemberMapper.h"
#include <sstream>

std::string MemberDAO::queryConditionBuilder(const MemberQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->name) {

		sqlCondition << " AND `name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
	}

	if (query->link) {

		sqlCondition << " AND `link`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->link.getValue(""));
	}
	if (query->id_card) {

		sqlCondition << " AND `id_card`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->id_card.getValue(""));
	}
	if (query->sex) {

		sqlCondition << " AND `sex`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue(""));
	}
	if (query->owner_type_cd) {

		sqlCondition << " AND `owner_type_cd`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->owner_type_cd.getValue(""));
	}
	if (query->address) {

		sqlCondition << " AND `address`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->address.getValue(""));
	}
	if (query->remark) {

		sqlCondition << " AND `remark`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->remark.getValue(""));
	}

	return sqlCondition.str();
}

uint64_t MemberDAO::count(const MemberQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM building_owner ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<MemberDO> MemberDAO::selectWithPage(const MemberQuery::Wrapper& query)
{
	SqlParams params; 
	string sql = "SELECT name,link,id_card,sex,owner_type_cd,address,remark FROM building_owner ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY `create_time` DESC, `member_id` DESC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	MemberMapper mapper;
	return sqlSession->executeQuery<MemberDO>(sql, mapper, params);
}

int MemberDAO::insert(const MemberDO& iObj)
{
	//插入的时候，数据库有多少列，就最好写多少。不要偷懒只写DTO的列。
	string sql = "INSERT INTO `building_owner` (`member_id`,`owner_id`,`b_id`,`age`,`user_id`,`status_cd`,`community_id`,`state`,`owner_flag`,`name`,`link`,`id_card`,`sex`,`owner_type_cd`,`address`,`remark`, `create_time`) VALUES (?,?,?,?, ?,?,?,?, ?,?,?,?, ?,?,?,? ,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", iObj.getMember_id(), iObj.getOwner_id(), iObj.getB_id(), iObj.getAge(), iObj.getUser_id(), iObj.getStatus_cd(), iObj.getCommunity_id(), iObj.getState(), iObj.getOwner_flag(), iObj.getName(), iObj.getLink(), iObj.getId_card(), iObj.getSex(), iObj.getOwner_type_cd(), iObj.getAddress(), iObj.getRemark(), iObj.getCreateTime());
}

int MemberDAO::update(const MemberDO& uObj)
{
	string sql = "UPDATE `building_owner` SET `name`=?,`link`=?,`id_card`=?,`sex`=?,`owner_type_cd`=?,`address`=?,`remark`=? WHERE `member_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s", uObj.getName(), uObj.getLink(), uObj.getId_card(), uObj.getSex(), uObj.getOwner_type_cd(), uObj.getAddress(), uObj.getRemark(), uObj.getMember_id());
}

int MemberDAO::deleteById(std::string member_id)
{
	string sql = "DELETE FROM `building_owner` WHERE `member_id`=?";
	return sqlSession->executeUpdate(sql, "%s", member_id);
}