#pragma once

#ifndef _CONTRACTPAYDTO_H_
#define _CONTRACTPAYDTO_H_


#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// 添加合同收费数据传输对象
class ContractpayAddDTO : public oatpp::DTO {
	DTO_INIT(ContractpayAddDTO, DTO);

	// 合同信息字段，还做外面那个分页查询的话就还会再用，到时候再复制粘贴出去
	/*
	// 合同编码
	API_DTO_FIELD_DEFAULT(String, contract_code, ZH_WORDS_GETTER("contractpay.field.code"));
	// 合同名称
	API_DTO_FIELD_DEFAULT(String, contract_name, ZH_WORDS_GETTER("contractpay.field.name"));
	// 合同类型
	API_DTO_FIELD_DEFAULT(String, contract_type, ZH_WORDS_GETTER("contractpay.field.type"));
	// 乙方
	API_DTO_FIELD_DEFAULT(String, party_b, ZH_WORDS_GETTER("contractpay.field.party_b"));
	// 合同金额
	API_DTO_FIELD_DEFAULT(Int32, amount, ZH_WORDS_GETTER("contractpay.field.amount"));
	// 合同开始时间
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("contractpay.field.start_time"));
	// 合同结束时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("contractpay.field.end_time"));
	*/
	
	// 合同费用字段
	// 付款方id，即合同id
	API_DTO_FIELD_DEFAULT(String, payer_obj_id, ZH_WORDS_GETTER("contractpay.newfield.payer_obj_id"));
	// 费用项目
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("contractpay.newfield.fee_name"));
	// 费用标志
	API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("contractpay.newfield.fee_flag"));
	// 费用类型
	API_DTO_FIELD_DEFAULT(String, fee_type_cd, ZH_WORDS_GETTER("contractpay.newfield.fee_type_cd"));
	// 应收金额（固定费用）
	API_DTO_FIELD_DEFAULT(Float64, additional_amount, ZH_WORDS_GETTER("contractpay.newfield.additional_amount"));
	// 创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("contractpay.newfield.create_time"));
	// 开始时间
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("contractpay.newfield.start_time"));
	// 结束时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("contractpay.newfield.end_time"));
	// 每平单价
	API_DTO_FIELD_DEFAULT(Float64, square_price, ZH_WORDS_GETTER("contractpay.newfield.square_price"));
	// 状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("contractpay.newfield.state"));

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

// 合同收费数据传输对象
class ContractpayDTO : public ContractpayAddDTO {
	DTO_INIT(ContractpayDTO, ContractpayAddDTO);
};

// 合同收费分页数据传输对象
class ContractpayPageDTO : public PageDTO<ContractpayAddDTO::Wrapper>
{
	DTO_INIT(ContractpayPageDTO, PageDTO<ContractpayAddDTO::Wrapper>);
};



/**
 * 缴纳合同费用数据传输对象
 */
class ContractcostChargeDTO : public oatpp::DTO
{
	//定义初始化
	DTO_INIT(ContractcostChargeDTO, DTO);
	//费用id
	API_DTO_FIELD_DEFAULT(String, feeid, ZH_WORDS_GETTER("contractcost.charge.feeid"));
	//// 费用项目
	//API_DTO_FIELD_DEFAULT(String, costobj, ZH_WORDS_GETTER("contractcost.charge.costobj"));
	//// 费用类型
	//API_DTO_FIELD_DEFAULT(String, costtype, ZH_WORDS_GETTER("contractcost.charge.costtype"));
	//// 计费起始时间
	//API_DTO_FIELD_DEFAULT(String, coststarttime, ZH_WORDS_GETTER("contractcost.charge.coststarttime"));
	//// 缴费时间
	//API_DTO_FIELD_DEFAULT(String, chargetime, ZH_WORDS_GETTER("contractcost.charge.chargetime"));
	// 缴费周期
	API_DTO_FIELD_DEFAULT(String, chargecycle, ZH_WORDS_GETTER("contractcost.charge.chargecycle"));
	// 备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("contractcost.charge.remark"));
	//// 面积
	//API_DTO_FIELD_DEFAULT(Int32, area, ZH_WORDS_GETTER("contractcost.charge.area"));
	////单价
	//API_DTO_FIELD_DEFAULT(Int32, unitprice, ZH_WORDS_GETTER("contractcost.charge.unitprice"));
	////附加费
	//API_DTO_FIELD_DEFAULT(Int32, extra, ZH_WORDS_GETTER("contractcost.charge.extra"));
	//应收款
	API_DTO_FIELD_DEFAULT(String, receivable, ZH_WORDS_GETTER("contractcost.charge.receivable"));
	//支付方式
	API_DTO_FIELD_DEFAULT(String, chargeway, ZH_WORDS_GETTER("contractcost.charge.chargeway"));
	//实收款
	API_DTO_FIELD_DEFAULT(String, received, ZH_WORDS_GETTER("contractcost.charge.received"));
	//收银员名字
	API_DTO_FIELD_DEFAULT(String, cashier, ZH_WORDS_GETTER("contractcost.charge.received"));
	////应缴金额
	//API_DTO_FIELD_DEFAULT(String, payable, ZH_WORDS_GETTER("contractcost.charge.payable"));

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);

};

