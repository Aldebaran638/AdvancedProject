                                        #pragma once
#ifndef _CarPaymentDTO_h_
#define _CarPaymentDTO_h_

#include "../../GlobalInclude.h"
#include"../../../controller/ApiDeclarativeServicesHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class GetVehicleFeeAddDTO : public oatpp::DTO
{
    DTO_INIT(GetVehicleFeeAddDTO, DTO);
    // 费用ID
    API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("fee.feeId.summary"));
    // 费用标识
    API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("fee.feeFlag.summary"));
    // 费用类型
    API_DTO_FIELD_DEFAULT(String, fee_type_cd, ZH_WORDS_GETTER("fee.feeTypeCd.summary"));
    // 支付对象
    API_DTO_FIELD_DEFAULT(String, value, ZH_WORDS_GETTER("usr.fee.value"));
    // 费用项
    API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("fee.feeName.summary"));
    // 费用状态
    API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("fee.state.summary"));
    // 建账时间
    API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("time.filed.creatTime"));
    // 应收开始时间
    API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("time.filed.startTime"));
    // 应收结束时间
    API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("time.field.endTime"));
    // 批次
    API_DTO_FIELD_DEFAULT(String, batch_id, ZH_WORDS_GETTER("car.batchId.summary"));
    // 欠费金额
    API_DTO_FIELD_DEFAULT(Float64, owe_amount, ZH_WORDS_GETTER("fee.oweAmonut.summary"));
    // 业主ID
    API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("fee.field.ownerId"));
    // 业主名称
    API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("usr.filed.ownerName"));
    // 业主联系方式
    API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("fee.field.link"));


    // 关联一个PayloadDTO负载数据对象
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

class GetVehicleFeeDTO : public GetVehicleFeeAddDTO
{
    DTO_INIT(GetVehicleFeeDTO, GetVehicleFeeAddDTO);

    // 主键ID（月ID）pay_fee_detail_month
    API_DTO_FIELD_DEFAULT(String, month_id, ZH_WORDS_GETTER("primary.monthId.summary"));
};

// 获取缴费记录列表数据传输对象
class GetPaymentRecordsDTO : public oatpp::DTO {
    DTO_INIT(GetPaymentRecordsDTO, DTO);

    // 费用项
    API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("fee.feeName.summary"));
    // 收费对象
    API_DTO_FIELD_DEFAULT(String, value, ZH_WORDS_GETTER("usr.fee.value"));
    // 周期(单位:月)
    API_DTO_FIELD_DEFAULT(Float64, cycle, ZH_WORDS_GETTER("fee.cycle.summary"));
    // 应收金额(单位:元)
    API_DTO_FIELD_DEFAULT(Float64, receivable_amount, ZH_WORDS_GETTER("fee.receivableAmount.summary"));
    // 实收金额(单位:元)
    API_DTO_FIELD_DEFAULT(Float64, received_amount, ZH_WORDS_GETTER("fee.receivedAmount.summary"));
    // 缴费起始段
    API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("time.filed.creatTime"));
    // 缴费时间
    API_DTO_FIELD_DEFAULT(String, pay_fee_time, ZH_WORDS_GETTER("time.field.payFeeTime"));
    // 收银员
    API_DTO_FIELD_DEFAULT(String, cashier_name, ZH_WORDS_GETTER("usr.fee.cashierName"));
    // 状态
    API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("common.filed.statusCd"));
    // 备注
    API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("common.field.remark"));
    // 关联一个PayloadDTO负载数据对象
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

class GetPaymentRecordsPageDTO : public PageDTO<GetPaymentRecordsDTO::Wrapper>
{
    DTO_INIT(GetPaymentRecordsPageDTO, PageDTO<GetPaymentRecordsDTO::Wrapper>);
};

// 车辆缴费记录数据传输对象
class GetPaymentDetailedRecordDTO : public oatpp::DTO {
    DTO_INIT(GetPaymentDetailedRecordDTO, DTO);
    // 缴费ID
    API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("fee.feeId.summary"));
    // 周期(单位:月)
    API_DTO_FIELD_DEFAULT(Float64, cycle, ZH_WORDS_GETTER("fee.cycle.summary"));
    // 应收金额(单位:元)
    API_DTO_FIELD_DEFAULT(Float64, receivable_amount, ZH_WORDS_GETTER("fee.receivableAmount.summary"));
    // 实收金额(单位:元)
    API_DTO_FIELD_DEFAULT(Float64, received_amount, ZH_WORDS_GETTER("fee.receivedAmount.summary"));
    // 缴费时间
    API_DTO_FIELD_DEFAULT(String, pay_fee_time, ZH_WORDS_GETTER("time.field.payFeeTime"));
    // 缴费起始时间
    API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("time.filed.creatTime"));
    // 缴费结束时间
    API_DTO_FIELD_DEFAULT(String, deadline_time, ZH_WORDS_GETTER("time.field.deadLineTime"));
    // 收银员
    API_DTO_FIELD_DEFAULT(String, cashier_name, ZH_WORDS_GETTER("usr.fee.cashierName"));
    // 状态
    API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("common.field.status"));
    // 备注
    API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("common.field.remark"));
    // 关联一个PayloadDTO负载数据对象
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

