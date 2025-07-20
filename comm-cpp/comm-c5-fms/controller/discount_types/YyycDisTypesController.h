#pragma once
#ifndef _YYYCDISTYPESCONTROLLER_
#define _YYYCDISTYPESCONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/discount_types/YyycDisTypesDTO.h"
#include "domain/vo/discount_types/YyycDisTypesVO.h"
#include "domain/query/discount_types/YyycDisTypesQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/*
	修改优惠类型模型
*/
class YyycDisTypesController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(YyycDisTypesController);
public: // 定义接口
	// 1.1 定义修改优惠类型接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("type.update.summary"), modifyTypes, StringJsonVO::Wrapper);
	// 1.2 定义修改优惠类型接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c5-feemanage/discounttype/put-discount-type", modifyTypes, BODY_DTO(YyycDisTypesDTO::Wrapper, dto), execModifyTypes(dto, authObject->getPayload()));

	// 2.1 定义删除优惠类型接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("type.delete.summary"), removeTypes, ListJsonVO<String>::Wrapper);
	// 2.2 定义删除优惠类型接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c5-feemanage/discounttype/delete-discount-type", removeTypes, BODY_DTO(List<String>, ids), execRemoveTypes(ids));


private:// 定义接口执行函数
	// 1.1 修改优惠类型数据
	StringJsonVO::Wrapper execModifyTypes(const YyycDisTypesDTO::Wrapper& dto, const PayloadDTO& payload);
	// 1.2 删除优惠类型数据
	ListJsonVO<String>::Wrapper execRemoveTypes(const List<String>& ids);
};
#include OATPP_CODEGEN_END(ApiController)
#endif