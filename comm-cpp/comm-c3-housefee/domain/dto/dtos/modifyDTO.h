#pragma once
#ifndef  _MODIFYDTO_H_
#define _MODIFYDTO_H_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)


class modifyDTO :public oatpp::DTO
{
	DTO_INIT(modifyDTO, DTO);
	//fee_type: 费用项
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("modify.get.fee_id"));
	/*API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("modify.get.fee_name"));
	API_DTO_FIELD_DEFAULT(String, obj_name, ZH_WORDS_GETTER("modify.get.obj_name"));*/
	API_DTO_FIELD_DEFAULT(String, fee_pro, ZH_WORDS_GETTER("modify.get.fee_pro"));

	//建账时间
	//API_DTO_FIELD_DEFAULT(String, pay_time, ZH_WORDS_GETTER("modify.get.pay_time"));
	//计费起始时间
	API_DTO_FIELD_DEFAULT(String, pay_start, ZH_WORDS_GETTER("modify.get.pay_start"));
	API_DTO_FIELD_DEFAULT(String, pay_end, ZH_WORDS_GETTER("modify.get.pay_end"));

	//actions : 动作
	API_DTO_FIELD_DEFAULT(String, actions, ZH_WORDS_GETTER("modify.get.actions"));
	//operator : 操作人
	API_DTO_FIELD_DEFAULT(String, oporator, ZH_WORDS_GETTER("modify.get.oporator"));
	//opt_time : 操作时间
	API_DTO_FIELD_DEFAULT(String, opt_time, ZH_WORDS_GETTER("modify.get.opt_time"));
	//CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);

};
/*
* 实例分页传输对象
*/
class modifyPageDTO :public PageDTO<modifyDTO::Wrapper>
{
	DTO_INIT(modifyPageDTO, PageDTO<modifyDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // ! _DETAILCONTROLLER_H_
