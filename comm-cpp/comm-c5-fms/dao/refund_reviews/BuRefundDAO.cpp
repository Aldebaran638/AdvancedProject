#include "BuRefundMapper.h"
#include "BuRefundDAO.h"
#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <ctime>
std::list<BuRefundDO> BuRefundDAO::getAll()
{
	std::string sql = "select return_fee_id,b_id,fee_type_cd,fee_id,cycles,received_amount,create_time,reason,apply_person_name,state,audit_person_name,status_cd from return_pay_fee";
	BuRefundMapper mapper;
	return sqlSession->executeQuery<BuRefundDO, BuRefundMapper>(sql, mapper);
}