
#ifndef _FLOOR_H_
#define _FLOOR_H_
#include"../DoInclude.h"

class FloorDO {
	//楼ID
	CC_SYNTHESIZE(string, floor_id, Floor_id);
	//业务ID
	CC_SYNTHESIZE(string, b_id, B_id);
	//楼编号
	CC_SYNTHESIZE(string, floor_num, Floor_num);
	//小区楼名称
	CC_SYNTHESIZE(string, name, Name);
	//用户ID
	CC_SYNTHESIZE(string, user_id, User_id);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//数据状态，详细参考c_status表，S保存，0在用，1失效
	CC_SYNTHESIZE(string, status_cd, Status_cd);
	//小区ID
	CC_SYNTHESIZE(string, community_id, Community_id);
	//建筑面积
	CC_SYNTHESIZE(string, floor_area, Floor_area);
	//楼栋加入顺序
	CC_SYNTHESIZE(int, seq, Seq);
public:
	FloorDO() {
		floor_id = "";
		b_id = "";
		floor_num = "";
		name = "";
		user_id = "";
		remark = "";
		create_time = "";
		status_cd = "";
		community_id = "";
		floor_area = "";
		seq = -1;
	};
	FloorDO(string floor_id, string b_id, string floor_num, string name, string user_id, string remark, string create_time, string status_cd, string community_id, string floor_area, int seq) {
		this->floor_id = floor_id;
		this->b_id = b_id;
		this->floor_num = floor_num;
		this->name = name;
		this->user_id = user_id;
		this->remark = remark;
		this->create_time = create_time;
		this->status_cd = status_cd;
		this->community_id = community_id;
		this->floor_area = floor_area;
		this->seq = seq;
	}
};
// 给FloorDO智能指针设定一个别名方便使用
typedef std::shared_ptr<FloorDO> PtrFloorDO;


#endif