#pragma once
#ifndef _PAYDET_SERVICE_
#define _PAYDET_SERVICE_
#include "domain/vo/paydet/PayDetVO.h"
#include "domain/query/paydet/PayDetQuery.h"
#include "domain/dto/paydet/PayDetDTO.h"

/**
 * 缴费明细服务实现
 */
class PayDetService
{
public:
    // 分页查询缴费明细
    PayDetPageDTO::Wrapper listAll(const GetPaydetQuery::Wrapper& query);
};

#endif // !_PAYDET_SERVICE_