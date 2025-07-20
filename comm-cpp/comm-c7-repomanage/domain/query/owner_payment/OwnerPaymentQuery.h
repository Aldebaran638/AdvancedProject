#pragma once

#ifndef _OWNERPAYMENTQUERY_H_
#define _OWNERPAYMENTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class OwnerPaymentQuery : public PageQuery
{
	DTO_INIT(OwnerPaymentQuery, PageQuery);

	// 收费大类
	API_DTO_FIELD_DEFAULT(String, feeTypeCd, ZH_WORDS_GETTER("owner-payment-detail.field.feeTypeCd"));
	// 收费项
	API_DTO_FIELD_DEFAULT(String, configName, ZH_WORDS_GETTER("owner-payment-detail.field.configName"));
	// 房屋编号
	API_DTO_FIELD_DEFAULT(String, roomName, ZH_WORDS_GETTER("owner-payment-detail.field.roomName"));
	// 业主名称
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("owner-payment-detail.field.ownerName"));
	// 年份
	API_DTO_FIELD_DEFAULT(Int32, pfYear, ZH_WORDS_GETTER("owner-payment-detail.field.pfYear")); 

};

/**
 * 简单查询对象
 * 用于查询收费类型和楼栋编号列表
 */
class OwnerPaymentListQuery : public PageQuery
{
	DTO_INIT(OwnerPaymentListQuery, PageQuery);
	// 小区id communityId
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("owner-payment-detail.field.communityId"));
	// 收费大类
	API_DTO_FIELD_DEFAULT(String, feeTypeCd, ZH_WORDS_GETTER("owner-payment-detail.field.feeTypeCd"));


};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERPAYMENTQUERY_H_