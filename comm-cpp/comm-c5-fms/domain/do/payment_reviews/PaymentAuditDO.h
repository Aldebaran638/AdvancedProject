#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yingjiu
 @Date: 2025/05/18 17:51:12

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
#ifndef _PAYMENTAUDIT_DO_
#define _PAYMENTAUDIT_DO_
#include "../DoInclude.h"

/**
 * 缴费审核列表实体
 */
class PaymentAuditListDO
{
    // 房屋
    CC_SYNTHESIZE(string, objname, ObjName);
    // 费用项目
    CC_SYNTHESIZE(string, feename, FeeName);
    // 付费周期
    CC_SYNTHESIZE(int, cycles, Cycles);
    // 缴费起始时间
    CC_SYNTHESIZE(string, starttime, StartTime);
    // 缴费结束时间
    CC_SYNTHESIZE(string, endtime, EndTime);
    // 应付金额
    CC_SYNTHESIZE(int, receivableamount, ReceivableAmount);
    // 实付金额
    CC_SYNTHESIZE(int, receivedamount, ReceivedAmount);
    // 操作员工
    CC_SYNTHESIZE(string, cashiername, CashierName);
    // 缴费时间
    CC_SYNTHESIZE(string, createtime, CreateTime);
    // 审核状态
    CC_SYNTHESIZE(string, state, State);
    // 审核说明
    CC_SYNTHESIZE(string, message, Message);
    // 缴费备注
    CC_SYNTHESIZE(string, remark, Remark);

public:
    PaymentAuditListDO() {
        objname = "";
        feename = "";
        cycles = 0;
        starttime = "";
        endtime = "";
        receivableamount = 0;
        receivedamount = 0;
        cashiername = "";
        createtime = "";
        state = "";
        message = "";
        remark = "";
    }
};
typedef std::shared_ptr<PaymentAuditListDO> PtrPaymentAuditListDO;

/**
 * 缴费审核详情实体
 */
class PaymentAuditDetailDO
{
    // 费用ID
    CC_SYNTHESIZE(string, feeid, FeeId);
    // 费用标识
    CC_SYNTHESIZE(string, feeflag, FeeFlag);
    // 费用类型
    CC_SYNTHESIZE(string, feetypecd, FeeTypeCd);
    // 付费对象
    CC_SYNTHESIZE(string, payerobjname, PayerObjName);
    // 费用项
    CC_SYNTHESIZE(string, feename, FeeName);
    // 费用状态
    CC_SYNTHESIZE(string, feestate, FeeState);
    // 建账时间
    CC_SYNTHESIZE(string, createtimea, CreateTimea);
    // 计费开始时间
    CC_SYNTHESIZE(string, starttime, StartTime);
    // 计费结束时间
    CC_SYNTHESIZE(string, endtime, EndTime);
    // 批次
    CC_SYNTHESIZE(string, batchid, BatchId);
    // 面积
    CC_SYNTHESIZE(int, area, Area);
    // 单价
    CC_SYNTHESIZE(int, squareprice, SquarePrice);
    // 附加费
    CC_SYNTHESIZE(int, feeaddition, FeeAddition);

public:
    PaymentAuditDetailDO() {
        feeid = "";
        feeflag = "";
        feetypecd = "";
        payerobjname = "";
        feename = "";
        feestate = "";
        createtimea = "";
        starttime = "";
        endtime = "";
        batchid = "";
        area = 0;
        squareprice = 0;
        feeaddition = 0;
    }
};
typedef std::shared_ptr<PaymentAuditDetailDO> PtrPaymentAuditDetailDO;

/**
 * 缴费历史实体
 */
class PaymentAuditHistoryDO
{
    // 缴费ID
    CC_SYNTHESIZE(string, detailid, DetailId);
    // 付费周期
    CC_SYNTHESIZE(int, cycles, Cycles);
    // 缴费方式
    CC_SYNTHESIZE(string, primerate, PrimeRate);
    // 应收金额
    CC_SYNTHESIZE(int, receivableamount, ReceivableAmount);
    // 实收金额
    CC_SYNTHESIZE(int, receivedamount, ReceivedAmount);
    // 缴费时间
    CC_SYNTHESIZE(string, createtime, CreateTime);
    // 缴费起始时间
    CC_SYNTHESIZE(string, starttime, StartTime);
    // 缴费结束时间
    CC_SYNTHESIZE(string, endtime, EndTime);
    // 收银员
    CC_SYNTHESIZE(string, cashiername, CashierName);
    // 状态
    CC_SYNTHESIZE(string, statuscd, StatusCd);
    // 备注
    CC_SYNTHESIZE(string, remark, Remark);

public:
    PaymentAuditHistoryDO() {
        detailid = "";
        cycles = 0;
        primerate = "";
        receivableamount = 0;
        receivedamount = 0;
        createtime = "";
        starttime = "";
        endtime = "";
        cashiername = "";
        statuscd = "";
        remark = "";
    }
};
typedef std::shared_ptr<PaymentAuditHistoryDO> PtrPaymentAuditHistoryDO;

#endif // !_PAYMENTAUDIT_DO_