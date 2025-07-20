#pragma once

#ifndef _PAYFEE_DO_
#define _PAYFEE_DO_
#include "DoInclude.h"
/**
 * 费用项数据库实体类
 */
class PayFeeDO
{
    // 主键 ID
    CC_SYNTHESIZE(string, config_id, Config_id);

    // 费用类型
    CC_SYNTHESIZE(string, fee_type_cd, Fee_type_cd);

    // 收费项目
    CC_SYNTHESIZE(string, fee_name, Fee_name);

    // 费用标识
    CC_SYNTHESIZE(string, fee_flag, Fee_flag);

    // 付费类型
    CC_SYNTHESIZE(string, payment_cd, Payment_cd);

    // 缴费周期
    CC_SYNTHESIZE(int, payment_cycle, Payment_cycle);

    CC_SYNTHESIZE(string, start_time, Start_time);

    CC_SYNTHESIZE(string, end_time, End_time);

    // 计算公式
    CC_SYNTHESIZE(string, computing_formula, Computing_formula);

    // 计费单价
    CC_SYNTHESIZE(string, square_price, Square_price);

    // 固定费用
    CC_SYNTHESIZE(string, additional_amount, Additional_amount);

    // 是否支持账户抵扣
    CC_SYNTHESIZE(string, deduct_from, Deduct_from);


public:
    PayFeeDO() {
        config_id = "";
        fee_type_cd = "";
        fee_name = "";
        fee_flag = "";
        payment_cd = "";
        payment_cycle = 0;  
        start_time = "";
        end_time = "";
        computing_formula = "";
        square_price = "";
        additional_amount = "";
        deduct_from = "";
    }
};

class ChargeItemDO
{
    CC_SYNTHESIZE(string, config_id, Config_id);
    CC_SYNTHESIZE(string, fee_type_cd, Fee_type_cd);
    CC_SYNTHESIZE(string, chargeItem, ChargeItem);
    ChargeItemDO() {
        config_id = "";
        fee_type_cd = "";
        chargeItem = "";
    }
};


#endif // !_FEEITEM_DO_