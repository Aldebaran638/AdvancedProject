#pragma once
#ifndef _UNIT_DTO_
#define _UNIT_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个修改单元信息的数据传输模型
 */
class UnitAddDTO : public oatpp::DTO
{
	DTO_INIT(UnitAddDTO, DTO);
	//单元编号
	API_DTO_FIELD_DEFAULT(String, unit_num, ZH_WORDS_GETTER("unit.field.unitnum"));
	//总层数
	API_DTO_FIELD_DEFAULT(Int32, layer_count, ZH_WORDS_GETTER("unit.field.layercount"));
	//单元面积
	API_DTO_FIELD_DEFAULT(String, unit_area, ZH_WORDS_GETTER("unit.field.unitarea"));
	//电梯状态
	API_DTO_FIELD_DEFAULT(String, lift, ZH_WORDS_GETTER("unit.field.lift"));
	//备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("unit.field.remark"));

	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

class UnitDTO : public UnitAddDTO {
	DTO_INIT(UnitDTO, UnitAddDTO);
	//业务ID
	API_DTO_FIELD_DEFAULT(String, b_id, ZH_WORDS_GETTER("unit.field.bid"));
	//单元ID
	API_DTO_FIELD_DEFAULT(String, unit_id, ZH_WORDS_GETTER("unit.field.unitid"));
	//楼ID
	API_DTO_FIELD_DEFAULT(String, floor_id, ZH_WORDS_GETTER("unit.field.floorid"));
	//总层数
	API_DTO_FIELD_DEFAULT(Int32, layer_count, ZH_WORDS_GETTER("unit.field.layer_count"));
	//是否有电梯 1010有 2020 无
	API_DTO_FIELD_DEFAULT(String, lift, ZH_WORDS_GETTER("unit.field.lift"));
	//用户ID
	API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("unit.field.userid"));
	//备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("unit.field.remark"));
	//单元面积
	API_DTO_FIELD_DEFAULT(String, unit_area, ZH_WORDS_GETTER("unit.field.unit_area"));
	//楼编号(连接查询用)
	API_DTO_FIELD_DEFAULT(String, floor_num, ZH_WORDS_GETTER("floor.field.floor_num"));
	//数据状态
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("unit.field.statuscd"));
	//创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("unit.field.create_time"));
};

class UnitPageDTO : public PageDTO<UnitDTO::Wrapper>
{
	DTO_INIT(UnitPageDTO, PageDTO<UnitDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif