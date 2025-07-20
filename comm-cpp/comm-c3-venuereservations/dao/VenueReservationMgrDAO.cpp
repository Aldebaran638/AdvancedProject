#include "stdafx.h"
#include "VenueReservationMgrDAO.h"
#include "VenueReservationMgrMapper.h"
#include "../comm-c3-venuereservations/domain/query/VenueReservationMgrQuery.h"
#include <sstream>

//根据Query构建场地预约列表的查询条件 Where部分
std::string VenueReservationMgrDAO::queryVenueReservationMgrConditionBuilder(const VenueReservationMgrQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
    sqlCondition << " WHERE community_space_person.status_cd = '0'";

    if (query->venueId) {
        sqlCondition << " AND community_venue.venue_id = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->venueId.getValue(""));
    }

    if (query->spaceId) {
        sqlCondition << " AND community_space_person.space_id = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->spaceId.getValue(""));
    }

    if (query->personName) {
        sqlCondition << " AND community_space_person.person_name LIKE CONCAT('%',?,'%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->personName.getValue(""));
    }

    if (query->personTel) {
        sqlCondition << " AND community_space_person.person_tel LIKE CONCAT('%',?,'%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->personTel.getValue(""));
    }

    if (query->reservationStatus) {
        sqlCondition << " AND community_space_person.reservationStatus = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->reservationStatus.getValue(""));
    }

    if (query->appointmentDate) {
        sqlCondition << " AND DATE(community_space_person.appointment_time) = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->appointmentDate.getValue(""));
    }

    return sqlCondition.str();
}

std::list<VenueReservationMgrDO> VenueReservationMgrDAO::selectWithPage(const VenueReservationMgrQuery::Wrapper& query)
{
	SqlParams params;

	// 核心变化：通过 JOIN 联表查询
	string sql =
        "SELECT community_space_person.csp_id, community_space_person.space_id, community_space_person.person_name, community_space_person.person_tel FROM community_space_person" ;
        
    

	// 添加条件
	sql += queryVenueReservationMgrConditionBuilder(query, params);

	// 排序和分页（保持原逻辑）
    sql += " ORDER BY csp.create_time DESC ";
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	VenueReservationMgrMapper mapper;
	return sqlSession->executeQuery<VenueReservationMgrDO>(sql, mapper, params);
}

int VenueReservationMgrDAO::cancelReservation(const string& cspId) {
    string sql = "UPDATE community_space_person SET state = 'C' WHERE csp_id = ?";
    return sqlSession->executeUpdate(sql, "%s", cspId);
}


int VenueReservationMgrDAO::insert(const VenueReservationMgrDO& iObj)
{
    // 组装SQL语句
    // 注意：这里的字段名需要和数据库表中的字段名一致
    // 如果是MySQL数据库，字段名需要加上``
    // 如果是Oracle数据库，字段名需要加上""
    // 如果是SQL Server数据库，字段名需要加上[]

    string sql = "INSERT INTO `community_space_confirm_order` (`order_id`, `csp_id`, `space_id`,`remark`, `status_cd`,`create_time`) VALUES ('132025051652540020',?,?,?,?,?,?)";
    return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s", iObj.getOrderId(), iObj.getVenueId(), iObj.getSpaceId(), iObj.getRemark(),  iObj.getReservationStatus(), iObj.getCreateTime()); 
}

