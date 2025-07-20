#pragma once
#ifndef _CLASSIFICATIONTABLE_SERVICE_H_
#define _CLASSIFICATIONTABLE_SERVICE_H_
#include <list>
#include "../../comm-c7-repomanage/domain/dto/repair_report/ClassificationTableDTO.h"
#include "../../comm-c7-repomanage/domain/do/repair_report/ClassificationTableDO.h"
#include "../../comm-c7-repomanage/domain/query/repair_report/ClassificationTableQuery.h"
#include "../../comm-c7-repomanage/domain/vo/repair_report/ClassificationTableVO.h"

class ClassificationTableService {
public:
	ClassificationTableListPageDTO::Wrapper listAll(const ClassificationTableQuery::Wrapper& query);
	std::list<ClassificationTableDO> listAllExport();
};
#endif // !_CLASSIFICATIONTABLE_SERVICE_H_
