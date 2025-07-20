#pragma once
#ifndef _HOUSEFEEMGRDTO_H_
#define _HOUSEFEEMGRDTO_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//详情的dto
class HouseFeeMgrDTO :public oatpp::DTO
{
	DTO_INIT(HouseFeeMgrDTO, DTO);
	//费用id
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("HouseFeeMgr.field.fee_id"));
	//费用项目
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("HouseFeeMgr.field.fee_name"));
	//费用标识
	API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("HouseFeeMgr.field.fee_flag"));
	//费用类型
	API_DTO_FIELD_DEFAULT(String, fee_type, ZH_WORDS_GETTER("HouseFeeMgr.field.fee_type"));
	//应收金额
	API_DTO_FIELD_DEFAULT(Float32, fee_pay, ZH_WORDS_GETTER("HouseFeeMgr.field.fee_pay"));
	//建帐时间
	API_DTO_FIELD_DEFAULT(String, makeTime, ZH_WORDS_GETTER("HouseFeeMgr.field.makeTime"));
	//计费起始时间
	API_DTO_FIELD_DEFAULT(String, startTime, ZH_WORDS_GETTER("HouseFeeMgr.field.startTime"));
	//计费结束时间
	API_DTO_FIELD_DEFAULT(String, endTime, ZH_WORDS_GETTER("HouseFeeMgr.field.endTime"));
	//状态
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("HouseFeeMgr.field.status"));
	//业主id
	API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("HouseFeeMgr.field.owner_id"));
	//业主名称
	API_DTO_FIELD_DEFAULT(String, ownerNameLike, ZH_WORDS_GETTER("HouseFeeMgr.field.ownerNameLike"));
	//房屋号
	API_DTO_FIELD_DEFAULT(String, roomNum, ZH_WORDS_GETTER("HouseFeeMgr.field.roomNum"));
	//业主联系方式
	API_DTO_FIELD_DEFAULT(String, owner_phone, ZH_WORDS_GETTER("HouseFeeMgr.field.owner_phone"));
	//费用批次
	API_DTO_FIELD_DEFAULT(String, fee_order, ZH_WORDS_GETTER("HouseFeeMgr.field.fee_order"));
};
//分页的dto
class HouseFeeMgrPageDTO :public PageDTO<HouseFeeMgrDTO::Wrapper>
{
	DTO_INIT(HouseFeeMgrPageDTO, PageDTO<HouseFeeMgrDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif
