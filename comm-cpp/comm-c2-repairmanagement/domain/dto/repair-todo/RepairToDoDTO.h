#pragma once
#ifndef _REPAIRTODODTO_H_
#define _REPAIRTODODTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class RepairToDoAddDTO : public oatpp::DTO
{
	DTO_INIT(RepairToDoAddDTO, DTO);
	//工单编号
	API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("repairtodo.field.repair_id"));
	// 报修人
	API_DTO_FIELD_DEFAULT(String, repair_name, ZH_WORDS_GETTER("repairtodo.field.repair_name"));
	// 报修人电话
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("repairtodo.field.tel"));
	// 报修类型
	API_DTO_FIELD_DEFAULT(String, repair_type, ZH_WORDS_GETTER("repairtodo.field.repair_type"));
	// 报修状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("repairtodo.field.state"));

};


class RepairToDoQueryDTO : public oatpp::DTO
{
	DTO_INIT(RepairToDoQueryDTO, DTO);
	// 维修单ID
	API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("repairtodo.field.repair_id"));
	// 报修人
	API_DTO_FIELD_DEFAULT(String, repair_name, ZH_WORDS_GETTER("repairtodo.field.repair_name"));
	// 报修人电话
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("repairtodo.field.tel"));
	// 报修状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("repairtodo.field.state"));
	// 位置信息
	API_DTO_FIELD_DEFAULT(String, repair_obj_name, ZH_WORDS_GETTER("repairtodo.field.repair_obj_name"));
	// 维修类型名称
	API_DTO_FIELD_DEFAULT(String, repair_type_name, ZH_WORDS_GETTER("repairtodo.field.repair_type_name"));
	// 预约时间
	API_DTO_FIELD_DEFAULT(String, appointment_time, ZH_WORDS_GETTER("repairtodo.field.appointment_time"));
	// 状态明细
	API_DTO_FIELD_DEFAULT(String, state_detail, ZH_WORDS_GETTER("repairtodo.field.state_detail"));
	// 上一级维修人id
	API_DTO_FIELD_DEFAULT(String, pre_staff_id, ZH_WORDS_GETTER("repairtodo.field.pre_staff_id"));
	// 上一级维修人姓名
	API_DTO_FIELD_DEFAULT(String, pre_staff_name, ZH_WORDS_GETTER("repairtodo.field.pre_staff_name"));
	// 是否是公共区域
	API_DTO_FIELD_DEFAULT(String, public_area, ZH_WORDS_GETTER("repairtodo.field.public_area"));
	// 报修对象ID
	API_DTO_FIELD_DEFAULT(String, repair_obj_id, ZH_WORDS_GETTER("repairtodo.field.repair_obj_id"));


};



//定义一个查询所有维修类型的DTO
class RepairToDoQueryAllRepairTypeDTO : public oatpp::DTO
{
	DTO_INIT(RepairToDoQueryAllRepairTypeDTO, DTO);
	// 维修类型名称
	API_DTO_FIELD_DEFAULT(String, repair_type_name, ZH_WORDS_GETTER("repairtodo.field.repair_type_name"));

	//维修类型ID
	API_DTO_FIELD_DEFAULT(String, repair_type, ZH_WORDS_GETTER("repairtodo.field.repair_type"));

};

//定义一个查询所有维修师傅的DTO
class RepairToDoQueryAllStaffDTO : public oatpp::DTO
{
	DTO_INIT(RepairToDoQueryAllStaffDTO, DTO);
	// 维修师傅名称
	API_DTO_FIELD_DEFAULT(String, staff_name, ZH_WORDS_GETTER("repairtodo.field.staff_name"));

	// 维修师傅ID
	API_DTO_FIELD_DEFAULT(String, staff_id, ZH_WORDS_GETTER("repairtodo.field.staff_id"));

};





/**
 * 定义一个维修代办信息明细
 */
class RepairToDoDTO :public RepairToDoAddDTO
{
	DTO_INIT(RepairToDoDTO, RepairToDoAddDTO);

	// 维修前照片路径
	API_DTO_FIELD_DEFAULT(String, before_photo_path, ZH_WORDS_GETTER("repairtodo.field.before_photo_path"));
	// 维修后照片路径
	API_DTO_FIELD_DEFAULT(String, after_photo_path, ZH_WORDS_GETTER("repairtodo.field.after_photo_path"));

