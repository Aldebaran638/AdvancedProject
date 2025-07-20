#pragma once
#ifndef _CARPAYMENT_DO_
#define _CARPAYMENT_DO_
#include "../DoInclude.h"

class GetVehicleFeeDO
{
    CC_SYNTHESIZE(string, fee_id, FeeId);        // 缴费费ID
    CC_SYNTHESIZE(string, fee_flag, FeeFlag);    // 费用标识 
    CC_SYNTHESIZE(string, fee_type_cd, FeeTypeCd); // 费用类型
    CC_SYNTHESIZE(string, value, Value);         // 付费对象
    CC_SYNTHESIZE(string, fee_name, FeeName);    // 费用项
    CC_SYNTHESIZE(string, state, State);         // 状态 （没有找到对应的）
    CC_SYNTHESIZE(string, create_time, CreateTime);// 建账时间
    CC_SYNTHESIZE(string, start_time, StartTime);// 应收开始时间
    CC_SYNTHESIZE(string, end_time, EndTime);    // 应收结束时间
    CC_SYNTHESIZE(string, batch_id, BatchId);    // 批次
    CC_SYNTHESIZE(float, owe_amount, OweAmount); //欠费金额
    CC_SYNTHESIZE(string, owner_id, OwnerId);    // 业主ID
    CC_SYNTHESIZE(string, owner_name, OwnerName);// 业主姓名
    CC_SYNTHESIZE(string, link, Link);           // 业主联系方式

public:
    GetVehicleFeeDO() :
        fee_id(""),
        fee_flag(""),
        fee_type_cd(""),
        value(""),
        fee_name(""),
        state(""),
        create_time(""),
        start_time(""),
        end_time(""),
        batch_id(""),
        owe_amount(-1),
        owner_id(""),
        owner_name(""),
        link("")
    {
    }
};

typedef std::shared_ptr<GetVehicleFeeDO> PtrGetVehicleFeeDO;

class GetPaymentRecordsDO
{

	CC_SYNTHESIZE(string, fee_name, FeeName); // 费用项
	CC_SYNTHESIZE(string, value, Value); // 付费对象
	CC_SYNTHESIZE(float, cycle, Cycle); // 周期(单位:月)
	CC_SYNTHESIZE(float, receivable_amount, ReceivableAmount); // 应收金额
	CC_SYNTHESIZE(float, received_amount, ReceivedAmount); // 实收金额
	CC_SYNTHESIZE(string, create_time, CreateTime); // 建账时间
	CC_SYNTHESIZE(string, pay_fee_time, PayFeeTime); // 缴费时间
    CC_SYNTHESIZE(string, cashier_name, CashierName); // 收银员
    CC_SYNTHESIZE(string, status_cd, StatusCd); // 状态
    CC_SYNTHESIZE(string, remark, Remark); // 备注
public:
    GetPaymentRecordsDO() {
        fee_name = "";
        value = "";
        cycle = 0;
        receivable_amount = -1;
        received_amount = -1;
        create_time = "";
        pay_fee_time = "";
        cashier_name = "";
        status_cd = "";
        remark = "";
    }
};

// 给GetPaymentRecordsDO智能指针设定一个别名方便使用
typedef std::shared_ptr<GetPaymentRecordsDO> PtrGetPaymentRecordsDO;

class GetPaymentDetailedRecordDO
{
    CC_SYNTHESIZE(string, fee_id, FeeId); // 缴费ID
    CC_SYNTHESIZE(float, cycle, Cycle); // 周期(单位:月)
    CC_SYNTHESIZE(float, receivable_amount, ReceivableAmount); // 应收金额
    CC_SYNTHESIZE(float, received_amount, ReceivedAmount); // 实收金额
    CC_SYNTHESIZE(string, pay_fee_time, PayFeeTime); // 缴费时间
    CC_SYNTHESIZE(string, create_time, CreateTime); // 建账时间
    CC_SYNTHESIZE(string, deadline_time, DeadlineTime); // 缴费结束时间
    CC_SYNTHESIZE(string, cashier_name, CashierName); // 收银员
    CC_SYNTHESIZE(string, status_cd, StatusCd); // 状态
    CC_SYNTHESIZE(string, remark, Remark); // 备注
public:
    GetPaymentDetailedRecordDO() {
        cycle = 0;
        receivable_amount = -1;
        received_amount = -1;
        pay_fee_time = "";
        create_time = "";
        deadline_time = "";
        cashier_name = "";
        status_cd = "";
        remark = "";
    }
};

// 给GetPaymentDetailedRecordDO智能指针设定一个别名方便使用
typedef std::shared_ptr<GetPaymentDetailedRecordDO> PtrGetPaymentDetailedRecordDO;

class GetFeeModificationRecordsDO
{
    CC_SYNTHESIZE(string, fee_name, FeeName); // 费用项
    CC_SYNTHESIZE(string, create_time, CreateTime); // 建账时间
    CC_SYNTHESIZE(string, start_time, StartTime); // 应收开始时间
    CC_SYNTHESIZE(string, create_user_name, CreateUserName); // 操作人
    //CC_SYNTHESIZE(string, cur_month_time, CurMonthTime); // 找不到（操作时间）只能用cur_month_time代替
public:
    GetFeeModificationRecordsDO() {
        fee_name = "";
        create_time = "";
        start_time = "";
        create_user_name = "";
    }
};

// 给GetFeeModificationRecordsDO智能指针设定一个别名方便使用
typedef std::shared_ptr<GetFeeModificationRecordsDO> PtrGetFeeModificationRecordsDO;




 //--------------------------------------------------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------------------------------------------------

// 这里才是大概率会用到的DO
class PayFeeDO
{
    CC_SYNTHESIZE(string, fee_id, FeeId);               // 费用ID
    CC_SYNTHESIZE(string, b_id, BId);                   // 业务ID
    CC_SYNTHESIZE(string, fee_type_cd, FeeTypeCd);      // 费用类型，物业费，停车费
    CC_SYNTHESIZE(string, community_id, CommunityId);   // 小区ID
    CC_SYNTHESIZE(string, payer_obj_id, PayerObjId);    // 付款方ID
    CC_SYNTHESIZE(string, income_obj_id, IncomeObjId);  // 收款方ID
    CC_SYNTHESIZE(string, start_time, StartTime);       // 开始时间
    CC_SYNTHESIZE(string, end_time, EndTime);           // 结束时间
    CC_SYNTHESIZE(double, amount, Amount);               // 总金额
    CC_SYNTHESIZE(string, user_id, UserId);             // 创建用户ID
    CC_SYNTHESIZE(string, create_time, CreateTime);     // 创建时间
    CC_SYNTHESIZE(string, status_cd, StatusCd);         // 数据状态
    CC_SYNTHESIZE(string, fee_flag, FeeFlag);           // 费用标识
    CC_SYNTHESIZE(string, state, State);                // 状态
    CC_SYNTHESIZE(string, config_id, ConfigId);         // 费用项ID
    CC_SYNTHESIZE(string, payer_obj_type, PayerObjType);// 付费对象类型
    CC_SYNTHESIZE(string, batch_id, BatchId);           // 批次ID

public:
    PayFeeDO() :
        fee_id(""),
        b_id("-1"),
        fee_type_cd(""),
        community_id(""),
        payer_obj_id(""),
        income_obj_id(""),
        start_time(""),
        end_time(""),
        amount(-1.00),
        user_id(""),
        create_time(""),
        status_cd("0"),
        fee_flag("1003006"),
        state("2008001"),
        config_id("-1"),
        payer_obj_type("3333"),
        batch_id("-1")
    {
    }
};

typedef std::shared_ptr<PayFeeDO> PtrPayFeeDO;

// 数据对象（DO）类：费用属性 PayFeeAttrs
class PayFeeAttrsDO
{
    CC_SYNTHESIZE(string, fee_id, FeeId);             // 费用ID
    CC_SYNTHESIZE(string, b_id, BId);                 // 业务Id
    CC_SYNTHESIZE(string, community_id, CommunityId); // 小区ID
    CC_SYNTHESIZE(string, attr_id, AttrId);           // 属性id
    CC_SYNTHESIZE(string, spec_cd, SpecCd);           // 规格id,参考spec表
    CC_SYNTHESIZE(string, value, Value);              // 属性值
    CC_SYNTHESIZE(string, status_cd, StatusCd);       // 数据状态

public:
    PayFeeAttrsDO() :
        fee_id(""),
        b_id(""),
        community_id(""),
        attr_id(""),
        spec_cd(""),
        value(""),
        status_cd("0")
    {
    }
};
typedef std::shared_ptr<PayFeeAttrsDO> PtrPayFeeAttrsDO;

// 数据对象（DO）类：催缴明细 FeeCollectionDetail
class FeeCollectionDetailDO
{
    CC_SYNTHESIZE(string, detail_id, DetailId);             // 明细ID
    CC_SYNTHESIZE(string, order_id, OrderId);               // 催缴订单ID
    CC_SYNTHESIZE(string, collection_name, CollectionName); // 催缴单名称
    CC_SYNTHESIZE(string, owner_id, OwnerId);               // 业主ID
    CC_SYNTHESIZE(string, owner_name, OwnerName);           // 业主名称
    CC_SYNTHESIZE(string, fee_name, FeeName);               // 费用名称
    CC_SYNTHESIZE(string, payer_obj_id, PayerObjId);        // 对象ID
    CC_SYNTHESIZE(string, payer_obj_name, PayerObjName);    // 付费对象名称
    CC_SYNTHESIZE(string, payer_obj_type, PayerObjType);    // 付费对象类型
    CC_SYNTHESIZE(string, community_id, CommunityId);       // 小区
    CC_SYNTHESIZE(string, collection_way, CollectionWay);   // 催缴方式
    CC_SYNTHESIZE(string, state, State);                    // 状态
    CC_SYNTHESIZE(string, create_time, CreateTime);         // 创建时间
    CC_SYNTHESIZE(string, remarks, Remarks);                // 备注
    CC_SYNTHESIZE(string, status_cd, StatusCd);             // 数据在用状态
    CC_SYNTHESIZE(double, owe_amount, OweAmount);            // 欠费金额

public:
    FeeCollectionDetailDO() :
        detail_id(""),
        order_id(""),
        collection_name(""),
        owner_id(""),
        owner_name(""),
        fee_name(""),
        payer_obj_id(""),
        payer_obj_name(""),
        payer_obj_type(""),
        community_id(""),
        collection_way("002"),
        state("W"),
        create_time(""),
        remarks(""),
        status_cd("0"),
        owe_amount(0.0f)
    {
    }
};
typedef std::shared_ptr<FeeCollectionDetailDO> PtrFeeCollectionDetailDO;

// 数据对象（DO）类：费用明细 PayFeeDetail
class PayFeeDetailDO
{
    CC_SYNTHESIZE(string, detail_id, DetailId);           // 费用明细ID
    CC_SYNTHESIZE(string, b_id, BId);                     // 业务ID
    CC_SYNTHESIZE(string, fee_id, FeeId);                 // 费用ID
    CC_SYNTHESIZE(string, community_id, CommunityId);     // 小区ID
    CC_SYNTHESIZE(float, cycles, Cycles);                 // 周期，以月为单位
    CC_SYNTHESIZE(float, receivable_amount, ReceivableAmount);   // 应收金额
    CC_SYNTHESIZE(float, received_amount, ReceivedAmount);       // 实收金额
    CC_SYNTHESIZE(float, prime_rate, PrimeRate);                 // 支付方式
    CC_SYNTHESIZE(string, remark, Remark);                 // 备注
    CC_SYNTHESIZE(string, create_time, CreateTime);         // 创建时间
    CC_SYNTHESIZE(string, status_cd, StatusCd);             // 数据状态
    CC_SYNTHESIZE(string, state, State);                    // 退费状态
    CC_SYNTHESIZE(string, start_time, StartTime);           // 费用开始时间
    CC_SYNTHESIZE(string, end_time, EndTime);               // 费用结束时间
    CC_SYNTHESIZE(float, payable_amount, PayableAmount);    // 应缴金额
    CC_SYNTHESIZE(string, pay_order_id, PayOrderId);        // 支付订单ID
    CC_SYNTHESIZE(string, cashier_id, CashierId);           // 收银员ID
    CC_SYNTHESIZE(string, cashier_name, CashierName);       // 收银员姓名
    CC_SYNTHESIZE(string, open_invoice, OpenInvoice);       // 是否开票
    CC_SYNTHESIZE(float, acct_amount, AcctAmount);          // 账户抵扣金额
    CC_SYNTHESIZE(float, discount_amount, DiscountAmount);  // 优惠打折金额
    CC_SYNTHESIZE(float, deduction_amount, DeductionAmount);// 优惠减免金额
    CC_SYNTHESIZE(float, late_amount, LateAmount);          // 滞纳金
    CC_SYNTHESIZE(float, gift_amount, GiftAmount);          // 赠送金额

public:
    PayFeeDetailDO() :
        detail_id(""),
        b_id(""),
        fee_id(""),
        community_id(""),
        cycles(0.0f),
        receivable_amount(0.0f),
        received_amount(0.0f),
        prime_rate(0.0f),
        remark(""),
        create_time(""),
        status_cd("0"),
        state("1400"),
        start_time(""),
        end_time(""),
        payable_amount(0.0f),
        pay_order_id(""),
        cashier_id(""),
        cashier_name(""),
        open_invoice("N"),
        acct_amount(0.0f),
        discount_amount(0.0f),
        deduction_amount(0.0f),
        late_amount(0.0f),
        gift_amount(0.0f)
    {
    }
};
typedef std::shared_ptr<PayFeeDetailDO> PtrPayFeeDetailDO;

class PayFeeDetailMonthDO
{
public:
    CC_SYNTHESIZE(std::string, month_id, MonthId);             // 月ID
    CC_SYNTHESIZE(std::string, fee_id, FeeId);                 // 费用ID
    CC_SYNTHESIZE(std::string, detail_id, DetailId);           // 费用明细ID
    CC_SYNTHESIZE(std::string, community_id, CommunityId);     // 小区ID
    CC_SYNTHESIZE(int, detail_year, DetailYear);               // 年
    CC_SYNTHESIZE(int, detail_month, DetailMonth);             // 月
    CC_SYNTHESIZE(double, receivable_amount, ReceivableAmount); // 应收金额
    CC_SYNTHESIZE(double, received_amount, ReceivedAmount);     // 实收金额 (SQL comment was '应收金额', using column name)
    CC_SYNTHESIZE(double, discount_amount, DiscountAmount);     // 折扣金额
    CC_SYNTHESIZE(std::string, remark, Remark);                // 说明
    CC_SYNTHESIZE(std::string, create_time, CreateTime);       // 创建时间 (timestamp as string)
    CC_SYNTHESIZE(std::string, status_cd, StatusCd);           // 数据状态
    CC_SYNTHESIZE(std::string, obj_name, ObjName);             // 收费对象名称
    CC_SYNTHESIZE(std::string, obj_id, ObjId);                 // 收费对象ID
    CC_SYNTHESIZE(std::string, owner_name, OwnerName);         // 业主名称
    CC_SYNTHESIZE(std::string, owner_id, OwnerId);             // 业主ID
    CC_SYNTHESIZE(std::string, link, Link);                    // 手机号
    CC_SYNTHESIZE(std::string, state, State);                  // 状态 W 未缴费 C缴费完成 R 已退费
    CC_SYNTHESIZE(std::string, pay_fee_time, PayFeeTime);       // 缴费时间 (datetime as string)
    CC_SYNTHESIZE(std::string, cur_month_time, CurMonthTime);   // 当月时间 (datetime as string)
    CC_SYNTHESIZE(std::string, fee_name, FeeName);             // 费用名称
    CC_SYNTHESIZE(std::string, config_id, ConfigId);           // 标准ID
    CC_SYNTHESIZE(std::string, deadline_time, DeadlineTime);   // 缴费截止时间 (date as string)
    CC_SYNTHESIZE(std::string, obj_fpc_id, ObjFpcId);           // 对象目录
    CC_SYNTHESIZE(std::string, fee_type_cd, FeeTypeCd);         // 费用大类

public:
    PayFeeDetailMonthDO() {
        // Initialize string members to empty
        month_id = "";
        fee_id = "";
        detail_id = "";
        community_id = "";
        remark = "";
        create_time = "";
        status_cd = "0"; // Default from SQL
        obj_name = "";
        obj_id = "";
        owner_name = "";
        owner_id = "";
        link = "";
        state = "C";     // Default from SQL
        pay_fee_time = "";
        cur_month_time = "";
        fee_name = "";
        config_id = "";
        deadline_time = "1000-01-01"; // Default from SQL
        obj_fpc_id = "";
        fee_type_cd = "";

        // Initialize numeric members to 0 or 0.0
        detail_year = 0;
        detail_month = 0;
        receivable_amount = 0.0;
        received_amount = 0.0;
        discount_amount = 0.0; // Default from SQL '0.0000'
    }
};

// Define a smart pointer alias for convenience
typedef std::shared_ptr<PayFeeDetailMonthDO> PtrPayFeeDetailMonthDO;

//车辆费用账单信息数据库实体类
class Pay_FeeDO
{
	CC_SYNTHESIZE(std::string, feeId, FeeId); // 费用ID
	CC_SYNTHESIZE(std::string, bId, BId); // 业务ID
	CC_SYNTHESIZE(std::string, feeTypeCd, FeeTypeCd); // 费用类型
	CC_SYNTHESIZE(std::string, communityId, CommunityId); // 小区ID
	CC_SYNTHESIZE(std::string, payerObjId, PayerObjId); // 付款方ID
	CC_SYNTHESIZE(std::string, incomeObjId, IncomeObjId); // 收款方ID
	CC_SYNTHESIZE(std::string, startTime, StartTime); // 开始时间
	CC_SYNTHESIZE(std::string, endTime, EndTime); // 结束时间
	CC_SYNTHESIZE(std::string, recePeriod, RecePeriod); // 应收时间段
	CC_SYNTHESIZE(double, amount, Amount); // 总金额
	CC_SYNTHESIZE(std::string, userId, UserId); // 创建用户ID
	CC_SYNTHESIZE(std::string, createTime, CreateTime); // 创建时间
	CC_SYNTHESIZE(std::string, statusCd, StatusCd); // 数据状态
	CC_SYNTHESIZE(std::string, feeFlag, FeeFlag); // 费用标识
	CC_SYNTHESIZE(std::string, state, State); // 状态
	CC_SYNTHESIZE(std::string, configId, ConfigId); // 费用项ID
	CC_SYNTHESIZE(std::string, payerObjType, PayerObjType); // 付费对象类型
	CC_SYNTHESIZE(std::string, batchId, BatchId); // 批次ID

	CC_SYNTHESIZE(std::string, feeName, FeeName); // 费用名称
	CC_SYNTHESIZE(std::string, description, Description); // 说明

public:
	Pay_FeeDO() :
		feeId(""), bId("-1"), feeTypeCd(""), communityId(""),
		payerObjId(""), incomeObjId(""), startTime(""), endTime(""),recePeriod("-1"),
		amount(-1.00), userId(""), createTime(""), statusCd("0"),
		feeFlag("1003006"), state("2008001"), configId("-1"),
		payerObjType("3333"), batchId("-1"),feeName(""),description("")
	{
	}
};

//车辆费用账单信息配置数据库实体类
class Pay_Fee_ConfigDO
{
	CC_SYNTHESIZE(std::string, configId, ConfigId); // 费用配置ID
	CC_SYNTHESIZE(std::string, bId, BId); // 业务ID
	CC_SYNTHESIZE(std::string, communityId, CommunityId); // 小区ID
	CC_SYNTHESIZE(std::string, feeTypeCd, FeeTypeCd); // 费用类型
	CC_SYNTHESIZE(double, squarePrice, SquarePrice); // 每平米单价
	CC_SYNTHESIZE(double, additionalAmount, AdditionalAmount); // 附加费用
	CC_SYNTHESIZE(std::string, createTime, CreateTime); // 创建时间
	CC_SYNTHESIZE(std::string, statusCd, StatusCd); // 数据状态
	CC_SYNTHESIZE(std::string, isDefault, IsDefault); // 是否默认
	CC_SYNTHESIZE(std::string, startTime, StartTime); // 开始时间
	CC_SYNTHESIZE(std::string, endTime, EndTime); // 结束时间
	CC_SYNTHESIZE(std::string, feeFlag, FeeFlag); // 费用标识
	CC_SYNTHESIZE(std::string, feeName, FeeName); // 费用项名称
	CC_SYNTHESIZE(std::string, computingFormula, ComputingFormula); // 计算公式
	CC_SYNTHESIZE(std::string, billType, BillType); // 出账类型
	CC_SYNTHESIZE(std::string, paymentCycle, PaymentCycle); // 缴费周期
	CC_SYNTHESIZE(std::string, paymentCd, PaymentCd); // 付费类型
	CC_SYNTHESIZE(std::string, computingFormulaText, ComputingFormulaText); // 自定义公式内容
	CC_SYNTHESIZE(std::string, deductFrom, DeductFrom); // 是否账户抵扣
	CC_SYNTHESIZE(std::string, payOnline, PayOnline); // 是否线上缴费
	CC_SYNTHESIZE(std::string, scale, Scale); // 进位规则
	CC_SYNTHESIZE(int, decimalPlace, DecimalPlace); // 小数点位数
	CC_SYNTHESIZE(std::string, units, Units); // 单位
	CC_SYNTHESIZE(std::string, prepaymentPeriod, PrepaymentPeriod); // 预付期

public:
	Pay_Fee_ConfigDO() :
		configId(""), bId("-1"), communityId(""), feeTypeCd(""),
		squarePrice(0.0), additionalAmount(0.0), createTime(""), statusCd("0"),
		isDefault("F"), startTime(""), endTime(""), feeFlag("1003006"),
		feeName("未知"), computingFormula("1001"), billType("004"),
		paymentCycle("1"), paymentCd("1200"), computingFormulaText(""),
		deductFrom("Y"), payOnline("Y"), scale("1"), decimalPlace(2),
		units("元"), prepaymentPeriod("")
	{
	}
};


