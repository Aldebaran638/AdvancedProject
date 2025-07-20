#pragma once
#ifndef _CLASSIFICATIONTABLE_DAO_H_
#define _CLASSIFICATIONTABLE_DAO_H_

#include "BaseDAO.h"
#include "../../../domain/do/repair_report/ClassificationTableDO.h"
#include "../../../domain/query/repair_report/ClassificationTableQuery.h"

class ClassificationTableDAO :public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const ClassificationTableQuery::Wrapper& query, SqlParams& params);
public:
	std::list<ClassificationTableDO> selectWithPage(const ClassificationTableQuery::Wrapper& query);
	std::list<ClassificationTableDO> listAllDO();
	uint64_t count(const ClassificationTableQuery::Wrapper& query);
};
#endif //!_CLASSIFICATIONTABLE_DAO_H_