#include "stdafx.h"
#include "ContractpayController.h"
#include "../../service/contractpay/ContractpayService.h"
#include "../../domain/dto/contractpay/ContractpayDTO.h"
#include<iostream>


ContractpayPageJsonVO::Wrapper ContractpayController::execQueryContractpay(const ContractpayQuery::Wrapper& query) {
	// 定义一个Service
	ContractpayService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ContractpayPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper ContractpayController::execAddContractpay(const ContractpayAddDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->payer_obj_id || !dto->start_time || !dto->end_time) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if ((dto->state != "2008001" && dto->state != "2007001" && dto->state != "2009001")) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	ContractpayService service;
	// 执行数据新增
	dto->setPayload(&payload);
	std::string id = service.saveData(dto);
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

StringJsonVO::Wrapper ContractpayController::execModifyContractpay(const ChangeContractcostDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 有效值校验
	if (!dto->fee_id) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	/*string a;
	std::cout << a.toString(dto->fee_id);*/
	//定义一个service
	ContractpayService service;
	//执行数据修改
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		//建账时间修改
		jvo->success(dto->create_time);
		//应收开始时间修改
		jvo->success(dto->start_time);
		//应结束时间修改
		jvo->success(dto->end_time);
	}
	else
	{
		jvo->fail(dto->create_time);
		jvo->fail(dto->start_time);
		jvo->fail(dto->end_time);

	}
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper ContractpayController::execRemoveContractpay(const CancelContractcostDTO::Wrapper& remove, const PayloadDTO& payload) {
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!remove->fee_id) {
		jvo->fail(String("need fee_id"));
		return jvo;
	}
	ContractpayService service;
	// 执行数据删除
	if (service.removeData(remove, payload)) {
		jvo->success(String("delete success"));
	}
	else
	{
		jvo->fail(String("delete fail"));
	}
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper ContractpayController::execChargeContractpay(const ContractcostChargeDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (dto->chargecycle->empty()|| dto->chargeway->empty() || dto->feeid->empty() || dto->received->empty()) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	//std::cout << "数据校验通过" << std::endl;
	//jvo->init(nullptr, RS_PARAMS_INVALID);
	//return jvo;
	// 定义一个Service
	ContractpayService service;
	// 执行数据新增
	dto->setPayload(&payload);
	std::string id = service.saveData(dto);
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

GetContractcostChargeRecordPageJsonVO::Wrapper ContractpayController::execQueryContractpayRecord(const ContractpayRecordQuery::Wrapper& query) {
	// 定义一个Service
	ContractpayService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = GetContractcostChargeRecordPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
ContractcostChargeRecordJsonVO::Wrapper ContractpayController::execQueryContractpayRecordDetail(const String& id) {
	// 定义返回数据对象
	auto jvo = ContractcostChargeRecordJsonVO::createShared();

	// 定义一个Service
	ContractpayService service;
	// 执行数据新增
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	//响应结果
	return jvo;
}