#pragma once

#ifndef _SPACE_DAO_
#define _SPACE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/space/SpaceDO.h"
//#include "../../domain/query/space/SpaceQuery.h"

/**
 * space表数据库操作实现
 */
class SpaceDAO : public BaseDAO
{
private:
	
public:
	// 插入场地数据
	int insert(const SpaceDO& iObj);
	// 修改场地数据
	int update(const SpaceDO& uObj);
	// 通过ID删除场地数据
	int deleteById(std::string spaceId);
};
#endif // !_SPACE_DAO_
