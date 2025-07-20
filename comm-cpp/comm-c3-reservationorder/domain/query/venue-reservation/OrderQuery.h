#pragma once
#ifndef _ORDER_QUERY_H_
#define _ORDER_QUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 场地预约订单查询对象
 */
class OrderQuery : public PageQuery
{
	DTO_INIT(OrderQuery, PageQuery);
	
	// 社区id
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("venue-reservation.field.communityId"));
	// 场地id
	API_DTO_FIELD_DEFAULT(String, spaceId, ZH_WORDS_GETTER("venue-reservation.field.spaceId"));
	// 状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("venue-reservation.field.state"));
	// 预约人
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("venue-reservation.field.personName"));
	// 预约人电话
	API_DTO_FIELD_DEFAULT(String, personTel, ZH_WORDS_GETTER("venue-reservation.field.personTel"));
	// 预约时间
	API_DTO_FIELD_DEFAULT(String, appointmentTime, ZH_WORDS_GETTER("venue-reservation.field.appointmentTime"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORDER_QUERY_H_
