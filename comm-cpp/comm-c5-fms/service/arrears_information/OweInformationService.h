#pragma once
#ifndef _OWEINFORMATIONSERVICE_H_
#define _OWEINFORMATIONSERVICE_H_

#include "Macros.h"
#include "../../dao/arrears_information/OweInformationMapper.h"
#include "../../dao/arrears_information/OweInformationDAO.h"
#include "../../domain/query/arrears_information/OweInformationQuery.h"
#include "../../domain/dto/arrears_information/OweInformationDTO.h"
#include "../../domain/do/arrears_information/OweInformationDo.h"
#include <iostream>


class OweInformationService
{
public:
	// 分页查询所有数据
	OweInformationPageDTO::Wrapper listAll(const OweInformationQuery::Wrapper& query);
	//导出数据
	std::list<OweInformationDTO::Wrapper> getTtoData();
};



#endif // !_OWEINFORMATIONSERVICE_H_