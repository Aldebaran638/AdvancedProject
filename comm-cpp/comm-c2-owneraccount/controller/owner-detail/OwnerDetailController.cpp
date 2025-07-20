#include "stdafx.h"
#include "OwnerDetailController.h"
#include "../../service/owner-detail/OwnerDetailService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

OwnerDetailPageJsonVO::Wrapper OwnerDetailController::OwnerDetail_execQueryAll(const OwnerDetailQuery::Wrapper& query)
{
	
	// 定义返回数据对象
	auto jvo = OwnerDetailPageJsonVO::createShared();
	
	// 参数校验
	// 非空校验
	if (!query->acct_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	
	// 定义一个Service
	OwnerDetailService service;
	// 查询数据
	auto result = service.OwnerDetail_listAll(query);
	// 响应结果
	jvo->success(result);
	
	return jvo;
}

StringJsonVO::Wrapper OwnerDetailController::execAddOwnerDetail(const OwnerDetailAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
/*
测试数据：
{
  "link": "13111011002",
  "owner_name": "孙悟空",
  "receivable_amount": 114514,
  "prime_rate": "1",
  "obj_type": "6006",
  "remark": "yesyesyes",
  "community_id": "2024022647620054"
}
*/

	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->link || !dto->owner_name || !dto->receivable_amount || !dto->prime_rate || !dto->obj_type)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->receivable_amount < 0)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 备注长度限制
	if (dto->remark && ((string)(dto->remark)).length()>512)
	{
		jvo->init(nullptr, ResultStatus(u8"字数超出限制", 400));
		return jvo;
	}
	
	// 定义一个Service
	OwnerDetailService service;

	dto->setPayload(&payload);
	std::string id = service.OwnerDetail_add_saveData(dto);
	if (id != "") {
		jvo->success(id);
	}
	else
	{
		jvo->fail("");
	}
	//响应结果
	return jvo;
}

OwnerDetailAccountNamePageJsonVO::Wrapper OwnerDetailController::execQueryAllAccountNameByLink(const OwnerDetailAccountNameQuery::Wrapper& Query)
{
	auto jvo = OwnerDetailAccountNamePageJsonVO::createShared();

	OwnerDetailService service;
	auto result = service.listAllAccountNameByLink(Query);
	jvo->success(result);
	return jvo;
}



StringJsonVO::Wrapper OwnerDetailController::execUndoOwnerDetail(const OwnerDetailUndoDTO::Wrapper& dto, const PayloadDTO& payload)
{

	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();

	// 备注长度限制
	if (dto->remark && ((string)(dto->remark)).length() > 512)
	{
		jvo->init(nullptr, ResultStatus(u8"字数超出限制", 400));
		return jvo;
	}

	// 定义一个Service
	OwnerDetailService service;

	dto->setPayload(&payload);
	std::string id = service.OwnerDetail_undo_saveData(dto);
	if (id != "") {
		jvo->success(id);
	}
	else
	{
		jvo->fail("");
	}
	//响应结果
	return jvo;
}