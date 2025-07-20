#include "stdafx.h"
#include "MemberController.h"
#include "../../service/member/MemberService.h"
//#include "../ApiDeclarativeServicesHelper.h"
//#include "ExcelComponent.h"
//#include "SimpleDateTimeFormat.h"

MemberPageJsonVO::Wrapper MemberController::execQueryMember(const MemberQuery::Wrapper& query)
{
	//测试接口定义
	//auto vo = StringJsonVO::createShared();
	//vo->success(String("test query1"));
	//return vo;

	// 定义一个Service
	MemberService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = MemberPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


StringJsonVO::Wrapper MemberController::execAddMember(const MemberAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//测试接口定义
	//auto vo = StringJsonVO::createShared();
	//vo->success(String("test query3"));
	//return vo;

	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->link || !dto->name || !dto->sex  || !dto->owner_type_cd)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->link->size() != 11 || dto->name->empty() || dto->sex->empty() || dto->owner_type_cd->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	MemberService service;
	// 执行数据新增
	dto->setPayload(&payload);
	std::string id = service.saveData(dto);
	if (id != "") 
	{
		jvo->success(id);
	}
	else
	{
		jvo->fail("");
	}
	//响应结果
	return jvo;
}

StringJsonVO::Wrapper MemberController::execModifyMember(const MemberDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//测试接口定义
	//auto vo = StringJsonVO::createShared();
	//vo->success(String("test query4"));
	//return vo;


	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->member_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	MemberService service;
	// 执行数据修改
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->member_id);
	}
	else
	{
		jvo->fail(dto->member_id);
	}
	// 响应结果
	return jvo;
}

ListJsonVO<String>::Wrapper MemberController::execRemoveMember(const List<String>& ids)
{
	//测试接口定义
	//auto vo = ListJsonVO<String>::createShared();
	//vo->success(ids);
	//return vo;


	// 定义返回数据对象
	auto jvo = ListJsonVO<String>::createShared();
	// 参数校验
	if (ids->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	MemberService service;
	// 执行数据删除
	if (service.removeData(ids)) {
		jvo->success(ids);
	}
	else
	{
		jvo->fail(nullptr);
	}
	// 响应结果
	return jvo;
}
