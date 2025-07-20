#pragma once
#ifndef _RAINDISTYPESDO_H_
#define _RAINDISTYPESDO_H_
#include "../DoInclude.h"
#include "Macros.h"

/**
 * 数据库实体类
 */
class RainDisTypesDO
{
	// 类型ID
	CC_SYNTHESIZE(string, apply_type, ApplyType);
	// 类型名称
	CC_SYNTHESIZE(string, type_name, TypeName);
	// 小区ID
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// 类型描述
	CC_SYNTHESIZE(string, type_desc, TypeDesc);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// status code
	CC_SYNTHESIZE(string, status_cd, StatusCd);

public:
	RainDisTypesDO()
	{
		apply_type = "";
		type_name = "";
		community_id = "0";
		type_desc = "";
		create_time = " ";
		status_cd = "0";
	}
};

// 给RainDisTypesDO智能指针设定一个别名方便使用
typedef std::shared_ptr<RainDisTypesDO> PtrRainDisTypesDO;
#endif // !_RAINDISTYPESDO_H_
