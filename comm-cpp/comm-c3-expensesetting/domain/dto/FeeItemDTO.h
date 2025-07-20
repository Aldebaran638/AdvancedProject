#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: awei
 @Date: 2025/05/17
*/

#ifndef _FEEITEMDTO_H_
#define _FEEITEMDTO_H_
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include "../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 添加费用项传输模型
 */
class FeeItemAddDTO : public oatpp::DTO
{
    DTO_INIT(FeeItemAddDTO, DTO);

    // 费用类型
    API_DTO_FIELD_DEFAULT(String, fee_type_cd, ZH_WORDS_GETTER("fee-item.field.fee_type_cd"));

    // 费用标识
    API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("fee-item.field.fee_flag"));

    // 缴费周期
    API_DTO_FIELD_DEFAULT(String, payment_cycle, ZH_WORDS_GETTER("fee-item.field.payment_cycle"));

    // 收费项目
    API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("fee-item.field.fee_name"));

    // 付费类型
    API_DTO_FIELD_DEFAULT(String, payment_cd, ZH_WORDS_GETTER("fee-item.field.payment_cd"));

    // 预付期
    API_DTO_FIELD_DEFAULT(String, prepayment_period, ZH_WORDS_GETTER("fee-item.prepayment_period"));

    // 开始时间
    API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("fee-item.field.start_time"));

    // 结束时间
    API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("fee-item.field.end_time"));

    // 单位
    API_DTO_FIELD_DEFAULT(String, units, ZH_WORDS_GETTER("fee-item.field.units"));

    // 是否支持账户抵扣
    API_DTO_FIELD_DEFAULT(String, deduct_from, ZH_WORDS_GETTER("fee-item.field.deduct_from"));

    // 手机缴费
    API_DTO_FIELD_DEFAULT(String, pay_online, ZH_WORDS_GETTER("fee-item.field.pay_online"));

    // 进位方式
    API_DTO_FIELD_DEFAULT(String, scale, ZH_WORDS_GETTER("fee-item.field.scale"));

    // 保留小数位
    API_DTO_FIELD(Int32, decimal_place, ZH_WORDS_GETTER("fee-item.field.decimal_place"), true, 2);

    // 计算公式
    API_DTO_FIELD_DEFAULT(String, computing_formula, ZH_WORDS_GETTER("fee-item.field.computing_formula"));

    // 计费单价
    API_DTO_FIELD_DEFAULT(String, square_price, ZH_WORDS_GETTER("fee-item.field.square_price"));

    // 固定费用
    API_DTO_FIELD_DEFAULT(String, additional_amount, ZH_WORDS_GETTER("fee-item.field.additional_amount"));

    // 社区 ID
    API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("fee-item.field.community_id"));

    ////  新字段：前端看到的是 operationTime
    //API_DTO_FIELD_DEFAULT(String, operationTime, ZH_WORDS_GETTER("fee-item.field.operation_time"));
    //// 用户ID
    //API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("fee-item.field.user_id"));



    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};


/**
 * 完整费用项 DTO（带主键 ID）
 */
class FeeItemDTO : public FeeItemAddDTO
{
    DTO_INIT(FeeItemDTO, FeeItemAddDTO);

    // 主键 ID
    API_DTO_FIELD_DEFAULT(String, config_id, ZH_WORDS_GETTER("fee-itemlog.field.caId"));
    //  新字段：前端看到的是 operationTime
    API_DTO_FIELD_DEFAULT(String, operation_Time, ZH_WORDS_GETTER("fee-item.field.operation_time"));
    //API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("fee-item.field.user_id"));
    API_DTO_FIELD_DEFAULT(String, user_name, ZH_WORDS_GETTER("fee-item.field.user_name"));// 显示用户名

};


/**
 * 分页费用项 DTO（用于分页查询结果）
 */
class FeeItemPageDTO : public PageDTO<FeeItemDTO::Wrapper>
{
    DTO_INIT(FeeItemPageDTO, PageDTO<FeeItemDTO::Wrapper>);
};

/**
 * 修改费用项传输模型
 */
class FeeItemModifyDTO : public FeeItemAddDTO
{
    DTO_INIT(FeeItemModifyDTO, FeeItemAddDTO);

    // 主键 ID
    API_DTO_FIELD_DEFAULT(String, config_id, ZH_WORDS_GETTER("fee-itemlog.field.caId"));
    //API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("fee-item.field.user_id"));
};
class FeeItemDeleteDTO : public oatpp::DTO {

    DTO_INIT(FeeItemDeleteDTO, DTO)

        DTO_FIELD(String, config_id); // 仅保留 config_id 一个字段
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FEEITEMDTO_H_
