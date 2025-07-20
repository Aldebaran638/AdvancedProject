#pragma once
#ifndef _FEEMGRDTO_H_
#define _FEEMGRDTO_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 添加折扣传输模型
 */
class FeeMgrAddDTO : public oatpp::DTO
{
    DTO_INIT(FeeMgrAddDTO, DTO);
    //折扣类型
    API_DTO_FIELD_DEFAULT(String, discount_type, ZH_WORDS_GETTER("FeeMgr.field.discount_type"));
    //折扣名称
    API_DTO_FIELD_DEFAULT(String, discount_name, ZH_WORDS_GETTER("FeeMgr.field.discount_name"));
   //缴费起始时间
    API_DTO_FIELD_DEFAULT(String,start_time, ZH_WORDS_GETTER("FeeMgr.field.start_time"));
	//缴费结束时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("FeeMgr.field.end_time"));
    //折扣终止时间
    API_DTO_FIELD_DEFAULT(String,discount_end_time, ZH_WORDS_GETTER("FeeMgr.field.discount_end_time"));

    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};


//删除折扣传输模型
class FeeMgrDeleteDTO : public oatpp::DTO
{
    DTO_INIT(FeeMgrDeleteDTO, DTO);
    //折扣ID
    API_DTO_FIELD_DEFAULT(String, discount_id, ZH_WORDS_GETTER("FeeMgr.field.discount_id"));
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

//获取费用项基础信息传输模型
class FeeMgrGetDTO : public oatpp::DTO
{
    DTO_INIT(FeeMgrGetDTO, DTO);
    //折扣ID
    API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("FeeMgr.field.fee_id"));
    //费用类型
    API_DTO_FIELD_DEFAULT(String, fee_type, ZH_WORDS_GETTER("FeeMgr.field.fee_type"));
    //收费项目
    API_DTO_FIELD_DEFAULT(String, fee_project, ZH_WORDS_GETTER("FeeMgr.field.fee_project"));
    //费用标识
    API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("FeeMgr.field.fee_flag"));
    //催缴类型
    API_DTO_FIELD_DEFAULT(String, urge_type, ZH_WORDS_GETTER("FeeMgr.field.urge_type"));
    //付费类型
    API_DTO_FIELD_DEFAULT(String, pay_type, ZH_WORDS_GETTER("FeeMgr.field.pay_type"));
    //付费周期
    API_DTO_FIELD_DEFAULT(String, pay_cycle, ZH_WORDS_GETTER("FeeMgr.field.pay_cycle"));
    //有效期
    API_DTO_FIELD_DEFAULT(String, valid_time, ZH_WORDS_GETTER("FeeMgr.field.valid_time"));
    //公式
    API_DTO_FIELD_DEFAULT(String, pay_formula, ZH_WORDS_GETTER("FeeMgr.field.pay_formula"));
    //计费单价
    API_DTO_FIELD_DEFAULT(String, pay_price, ZH_WORDS_GETTER("FeeMgr.field.pay_price"));
    //计费附加
    API_DTO_FIELD_DEFAULT(String, pay_extra, ZH_WORDS_GETTER("FeeMgr.field.pay_extra"));
    //账户抵扣
    API_DTO_FIELD_DEFAULT(String, account_deduction, ZH_WORDS_GETTER("FeeMgr.field.account_deduction"));

    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * 完整费用项 DTO（带主键 ID）
 */
class FeeMgrDTO : public FeeMgrAddDTO
{
    DTO_INIT(FeeMgrDTO, FeeMgrAddDTO);

    // 主键 ID
    API_DTO_FIELD_DEFAULT(String, discount_id, ZH_WORDS_GETTER("FeeMgr.field.discount_id"));
};


//分页的dto
class FeeMgrPageDTO :public PageDTO<FeeMgrDTO::Wrapper>
{
    DTO_INIT(FeeMgrPageDTO, PageDTO<FeeMgrDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif
