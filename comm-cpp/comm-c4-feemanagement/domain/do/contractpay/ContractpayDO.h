#pragma once

#ifndef _CONTRACTPAYDO_H_
#define _CONTRACTPAYDO_H_


#include "../DoInclude.h"

/*
// contract数据库实体类 暂时弃用
class ContractpayDO {
	// 合同ID
	CC_SYNTHESIZE(string, contract_id, ContractId);
	// 合同编码
	CC_SYNTHESIZE(string, contract_code, ContractCode);
	// 合同名称
	CC_SYNTHESIZE(string, contract_name, ContractName);
	// 合同类型
	CC_SYNTHESIZE(string, contract_type, ContractType);
	// 合同对象类型：3333 房屋 ，1111 没有合同对象
	CC_SYNTHESIZE(string, obj_type, ObjType);
	// 合同对象
	CC_SYNTHESIZE(string, obj_id, ObjId);
	// 甲方
	CC_SYNTHESIZE(string, party_a, PartyA);
	// 乙方
	CC_SYNTHESIZE(string, party_b, PartyB);
	// 甲方联系人
	CC_SYNTHESIZE(string, a_contacts, AContacts);
	// 甲方联系电话
	CC_SYNTHESIZE(string, a_link, ALink);
	// 乙方联系人
	CC_SYNTHESIZE(string, b_contacts, BContacts);
	// 乙方联系电话
	CC_SYNTHESIZE(string, b_link, BLink);
	// 经办人
	CC_SYNTHESIZE(string, operator, Operator);
	// 经办人电话
	CC_SYNTHESIZE(string, operator_link, OperatorLink);
	// 合同金额
	CC_SYNTHESIZE(double, amount, Amount);
	// 合同开始时间
	CC_SYNTHESIZE(string, start_time, StartTime);
	// 合同结束时间
	CC_SYNTHESIZE(string, end_time, EndTime);
	// 签订时间
	CC_SYNTHESIZE(string, signing_time, SigningTime);
	// 商户ID
	CC_SYNTHESIZE(string, store_id, StoreId);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	// 11 待审核 22 审核通过 33 审核失败 44 手工停止
	CC_SYNTHESIZE(string, state, State);
	// 审核意见
	CC_SYNTHESIZE(string, state_desc, StateDesc);
	// 父合同ID
	CC_SYNTHESIZE(string, contract_parent_id, ContractParentId);
	// 合同对象名称
	CC_SYNTHESIZE(string, obj_name, ObjName);
	// 合同对象用户名称
	CC_SYNTHESIZE(string, obj_person_name, ObjPersonName);
	// 合同对象用户ID
	CC_SYNTHESIZE(string, obj_person_id, ObjPersonId);
	// 提交用户
	CC_SYNTHESIZE(string, start_user_id, StartUserId);
public:
	ContractpayDO() {}
};

// 给ContractpayDO智能指针设定一个别名方便使用
typedef std::shared_ptr<ContractpayDO> PtrContractpayDO;
*/

// pay_fee_config pay_fee数据库实体类
class ContractpayDO {
	//// pay_fee_config数据表 应该用不到，需要的时候再解注释
	//// 费用ID
	//CC_SYNTHESIZE(string, config_id, ConfigId);
	//// 业务ID
	//CC_SYNTHESIZE(string, b_id, BId);
	//// 小区ID
	//CC_SYNTHESIZE(string, community_id, CommunityId);
	//// 费用类型
	//CC_SYNTHESIZE(string, fee_type_cd, FeeTypeCd);
	//// 每平米单价
	//CC_SYNTHESIZE(double, square_price, SquarePrice);
	//// 附加费用
	//CC_SYNTHESIZE(double, additional_amount, AdditionalAmount);
	//// 创建时间
	//CC_SYNTHESIZE(string, create_time, CreateTime);
	//// 数据状态
	//CC_SYNTHESIZE(string, status_cd, StatusCd);
	//// 是否默认费用
	//CC_SYNTHESIZE(string, is_default, IsDefault);
	//// 开始时间
	//CC_SYNTHESIZE(string, start_time, StartTime);
	//// 结束时间
	//CC_SYNTHESIZE(string, end_time, EndTime);
	//// 费用标识
	//CC_SYNTHESIZE(string, fee_flag, FeeFlag);
	//// 费用项名称
	//CC_SYNTHESIZE(string, fee_name, FeeName);
	//// 计算公式
	//CC_SYNTHESIZE(string, computing_formula, ComputingFormula);
	//// 出账类型
	//CC_SYNTHESIZE(string, bill_type, BillType);
	//// 缴费周期
	//CC_SYNTHESIZE(string, payment_cycle, PaymentCycle);
	//// 付费类型
	//CC_SYNTHESIZE(string, payment_cd, PaymentCd);
	//// 自定义公式内容
	//CC_SYNTHESIZE(string, computing_formula_text, ComputingFormulaText);
	//// 是否账户抵扣
	//CC_SYNTHESIZE(string, deduct_from, DeductFrom);
	//// 是否线上缴费
	//CC_SYNTHESIZE(string, pay_online, PayOnline);
	//// 进位规则
	//CC_SYNTHESIZE(string, scale, Scale);
	//// 小数点位数
	//CC_SYNTHESIZE(int, decimal_place, DecimalPlace);
	//// 单位
	//CC_SYNTHESIZE(string, units, Units);
	//// 预付期
	//CC_SYNTHESIZE(string, prepayment_period, PrepaymentPeriod);

