#include "stdafx.h"
#include "OrderDAO.h"
#include "OrderMapper.h"
#include <sstream>

inline std::string OrderDAO::queryConditionBuilder(const OrderQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE cv.community_id=?";
	SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
	if (query->spaceId)
	{
		sqlCondition << " AND cs.space_Id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->spaceId.getValue(""));
	}
	if (query->state)
	{
		sqlCondition << " AND csp.state=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->state.getValue(""));
	}
	if (query->personName)
	{
		sqlCondition << " AND csp.person_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->personName.getValue(""));
	}
	if (query->personTel)
	{
		sqlCondition << " AND csp.person_tel=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->personTel.getValue(""));
	}
	if (query->appointmentTime)
	{
		sqlCondition << " AND csp.appointment_time=? AND cspt.hours=?";
		std::string str = query->appointmentTime.getValue("");
		size_t plus_pos = str.find('+');
		std::string time = str.substr(0, plus_pos);
		size_t percent_pos = str.find('%', plus_pos);
		std::string hours = str.substr(plus_pos + 1, percent_pos - plus_pos - 1);
		SQLPARAMS_PUSH(params, "s", std::string, time);
		SQLPARAMS_PUSH(params, "s", std::string, hours);
	}
	return sqlCondition.str();
}

int OrderDAO::update(const std::string id)
{
	PreparedStatement* pstmt1;
	PreparedStatement* pstmt2;
	sqlSession->beginTransaction();
	try {
		NULL_PTR_CHECK(sqlSession->getConnection(), "connection is null");
		pstmt2 = sqlSession->getConnection()->prepareStatement("UPDATE `community_space_person_time` SET `state`=? WHERE `csp_id`=?");
		pstmt1 = sqlSession->getConnection()->prepareStatement("UPDATE `community_space_person` SET `state`=? WHERE `csp_id`=?");
		pstmt1->setString(1, "CL");
		pstmt1->setString(2, id);
		pstmt1->executeUpdate();
		pstmt2->setString(1, "CL");
		pstmt2->setString(2, id);
		pstmt2->executeUpdate();
		sqlSession->commitTransaction();
		RELEASE_SQL_OBJECT(pstmt1, "releasePreparedStatement");
		RELEASE_SQL_OBJECT(pstmt2, "releasePreparedStatement");
		return 0;
	}
	catch (SQLException e) {
		sqlSession->rollbackTransaction();
		std::cerr << "OrderDAO update error: " << e.what() << std::endl;
		RELEASE_SQL_OBJECT(pstmt1, "releasePreparedStatement");
		RELEASE_SQL_OBJECT(pstmt2, "releasePreparedStatement");
		return -1;
	}
		
}

uint64_t OrderDAO::count(const OrderQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM community_venue cv JOIN community_space cs ON cv.venue_id = cs.venue_id JOIN community_space_person csp ON cs.space_id = csp.space_id LEFT JOIN community_space_person_time cspt ON csp.csp_id = cspt.csp_id";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<OrderDO> OrderDAO::selectWithPage(const OrderQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT cv.name AS venue_name, cs.name AS space_name, csp.csp_id, csp.person_name, csp.person_tel, csp.appointment_time, csp.receivable_amount, csp.received_amount, csp.pay_way, csp.state, csp.create_time, csp.remark, cspt.hours FROM community_venue cv JOIN community_space cs ON cv.venue_id = cs.venue_id JOIN community_space_person csp ON cs.space_id = csp.space_id LEFT JOIN community_space_person_time cspt ON csp.csp_id = cspt.csp_id";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建排序语句
	sql += " ORDER BY csp.create_time DESC, csp.csp_id DESC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	OrderMapper mapper;
	return sqlSession->executeQuery<OrderDO>(sql, mapper, params);
}