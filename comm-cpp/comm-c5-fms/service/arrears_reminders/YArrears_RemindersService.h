#pragma once
#ifndef _YARREARS_REMINDERSSERVICE_
#define _YARREARS_REMINDERSSERVICE_
#include "Macros.h"
#include "domain/query/arrears_reminders/YArrears_RemindersQuery.h"
#include "domain/dto/arrears_reminders/YArrears_RemindersDTO.h"
#include "domain/vo/arrears_reminders/YArrears_RemindersVO.h"

class YArrears_RemindersService
{
public:
	// ÐÞ¸ÄÊý¾Ý
	std::string addData(const YArrears_RemindersAddDTO::Wrapper& dto);
};

#endif
