#include "stdafx.h"
#include "SpaceDAO.h"
#include "SpaceMapper.h"
#include <sstream>

// 添加场地信息
int SpaceDAO::insert(const SpaceDO& iObj)
{
	string sql = "INSERT INTO `community_space` (`space_id`, `name`, `start_time`, `end_time`\
												, `fee_money`, `admin_name`, `tel`,`community_id`\
												,`state`,`create_time`,`status_cd`,`venue_id`)\
												 VALUES(? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? )";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%d%s%s%s%s%s%s%s", iObj.getSpaceId(), iObj.getName(), iObj.getStartTime(), iObj.getEndTime()
		, iObj.getFeeMoney(), iObj.getAdminName(), iObj.getTel(), iObj.getCommunityId()
		, iObj.getState(), iObj.getCreateTime(), iObj.getStatusCd(), iObj.getVenueId());

}

// 修改场地信息
int SpaceDAO::update(const SpaceDO& uObj)
{
	string sql = "UPDATE `community_space` SET `name`=?, `fee_money`=?, `admin_name`=?, `tel`=?, `state`=? WHERE `space_id`=?";
	return sqlSession->executeUpdate(sql, "%s%d%s%s%s%s", uObj.getName(),uObj.getFeeMoney(), uObj.getAdminName(), uObj.getTel()
												, uObj.getState(), uObj.getSpaceId());
}

// 删除场地信息
int SpaceDAO::deleteById(std::string spaceId)
{
	string sql = "DELETE FROM `community_space` WHERE `space_id`=?";
	return sqlSession->executeUpdate(sql, "%s", spaceId);
}