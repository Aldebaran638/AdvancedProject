#include "stdafx.h"
#include "CommunityVenueController.h"
#include "service/CommunityVenueService.h"

/*--- 分页查询场馆 ---*/
CommunityVenuePageJsonVO::Wrapper
CommunityVenueController::execQueryVenue(const CommunityVenueQuery::Wrapper& query) {

    CommunityVenueService service;
    //直接返回一个PageDTO实例
    auto result = service.listAll(query);
    auto jvo = CommunityVenuePageJsonVO::createShared();

    jvo->success(result);
    return jvo;
}

/*id 查询*/
CommunityVenueJsonVO::Wrapper CommunityVenueController::execQueryById(const String& id)
{
    // 定义返回数据对象
    auto jvo = CommunityVenueJsonVO::createShared();

    // 参数校验
    // 非空校验
    if (!id)
    {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        return jvo;
    }

    // 定义一个Service
    CommunityVenueService service;
    // 执行数据新增
    auto res = service.getById(id.getValue({}));
    jvo->success(res);

    //响应结果
    return jvo;
}

/*--- 新增场馆 ---*/
StringJsonVO::Wrapper
CommunityVenueController::execAddVenue(const CommunityVenueAddDTO::Wrapper& dto,
    const PayloadDTO& payload) {
    // 1. 创建返回 VO
    auto jvo = StringJsonVO::createShared();

    // 2. 参数校验：非空 & 非空字符串
    if (!dto->name || dto->name->empty() ||
        !dto->startTime || dto->startTime->empty() ||
        !dto->endTime || dto->endTime->empty()) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        return jvo;
    }

    // 3. 注入 Payload
    dto->setPayload(&payload);

    // 4. 调用 Service 执行新增
    CommunityVenueService service;
    std::string newId = service.saveData(dto);

    // 5. 根据 Service 返回值决定 success 或 fail
    if (!newId.empty()) {
        jvo->success(newId);
    }
    else {
        jvo->fail("");
    }

    return jvo;
}


/*--- 修改场馆 ---*/
StringJsonVO::Wrapper CommunityVenueController::execModifyVenue(const CommunityVenueModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
    // 定义返回数据对象
    auto jvo = StringJsonVO::createShared();
    // 参数校验
    if (!dto->venueId)
    {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        return jvo;
    }
    // 定义一个Service
    CommunityVenueService service;
    // 执行数据修改
    dto->setPayload(&payload);
    if (service.updateData(dto)) {
        jvo->success(dto->venueId);
    }
    else
    {
        jvo->fail(dto->venueId);
    }
    // 响应结果
    return jvo;
}



/*--- 删除场馆 ---*/
ListJsonVO<String>::Wrapper
CommunityVenueController::execDeleteVenue(const List<String>& ids) {
    auto jvo = ListJsonVO<String>::createShared();
    if (ids->empty()) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        return jvo;
    }
    CommunityVenueService service;
    // TODO: 删除逻辑，返回删除后的 ID 
    if (service.removeData(ids)) {
        jvo->success(ids);
    }
    else
    {
        jvo->fail(nullptr);
    }
    return jvo;
}
