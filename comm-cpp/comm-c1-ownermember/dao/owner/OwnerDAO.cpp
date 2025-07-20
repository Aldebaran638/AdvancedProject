
#include "stdafx.h"
#include "OwnerDAO.h"
#include "OwnerMapper.h"
#include <sstream>

PtrOwnerDO OwnerDAO::selectById(std::string id)
{
	string sql = "SELECT `owner_id`,`name`,`sex`,`age`,`id_card`,`link` FROM building_owner WHERE `owner_id`=?";
	PtrOwnerMapper mapper;
	return sqlSession->executeQueryOne<PtrOwnerDO>(sql, mapper, "%s", id);
}
