#pragma once
#ifndef _MEMBER_DO_
#define _MEMBER_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class MemberDO
{
	// 业主成员id
	CC_SYNTHESIZE(string, member_id, Member_id);
	// 业主id
	CC_SYNTHESIZE(string, owner_id, Owner_id);
	// 业务id
	CC_SYNTHESIZE(string, b_id, B_id);
	// 用户id
	CC_SYNTHESIZE(string, user_id, User_id);
	// 小区id
	CC_SYNTHESIZE(string, community_id, Community_id);
	// 业主姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 电话号
	CC_SYNTHESIZE(string, link, Link);
	// 年龄
	CC_SYNTHESIZE(string, age, Age);
	// 身份证
	CC_SYNTHESIZE(string, id_card, Id_card);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 数据状态
	CC_SYNTHESIZE(string, status_cd, Status_cd);
	// 业主标识
	CC_SYNTHESIZE(string, owner_flag, Owner_flag);
	// 成员类型
	CC_SYNTHESIZE(string, owner_type_cd, Owner_type_cd);
	// 业主成员状态
	CC_SYNTHESIZE(string, state, State);
	// 家庭地址
	CC_SYNTHESIZE(string, address, Address);
public:
	MemberDO() {
		member_id = "";
		owner_id = "";
		b_id = "";
		name = "";
		sex = "";
		age = "";
		link = "";
		user_id = "";
		remark = "";
		status_cd = "0";
		owner_type_cd = "1001";
		community_id = "";
		id_card = "-1";
		state = "2000";
		owner_flag = "T";
		address = "";
	}
};



// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<MemberDO> PtrMemberDO;
#endif // !_SAMPLE_DO_
