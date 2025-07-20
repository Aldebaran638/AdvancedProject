#pragma once
#ifndef _SUMMFEE_DO
#define _SUMMFEE_DO

#include "../DoInclude.h"

/**
 * 费用汇总数据对象
 */
class SummfeeDO
{
public:
    // 创建时间
    CC_SYNTHESIZE(std::string, create_time, Create_time);
    // 费用对象ID
    CC_SYNTHESIZE(std::string, obj_id, Obj_id);
    // 费用对象名称
    CC_SYNTHESIZE(std::string, obj_name, Obj_name);
    // 应收金额
    CC_SYNTHESIZE(int, receivable_amount, Receivable_amount);
    // 实收金额
    CC_SYNTHESIZE(int, amount, Amount);
    

public:
    SummfeeDO() {
        create_time = "";
        obj_id = "";
        obj_name = "";
        receivable_amount = 0;
        amount = 0;
    }
};

// 定义SummfeeDO智能指针类型
typedef std::shared_ptr<SummfeeDO> PtrSummfeeDO;
#endif // !_SUMMFEEDO_H_