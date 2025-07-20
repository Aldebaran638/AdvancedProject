#pragma once

#ifndef _UNIT_DO_
#define _UNIT_DO_
#include "../DoInclude.h"

/**
 * 单元信息数据库实体类
 */
class UnitDO
{
	//单元ID
	CC_SYNTHESIZE(string, unit_id, UnitId);
	//业务ID
	CC_SYNTHESIZE(string, b_id, BId);
	//单元编号
	CC_SYNTHESIZE(string, unit_num, UnitNum);
	//楼ID
	CC_SYNTHESIZE(string, floor_id, FloorId);
	//总层数
	CC_SYNTHESIZE(int, layer_count, LayerCount);
	//电梯状态
	CC_SYNTHESIZE(string, lift, Lift);
	//用户ID
	CC_SYNTHESIZE(string, user_id, UserId);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	//数据状态
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	//单元面积
	CC_SYNTHESIZE(string, unit_area, UnitArea);
	//楼编号(连接查询用的)
	CC_SYNTHESIZE(string, floor_num, FloorNum);
public:
	UnitDO() {
		unit_id = "";
		b_id = "";
		unit_num = "";
		floor_id = "";
		layer_count = 0;
		lift = "2020";
		user_id = "";
		remark = "";
		create_time = "";
		status_cd = "";
		unit_area = "";
	}
	UnitDO(string unit_id, string b_id, string unit_num, string floor_id, int layer_count,
		string lift, string user_id, string remark, string create_time, string status_cd, string unit_area) {
		this->unit_id = unit_id;
		this->b_id = b_id;
		this->unit_num = unit_num;
		this->floor_id = floor_id;
		this->layer_count = layer_count;
		this->lift = lift;
		this->user_id = user_id;
		this->remark = remark;
		this->create_time = create_time;
		this->status_cd = status_cd;
		this->unit_area = unit_area;
	}
};
// 给UnitDO智能指针设定一个别名方便使用
typedef std::shared_ptr<UnitDO> PtrUnitDO;

#endif