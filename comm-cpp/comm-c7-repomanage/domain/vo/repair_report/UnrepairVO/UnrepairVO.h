#ifndef _UNREPAIRVO_H_
#define _UNREPAIRVO_H_

#include "../../../GlobalInclude.h"
#include "../../../dto/repair_report/Unrepair/UnrepairDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 报修未完成显示JsonVO，用于响应给客户端的Json对象
 */
class UnrepairJsonVO : public JsonVO<UnrepairDTO::Wrapper> {
	DTO_INIT(UnrepairJsonVO, JsonVO<UnrepairDTO::Wrapper>);
};

/**
 * 报修未完成分页显示JsonVO，用于响应给客户端的Json对象
 */
class UnrepairPageJsonVO : public JsonVO<UnrepairPageDTO::Wrapper> {
	DTO_INIT(UnrepairPageJsonVO, JsonVO<UnrepairPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif