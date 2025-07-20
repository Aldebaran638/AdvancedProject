#pragma once

#ifndef  _REMITFEE_DAO_
#define  _REMITFEE_DAO_


#include "BaseDAO.h"
#include "../../domain/do/dos/RemitFeeDO.h"
#include "../../domain/query/querys/RemitFeeQuery.h"

class RemitFeeDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const RemitFeeQuery::Wrapper& query, SqlParams& params);
public:
	uint64_t count(const RemitFeeQuery::Wrapper& query);
	std::list<RemitFeeDO> selectWithPage(const RemitFeeQuery::Wrapper& query);

};

#endif // ! 
