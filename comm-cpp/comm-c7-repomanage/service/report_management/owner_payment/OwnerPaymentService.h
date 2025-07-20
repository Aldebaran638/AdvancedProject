#pragma once

#ifndef _OWNERPAYMENTSERVICE_
#define _OWNERPAYMENTSERVICE_
#include "domain/vo/owner_payment/OwnerPaymentVO.h"
#include "domain/query/owner_payment/OwnerPaymentQuery.h"
#include "domain/dto/owner_payment/OwnerPaymentDTO.h"
#include "domain/do/owner_payment/OwnerPaymentDO.h"

/**
 *  获取业主缴费明细列表服务实现
 */
class OwnerPaymentService
{
public:
	// 分页查询所有数据
	OwnerPaymentPageDTO::Wrapper listOwnerPayment(const OwnerPaymentQuery::Wrapper& query);
	std::list<OwnerPaymentDO> listAllExport();
	OwnerPaymentFeeTypeListDTO::Wrapper listFeeTypeList(const OwnerPaymentListQuery::Wrapper& query);
	OwnerPaymentConfigNameListDTO::Wrapper listConfigNametList(const OwnerPaymentListQuery::Wrapper& query);
};

#endif // !_OWNERPAYMENTSERVICE_

