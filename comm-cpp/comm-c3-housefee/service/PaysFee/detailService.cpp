#include "stdafx.h"
#include "detailService.h"
#include "../../dao/paysFee/detailDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

detailDTO::Wrapper detailService::getById(std::string id)
{
	detailDAO dao;
	auto res = dao.selectById(id);
	if (!res)
		return nullptr;
	auto dto = detailDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, fee_id, FEE_ID, cycle, CYCLE, pay_path, PAY_PATH, receivable_amount, RECEIVABLE_AMOUNT, amount, AMOUNT, pay_time, PAY_TIME, start_time, START_TIME, end_time, END_TIME, receive_id, RECEIVE_ID, status_cd, STATUS_CD, remark, REMARK, opt, OPT);
	return dto;
}