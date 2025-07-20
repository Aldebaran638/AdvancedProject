#pragma once
#ifndef _YYYCDISTYPESDO_
#define _YYYCDISTYPESDO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class YyycDisTypesDO
{
	// 类型名称
	CC_SYNTHESIZE(string, type_name, Type_Name);
	// 类型描述
	CC_SYNTHESIZE(string, type_desc, Type_Desc);
	// 类型id
	CC_SYNTHESIZE(string, type_id, Type_Id);
	// 小区id
	CC_SYNTHESIZE(int, community_id, Community_Id);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_Time);
	// 数据状态
	CC_SYNTHESIZE(string, state, State);
public:
	YyycDisTypesDO() {
		type_name = "";
		type_desc = "";
		type_id = "";
		community_id = 1;
		create_time = "";
		state = "";
	}
};

#endif 
