#pragma once

#ifndef _OWNERPAYMENTVO_H_
#define _OWNERPAYMENTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/owner_payment/OwnerPaymentDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 业主缴费明细显示JsonVO，用于响应给客户端的Json对象
 */
class OwnerPaymentJsonVO : public JsonVO<OwnerPaymentDetailDTO::Wrapper> {
	DTO_INIT(OwnerPaymentJsonVO, JsonVO<OwnerPaymentDetailDTO::Wrapper>);
};

/**
 * 业主缴费明细分页显示JsonVO，用于响应给客户端的Json对象
 */
class OwnerPaymentPageJsonVO : public JsonVO<OwnerPaymentPageDTO::Wrapper> {
	DTO_INIT(OwnerPaymentPageJsonVO, JsonVO<OwnerPaymentPageDTO::Wrapper>);
};

/**
 * 项目大类显示JsonVO
 */
class OwnerPaymentFeeTypeJsonVO : public JsonVO<OwnerPaymentFeeTypeListDTO::Wrapper> {
	DTO_INIT(OwnerPaymentFeeTypeJsonVO, JsonVO<OwnerPaymentFeeTypeListDTO::Wrapper>);
};

/**
 * 项目名称显示JsonVO
 */
class OwnerPaymentConfigNameJsonVO : public JsonVO<OwnerPaymentConfigNameListDTO::Wrapper> {
	DTO_INIT(OwnerPaymentConfigNameJsonVO, JsonVO<OwnerPaymentConfigNameListDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERPAYMENTVO_H_