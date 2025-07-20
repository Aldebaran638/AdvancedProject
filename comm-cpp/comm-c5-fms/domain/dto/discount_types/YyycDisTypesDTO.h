#pragma once
#ifndef _YYYCDISTYPESDTO_H_
#define _YYYCDISTYPESDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
	优惠类型模型
*/
class YyycDisTypesDTO : public oatpp::DTO
{
	DTO_INIT(YyycDisTypesDTO, DTO);

	// 类型名称
	API_DTO_FIELD_DEFAULT(String, type_name, ZH_WORDS_GETTER("type.field.type_name"));
	// 类型描述
	API_DTO_FIELD_DEFAULT(String, type_desc, ZH_WORDS_GETTER("type.field.type_desc"));
	// 类型id
	API_DTO_FIELD_DEFAULT(String, type_id, ZH_WORDS_GETTER("type.field.type_id"));

	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};
/*
	修改优惠类型模型（比较完整，由于列表数据）
*/
class YyycDisTypesUpdateDTO : public YyycDisTypesDTO {
	DTO_INIT(YyycDisTypesUpdateDTO, YyycDisTypesDTO);

	// 校区id
	API_DTO_FIELD_DEFAULT(String, type_comm_id, ZH_WORDS_GETTER("type.field.type_comm_id"));
	// 创建时间
	API_DTO_FIELD_DEFAULT(String, creat_time, ZH_WORDS_GETTER("type.field.creat_time"));
	// 数据状态
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("type.field.status"));
};

#include OATPP_CODEGEN_BEGIN(DTO)

#endif  //!_YYYCDISTYPESDTO_H_