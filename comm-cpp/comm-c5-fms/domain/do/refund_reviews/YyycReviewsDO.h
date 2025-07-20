#pragma once
#ifndef _YYYCREVIEWSDO_
#define _YYYCREVIEWSDO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class YyycReviewsDO
{
	// 审核状态
	CC_SYNTHESIZE(string, state, State);
	// 原因
	CC_SYNTHESIZE(string, reason, Reason);
	// 退费id
	CC_SYNTHESIZE(string, id, Id);
public:
	YyycReviewsDO() {
		id = "";
		state = "";
		reason = "";
	}
};

#endif 