// 车辆费用配置修改数据传输对象
class GetFeeModificationRecordsDTO : public oatpp::DTO {
    DTO_INIT(GetFeeModificationRecordsDTO, DTO);

    // 费用项
    API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("fee.feeName.summary"));
    // 建账时间
    API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("time.filed.creatTime"));
    // 应收开始时间
    API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("time.filed.startTime"));
    // 操作人
    API_DTO_FIELD_DEFAULT(String, create_user_name, ZH_WORDS_GETTER("usr.fee.createUserName"));
    // 找不到（操作时间）只能用cur_month_time代替
    API_DTO_FIELD_DEFAULT(String, cur_month_time, ZH_WORDS_GETTER("time.filed.curMonthTime"));
    // 关联一个PayloadDTO负载数据对象
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

class GetFeeModificationRecordsPageDTO : public PageDTO<GetFeeModificationRecordsDTO::Wrapper>
{
    DTO_INIT(GetFeeModificationRecordsPageDTO, PageDTO<GetFeeModificationRecordsDTO::Wrapper>);
};

//创建车辆费用数据传输对象
class CarPaymentAddDTO: public oatpp::DTO
{
	DTO_INIT(CarPaymentAddDTO, DTO);
	//车辆
	API_DTO_FIELD_DEFAULT(String, car_name, ZH_WORDS_GETTER("carpayment.field.car_name"));
	// 费用类型
	API_DTO_FIELD_DEFAULT(String,fee_type,ZH_WORDS_GETTER("carpayment.field.fee_type"));
	// 收费项目
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("carpayment.field.fee_name"));

	//计费起始时间
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("carpayment.field.start_time"));
	//计费结束时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("carpayment.field.end_time"));

	//费用标识
	API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("carpayment.field.fee_flag"));
	//建账时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("carpayment.create.create_time"));
	//应收款
	API_DTO_FIELD_DEFAULT(Float64, rece_pay, ZH_WORDS_GETTER("carpayment.field.recr_pay"));
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
	
};

//车辆费用数据传输对象（较完整版）
class CarPaymentDTO : public oatpp::DTO
{
	DTO_INIT(CarPaymentDTO, DTO);


