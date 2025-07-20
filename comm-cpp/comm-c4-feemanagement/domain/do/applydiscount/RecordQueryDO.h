#pragma once
#ifndef _RECORD_QUERY_DO_
#define _RECORD_QUERY_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class RecordQueryDO
{
	// 空置房验房跟踪记录ID
	CC_SYNTHESIZE(string, ardr_id, Ardr_id);
	// 房屋名称
	CC_SYNTHESIZE(string, room_name, Room_name);
	// 创建人
	CC_SYNTHESIZE(string, create_user_name, Create_user_name);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 是否违规
	CC_SYNTHESIZE(string, is_true, Is_true);
	// 审核状态
	CC_SYNTHESIZE(string, state, State);
public:
	RecordQueryDO() {
		ardr_id = "";
		room_name = "";
		create_user_name = "";
		create_time = "";
		remark = "";
		is_true = "";
		state = "0";
	}
};

// 给ApplyRoomDiscountRecordDO智能指针设定一个别名方便使用
typedef std::shared_ptr<RecordQueryDO> PtrRecordQueryDO;
#endif // !_RECORD_Query_DO_
