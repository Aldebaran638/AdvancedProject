#pragma

#ifndef _SPACEMGRCONTROLLER_H_
#define _SPACEMGRCONTROLLER_H_

#include "domain/dto/SpaceDTO.h"
#include "domain/vo/SpaceVO.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class SpaceMgrController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(SpaceMgrController);
public:	//定义接口

	// 定义添加场地接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("space.add-space.summary"), addSpace, StringJsonVO::Wrapper);
	// 定义添加场地接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/c3-pacemgr/add-venue", addSpace, BODY_DTO(SpaceAddDTO::Wrapper, dto), execAddSpace(dto, authObject->getPayload()));

	// 定义修改场地接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("space.modify-space.summary"), modifySpace, StringJsonVO::Wrapper);
	// 定义修改场地接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c3-pacemgr/modify-venue", modifySpace, BODY_DTO(SpaceUpdateDTO::Wrapper, dto), execModifySpace(dto, authObject->getPayload()));

	// 删除场地接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("space.delete-space.summary"), removeSpace, ListJsonVO<String>::Wrapper);
	// 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c3-pacemgr/remove-venue", removeSpace, BODY_DTO(List<String>, ids), execRemoveSpace(ids));

private: //定义接口执行函数
	// 添加场地执行函数
	StringJsonVO::Wrapper execAddSpace(const SpaceAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改场地执行函数
	StringJsonVO::Wrapper execModifySpace(const SpaceUpdateDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改场地执行函数
	ListJsonVO<String>::Wrapper execRemoveSpace(const List<String>& ids);
};

#include OATPP_CODEGEN_END(ApiController)
#endif
