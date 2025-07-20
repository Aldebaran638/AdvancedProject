#ifndef _CANCELLATIONFEE_VO_
#define _CANCELLATIONFEE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/fee_cancellations/CancellationFeeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 费用批次显示JsonVO，用于响应给客户端的Json对象
 */
class CancellationFeeJsonVO : public JsonVO<CancellationFeeDTO::Wrapper> {
	DTO_INIT(CancellationFeeJsonVO, JsonVO<CancellationFeeDTO::Wrapper>);
};

/**
 * 费用批次分页显示JsonVO，用于响应给客户端的Json对象
 */
class CancellationFeePageJsonVO : public JsonVO<CancellationFeePageDTO::Wrapper> {
	DTO_INIT(CancellationFeePageJsonVO, JsonVO<CancellationFeePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_