#include "stdafx.h"
#include "OwnerDAO.h"
#include "OwnerMapper.h"
#include <sstream>

std::string OwnerDAO::queryConditionBuilder(const OwnerListQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";

    if (query->room_num) {
        sqlCondition << " AND `room_num`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->room_num.getValue(""));
    }
    if (query->name) {
        sqlCondition << " AND `name`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
    }
    
    return sqlCondition.str();
}

uint64_t OwnerDAO::count(const OwnerListQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql = "SELECT COUNT(*) FROM building_owner";
    sql += queryConditionBuilder(query, params);
    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<OwnerDO> OwnerDAO::selectWithPage(const OwnerListQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql = "SELECT name,sex,link,id_card,create_by,remark,address,owner_id FROM building_owner ";
    sql += queryConditionBuilder(query, params);
    sql += " ORDER BY create_time DESC,owner_id DESC ";
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    OwnerMapper mapper;
    return sqlSession->executeQuery<OwnerDO>(sql, mapper, params);
}

/*PtrOwnerDO OwnerDAO::selectById(std::string id)
{
    std::string sql = "SELECT member_id, owner_id, b_id, name, sex, age, link, user_id, remark, create_time, status_cd, owner_type_cd, community_id, id_card, state, owner_flag, address FROM building_owner WHERE `owner_id`=?";
    PtrOwnerMapper mapper;
    return sqlSession->executeQueryOne<PtrOwnerDO>(sql, mapper, "%s", id);
}*/

int OwnerDAO::insert(const OwnerDO& iObj)
{
    std::string sql = "INSERT INTO `building_owner` (`member_id`, `owner_id`, `b_id`, `name`, `sex`, `age`, `link`, `user_id`, `remark`, `create_time`, `status_cd`, `owner_type_cd`, `community_id`, `id_card`, `state`, `owner_flag`, `address`,`create_by`,`room_num`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,?,?)";
    return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
        iObj.getMemberId(), iObj.getOwnerId(), iObj.getBId(),
        iObj.getName(), iObj.getSex(), iObj.getAge(), iObj.getLink(),
        iObj.getUserId(), iObj.getRemark(), iObj.getCreateTime(),
        iObj.getStatusCd(), iObj.getOwnerTypeCd(), iObj.getCommunityId(),
        iObj.getIdCard(), iObj.getState(), iObj.getOwnerFlag(),
        iObj.getAddress(),iObj.getCreateBy(), iObj.getRoomNum());
}

int OwnerDAO::update(const OwnerDO& uObj)
{
    std::string sql = "UPDATE `building_owner` SET `name`=?, `sex`=?, `link`=?, `remark`=? ,`id_card`=?, `address`=? WHERE `owner_id`=?";
    return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s",
        uObj.getName(), uObj.getSex(), uObj.getLink(),
        uObj.getRemark(), uObj.getIdCard(), uObj.getAddress(),
        uObj.getOwnerId()
        );
}

int OwnerDAO::deleteById(std::string id)
{
    std::string sql = "DELETE FROM `building_owner` WHERE `owner_id`=?";
    return sqlSession->executeUpdate(sql, "%s", id);
}