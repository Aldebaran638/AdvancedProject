#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _TABLEREADINGTYPEDO_H_
#define _TABLEREADINGTYPEDO_H_
#include "../DoInclude.h"

/**
 * 抄表类型数据库实体类
 */
class TableReadingTypeDO
{
	// 抄表类型
	CC_SYNTHESIZE(string, type_id, TypeId);
	// 名称
	CC_SYNTHESIZE(string, type_name, TypeName);
	// 社区id
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// 说明
	CC_SYNTHESIZE(string, remark, Remark);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// 状态码
	CC_SYNTHESIZE(string, status_cd, StatusCd);
public:
	TableReadingTypeDO() {
		type_id = "";
		type_name = "";
		community_id = "";
		remark = "";
		create_time = "";
		status_cd = "0";
	}
};

// 给TableReadingTypeDO智能指针设定一个别名方便使用
typedef std::shared_ptr<TableReadingTypeDO> PtrTableReadingTypeDO;
#endif // !_TABLEREADINGTYPEDO_H_