	// 维修人员名称
	API_DTO_FIELD_DEFAULT(String, staff_name, ZH_WORDS_GETTER("repairtodo.field.staff_name"));
	// 报修对象类型 001 小区 002 楼栋 003 单元 004 房屋
	API_DTO_FIELD_DEFAULT(String, repair_obj_type, ZH_WORDS_GETTER("repairtodo.field.repair_obj_type"));
	// 提交时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("repairtodo.field.create_time"));
	// 报修内容
	API_DTO_FIELD_DEFAULT(String, context, ZH_WORDS_GETTER("repairtodo.field.context"));
	// 开始时间
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("repairtodo.field.start_time"));
	// 结束时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("repairtodo.field.end_time"));
	// 位置信息
	API_DTO_FIELD_DEFAULT(String, repair_obj_name, ZH_WORDS_GETTER("repairtodo.field.repair_obj_name"));
	// 维修类型名称
	API_DTO_FIELD_DEFAULT(String, repair_type_name, ZH_WORDS_GETTER("repairtodo.field.repair_type_name"));
	// 预约时间
	API_DTO_FIELD_DEFAULT(String, appointment_time, ZH_WORDS_GETTER("repairtodo.field.appointment_time"));
	// 状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("repairtodo.field.state"));
};


//改单操作：负载信息
class RepairToDoUpdateDTO : public oatpp::DTO
{
	DTO_INIT(RepairToDoUpdateDTO, DTO);
	// 报修单ID
	API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("repairtodo.field.repair_id"),true,"822024021727861281");
	// 处理意见
	API_DTO_FIELD(String, context, ZH_WORDS_GETTER("repairtodo.field.context"),true,ZH_WORDS_GETTER("repairtodo.field.context_update_example"));
	// 报修师傅ID
	API_DTO_FIELD(String, staff_id, ZH_WORDS_GETTER("repairtodo.field.staff_id"), true, "302025052972240004");

};

//暂停操作：负载信息
class RepairToDoUpdateToSuspendDTO : public oatpp::DTO
{
	DTO_INIT(RepairToDoUpdateToSuspendDTO, DTO);
	// 报修单ID
	API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("repairtodo.field.repair_id"),true,"822024021727861281");
	// 暂停意见
	API_DTO_FIELD(String, context, ZH_WORDS_GETTER("repairtodo.field.suspend_context"),true,ZH_WORDS_GETTER("repairtodo.field.context_suspend_example"));
};


//退单操作：负载信息
class RepairToDoUpdateToRemoveDTO : public oatpp::DTO
{
	DTO_INIT(RepairToDoUpdateToRemoveDTO, DTO);
	// 报修单ID
	API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("repairtodo.field.repair_id"),true,"822024021727861281");
	// 暂停意见
	API_DTO_FIELD(String, context, ZH_WORDS_GETTER("repairtodo.field.remove_context"),true,ZH_WORDS_GETTER("repairtodo.field.context_remove_example"));
};





class RepairMaterialItemDTO : public oatpp::DTO {
	DTO_INIT(RepairMaterialItemDTO, DTO);
	// 商品ID（必填，默认值建议为空）
	API_DTO_FIELD(String, res_id, ZH_WORDS_GETTER("repairtodo.field.res_id"), true, "");
	// 商品名称（必填，默认值可为空）
	API_DTO_FIELD(String, material_name, ZH_WORDS_GETTER("repairtodo.field.material_name"), true, "");
	// 商品数量（建议用数值类型而非字符串）
	API_DTO_FIELD(Int32, material_count, ZH_WORDS_GETTER("repairtodo.field.material_count"), true, 1);

	// 商品单位（建议用字符串类型）
	API_DTO_FIELD(String, material_unit, ZH_WORDS_GETTER("repairtodo.field.material_unit"), false, "");
	// 商品规格（建议用字符串类型）
	API_DTO_FIELD(String, material_specification, ZH_WORDS_GETTER("repairtodo.field.material_specification"), false, "");
	// 商品单价（建议用浮点数类型）
	API_DTO_FIELD(Float64, material_price, ZH_WORDS_GETTER("repairtodo.field.material_price"), false, 0.0);
};


