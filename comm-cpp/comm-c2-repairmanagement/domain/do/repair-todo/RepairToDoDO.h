#pragma once
#ifndef _REPAIRTODO_DO_
#define _REPAIRTODO_DO_
#include "../DoInclude.h"



class RepairMaterialDO {
public:
	// 商品ID
	CC_SYNTHESIZE(string, res_id, ResId);
	// 商品名称
	CC_SYNTHESIZE(string, material_name, MaterialName);
	// 商品数量
	CC_SYNTHESIZE(int, material_count, MaterialCount);
	// 商品单位
	CC_SYNTHESIZE(string, material_unit, MaterialUnit);
	// 商品规格
	CC_SYNTHESIZE(string, material_specification, MaterialSpecification);
	// 商品单价
	CC_SYNTHESIZE(double, material_price, MaterialPrice);
};

/**
 * 示例数据库实体类
 */
class RepairToDoDO
{
	// 报修Id
	CC_SYNTHESIZE(string, repair_id, RepairId);
	// 报修人姓名
	CC_SYNTHESIZE(string, repair_name, RepairName);
	// 报修人电话
	CC_SYNTHESIZE(string, tel, Tel);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);

	//数据状态
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	// 报修对象名称（位置）
	CC_SYNTHESIZE(string, repair_obj_name, RepairObjName);

	// 报修类型名称
	CC_SYNTHESIZE(string, repair_type_name, RepairTypeName);

	// 预约时间
	CC_SYNTHESIZE(string, appointment_time, AppointmentTime);

	// 状态
	CC_SYNTHESIZE(string, state, State);


	// 维修师傅名称
	CC_SYNTHESIZE(string, staff_name, StaffName);

	// 状态明细
	CC_SYNTHESIZE(string, state_detail, StateDetail);

	/*
	* 以下是r_repair_user表的字段
	*/
	// 保修派单ID
	CC_SYNTHESIZE(string, ru_id, RuId);
	// 业务ID
	CC_SYNTHESIZE(string, b_id, BId);
	// 小区ID
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// r_repair_user状态
	CC_SYNTHESIZE(string, ru_state, RuState);
	// 报修内容
	CC_SYNTHESIZE(string, context, Context);
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

	/*
	* 以下是r_repair_pool表的字段
	*/
	// 报修类型
	CC_SYNTHESIZE(string, repair_type, RepairType);
	// 数据状态 添加ADD 删除DEL 修改MOD
	CC_SYNTHESIZE(string, operate, Operate);


	// 报修对象类型 001小区 002楼栋 003单元 004房间
	CC_SYNTHESIZE(string, repair_obj_type, RepairObjType);
	// 报修对象Id
	CC_SYNTHESIZE(string, repair_obj_id, RepairObjId);
	// 维修类型
	CC_SYNTHESIZE(string, maintenance_type, MaintenanceType);
	// 报修渠道
	CC_SYNTHESIZE(string, repair_channel, RepairChannel);
	// 维修物料
	CC_SYNTHESIZE(string, repair_materials, RepairMaterials);
	//费用明细
	CC_SYNTHESIZE(string, repair_fee, RepairFee);


	// 以下是办结需要的额外字段
	
	// 是否用料
	CC_SYNTHESIZE(string, is_material, IsMaterial);
	// 商品数量
	CC_SYNTHESIZE(string, material_count, MaterialCount);
	// 支付方式
	CC_SYNTHESIZE(string, pay_type,PayType);

	
	// 商品单位
	CC_SYNTHESIZE(string, material_unit, MaterialUnit);

	// 商品规格
	CC_SYNTHESIZE(string, material_specifications, MaterialSpecifications);

	// 商品总金额
	CC_SYNTHESIZE(string, total_price, TotalPrice);

	//维修前照片路径
	CC_SYNTHESIZE(std::vector<string>, repair_before_photo_path, RepairBeforePhotoPath);
	//维修后照片路径
	CC_SYNTHESIZE(std::vector<string>, repair_after_photo_path, RepairAfterPhotoPath);
	//文件关系ID
	CC_SYNTHESIZE(string, file_rel_id, FileRelId);

	//文件类型
	CC_SYNTHESIZE(string, rel_type_cd, RelTypeCd);

	//存放方式
	CC_SYNTHESIZE(string, save_way, SaveWay);

	//对象ID
	CC_SYNTHESIZE(string, obj_id, ObjId);

	//文件真实名称
	CC_SYNTHESIZE(string, file_real_name, FileRealName);

	//文件存储名称
	CC_SYNTHESIZE(string, file_save_name, FileSaveName);


	// 商品ID
	CC_SYNTHESIZE(string, res_id, ResId);

	CC_SYNTHESIZE(std::vector<RepairMaterialDO>, materials, Materials);
	// 库存数
	CC_SYNTHESIZE(string, stock, Stock);

	// 用户ID
	CC_SYNTHESIZE(string, user_id, UserId);

	// 使用记录ID
	CC_SYNTHESIZE(string, rsur_id, RsurId);
	// 商户ID
	CC_SYNTHESIZE(string, store_id, StoreId);
	// 数量
	CC_SYNTHESIZE(string, quantity, Quantity);
	// 单价
	CC_SYNTHESIZE(string, unit_price, UnitPrice);
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

	//房间ID
	CC_SYNTHESIZE(string, room_id, RoomId);

	//业主ID
	CC_SYNTHESIZE(string, owner_id, OwnerId);
	//业主名称
	CC_SYNTHESIZE(string, owner_name, OwnerName);
	/*
		pay_fee表
	*/
	// 费用ID
	CC_SYNTHESIZE(string, fee_id, FeeId);


	// 费用类型
	CC_SYNTHESIZE(string, fee_type_cd, FeeTypeCd);


	// 付款方ID
	CC_SYNTHESIZE(string, payer_obj_id, PayerObjId);
	// 收款方ID
	CC_SYNTHESIZE(string, income_obj_id, IncomeObjId);

	// 总金额
	CC_SYNTHESIZE(string, amount, Amount);

	// 费用标识
	CC_SYNTHESIZE(string, fee_flag, FeeFlag);

	// 费用项ID
	CC_SYNTHESIZE(string, config_id, ConfigId);
	// 付费对象类型
	CC_SYNTHESIZE(string, payer_obj_type, PayerObjType);
	// 批次ID
	CC_SYNTHESIZE(string, batch_id, BatchId);
	

public:
	RepairToDoDO() {}


};

// 给RepairToDoDO智能指针设定一个别名方便使用

typedef std::shared_ptr<RepairToDoDO> PtrRepairToDoDO;
#endif // !_REPAIRTODO_DO_