/**
 * 定义一个变更合同费用数据传输模型
 */
class ChangeContractcostDTO : public oatpp::DTO
{
	// 定义初始化
	DTO_INIT(ChangeContractcostDTO, DTO);
	//费用id
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("contractcost.change.feeid"));
	// 开始时间
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("contractpay.newfield.start_time"));
	// 结束时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("contractpay.newfield.end_time"));
	// 创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("contractpay.newfield.create_time"));
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * 取消合同费用数据传输模型
 */
class CancelContractcostDTO : public oatpp::DTO
{
	DTO_INIT(CancelContractcostDTO, DTO);
	//费用id
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("contractcost.change.feeid"));
};


/**
 * 获取合同缴费记录详情
 */
class ContractcostChargeRecordDTO : public ContractcostChargeDTO
{
	DTO_INIT(ContractcostChargeRecordDTO, ContractcostChargeDTO);
	//请选择开始时间
	API_DTO_FIELD_DEFAULT(String, choosestarttime, ZH_WORDS_GETTER("contractcost.charge.choosestarttime"));
	//请选择结束时间
	API_DTO_FIELD_DEFAULT(String, chooseendtime, ZH_WORDS_GETTER("contractcost.charge.chooseendtime"));

};
/**
 * 获取合同缴费记录传输模型
 */
class ContractcostDTO : public oatpp::DTO
{
	//定义初始化
	DTO_INIT(ContractcostDTO, DTO);
	//费用id
	API_DTO_FIELD_DEFAULT(String, feeid, ZH_WORDS_GETTER("contractcost.charge.feeid"));
	// 费用项目
	API_DTO_FIELD_DEFAULT(String, feeobj, ZH_WORDS_GETTER("contractcost.charge.costobj"));
	// 收费对象
	API_DTO_FIELD_DEFAULT(String, chargeobj, ZH_WORDS_GETTER("contractcost.charge.chargeobj"));
	// 缴费周期
	API_DTO_FIELD_DEFAULT(String, chargecycle, ZH_WORDS_GETTER("contractcost.charge.chargecycle"));
	//应收款
	API_DTO_FIELD_DEFAULT(String, receivable, ZH_WORDS_GETTER("contractcost.charge.receivable"));
	//实收款
	API_DTO_FIELD_DEFAULT(String, received, ZH_WORDS_GETTER("contractcost.charge.received"));
	//支付方式
	API_DTO_FIELD_DEFAULT(String, chargeway, ZH_WORDS_GETTER("contractcost.charge.chargeway"));
	// 计费起始时间
	API_DTO_FIELD_DEFAULT(String, coststarttime, ZH_WORDS_GETTER("contractcost.charge.coststarttime"));
	// 计费起始时间
	API_DTO_FIELD_DEFAULT(String, costendtime, ZH_WORDS_GETTER("contractcost.charge.costendtime"));
	// 缴费时间
	API_DTO_FIELD_DEFAULT(String, chargetime, ZH_WORDS_GETTER("contractcost.charge.chargetime"));
	//收银员名字
	API_DTO_FIELD_DEFAULT(String, cashier, ZH_WORDS_GETTER("contractcost.charge.received"));
	//状态
	API_DTO_FIELD_DEFAULT(String, statu, ZH_WORDS_GETTER("contractcost.charge.statu"));
	// 备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("contractcost.charge.remark"));
	// 付款方id，即合同id
	API_DTO_FIELD_DEFAULT(String, payer_obj_id, ZH_WORDS_GETTER("contractpay.newfield.payer_obj_id"));

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);

};

/**
 * 获取合同缴费记录（条件 + 分页）
 */
class GetContractcostChargeRecordPageDTO : public PageDTO<ContractcostDTO::Wrapper>
{
	DTO_INIT(GetContractcostChargeRecordPageDTO, PageDTO<ContractcostDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)


#endif // !_CONTRACTPAYDTO_H_