//办结操作：负载信息
class RepairToDoUpdateToFinishDTO : public oatpp::DTO
{
	DTO_INIT(RepairToDoUpdateToFinishDTO, DTO);
	// 报修单ID
	API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("repairtodo.field.repair_id"), true, "822024021727861281");

	// 是否用料
	API_DTO_FIELD(String, is_material, ZH_WORDS_GETTER("repairtodo.field.is_material"), true, "1");
	// 商品列表（核心修改点）
	API_DTO_FIELD(oatpp::Vector<oatpp::Object<RepairMaterialItemDTO>>, materials,
		ZH_WORDS_GETTER("repairtodo.field.materials"),
		false,
		[]() {
			auto v = oatpp::Vector<oatpp::Object<RepairMaterialItemDTO>>::createShared();
			auto item = RepairMaterialItemDTO::createShared();
			item->res_id = "852025060109790015";
			item->material_name = ZH_WORDS_GETTER("repairtodo.field.material_name_example");
			item->material_count = 1;
			item->material_unit = ZH_WORDS_GETTER("repairtodo.field.material_unit_example");
			item->material_specification = "1000mAh";
			item->material_price = 10.0;
			v->push_back(item);  
			return v;
		}());


	// 处理意见
	API_DTO_FIELD(String, context, ZH_WORDS_GETTER("repairtodo.field.finish_context"), true, ZH_WORDS_GETTER("repairtodo.field.context_finish_example"));

	// 维修照片路径
	API_DTO_FIELD(oatpp::Vector<oatpp::String>, repair_before_photo_path, ZH_WORDS_GETTER("repairtodo.field.repair_before_photo_path"), true, []() {
		auto list = oatpp::Vector<oatpp::String>::createShared();
		list->push_back("D:\\computer practice\\imgs\\repair_before_1.jpg");
		list->push_back("D:\\computer practice\\imgs\\repair_before_2.jpg");
		list->push_back("D:\\computer practice\\imgs\\repair_before_3.jpg");
		return list;
	}());


	// 维修后照片路径
	API_DTO_FIELD(oatpp::Vector<oatpp::String>, repair_after_photo_path, ZH_WORDS_GETTER("repairtodo.field.repair_after_photo_path"), true, []() {
		auto list = oatpp::Vector<oatpp::String>::createShared();
		list->push_back("D:\\computer practice\\imgs\\repair_after_1.jpg");
		list->push_back("D:\\computer practice\\imgs\\repair_after_2.jpg");
		list->push_back("D:\\computer practice\\imgs\\repair_after_3.jpg");
		return list;
	}());

	// 房间ID
	API_DTO_FIELD(String, room_id, ZH_WORDS_GETTER("repairtodo.field.room_id"), false, "102025052701090065");
	// 支付方式
	API_DTO_FIELD(String, pay_type, ZH_WORDS_GETTER("repairtodo.field.pay_type"), false, ZH_WORDS_GETTER("repairtodo.field.pay_type_example"));
	// 商品总金额
	API_DTO_FIELD(String, total_price, ZH_WORDS_GETTER("repairtodo.field.total_price"), false, "2");

};

/**
 * 定义一个报修代办信息分页传输对象
 */
class RepairToDoPageDTO : public PageDTO<RepairToDoQueryDTO::Wrapper>
{
	DTO_INIT(RepairToDoPageDTO, PageDTO<RepairToDoQueryDTO::Wrapper>);
};


/**
 * 定义一个报修类型信息分页传输对象
 */
class RepairToDoQueryAllRepairTypePageDTO : public PageDTO<RepairToDoQueryAllRepairTypeDTO::Wrapper>
{
	DTO_INIT(RepairToDoQueryAllRepairTypePageDTO, PageDTO<RepairToDoQueryAllRepairTypeDTO::Wrapper>);
};


/**
 * 定义一个报修师傅信息分页传输对象
 */
class RepairToDoQueryAllStaffPageDTO : public PageDTO<RepairToDoQueryAllStaffDTO::Wrapper>
{
	DTO_INIT(RepairToDoQueryAllStaffPageDTO, PageDTO<RepairToDoQueryAllStaffDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // ! _REPAIRTODODTO_H_