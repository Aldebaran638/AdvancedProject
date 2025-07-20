#pragma once
#pragma once
#ifndef _ORDER_DTO_H_
#define _ORDER_DTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 场地预约订单id
 */
class OrderIdDTO : public oatpp::DTO
{
	DTO_INIT(OrderIdDTO, oatpp::DTO);

	// 订单编号
	API_DTO_FIELD_DEFAULT(String, cspId, ZH_WORDS_GETTER("venue-reservation.field.cspId"));
};

/**
 * 场地预约订单分页传输对象
 */
class OrderDTO : public OrderIdDTO
{
	DTO_INIT(OrderDTO, OrderIdDTO);

	// 场馆
	API_DTO_FIELD_DEFAULT(String, venueName, ZH_WORDS_GETTER("venue-reservation.field.venueName"));
	// 场地
	API_DTO_FIELD_DEFAULT(String, spaceName, ZH_WORDS_GETTER("venue-reservation.field.spaceName"));
	// 预约人
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("venue-reservation.field.personName"));
	// 预约电话
	API_DTO_FIELD_DEFAULT(String, personTel, ZH_WORDS_GETTER("venue-reservation.field.personTel"));
	// 预约日期
	API_DTO_FIELD_DEFAULT(String, appointmentTime, ZH_WORDS_GETTER("venue-reservation.field.appointmentTime"));
	// 预约时间
	API_DTO_FIELD_DEFAULT(String, times, ZH_WORDS_GETTER("venue-reservation.field.times"));
	// 应收金额
	API_DTO_FIELD_DEFAULT(String, receivableAmount, ZH_WORDS_GETTER("venue-reservation.field.receivableAmount"));
	// 实收金额
	API_DTO_FIELD_DEFAULT(String, receivedAmount, ZH_WORDS_GETTER("venue-reservation.field.receivedAmount"));
	// 支付方式
	API_DTO_FIELD_DEFAULT(String, payWay, ZH_WORDS_GETTER("venue-reservation.field.payWay"));
	// 支付方式名称
	API_DTO_FIELD_DEFAULT(String, payWayName, ZH_WORDS_GETTER("venue-reservation.field.payWayName"));
	// 状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("venue-reservation.field.state"));
	// 状态名称
	API_DTO_FIELD_DEFAULT(String, stateName, ZH_WORDS_GETTER("venue-reservation.field.stateName"));
	// 创建时间
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("venue-reservation.field.createTime"));
	// 备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("venue-reservation.field.remark"));
};

class OrderPageDTO : public PageDTO<OrderDTO::Wrapper>
{
	DTO_INIT(OrderPageDTO, PageDTO<OrderDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORDER_DTO_H_
