#pragma once
#ifndef _EXRMREMINDERS_DAO_
#define _EXRMREMINDERS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/arrears_reminders/ExRmremindersDO.h"


/**
 * 示例表数据库操作实现
 */
class ExRmremindersDAO : public BaseDAO
{

public:
	//查询excle要导出的数据
	std::list<ExRmremindersDO> getAll();
	// 通过ID删除数据
	int deleteById(std::string ofc_id);
};
#endif // !_SAMPLE_DAO_