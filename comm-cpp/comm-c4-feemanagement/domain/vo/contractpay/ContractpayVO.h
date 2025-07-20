#pragma once

#ifndef _CONTRACTPAYVO_H_
#define _CONTRACTPAYVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/contractpay/ContractpayDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

// 合同收费显示JsonVO，用于响应给客户端的Json对象
class ContractpayJsonVO : public JsonVO<ContractpayAddDTO::Wrapper> {
	DTO_INIT(ContractpayJsonVO, JsonVO<ContractpayAddDTO::Wrapper>);
};

// 合同收费分页显示JsonVO，用于响应给客户端的Json对象
class ContractpayPageJsonVO : public JsonVO<ContractpayPageDTO::Wrapper> {
	DTO_INIT(ContractpayPageJsonVO, JsonVO<ContractpayPageDTO::Wrapper>);
};

// 变更合同收费显示JsonVO，用于响应给客户端的Json对象
class ChangeContractcostJsonVO : public JsonVO<ChangeContractcostDTO::Wrapper> {
	DTO_INIT(ChangeContractcostJsonVO, JsonVO<ChangeContractcostDTO::Wrapper>);
};

// 取消合同收费显示JsonVO，用于响应给客户端的Json对象
class CancelContractcostJsonVO : public JsonVO<CancelContractcostDTO::Wrapper> {
	DTO_INIT(CancelContractcostJsonVO, JsonVO<CancelContractcostDTO::Wrapper>);
};

// 缴纳合同收费显示JsonVO，用于响应给客户端的Json对象
class ContractcostChargeJsonVO : public JsonVO<ContractcostChargeDTO::Wrapper> {
	DTO_INIT(ContractcostChargeJsonVO, JsonVO<ContractcostChargeDTO::Wrapper>);
};

// 合同缴费记录显示JsonVO，用于响应给客户端的Json对象
class ContractcostChargeRecordJsonVO : public JsonVO<ContractcostChargeRecordDTO::Wrapper> {
	DTO_INIT(ContractcostChargeRecordJsonVO, JsonVO<ContractcostChargeRecordDTO::Wrapper>);
};

// 合同缴费记录分页显示JsonVO，用于响应给客户端的Json对象
class GetContractcostChargeRecordPageJsonVO : public JsonVO<GetContractcostChargeRecordPageDTO::Wrapper> {
	DTO_INIT(GetContractcostChargeRecordPageJsonVO, JsonVO<GetContractcostChargeRecordPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)


#endif // !_CONTRACTPAYVO_H_