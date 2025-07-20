#include "stdafx.h"
#include "ExRmremindersDAO.h"
#include "ExRmremindersMapper.h"
#include <sstream>
//查询excle要导出的数据
std::list<ExRmremindersDO> ExRmremindersDAO::getAll()
{
	std::string sql = "select ofc_id,owner_name,payer_obj_name,fee_name, \
		amountd_owed,callable_way,start_time,staff_name, \
    state,create_time,remark from owe_fee_callable";
	ExRmremindersMapper mapper;
	return sqlSession->executeQuery<ExRmremindersDO, ExRmremindersMapper>(sql, mapper);
}
// 通过ID删除数据
int ExRmremindersDAO::deleteById(std::string ofc_id)
{
	string sql = "DELETE FROM `owe_fee_callable` WHERE `ofc_id`=?";
	return sqlSession->executeUpdate(sql, "%s", ofc_id);
}