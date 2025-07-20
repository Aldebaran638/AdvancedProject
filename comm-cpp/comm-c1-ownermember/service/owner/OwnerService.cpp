
#include "stdafx.h"
#include "OwnerService.h"
#include "dao/owner/OwnerDAO.h"
#include "id/UuidFacade.h"
//#include "SimpleDateTimeFormat.h"
#include "domain/dto/owner/OwnerDTO.h"
//using namespace dto;

OwnerDTO::Wrapper OwnerService::getById(std::string id)
{
	// 查询数据
	OwnerDAO dao;
	auto res = dao.selectById(id);

	// 没有查询到数据
	if (!res)
		return nullptr;

	// 查询到数据转换成DTO
	auto dto = OwnerDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, owner_id, Owner_id, name, Name, sex, Sex, age, Age, id_card, Id_card, link, Link);
	return dto;
}
