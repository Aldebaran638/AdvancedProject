#ifndef PAYDETVO_H
#define PAYDETVO_H

#include "../../GlobalInclude.h"
#include "../../dto/paydet/PayDetDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * 缴费明细JsonVO对象
 */
class GetPaydetJsonVO : public JsonVO<PayDetDTO::Wrapper> {
    DTO_INIT(GetPaydetJsonVO, JsonVO<PayDetDTO::Wrapper>);
};

/*
 * 缴费明细分页显示JsonVO对象，响应给客户端
 */
class PayDetPageJsonVO : public JsonVO<PayDetPageDTO::Wrapper> {
    DTO_INIT(PayDetPageJsonVO, JsonVO<PayDetPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // PAYDETVO_H