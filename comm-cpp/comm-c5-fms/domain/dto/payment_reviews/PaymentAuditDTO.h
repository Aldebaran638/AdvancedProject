#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yingjiu
 @Date: 2025/5/18 10:21:48

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
#ifndef _PAYMENTAUDITDTO_
#define _PAYMENTAUDITDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*新增缴费审核列表传输对象*/
class PaymentAuditListDTO : public oatpp::DTO
{
	DTO_INIT(PaymentAuditListDTO, DTO);
	// 房屋
	API_DTO_FIELD_DEFAULT(String, objname, ZH_WORDS_GETTER("paymentaudit.field.obj_name"));
	// 费用项目
	API_DTO_FIELD_DEFAULT(String, feename, ZH_WORDS_GETTER("paymentaudit.field.fee_name"));
	// 付费周期
	API_DTO_FIELD_DEFAULT(Int64, cycles, ZH_WORDS_GETTER("paymentaudit.field.cycles"));
	// 缴费起始时间
	API_DTO_FIELD_DEFAULT(String, starttime, ZH_WORDS_GETTER("paymentaudit.field.start_time"));
	// 缴费结束时间
	API_DTO_FIELD_DEFAULT(String, endtime, ZH_WORDS_GETTER("paymentaudit.field.end_time"));
	// 应付金额(单位:元)
	API_DTO_FIELD_DEFAULT(Int64, receivableamount, ZH_WORDS_GETTER("paymentaudit.field.receivable_amount"));
	// 实付金额(单位:元)
	API_DTO_FIELD_DEFAULT(Int64, receivedamount, ZH_WORDS_GETTER("paymentaudit.field.received_amount"));
	// 操作员工
	API_DTO_FIELD_DEFAULT(String, cashiername, ZH_WORDS_GETTER("paymentaudit.field.cashier_name"));
	// 缴费时间
	API_DTO_FIELD_DEFAULT(String, createtime, ZH_WORDS_GETTER("paymentaudit.field.create_time"));
	// 审核状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("paymentaudit.field.state"));
	// 审核说明
	API_DTO_FIELD_DEFAULT(String, message, ZH_WORDS_GETTER("paymentaudit.field.message"));
	// 缴费备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("paymentaudit.field.remark"));

};
/*新增缴费审核传输详情传输对象*/
class PaymentAuditDetailDTO : public oatpp::DTO
{
	DTO_INIT(PaymentAuditDetailDTO, DTO);
	// 费用id
	API_DTO_FIELD_DEFAULT(String, feeid, ZH_WORDS_GETTER("paymentaudit.field.fee_id"));
	// 费用标识
	API_DTO_FIELD_DEFAULT(String, feeflag, ZH_WORDS_GETTER("paymentaudit.field.fee_flag"));
	// 费用类型
	API_DTO_FIELD_DEFAULT(String, feetypecd, ZH_WORDS_GETTER("paymentaudit.field.fee_type_cd"));
	//付费对象
	API_DTO_FIELD_DEFAULT(String, payerobjname, ZH_WORDS_GETTER("paymentaudit.field.payer_obj_name"));
	//费用项
	API_DTO_FIELD_DEFAULT(String, feename, ZH_WORDS_GETTER("paymentaudit.field.fee_name"));
	//费用状态
	API_DTO_FIELD_DEFAULT(String, feestate, ZH_WORDS_GETTER("paymentaudit.field.fee_state"));
	//建账时间
	API_DTO_FIELD_DEFAULT(String, createtimea, ZH_WORDS_GETTER("paymentaudit.field.create_timea"));
	//计费开始时间
	API_DTO_FIELD_DEFAULT(String, starttime, ZH_WORDS_GETTER("paymentaudit.field.start_time"));
	//计费结束时间
	API_DTO_FIELD_DEFAULT(String, endtime, ZH_WORDS_GETTER("paymentaudit.field.end_time"));
	//批次
	API_DTO_FIELD_DEFAULT(String, batchid, ZH_WORDS_GETTER("paymentaudit.field.batch_id"));
	//面积
	API_DTO_FIELD_DEFAULT(Int64, area, ZH_WORDS_GETTER("paymentaudit.field.area"));
	//单价
	API_DTO_FIELD_DEFAULT(Int64, squareprice, ZH_WORDS_GETTER("paymentaudit.field.square_price"));
	//附加费
	API_DTO_FIELD_DEFAULT(Int64, feeaddition, ZH_WORDS_GETTER("paymentaudit.field.fee_addition"));

};
/*新增缴费历史列表传输对象*/
class PaymentAuditHistoryDTO : public oatpp::DTO
{
	DTO_INIT(PaymentAuditHistoryDTO, DTO);
	// 缴费id
	API_DTO_FIELD_DEFAULT(String, detailid, ZH_WORDS_GETTER("paymentaudit.field.detail_id"));
	// 周期(单位:月)	
	API_DTO_FIELD_DEFAULT(Int64, cycles, ZH_WORDS_GETTER("paymentaudit.field.cycles"));
	// 缴费方式
	API_DTO_FIELD_DEFAULT(String, primerate, ZH_WORDS_GETTER("paymentaudit.prime_rate"));
	// 应收金额(单位:元)
	API_DTO_FIELD_DEFAULT(Int64, receivableamount, ZH_WORDS_GETTER("paymentaudit.field.receivable_amount"));
	// 实收金额(单位:元)
	API_DTO_FIELD_DEFAULT(Int64, receivedamount, ZH_WORDS_GETTER("paymentaudit.field.received_amount"));
	// 缴费时间
	API_DTO_FIELD_DEFAULT(String, createtime, ZH_WORDS_GETTER("paymentaudit.field.create_time"));
	// 缴费起始时间
	API_DTO_FIELD_DEFAULT(String, starttime, ZH_WORDS_GETTER("paymentaudit.field.start_time"));
	// 缴费结束时间
	API_DTO_FIELD_DEFAULT(String, endtime, ZH_WORDS_GETTER("paymentaudit.field.end_time"));
	// 收银员	
	API_DTO_FIELD_DEFAULT(String, cashiername, ZH_WORDS_GETTER("paymentaudit.field.cashier_name"));
	// 状态	
	API_DTO_FIELD_DEFAULT(String, statuscd, ZH_WORDS_GETTER("paymentaudit.field.status_cd"));
	// 备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("paymentaudit.field.remark"));

};
// 分页查询对象
class PaymentAuditListPageDTO : public PageDTO<PaymentAuditListDTO::Wrapper>
{
	DTO_INIT(PaymentAuditListPageDTO, PageDTO<PaymentAuditListDTO::Wrapper>);
};

class PaymentAuditHistoryPageDTO : public PageDTO<PaymentAuditHistoryDTO::Wrapper>
{
	DTO_INIT(PaymentAuditHistoryPageDTO, PageDTO<PaymentAuditHistoryDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_PAYMENTAUDIT_DTO_