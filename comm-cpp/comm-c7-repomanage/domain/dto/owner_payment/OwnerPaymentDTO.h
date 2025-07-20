#pragma once

#ifndef _OWNERPAYMENTDTO_H_
#define _OWNERPAYMENTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 业主缴费明细列表数据传输模型
**/
class OwnerPaymentDetailDTO : public oatpp::DTO
{
	DTO_INIT(OwnerPaymentDetailDTO, DTO);

	// 业主
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("owner-payment-detail.field.ownerName"));
	// 房屋编号
	API_DTO_FIELD_DEFAULT(String, roomName, ZH_WORDS_GETTER("owner-payment-detail.field.roomName"));
	// 费用项目
	API_DTO_FIELD_DEFAULT(String, configName, ZH_WORDS_GETTER("owner-payment-detail.field.configName"));
	// 不同月份费用
	API_DTO_FIELD_DEFAULT(List<Float64>, pfMonth, ZH_WORDS_GETTER("owner-payment-detail.field.pfMonth"));
	// 合计费用
	API_DTO_FIELD_DEFAULT(Float64, totalAmount, ZH_WORDS_GETTER("owner-payment-detail.field.totalAmount"));
	// 应收费用
	API_DTO_FIELD_DEFAULT(Float64, receivableAmount, ZH_WORDS_GETTER("owner-payment-detail.field.receivableAmount"));
	// 预收费用
	API_DTO_FIELD_DEFAULT(Float64, receivedAmount, ZH_WORDS_GETTER("owner-payment-detail.field.receivedAmount"));
};


/**
 * 获取报修明细列表,添加小区id标识
 */
class OwnerPaymentDTO : public OwnerPaymentDetailDTO
{
	DTO_INIT(OwnerPaymentDTO, OwnerPaymentDetailDTO);
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("owner-payment-detail.field.communityId"));
};

/**
 * 业主缴费明细列表分页传输对象
 */
class  OwnerPaymentPageDTO : public PageDTO<OwnerPaymentDetailDTO::Wrapper>
{
	DTO_INIT(OwnerPaymentPageDTO, PageDTO<OwnerPaymentDetailDTO::Wrapper>);
};


// 费用大类DTO
class OwnerPaymentFeeTypeDTO : public oatpp::DTO
{
	DTO_INIT(OwnerPaymentFeeTypeDTO, DTO);
	// 收费类型编号
	DTO_FIELD(String, feeTypeCd);
	DTO_FIELD_INFO(feeTypeCd) {
		info->description = ZH_WORDS_GETTER("owner-payment-detail.field.feeTypeCd");
	}
	// 收费类型名称
	DTO_FIELD(String, feeTypeName);
	DTO_FIELD_INFO(feeTypeName) {
		info->description = ZH_WORDS_GETTER("owner-payment-detail.field.feeTypeName");
	}
};

// 费用名称DTO
class OwnerPaymentConfigNameDTO : public oatpp::DTO
{
	DTO_INIT(OwnerPaymentConfigNameDTO, DTO);
	// 收费类型编号
	DTO_FIELD(String, configId);
	DTO_FIELD_INFO(configId) {
		info->description = ZH_WORDS_GETTER("owner-payment-detail.field.configId");
	}
	// 收费类型名称
	DTO_FIELD(String, configName);
	DTO_FIELD_INFO(configName) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.configName");
	}
};

/**
* 费用大类列表传输模型
**/
class OwnerPaymentFeeTypeListDTO : public oatpp::DTO
{
	DTO_INIT(OwnerPaymentFeeTypeListDTO, DTO);
	DTO_FIELD(List<OwnerPaymentFeeTypeDTO::Wrapper>, rows) = {};
	DTO_FIELD_INFO(rows) {
		info->description = ZH_WORDS_GETTER("owner-payment-detail.field.feeTypeCdList");
	}
public:
	void addData(OwnerPaymentFeeTypeDTO::Wrapper data) {
		this->rows->push_back(data);
	}
};

/**
* 费用名称列表传输模型
**/
class OwnerPaymentConfigNameListDTO : public oatpp::DTO
{
	DTO_INIT(OwnerPaymentConfigNameListDTO, DTO);
	DTO_FIELD(List<OwnerPaymentConfigNameDTO::Wrapper>, rows) = {};
	DTO_FIELD_INFO(rows) {
		info->description = ZH_WORDS_GETTER("owner-payment-detail.field.configNameList");
	}
public:
	void addData(OwnerPaymentConfigNameDTO::Wrapper data) {
		this->rows->push_back(data);
	}
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_OWNERPAYMENTDTO_H_