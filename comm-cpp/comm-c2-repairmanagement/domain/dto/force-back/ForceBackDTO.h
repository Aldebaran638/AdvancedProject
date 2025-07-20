#pragma once
#ifndef _FORCEBACKDTO_H_
#define _FORCEBACKDTO_H_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

// 定义一个添加强制回单结果的数据模型
class ForceBackAddDTO : public oatpp::DTO
{
	DTO_INIT(ForceBackAddDTO, DTO);
	//提交时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("forceback.force-back.create_time"));
	//状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("forceback.force-back.state"));

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

//定义一个强制回单的数据传输模型
class ForceBackDTO : public oatpp::DTO
{
	DTO_INIT(ForceBackDTO, DTO);
	//报修id
	API_DTO_FIELD_DEFAULT(String, repair_id, ZH_WORDS_GETTER("forceback.force-back.repair_id"));
	// 工单编码
	//API_DTO_FIELD_DEFAULT(String, setting_id, ZH_WORDS_GETTER("forceback.force-back.setting_id"));
	//位置
	API_DTO_FIELD_DEFAULT(String, repair_obj_name, ZH_WORDS_GETTER("forceback.force-back.repair_obj_name"));
	// 报修类型 
	API_DTO_FIELD_DEFAULT(String, repair_type, ZH_WORDS_GETTER("forceback.force-back.repair_type"));
	// 报修类型-中文映射 
	API_DTO_FIELD_DEFAULT(String, repair_type_detail, ZH_WORDS_GETTER("forceback.force-back.repair_type_detail"));
	// 报修人
	API_DTO_FIELD_DEFAULT(String, repair_name, ZH_WORDS_GETTER("forceback.force-back.repair_name"));
	//联系方式
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("forceback.force-back.tel"));
	//预约时间
	API_DTO_FIELD_DEFAULT(String, appointment_time, ZH_WORDS_GETTER("forceback.force-back.appointment_time"));
	//提交时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("forceback.force-back.create_time"));
	//状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("forceback.force-back.state"));
	//报修状态-中文映射
	API_DTO_FIELD_DEFAULT(String, state_detail, ZH_WORDS_GETTER("forceback.force-back.state_detail"));

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

class RepairMaterialDTO : public oatpp::DTO {
	DTO_INIT(RepairMaterialDTO, DTO);
	// 商品ID（必填，默认值建议为空）
	API_DTO_FIELD(String, res_id, ZH_WORDS_GETTER("forceback.force-back.res_id"), true, "");
	// 商品名称（必填，默认值可为空）
	API_DTO_FIELD(String, material_name, ZH_WORDS_GETTER("forceback.force-back.material_name"), true, "");
	// 商品数量（建议用数值类型而非字符串）
	API_DTO_FIELD(Int32, material_count, ZH_WORDS_GETTER("forceback.force-back.material_count"), true, 1);

	// 商品单位（建议用字符串类型）
	API_DTO_FIELD(String, material_unit, ZH_WORDS_GETTER("forceback.force-back.material_unit"), false, "");
	// 商品规格（建议用字符串类型）
	API_DTO_FIELD(String, material_specification, ZH_WORDS_GETTER("forceback.force-back.material_specification"), false, "");
	// 商品单价（建议用浮点数类型）
	API_DTO_FIELD(Float64, material_price, ZH_WORDS_GETTER("forceback.force-back.material_price"), false, 0.0);
};

// 定义一个修改强制回单状态的数据传输模型
class ForceBackModifyDTO : public oatpp::DTO
{
	DTO_INIT(ForceBackModifyDTO, DTO);
	//报修id
	API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("forceback.force-back.repair_id"), true, "822024022794890018");
	//维修类型
	API_DTO_FIELD(String, maintenance_type, ZH_WORDS_GETTER("forceback.force-back.maintenance_type"), true, ZH_WORDS_GETTER("forceback.force-back.maintenance_type_detail"));
	//维修物料
	//API_DTO_FIELD(String, repair_materials, ZH_WORDS_GETTER("forceback.force-back.repair_materials"), false, "");
	// 商品列表（核心修改点）
	API_DTO_FIELD(oatpp::Vector<oatpp::Object<RepairMaterialDTO>>, materials,
		ZH_WORDS_GETTER("forceback.force-back.materials"),
		false,
		[]() {
			auto v = oatpp::Vector<oatpp::Object<RepairMaterialDTO>>::createShared();
			auto item = RepairMaterialDTO::createShared();
			item->res_id = "852025060109790015";
			item->material_name = ZH_WORDS_GETTER("forceback.force-back.material_name_example");
			item->material_count = 1;
			item->material_unit = ZH_WORDS_GETTER("forceback.force-back.material_unit_example");
			item->material_specification = "1000mAh";
			item->material_price = 10.0;
			v->push_back(item);
			return v;
		}());
	//总价
	API_DTO_FIELD_DEFAULT(String, repair_fee, ZH_WORDS_GETTER("forceback.force-back.repair_fee"));
	//支付方式
	API_DTO_FIELD(String, pay_type, ZH_WORDS_GETTER("forceback.force-back.pay_type"), false, ZH_WORDS_GETTER("forceback.force-back.pay_type_detail"));
	// 处理意见
	API_DTO_FIELD(String, context, ZH_WORDS_GETTER("forceback.force-back.finish_context"), true, ZH_WORDS_GETTER("forceback.force-back.context_finish_example"));
	//状态
	//API_DTO_FIELD(String, state, ZH_WORDS_GETTER("forceback.force-back.state"),false,"1900");
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * 定义一个强制回单分页传输对象
 */
class ForceBackPageDTO : public PageDTO<ForceBackDTO::Wrapper>
{
	DTO_INIT(ForceBackPageDTO, PageDTO<ForceBackDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif //!_FORCEBACKDTO_H_

