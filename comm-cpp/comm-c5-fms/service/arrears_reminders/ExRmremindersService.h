#pragma once
#ifndef _EXRMREMINDERS_SERVICE_
#define _EXRMREMINDERS_SERVICE_
#include "domain/vo/arrears_reminders/ExRmremindersVO.h"

#include "domain/dto/arrears_reminders/ExRmremindersDTO.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ExRmremindersService
{
public:

	//导出数据
	std::list<ExRmremindersDTO::Wrapper> getData();
	// 通过ID删除数据
	bool removeData(const oatpp::List<oatpp::String>& ids);
};

#endif // !_EXRMREMINDERS_SERVICE_