	// pay_fee_config数据表
	// 费用项名称
	CC_SYNTHESIZE(string, fee_name, FeeName);
	// 附加费用
	CC_SYNTHESIZE(double, additional_amount, AdditionalAmount);
	// 每平米单价
	CC_SYNTHESIZE(double, square_price, SquarePrice);

	// pay_fee数据表
	// 费用ID
	CC_SYNTHESIZE(string, fee_id, FeeId);
	// 业务ID
	CC_SYNTHESIZE(string, b_id, BId);
	// 费用类型
	CC_SYNTHESIZE(string, fee_type_cd, FeeTypeCd);
	// 小区ID
	CC_SYNTHESIZE(string, community_id, CommunityId);
	// 付款方ID
	CC_SYNTHESIZE(string, payer_obj_id, PayerObjId);
	// 收款方ID
	CC_SYNTHESIZE(string, income_obj_id, IncomeObjId);
	// 开始时间
	CC_SYNTHESIZE(string, start_time, StartTime);
	// 结束时间
	CC_SYNTHESIZE(string, end_time, EndTime);
	// 总金额
	CC_SYNTHESIZE(double, amount, Amount);
	// 创建用户ID
	CC_SYNTHESIZE(string, user_id, UserId);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// 数据状态
	CC_SYNTHESIZE(string, status_cd, StatusCd);
	// 费用标识
	CC_SYNTHESIZE(string, fee_flag, FeeFlag);
	// 状态
	CC_SYNTHESIZE(string, state, State);
	// 费用项ID
	CC_SYNTHESIZE(string, config_id, ConfigId);
	// 付费对象类型
	CC_SYNTHESIZE(string, payer_obj_type, PayerObjType);
	// 批次ID
	CC_SYNTHESIZE(string, batch_id, BatchId);


	//pay_fee_detail 表

	// 支付方式
	CC_SYNTHESIZE(string, chargeway, ChargeWay);
	// 实收款
	CC_SYNTHESIZE(string, received, Received);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	//费用明细id
	CC_SYNTHESIZE(string, detail_id, DetailId);
	//周期
	CC_SYNTHESIZE(string, cycle, Cycle);
	//应收金额
	CC_SYNTHESIZE(string, receivable, Receivable);
	//支付订单id
	CC_SYNTHESIZE(string, pay_order_id, PayOrderId);
	//cashier_name
	CC_SYNTHESIZE(string, cashier_name, CashierName);
	//状态
	CC_SYNTHESIZE(string, state_charge, StateCharge);

	//contarct表
	CC_SYNTHESIZE(string, contract_name, ContractName);
public:
	ContractpayDO() {
		// pay_fee_config相关字段
		fee_name = "";
		additional_amount = 0.0;
		square_price = 0.0;

		// pay_fee相关字段
		fee_id = "";
		b_id = "-1";          // 默认无效业务ID
		fee_type_cd = "";
		community_id = "";
		payer_obj_id = "";
		income_obj_id = "";
		start_time = "";
		end_time = "";
		amount = -1.00;         // 默认金额为0
		user_id = "";
		create_time = "";
		status_cd = "0";       // 默认数据状态为在用
		fee_flag = "";
		state = "2008001";          
		config_id = "";
		payer_obj_type = "3333";
		batch_id = "-1";

		pay_order_id = "";
		cashier_name = "";
		state_charge = "1400";
		
	}

};

// 给ContractpayDO智能指针设定一个别名方便使用
typedef std::shared_ptr<ContractpayDO> PtrContractpayDO;

#endif // !_CONTRACTPAYDO_H_
