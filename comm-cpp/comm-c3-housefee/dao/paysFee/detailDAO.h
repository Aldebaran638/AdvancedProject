#pragma once
#ifndef _DETAIL_DAO
#define _DETAIL_DAO
#include "BaseDAO.h"
#include "../../domain/do/dos/detailDO.h"
#include "../../domain/query/querys/detailQuery.h"

class detailDAO :public BaseDAO {
private:
	inline std::string queryConditionBuilder(const detailQuery::Wrapper& query, SqlParams& params);
public:
	PtrdetailDO selectById(std::string id);
	
};


#endif