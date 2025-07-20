#pragma once

#ifndef _OWNER_DTO_
#define _OWNER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class OwnerDTO :public oatpp::DTO
{
	DTO_INIT(OwnerDTO, DTO);
	//业主id
	API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("owner.field.id"));
	//业主姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("owner.field.name"));
	//业主人脸
	API_DTO_FIELD(String, file_real_name, ZH_WORDS_GETTER("owner.field.img-url"), false, {});
	//业主性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("owner.field.sex"));
	//业主身份证
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("owner.field.id_card"));
	//联系方式
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("owner.field.link"));
	//家庭住址
	API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("owner.field.address"));
	//房屋数
	API_DTO_FIELD_DEFAULT(Int32, house_num, ZH_WORDS_GETTER("owner.field.house_num"));
	//业主成员数量
	API_DTO_FIELD_DEFAULT(Int32, member_num, ZH_WORDS_GETTER("owner.field.owner_member_num"));
	//车辆数
	API_DTO_FIELD_DEFAULT(Int32, car_number, ZH_WORDS_GETTER("owner.field.car_number"));
	//投诉数
	API_DTO_FIELD_DEFAULT(Int32, complaint_num, ZH_WORDS_GETTER("owner.field.complaint_num"));
	//报修数
	API_DTO_FIELD_DEFAULT(Int32, repair_num, ZH_WORDS_GETTER("owner.field.repair_num"));
	//欠费金额
	API_DTO_FIELD_DEFAULT(String, amount_owed, ZH_WORDS_GETTER("owner.field.amount_owed"))
	//合同数
	API_DTO_FIELD_DEFAULT(Int32, contract_num, ZH_WORDS_GETTER("owner.field.context"));
	//门禁钥匙
	API_DTO_FIELD_DEFAULT(String, access_control_key, ZH_WORDS_GETTER("owner.field.key"));
};


class OwnerPageDTO : public PageDTO<OwnerDTO::Wrapper>
{
	DTO_INIT(OwnerPageDTO, PageDTO<OwnerDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif

