#include "CommunityVenueDAO.h"
#include "CommunityVenueMapper.h"
#include <sstream>

inline std::string CommunityVenueDAO::queryConditionBuilder(
    const CommunityVenueQuery::Wrapper& query,
    SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    if (query->id) {
        sqlCondition << " AND venue_id = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue(""));
    }
    if (query->name) {
        sqlCondition << " AND name LIKE CONCAT('%',?,'%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
    }
    return sqlCondition.str();
}

uint64_t CommunityVenueDAO::count(const CommunityVenueQuery::Wrapper& query) {
    SqlParams params;
    std::string sql = "SELECT COUNT(*) FROM community_venue";
    sql += queryConditionBuilder(query, params);
    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<CommunityVenueDO> CommunityVenueDAO::selectWithPage(
    const CommunityVenueQuery::Wrapper& query)
{
    SqlParams params;
    std::stringstream ss;
    ss << "SELECT "
        << "venue_id, name, remark, b_id, community_id, create_time, status_cd, start_time, end_time "
        << "FROM community_venue";
    ss << queryConditionBuilder(query, params);
    ss << " ORDER BY IFNULL(update_time, create_time) DESC, venue_id DESC";
    ss << " LIMIT " << ((query->pageIndex - 1) * query->pageSize)
        << ", " << query->pageSize;

    CommunityVenueMapper mapper;
    return sqlSession->executeQuery<CommunityVenueDO>(ss.str(), mapper, params);
}

std::list<CommunityVenueDO> CommunityVenueDAO::selectByName(const std::string& name) {
    std::string sql =
        "SELECT venue_id, name, remark, b_id, community_id, create_time, status_cd, start_time, end_time "
        "FROM community_venue "
        "WHERE name LIKE CONCAT('%',?,'%')";
    CommunityVenueMapper mapper;
    return sqlSession->executeQuery<CommunityVenueDO>(sql, mapper, "%s", name);
}

PtrCommunityVenueDO CommunityVenueDAO::selectById(const std::string& id) {
    std::string sql =
        "SELECT venue_id, name, remark, b_id, community_id, create_time, status_cd, start_time, end_time "
        "FROM community_venue "
        "WHERE venue_id = ?";
    PtrCommunityVenueMapper mapper;
    return sqlSession->executeQueryOne<PtrCommunityVenueDO>(sql, mapper, "%s", id);
}

int CommunityVenueDAO::insert(const CommunityVenueDO& obj) {
    std::string sql =
        "INSERT INTO community_venue "
        "(`venue_id`,`name`,`remark`,`b_id`,`community_id`,`create_time`,`status_cd`,`start_time`,`end_time`) "
        "VALUES(?,?,?,?,?,?,?,?,?)";
    return sqlSession->executeUpdate(
        sql,
        "%s%s%s%s%s%s%s%s%s",
        obj.getVenueId(),
        obj.getName(),
        obj.getRemark(),
        obj.getBId(),
        obj.getCommunityId(),
        //obj.getCreateBy(),
        obj.getCreateTime(),
        obj.getStatusCd(),
        obj.getStartTime(),
        obj.getEndTime()
    );
}

// DAO ²ãÊ¾Àý
int CommunityVenueDAO::update(const CommunityVenueDO& obj) {
    static const char* sql = R"sql(
    UPDATE community_venue SET
      name       = ?,
      remark     = ?,
      start_time = ?,
      end_time   = ?
    WHERE venue_id = ?
  )sql";
    return sqlSession->executeUpdate(
        sql,
        "%s%s%s%s%s",
        obj.getName(),
        obj.getRemark(),
        obj.getStartTime(),
        obj.getEndTime(),
        obj.getVenueId()
    );
}



int CommunityVenueDAO::deleteById(const std::string& id) {
    std::string sql = "DELETE FROM community_venue WHERE venue_id = ?";
    return sqlSession->executeUpdate(sql, "%s", id);
}
