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
#ifndef _FEE_PRINT_PAGE_DO_H_
#define _FEE_PRINT_PAGE_DO_H_
#include "../DoInclude.h"

class FeePrintPageDO				// 物业的名称
{
	// 页面id
	CC_SYNTHESIZE(string, page_id, Page_id);
	// 物业的名称
	CC_SYNTHESIZE(string, page_name, Page_name);
	// 小区id
	CC_SYNTHESIZE(string, community_id, Community_id);
	// 收据页面
	CC_SYNTHESIZE(string, page_url, Page_url);
	// 状态 T 有效  F 为无效
	CC_SYNTHESIZE(string, state, State);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 数据状态 1 表示失败  0 有效
	CC_SYNTHESIZE(string, status_cd, Status_cd);
public:
	FeePrintPageDO() {
		page_id = "";
		page_name = "";
		community_id = "";
		page_url = "";
		state = "";
		create_time = "";
		status_cd = "";
	}
};

typedef std::shared_ptr<FeePrintPageDO> PtrFeePrintPageDO;
#endif