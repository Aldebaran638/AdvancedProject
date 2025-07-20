#pragma once
#ifndef _MODIFY_DTO
#define _MODIFY_DTO
#include "BaseDAO.h"
#include "../../domain/do/dos/modifyDO.h"
#include "../../domain/query/querys/modifyQuery.h"

class modifyDAO :public BaseDAO {
private:
	inline std::string queryConditionBuilder(const modifyQuery::Wrapper& query, SqlParams& params);
public:
	uint64_t count(const modifyQuery::Wrapper& query);
	list<modifyDO> selectById(const modifyQuery::Wrapper& query);
	//std::list<modifyDO> modifyDAO::selectWithPage(const modifyQuery::Wrapper& query);

};

#endif // _MODIFY_DTO
