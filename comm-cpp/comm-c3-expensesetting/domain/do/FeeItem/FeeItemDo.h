#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _FEEITEM_DO_
#define _FEEITEM_DO_

#include "../DoInclude.h"
#include <string>
#include <memory>
//#include <functional> // ? 为 std::hash 添加支持

/**
 * 费用项数据库实体类
 */
class FeeItemDO
{
    // 主键 ID
    CC_SYNTHESIZE(std::string, config_id, Config_id);

    // 费用类型
    CC_SYNTHESIZE(std::string, fee_type_cd, Fee_type_cd);

    // 费用标识
    CC_SYNTHESIZE(std::string, fee_flag, Fee_flag);

    // 缴费周期
    CC_SYNTHESIZE(std::string, payment_cycle, Payment_cycle);

    // 收费项目
    CC_SYNTHESIZE(std::string, fee_name, Fee_name);

    // 付费类型
    CC_SYNTHESIZE(std::string, payment_cd, Payment_cd);

    // 预付期
    CC_SYNTHESIZE(std::string, prepayment_period, Prepayment_period);

    // 开始时间
    CC_SYNTHESIZE(std::string, start_time, Start_time);

    // 结束时间
    CC_SYNTHESIZE(std::string, end_time, End_time);

    // 单位
    CC_SYNTHESIZE(std::string, units, Units);

    // 是否支持账户抵扣
    CC_SYNTHESIZE(std::string, deduct_from, Deduct_from);

    // 手机缴费
    CC_SYNTHESIZE(std::string, pay_online, Pay_online);

    // 进位方式
    CC_SYNTHESIZE(std::string, scale, Scale);

    // 保留小数位
    CC_SYNTHESIZE(int, decimal_place, Decimal_place);

    // 计算公式
    CC_SYNTHESIZE(std::string, computing_formula, Computing_formula);

    // 计费单价
    CC_SYNTHESIZE(std::string, square_price, Square_price);

    // 固定费用
    CC_SYNTHESIZE(std::string, additional_amount, Additional_amount);


    // 创建人
    //CC_SYNTHESIZE(std::string, createBy, CreateBy);

    // 创建时间
    CC_SYNTHESIZE(std::string, create_Time, Create_Time);

    //// 修改人
    //CC_SYNTHESIZE(std::string, updateBy, UpdateBy);

    //// 修改时间
    //CC_SYNTHESIZE(std::string, updateTime, UpdateTime);

    // 社区 ID
    CC_SYNTHESIZE(std::string, community_id, Community_id);

    //业务id
    CC_SYNTHESIZE(std::string, b_id, B_id);

    // 操作
    CC_SYNTHESIZE(std::string, operate, Operate);

    //默认费用
    CC_SYNTHESIZE(std::string, is_default, Is_default);

    //出账类型
    CC_SYNTHESIZE(std::string, bill_type, Bill_type);

    //自定义公示内容
    CC_SYNTHESIZE(std::string, computing_formula_text, Computing_formula_text);



    //数据状态
    CC_SYNTHESIZE(std::string, status_cd, Status_cd);
    // 用户ID
    CC_SYNTHESIZE(std::string, user_Id, User_Id);  // 生成 getUserId() / setUserId()
    // 用户name
    CC_SYNTHESIZE(std::string, name, Name);
public:
    FeeItemDO() {
        config_id = "";
        b_id = "- 1";
        fee_type_cd = "888800010008";
        fee_flag = "1003006";
        payment_cycle = "1";
        fee_name = "";
        payment_cd = "1200";
        prepayment_period = "NULL";
        start_time = "";
        end_time = "";
        units = "元";
        deduct_from = "Y";
        pay_online = "Y";
        scale = "1";
        decimal_place = 2;
        computing_formula = "1001";
        square_price = "";
        additional_amount = "";
        //createBy = "";
        //createTime = CURRENT_TIMESTAMP;
        //updateBy = "";
        //updateTime = "";
        community_id = "1";
        b_id= "";
        operate = "ADD";
        is_default = "F";
        bill_type = "004";
        computing_formula_text = "NULL";
        status_cd = "0";
        user_Id = "";
    }
};

    //    // ? 重载等于运算符（基于 config_id）
    //    bool operator==(const FeeItemDO& other) const {
    //        return this->config_id == other.config_id;
    //    }
    //};
    //
    //// ? 特化 std::hash，让 FeeItemDO 支持哈希容器（如 unordered_map）
    //namespace std {
    //    template<>
    //    struct hash<FeeItemDO> {
    //        std::size_t operator()(const FeeItemDO& k) const {
    //            return std::hash<std::string>()(k.getConfig_id());
    //        }
     
    

    // ? 智能指针别名
    typedef std::shared_ptr<FeeItemDO> PtrFeeItemDO;

#endif // !_FEEITEM_DO_
