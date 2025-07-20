#pragma once
#ifndef _OWNER_DO_
#define _OWNER_DO_
#include "../DoInclude.h"  // 包含项目公共头文件

/**
 * 业主数据库实体类
 * 对应数据库表: owner
 */
class OwnerDO
{
	// 业主ID
	CC_SYNTHESIZE(std::string, owner_id, Owner_id);
	// 业主姓名
	CC_SYNTHESIZE(std::string, name, Name);
	// 性别
	CC_SYNTHESIZE(std::string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(std::string, age, Age);
	// 身份证号
	CC_SYNTHESIZE(std::string, id_card, Id_card);
	// 联系方式
	CC_SYNTHESIZE(std::string, link, Link);

public:
	OwnerDO() {
		owner_id = "";
		name = "";
		sex = "";
		age = "";
		id_card = "";
		link = "";
	}
};

// 给OwnerDO智能指针设定一个别名方便使用
typedef std::shared_ptr<OwnerDO> PtrOwnerDO;

#endif // !_OWNER_DO_#pragma once
