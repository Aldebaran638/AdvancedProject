#pragma once
#ifndef _DETAILCONTROLLER_H_
#define _DETAILCONTROLLER_H_
#include "domain/dto/dtos/detailDTO.h"
#include "domain/GlobalInclude.h"
#include "domain/query/querys/detailQuery.h"
#include "domain/vo/vos/detailVO.h"
#include "domain/vo/BaseJsonVO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)


class detailController :public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(detailController);
public://定义接口
	ENDPOINT_INFO(queryDetail) {

		
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("menu-catalog.detail.summary"), detailJsonVO::Wrapper);



	}

	// 3.2 定义查询接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/c3-housefeemgr/query-paymentrecord-detail", queryDetail, QUERY(String, id), execQueryDetail(id));



private://定义接口执行函数
	// 3.3 演示分页查询数据
	detailJsonVO::Wrapper execQueryDetail(const String& id);


};

#include OATPP_CODEGEN_END(ApiController)


#endif 