// 车辆费用账单操作记录数据库实体类
class Business_Pay_FeeDO
{
	CC_SYNTHESIZE(std::string, feeId, FeeId); // 费用ID
	CC_SYNTHESIZE(std::string, bId, BId); // 业务ID
	CC_SYNTHESIZE(std::string, feeTypeCd, FeeTypeCd); // 费用类型
	CC_SYNTHESIZE(std::string, communityId, CommunityId); // 小区ID
	CC_SYNTHESIZE(std::string, payerObjId, PayerObjId); // 付款方ID
	CC_SYNTHESIZE(std::string, incomeObjId, IncomeObjId); // 收款方ID
	CC_SYNTHESIZE(std::string, startTime, StartTime); // 开始时间
	CC_SYNTHESIZE(std::string, endTime, EndTime); // 结束时间
	CC_SYNTHESIZE(double, amount, Amount); // 总金额
	CC_SYNTHESIZE(std::string, userId, UserId); // 创建用户ID
	CC_SYNTHESIZE(std::string, createTime, CreateTime); // 创建时间
	CC_SYNTHESIZE(std::string, operate, Operate); // 操作类型（ADD、MOD、DEL）
	CC_SYNTHESIZE(std::string, feeFlag, FeeFlag); // 费用标识
	CC_SYNTHESIZE(std::string, state, State); // 状态
	CC_SYNTHESIZE(std::string, configId, ConfigId); // 费用项ID
	CC_SYNTHESIZE(std::string, payerObjType, PayerObjType); // 付费对象类型
	CC_SYNTHESIZE(std::string, batchId, BatchId); // 批次ID

public:
	Business_Pay_FeeDO() :
		feeId(""), bId(""), feeTypeCd(""), communityId(""),
		payerObjId(""), incomeObjId(""), startTime(""), endTime(""),
		amount(-1.00), userId(""), createTime(""), operate(""),
		feeFlag("1003006"), state("2008001"), configId("-1"),
		payerObjType("3333"), batchId("-1")
	{
	}
};

