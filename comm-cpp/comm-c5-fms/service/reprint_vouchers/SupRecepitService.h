#pragma once

#ifndef SUP_RECEPIT_SERVICE
#define SUP_RECEPIT_SERVICE

#include"domain/do/reprint_vouchers/SupRecepitDO.h"
#include"domain/dto/reprint_vouchers/SupRecepitDTO.h"
#include"domain/query/reprint_vouchers/SupRecepitQuery.h"
#include"domain/vo/reprint_vouchers/SupRecepitVO.h"
#include"domain/do/reprint_vouchers/SupRecepitForRoomDO.h"

class SupRecepitService {
public:
	SupRecepitPageDTO::Wrapper SupRecepitListAll(const SupRecepitQuery::Wrapper& query);
	ReprintSupRecepitDTO::Wrapper ReprintRecepit(std::string id);
	ReprintSupRecepit2DTO::Wrapper ReprintRecepit2(std::string id);
private:
	std::string roomName(list<SupRecepitForRoomDO> roomlist);
};

#endif // !SUP_RECEPIT_SERVICE
