//这里的预编译标头顺序不能改变
#include "stdafx.h"
#include "RoomController.h"
#include "domain/dto/room/RoomDTO.h"
#include "service/room/RoomService.h"
#include "domain/query/room/RoomQuery.h"
#include "domain/vo/room/RoomVO.h"

using namespace oatpp::web::server::api;

//RoomJsonVO::Wrapper RoomController::execQueryById(const String& id)
//{
//    // 响应对象
//    auto jvo = RoomJsonVO::createShared();
//
//    if (id == nullptr || id->empty()) {
//        jvo->init(nullptr, RS_PARAMS_INVALID); //RS_PARAMS_INVALID->错误码
//        return jvo;
//    }
//
//    try {
//        RoomService service;
//
//        // 执行查询
//        auto res = service.getById(id);
//
//        if (res) {
//            jvo->success(res); // 成功返回数据
//        }
//        else {
//            jvo->init(nullptr, RS_NOT_FOUND); //数据不存在
//        }
//    }
//    catch (const std::exception& e) {
//        OATPP_LOGE("RoomController", "Error: %s", e.what());
//        jvo->init(nullptr, RS_INTERNAL_ERROR); //服务器内部错误
//    }
//
//    return jvo;
//}

RoomPageJsonVO::Wrapper RoomController::execQueryRoom(const RoomQuery::Wrapper& query)
{
    
	// 定义一个Service
	RoomService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = RoomPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

