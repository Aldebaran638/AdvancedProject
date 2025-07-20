#pragma once
#ifndef _FORCEBACKDO_H_
#define _FORCEBACKDO_H_
#include "../DoInclude.h"
/**
 * 示例数据库实体类
 * 前端可以操作的字段：repair_type_name、repair_name、tel
 * 后端自动生成其他字段
 */
class ForceBackDO
{
	// 工单编码  （C++数据类型，mysql中表名，大驼峰命名法）
	//CC_SYNTHESIZE(string, setting_id, SettingId);
	//位置
	CC_SYNTHESIZE(string, repair_obj_name, RepairObjName);
	// 报修类型 
	CC_SYNTHESIZE(string, repair_type, RepairType);
	// 报修人
	CC_SYNTHESIZE(string, repair_name, RepairName);
	//联系方式
	CC_SYNTHESIZE(string, tel, Tel);
	//预约时间
	CC_SYNTHESIZE(string, appointment_time, AppointmentTime);
	//提交时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	//状态
	CC_SYNTHESIZE(string, state, State);
	//报修id
	CC_SYNTHESIZE(string, repair_id, RepairId);
	// 维修类型
	CC_SYNTHESIZE(string, maintenance_type, MaintenanceType);
	//维修物料
	CC_SYNTHESIZE(string, repair_materials, RepairMaterials);
	//总价
	CC_SYNTHESIZE(string, repair_fee, RepairFee);
	//支付方式
	CC_SYNTHESIZE(string, pay_type, PayType);
	//报修类型-中文映射
	CC_SYNTHESIZE(string, repair_type_detail, RepairTypeDetail);
	//报修状态-中文映射
	CC_SYNTHESIZE(string, state_detail, StateDetail);

	//处理意见
	CC_SYNTHESIZE(string, context, Context);

	// 库存数
	CC_SYNTHESIZE(string, stock, Stock);
	// 商户ID
	CC_SYNTHESIZE(string, store_id, StoreId);
	// 用户ID
	CC_SYNTHESIZE(string, user_id, UserId);
	// 商品ID
	CC_SYNTHESIZE(string, res_id, ResId);
	// 使用记录ID
	CC_SYNTHESIZE(string, rsur_id, RsurId);
	// 业务ID
	CC_SYNTHESIZE(string, b_id, BId);
	// 小区ID
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// 数量
	CC_SYNTHESIZE(string, quantity, Quantity);
	//数据状态
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	// 创建用户ID
	CC_SYNTHESIZE(string, create_user_id, CreateUserId);
	// 创建用户名称
	CC_SYNTHESIZE(string, create_user_name, CreateUserName);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 商品名称
	CC_SYNTHESIZE(string, resource_store_name, ResourceStoreName);
	// 物品使用类型
	CC_SYNTHESIZE(string, record_state, RecordState);
	// 报修派单ID
	CC_SYNTHESIZE(string, ru_id, RuId);
	// 数据状态 添加ADD 删除DEL 修改MOD
	CC_SYNTHESIZE(string, operate, Operate);

	// 数据状态
	CC_SYNTHESIZE(string, ru_status_cd, RuStatusCd);
	// 当前处理员工
	CC_SYNTHESIZE(string, ru_staff_id, RuStaffId);
	// 当前处理员工名称
	CC_SYNTHESIZE(string, ru_staff_name, RuStaffName);
	//上一节点处理员工
	CC_SYNTHESIZE(string, pre_staff_id, PreStaffId);
	//上一节点处理员工名称
	CC_SYNTHESIZE(string, pre_staff_name, PreStaffName);
	// 开始时间
	CC_SYNTHESIZE(string, start_time, StartTime);
	// 结束时间
	CC_SYNTHESIZE(string, end_time, EndTime);
	// 事件 startUser开始用户，auditUser审核处理员工
	CC_SYNTHESIZE(string, repair_event, RepairEvent);
	// 上一节点处理ID
	CC_SYNTHESIZE(string, pre_ru_id, PreRuId);
public:
	ForceBackDO() {
		repair_type = "";
		repair_name = "";
		tel = "";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<ForceBackDO> PtrForceBackDO;
#endif // !_FORCEBACKDO_H_
