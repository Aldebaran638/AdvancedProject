#pragma once

#ifndef _CAR_DTO_
#define _CAR_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 车辆信息传输数据对象
 */
class CarDTO : public oatpp::DTO 
{
	DTO_INIT(CarDTO, DTO);
	// 车牌号
	API_DTO_FIELD_DEFAULT(String, car_num, ZH_WORDS_GETTER("car.field.car_num"));
	// 成员车辆数
	//API_DTO_FIELD_DEFAULT(Int32, member_car_num, ZH_WORDS_GETTER("car.field.member_num"));
	// 房屋号 楼栋-单元-房屋
	//API_DTO_FIELD_DEFAULT(String, room_num, ZH_WORDS_GETTER("car.field.room_num"));
	// 车牌类型 9901 家用小汽车，9902 客车，9903 货车
	API_DTO_FIELD_DEFAULT(String, lease_type, ZH_WORDS_GETTER("car.field.lease_type"));
	// 车辆类型 H 月租车 S 出售车 I 内部车 NM 免费车
	API_DTO_FIELD_DEFAULT(String, car_type, ZH_WORDS_GETTER("car.field.car_type"));
	// 颜色
	API_DTO_FIELD_DEFAULT(String, car_color, ZH_WORDS_GETTER("car.field.car_color"));
	// 业主
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("car.field.name"));
	// 车位编号
	API_DTO_FIELD_DEFAULT(String, num, ZH_WORDS_GETTER("car.field.num"));
	//有效期
	API_DTO_FIELD_DEFAULT(String, valid_time, ZH_WORDS_GETTER("car.field.valid_time"));
	// 状态 0 正常 1 停用
	//API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("car.field.state"));
	// 备注
	//API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("car.field.remark"));
};



class CarPageDTO : public PageDTO<CarDTO::Wrapper>
{
	DTO_INIT(CarPageDTO, PageDTO<CarDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif
