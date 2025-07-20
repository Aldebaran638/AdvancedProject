#pragma once
#ifndef _DEPOSIT_REPORT_DO_
#define _DEPOSIT_REPORT_DO_
#include "../DoInclude.h"

class DepositReportVO 
{	
	// 暂时定义的VO 后续根据实际数据库表定义
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	// 创建人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// 创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// 修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
public:
	DepositReportVO() {
		id = "";
		name = "";
		sex = "";
		age = -1;
	}
};





#endif // !_DEPOSIT_REPORT_DO_