	//车辆
	API_DTO_FIELD_DEFAULT(String, car_name, ZH_WORDS_GETTER("carpayment.field.car_name"));
	// 费用类型
	API_DTO_FIELD_DEFAULT(String, fee_type, ZH_WORDS_GETTER("carpayment.field.fee_type"));
	// 收费项目
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("carpayment.field.fee_name"));

	

	//费用标识
	API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("carpayment.field.fee_flag"));
	//建账时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("carpayment.create.create_time"));
	//应收款
	API_DTO_FIELD_DEFAULT(Float64, rece_pay, ZH_WORDS_GETTER("carpayment.field.recr_pay"));
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
	//费用项ID
	API_DTO_FIELD_DEFAULT(String, fee_item_id, ZH_WORDS_GETTER("carpayment.field.fee_item_id"));
	//收费金额
	API_DTO_FIELD_DEFAULT(Float64, amount, ZH_WORDS_GETTER("carpayment.field.amount"));
	//催缴类型
	API_DTO_FIELD_DEFAULT(String, call_type, ZH_WORDS_GETTER("carpayment.field.call_type"));
	//付款类型
	API_DTO_FIELD_DEFAULT(String, pay_type, ZH_WORDS_GETTER("carpayment.field.pay_type"));
	//缴费周期
	API_DTO_FIELD_DEFAULT(String, pay_cycle, ZH_WORDS_GETTER("carpayment.field.pay_cycle"));
	//公式
	API_DTO_FIELD_DEFAULT(String, formula, ZH_WORDS_GETTER("carpayment.field.formula"));
	//计费单价
	API_DTO_FIELD_DEFAULT(Float64, unit_price, ZH_WORDS_GETTER("carpayment.field.unit_price"));
	//附加费用
	API_DTO_FIELD_DEFAULT(Float64, sur_fee, ZH_WORDS_GETTER("carpayment.field.sur_fee"));
	//固定费用
	API_DTO_FIELD_DEFAULT(Float64, fix_fee, ZH_WORDS_GETTER("carpayment.field.fix_fee"));
	//应收时间段
	API_DTO_FIELD_DEFAULT(String, qdt, ZH_WORDS_GETTER("carpayment.field.qdt"));


	//费用ID
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("carpayment.field.fee_id"));	
	//小区ID
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("carpayment.field.community_id"));
	//备注
	API_DTO_FIELD_DEFAULT(String, text, ZH_WORDS_GETTER("carpayment.field.text"));
	//说明
	API_DTO_FIELD_DEFAULT(String, description, ZH_WORDS_GETTER("carpayment.field.description"));
	//状态
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("carpayment.field.status"));
	//支付方式
	API_DTO_FIELD_DEFAULT(String, pay_way, ZH_WORDS_GETTER("carpayment.field.pay_way"));
	//实收款
	API_DTO_FIELD_DEFAULT(Float64, act_pay, ZH_WORDS_GETTER("carpayment.field.act_pay"));

	//应收开始时间
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("carpayment.create.start_time"));
	//应收结束时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("carpayment.create.end_time"));
	//欠费主键
	API_DTO_FIELD_DEFAULT(String, owe_id, ZH_WORDS_GETTER("carpayment.field.owe_id"));	
	//付款方ID
	API_DTO_FIELD_DEFAULT(String, payer_obj_id, ZH_WORDS_GETTER("carpayment.field.payer_obj_id"));
	//付款方ID
	API_DTO_FIELD_DEFAULT(String, income_obj_id, ZH_WORDS_GETTER("carpayment.field.income_obj_id"));
	//创建用户ID
	API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("carpayment.field.user_id"))
	//每平米单价
	API_DTO_FIELD_DEFAULT(Float64, square_price, ZH_WORDS_GETTER("carpayment.field.square_price"));
	//计算公式
	API_DTO_FIELD_DEFAULT(String, computing_formula, ZH_WORDS_GETTER("carpayment.field.computing_formula"));
	//出账类型
	API_DTO_FIELD_DEFAULT(String, bill_type, ZH_WORDS_GETTER("carpayment.field.bill_type"));
	//自定义公式内容
	API_DTO_FIELD_DEFAULT(String, computing_formula_text, ZH_WORDS_GETTER("carpayment.field.computing_formula_text"));
	//是否账户抵扣
	API_DTO_FIELD_DEFAULT(String, deduct_from, ZH_WORDS_GETTER("carpayment.field.deduct_from"));
	//是否线上缴费
	API_DTO_FIELD_DEFAULT(String, pay_online, ZH_WORDS_GETTER("carpayment.field.pay.online"));
	//进位
	API_DTO_FIELD_DEFAULT(String, scale, ZH_WORDS_GETTER("carpayment.field.scale"));
	//小数点位数
	API_DTO_FIELD_DEFAULT(Int32, decimal_place, ZH_WORDS_GETTER("carpayment.field.decomal_place"));
	//单位
	API_DTO_FIELD_DEFAULT(String, units, ZH_WORDS_GETTER("carpayment.field.units"));
	//预付期
	API_DTO_FIELD_DEFAULT(String, prepayment_period, ZH_WORDS_GETTER("carpayment.field.prepayment_period"));
	//业主ID
	API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("carpayment.field.owner_id"))
	//业主名称
	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("carpayment.field.owner_name"));
	//费用项名称
	API_DTO_FIELD_DEFAULT(String, config_name, ZH_WORDS_GETTER("carpayment.field.config_name"));
	//业主联系电话
	API_DTO_FIELD_DEFAULT(String, owner_tel, ZH_WORDS_GETTER("carpayment.field.owner_tel"));
	//付费对象名称
	API_DTO_FIELD_DEFAULT(String, payer_obj_name, ZH_WORDS_GETTER("carpayment.field.payer_obj_name"));
	//截止时间
	API_DTO_FIELD_DEFAULT(String, deadline_time, ZH_WORDS_GETTER("carpayment.field.deadline_time"));
	//本次支付金额
	API_DTO_FIELD_DEFAULT(Float64, paid_amount, ZH_WORDS_GETTER("carpayment.field.paid_amount"));

};
class CarPaymentDeleteDTO : public oatpp::DTO
{
	DTO_INIT(CarPaymentDeleteDTO, DTO);
	// 表编号id
	DTO_FIELD(String, fee_id);
	DTO_FIELD_INFO(fee_id) {
		info->description = ZH_WORDS_GETTER("carpayment.field.fee_id");
	}
};

// 定义一个分页传输对象
class CarPaymentPageDTO : public PageDTO<CarPaymentDTO::Wrapper>
{
	DTO_INIT(CarPaymentPageDTO, PageDTO<CarPaymentDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 