// 车辆费用账单配置信息数据库实体类
class Business_Pay_Fee_ConfigDO
{
	CC_SYNTHESIZE(std::string, configId, ConfigId); // 费用配置ID
	CC_SYNTHESIZE(std::string, bId, BId); // 业务ID
	CC_SYNTHESIZE(std::string, communityId, CommunityId); // 小区ID
	CC_SYNTHESIZE(std::string, feeTypeCd, FeeTypeCd); // 费用类型
	CC_SYNTHESIZE(double, squarePrice, SquarePrice); // 每平米收取的单价
	CC_SYNTHESIZE(double, additionalAmount, AdditionalAmount); // 附加费用
	CC_SYNTHESIZE(std::string, createTime, CreateTime); // 创建时间
	CC_SYNTHESIZE(std::string, operate, Operate); // 操作类型（ADD、MOD、DEL）
	CC_SYNTHESIZE(std::string, isDefault, IsDefault); // 是否默认费用
	CC_SYNTHESIZE(std::string, startTime, StartTime); // 开始时间
	CC_SYNTHESIZE(std::string, endTime, EndTime); // 结束时间
	CC_SYNTHESIZE(std::string, feeFlag, FeeFlag); // 费用标识
	CC_SYNTHESIZE(std::string, feeName, FeeName); // 费用项名称
	CC_SYNTHESIZE(std::string, computingFormula, ComputingFormula); // 计算公式
	CC_SYNTHESIZE(std::string, billType, BillType); // 出账类型
	CC_SYNTHESIZE(std::string, paymentCycle, PaymentCycle); // 缴费周期
	CC_SYNTHESIZE(std::string, paymentCd, PaymentCd); // 付费类型
	CC_SYNTHESIZE(std::string, computingFormulaText, ComputingFormulaText); // 自定义公式内容
	CC_SYNTHESIZE(std::string, deductFrom, DeductFrom); // 是否账户抵扣
	CC_SYNTHESIZE(std::string, units, Units); // 单位
	CC_SYNTHESIZE(int, decimalPlace, DecimalPlace); // 小数点位数
	CC_SYNTHESIZE(std::string, scale, Scale); // 进位方式
	CC_SYNTHESIZE(std::string, payOnline, PayOnline); // 是否线上缴费
	CC_SYNTHESIZE(std::string, prepaymentPeriod, PrepaymentPeriod); // 预付期

public:
	Business_Pay_Fee_ConfigDO() :
		configId(""), bId(""), communityId(""), feeTypeCd(""),
		squarePrice(0.0), additionalAmount(0.0), createTime(""), operate(""),
		isDefault("F"), startTime(""), endTime(""), feeFlag("1003006"),
		feeName("未知"), computingFormula("1001"), billType("004"),
		paymentCycle("1"), paymentCd("1200"), computingFormulaText(""),
		deductFrom("Y"), units("元"), decimalPlace(2), scale("1"),
		payOnline("Y"), prepaymentPeriod("")
	{
	}
};


// 欠费报告数据库实体类
class Report_Owe_FeeDO
{
	CC_SYNTHESIZE(std::string, oweId, OweId); // 欠费主键
	CC_SYNTHESIZE(std::string, configId, ConfigId); // 费用项ID
	CC_SYNTHESIZE(std::string, configName, ConfigName); // 费用项名称
	CC_SYNTHESIZE(std::string, feeId, FeeId); // 费用ID
	CC_SYNTHESIZE(std::string, feeName, FeeName); // 费用名称
	CC_SYNTHESIZE(double, amountOwed, AmountOwed); // 当前欠费金额
	CC_SYNTHESIZE(std::string, ownerId, OwnerId); // 业主ID
	CC_SYNTHESIZE(std::string, ownerName, OwnerName); // 业主名称
	CC_SYNTHESIZE(std::string, ownerTel, OwnerTel); // 业主联系电话
	CC_SYNTHESIZE(std::string, payerObjId, PayerObjId); // 对象ID
	CC_SYNTHESIZE(std::string, payerObjName, PayerObjName); // 付费对象名称
	CC_SYNTHESIZE(std::string, payerObjType, PayerObjType); // 付费对象类型
	CC_SYNTHESIZE(std::string, communityId, CommunityId); // 小区ID
	CC_SYNTHESIZE(std::string, createTime, CreateTime); // 创建时间
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime); // 数据更新时间
	CC_SYNTHESIZE(std::string, endTime, EndTime); // 费用结束时间
	CC_SYNTHESIZE(std::string, deadlineTime, DeadlineTime); // 截止时间

public:
	Report_Owe_FeeDO() :
		oweId(""), configId(""), configName(""), feeId(""), feeName(""),
		amountOwed(0.0), ownerId(""), ownerName(""), ownerTel(""),
		payerObjId(""), payerObjName(""), payerObjType(""), communityId(""),
		createTime(""), updateTime(""), endTime(""), deadlineTime("")
	{
	}
};
typedef std::shared_ptr<Pay_Fee_ConfigDO> PtrPay_Fee_ConfigDO;
typedef std::shared_ptr<Pay_FeeDO> PtrPay_FeeDO;
typedef std::shared_ptr<Business_Pay_Fee_ConfigDO> PtrBusiness_Pay_Fee_ConfigDO;
typedef std::shared_ptr<Business_Pay_FeeDO> PtrBusiness_Pay_FeeDO;
typedef std::shared_ptr<Report_Owe_FeeDO> PtrReport_Owe_FeeDO;
#endif 

