#include "stdafx.h"
#include "TrackRecordController.h"
#include "../../service/applydiscount/TrackRecordService.h"

TrackRecordJsonVO::Wrapper TrackRecordController::execQueryTrackRecordDetail(const String& ardr_id) {
	// 定义返回数据对象
	auto jvo = TrackRecordJsonVO::createShared();

	// 参数检查
	if (!ardr_id) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	TrackRecordService service;
	// 执行数据新增
	auto res = service.getById(ardr_id.getValue({}));
	jvo->success(res);

	return jvo;
}

StringJsonVO::Wrapper TrackRecordController::execAddTrackRecord(const TrackRecordADDDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数检查
	// 非空效验
	if (!dto->is_true || !dto->remark) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值效验
	if (dto->is_true != "false" && dto->is_true != "true") {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	TrackRecordService service;
	// 执行数据新增
	dto->setPayload(&payload);
	std::string id = service.saveData(dto);
	if (id != "") {
		jvo->success(id);
	}
	else {
		jvo->fail("");
	}

	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper TrackRecordController::execDeleteTrackRecord(const TrackRecordDeleteDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	if (!dto->ardr_id) {
		jvo->fail(String("need water_id"));
		return jvo;
	}

	// 定义一个Service
	TrackRecordService service;
	service.removeData(dto, payload);
	jvo->success(String("delete success"));
	return jvo;
}

