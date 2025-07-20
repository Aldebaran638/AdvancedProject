#pragma once
#ifndef _MEMBER_CONTROLLER_
#define _MEMBER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/member/MemberQuery.h"
#include "domain/dto/member/MemberDTO.h"
#include "domain/vo/member/MemberVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class MemberController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(MemberController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryMember) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("member.get.summary"), MemberPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("member.field.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "link", ZH_WORDS_GETTER("member.field.link"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "id_card", ZH_WORDS_GETTER("member.field.id_card"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "owner_type_cd", ZH_WORDS_GETTER("member.field.owner_type_cd"), "1001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("member.field.sex"), "0", false);
		API_DEF_ADD_QUERY_PARAMS(String, "address", ZH_WORDS_GETTER("member.field.address"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "remark", ZH_WORDS_GETTER("member.field.remark"), "", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/member", queryMember, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, MemberQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryMember(userQuery));
	}

	// 3.1 定义新增接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("member.post.summary"), addMember, StringJsonVO::Wrapper);
	// 3.2 定义新增接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/member", addMember, BODY_DTO(MemberAddDTO::Wrapper, dto), execAddMember(dto, authObject->getPayload()));

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("member.put.summary"), modifyMember, StringJsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/member", modifyMember, BODY_DTO(MemberDTO::Wrapper, dto), execModifyMember(dto, authObject->getPayload()));

	// 3.1 定义删除接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("member.delete.summary"), removeMember, ListJsonVO<String>::Wrapper);
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/member", removeMember, BODY_DTO(List<String>, ids), execRemoveMember(ids));

private:
	// 3.3 分页查询数据
	MemberPageJsonVO::Wrapper execQueryMember(const MemberQuery::Wrapper& query);
	// 3.3 新增数据
	StringJsonVO::Wrapper execAddMember(const MemberAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 修改数据
	StringJsonVO::Wrapper execModifyMember(const MemberDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 删除数据
	ListJsonVO<String>::Wrapper execRemoveMember(const List<String>& ids);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_