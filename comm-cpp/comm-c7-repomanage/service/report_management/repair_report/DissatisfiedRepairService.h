#pragma once

#ifndef _DISSATISFIEDREPAIR_SERVICE_H_
#define _DISSATISFIEDREPAIR_SERVICE_H_

#include <list>
#include "../../comm-c7-repomanage/domain/dto/repair_report/DissatisfiedRepairDTO.h"
#include "../../comm-c7-repomanage/domain/do/repair_report/DissatisfiedRepairDO.h"
#include "../../comm-c7-repomanage/domain/query/repair_report/DissatisfiedRepairQuery.h"
#include "../../comm-c7-repomanage/domain/vo/repair_report/DissatisfiedRepairVO.h"

class DissatisfiedRepairService {
public:
	DissatisfiedRepairPageDTO::Wrapper listAll(const DissatisfiedRepairQuery::Wrapper& query);
	std::list<DissatisfiedRepairDO> listAllExport();
};

#endif // !_DISSATISFIEDREPAIR_SERVICE_H_