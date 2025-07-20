#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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
#ifndef _FEE_ITEM_MAPPER_
#define _FEE_ITEM_MAPPER_
    
#include "Mapper.h"
#include "../../domain/do/FeeItem/FeeItemDo.h"

/**
 * 费用项表字段匹配映射
 */
class FeeItemPostMapper : public Mapper<FeeItemDO>
{
public:
    FeeItemDO mapper(ResultSet* resultSet) const override
    {
        FeeItemDO data;
        data.setConfig_id(resultSet->getString(1));        // config_id
        data.setB_id(resultSet->getString(2));             // b_id
        data.setCommunity_id(resultSet->getString(3));     // community_id
        data.setFee_type_cd(resultSet->getString(4));      // fee_type_cd
        data.setSquare_price(resultSet->getString(5));     // square_price
        data.setAdditional_amount(resultSet->getString(6));// additional_amount
        data.setOperate(resultSet->getString(8));          // operate
        data.setIs_default(resultSet->getString(9));       // is_default
        data.setStart_time(resultSet->getString(10));      // start_time
        data.setEnd_time(resultSet->getString(11));        // end_time
        data.setFee_flag(resultSet->getString(12));        // fee_flag
        data.setFee_name(resultSet->getString(13));        // fee_name
        data.setComputing_formula(resultSet->getString(14)); // computing_formula
        data.setBill_type(resultSet->getString(15));       // bill_type
        data.setPayment_cycle(resultSet->getString(16));   // payment_cycle
        data.setPayment_cd(resultSet->getString(17));      // payment_cd
        data.setComputing_formula_text(resultSet->getString(18)); // computing_formula_text
        data.setDeduct_from(resultSet->getString(19));     // deduct_from
        data.setUnits(resultSet->getString(20));            // units
        data.setDecimal_place(resultSet->getInt(21));       // decimal_place
        data.setScale(resultSet->getString(22));            // scale
        data.setPay_online(resultSet->getString(23));       // pay_online
        data.setPrepayment_period(resultSet->getString(24));// prepayment_period
        data.setUser_Id(resultSet->getString(25));        // create_by
        return data;
        //data.setConfig_id(resultSet->getString(1));
        //data.setFee_type_cd(resultSet->getString(2));
        //data.setFee_flag(resultSet->getString(3));
        //data.setPayment_cycle(resultSet->getString(4));
        //data.setFee_name(resultSet->getString(5));
        //data.setPayment_cd(resultSet->getString(6));
        //data.setPrepayment_period(resultSet->getString(7));
        //data.setStart_time(resultSet->getString(8));
        //data.setEnd_time(resultSet->getString(9));
        //data.setUnits(resultSet->getString(10));
        //data.setDeduct_from(resultSet->getString(11));
        //data.setPay_online(resultSet->getString(12));
        //data.setScale(resultSet->getString(13));
        //data.setDecimal_place(resultSet->getInt(14));
        //data.setComputing_formula(resultSet->getString(15));
        //data.setSquare_price(resultSet->getString(16));
        //data.setAdditional_amount(resultSet->getString(17));
        ////data.setCreateBy(resultSet->getString(18));
        ////data.setCreateTime(resultSet->getString(19));
        //// 如果你将 updateBy 和 updateTime 用注释去掉，可以忽略
        //// data.setUpdateBy(resultSet->getString(20));
        //// data.setUpdateTime(resultSet->getString(21));
        //data.setCommunity_id(resultSet->getString(20));  // 注意字段位置根据实际数据库顺序调整
        //data.setB_id(resultSet->getString(21));
        //data.setOperate(resultSet->getString(22));
        ////data.setIs_default(resultSet->getString(23));
        ////data.setBill_type(resultSet->getString(24));
        ////data.setComputing_formula_text(resultSet->getString(25));
        ////data.setStatus_cd(resultSet->getString(26));
        //return data;
    }
};

/**
 * 费用项表字段匹配映射 - 创建智能指针对象
 */
class PtrFeeItemMapper : public Mapper<PtrFeeItemDO>
{
public:
    PtrFeeItemDO mapper(ResultSet* resultSet) const override
    {
        auto data = std::make_shared<FeeItemDO>();
        data->setConfig_id(resultSet->getString(1));
        data->setFee_type_cd(resultSet->getString(2));
        data->setFee_flag(resultSet->getString(3));
        data->setPayment_cycle(resultSet->getString(4));
        data->setFee_name(resultSet->getString(5));
        data->setPayment_cd(resultSet->getString(6));
        data->setPrepayment_period(resultSet->getString(7));
        data->setStart_time(resultSet->getString(8));
        data->setEnd_time(resultSet->getString(9));
        data->setUnits(resultSet->getString(10));
        data->setDeduct_from(resultSet->getString(11));
        data->setPay_online(resultSet->getString(12));
        data->setScale(resultSet->getString(13));
        data->setDecimal_place(resultSet->getInt(14));
        data->setComputing_formula(resultSet->getString(15));
        data->setSquare_price(resultSet->getString(16));
        data->setAdditional_amount(resultSet->getString(17));
        //data->setCreateBy(resultSet->getString(18));
        //data->setCreateTime(resultSet->getString(19));
        // data->setUpdateBy(resultSet->getString(20));
        // data->setUpdateTime(resultSet->getString(21));
        data->setCommunity_id(resultSet->getString(20));
        data->setB_id(resultSet->getString(21));
        data->setOperate(resultSet->getString(22));
        /*data->setIs_default(resultSet->getString(23));
        data->setBill_type(resultSet->getString(24));
        data->setComputing_formula_text(resultSet->getString(25));
        data->setStatus_cd(resultSet->getString(26));*/
        return data;
    }
};

#endif // !_FEE_ITEM_MAPPER_
