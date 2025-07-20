#pragma once
#ifndef _OWNER_CONTROLLER_
#define _OWNER_CONTROLLER_
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"
#include "domain/dto/owner/OwnerDTO.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/owner/OwnerVO.h"
#include "ApiHelper.h"


#include OATPP_CODEGEN_BEGIN(ApiController)
//using namespace dto;


class OwnerController : public oatpp::web::server::api::ApiController {
    // 2 定义控制器访问入口
    API_ACCESS_DECLARE(OwnerController);
    // 3 定义接口
public:
	// 3.1 定义ID查询接口描述
	ENDPOINT_INFO(queryOwnerById) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("owner.query-by-id.summary"), OwnerJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "owner_id", ZH_WORDS_GETTER("owner.field.ownerId"), "d934050a8bb373e8f8eed0bf7507ec17", true);
	}
	// 3.2 定义ID查询接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/owner/query-by-id", queryOwnerById, QUERY(String, owner_id), execQueryById(owner_id));


private:
    // 实际业务逻辑：根据ID获取业主信息详情
	// 3.3 演示ID查询数据
	OwnerJsonVO::Wrapper execQueryById(const String& id);
};

#include OATPP_CODEGEN_END(ApiController)
#endif 