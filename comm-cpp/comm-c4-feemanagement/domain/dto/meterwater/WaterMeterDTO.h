#pragma once
#ifndef _WATERMETERDTO_H_
#define _WATERMETERDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 水电抄表新增数据传输对象
 */
class WaterMeterAddDTO : public oatpp::DTO
{
	DTO_INIT(WaterMeterAddDTO, DTO);
	//// 费用类型
	//DTO_FIELD(String, fee_type_cd);
	//DTO_FIELD_INFO(fee_type_cd) {
	//	info->description = ZH_WORDS_GETTER("watermeter.feetype");
	//}
	//// 收费项目
	//DTO_FIELD(String, config_id);
	//DTO_FIELD_INFO(config_id) {
	//	info->description = ZH_WORDS_GETTER("watermeter.feeproject");
	//}
	// 	
	// 抄表类型
	DTO_FIELD(String, meter_type);
	DTO_FIELD_INFO(meter_type) {
		info->description = ZH_WORDS_GETTER("watermeter.metertype");
	}
	//房屋名称（楼栋-单元-房间号）
	DTO_FIELD(String, obj_name);
	DTO_FIELD_INFO(obj_name) {
		info->description = ZH_WORDS_GETTER("watermeter.roomid");
	}
	//上期度数
	DTO_FIELD(Float32, pre_degrees);
	DTO_FIELD_INFO(pre_degrees) {
		info->description = ZH_WORDS_GETTER("watermeter.predegrees");
	}
	//本期度数
	DTO_FIELD(Float32, cur_degrees);
	DTO_FIELD_INFO(cur_degrees) {
		info->description = ZH_WORDS_GETTER("watermeter.curdegrees");
	}
	//上期读表时间
	DTO_FIELD(String, pre_reading_time);
	DTO_FIELD_INFO(pre_reading_time) {
		info->description = ZH_WORDS_GETTER("watermeter.prereadtime");
	}
	//本期读表时间
	DTO_FIELD(String, cur_reading_time);
	DTO_FIELD_INFO(cur_reading_time) {
		info->description = ZH_WORDS_GETTER("watermeter.curreadtime");
	}
	//备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("watermeter.remark");
	}
	////类型 1001 房屋 2002 车位
	//DTO_FIELD(String, obj_type);
	//DTO_FIELD_INFO(obj_type) {
	//	info->description = ZH_WORDS_GETTER("watermeter.objtype");
	//}
	////对象ID，1001 是房屋 2002 是车位
	//DTO_FIELD(String, obj_id);
	//DTO_FIELD_INFO(obj_id) {
	//	info->description = ZH_WORDS_GETTER("watermeter.objtype");
	//}

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * 水电抄表传输对象
 */
class WaterMeterDTO : public WaterMeterAddDTO
{
	DTO_INIT(WaterMeterDTO, WaterMeterAddDTO);
	// 表编号id
	DTO_FIELD(String, water_id);
	DTO_FIELD_INFO(water_id) {
		info->description = ZH_WORDS_GETTER("watermeter.meterid");
	}
	//创建时间
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("watermeter.createtime");
	}

};



/**
 * 水电抄表删除数据传输对象
 */
class WaterMeterDeleteDTO : public oatpp::DTO
{
	DTO_INIT(WaterMeterDeleteDTO, DTO);
	// 表编号id
	DTO_FIELD(String, water_id);
	DTO_FIELD_INFO(water_id) {
		info->description = ZH_WORDS_GETTER("watermeter.meterid");
	}
};

/**
 * 水电抄表修改数据传输对象
 */
class WaterMeterUpdateDTO : public WaterMeterDTO
{
	DTO_INIT(WaterMeterUpdateDTO, WaterMeterDTO);
};


/**
 * 水电抄表分页传输对象
 */
class WaterMeterPageDTO : public PageDTO<WaterMeterDTO::Wrapper>
{
	DTO_INIT(WaterMeterPageDTO, PageDTO<WaterMeterDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_WATERMETERDTO_H_
