#pragma once
#ifndef SUP_RECEPIT_DAO
#define SUP_RECEPIT_DAO

#include "BaseDAO.h"
#include"../../domain/do/reprint_vouchers/SupRecepitDO.h"
#include"../../domain/query/reprint_vouchers/SupRecepitQuery.h"
#include"../../domain/do/reprint_vouchers/SupRecepitForRoomDO.h"

class SupRecepitDAO : public BaseDAO {
private:
	inline std::string queryConditionBuilder(const SupRecepitQuery::Wrapper& query, SqlParams& params);
public:
	uint64_t count(const SupRecepitQuery::Wrapper& query);
	std::list<SupRecepitDO> selectWithPage(const SupRecepitQuery::Wrapper& query);
	std::list<SupRecepitForRoomDO> selectForRoom(std::string pay_id);
	PtrReprintSupRecepitDO selectForReprint1(std::string id);//补打收据
	PtrReprintSupRecepit2DO selectForReprint2(std::string id);//补打小票
};

#endif // !SUP_RECEPIT_DAO
