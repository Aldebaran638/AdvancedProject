#pragma once
#ifndef _PAYREMAINBUDTO_H_
#define _PAYREMAINBUDTO_H_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/*
添加获取催缴列表查询返回值（条件+分页）
*/
class PayRemainBuDTO : public oatpp::DTO
{
	DTO_INIT(PayRemainBuDTO, DTO);
	////编号
	//API_DTO_FIELD_DEFAULT(UInt64, ofc_id, ZH_WORDS_GETTER("Bupayremind.field.ofc_id"));
	// 业主名称
	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("Bupayremind.field.owner_name"));
	//付费对象
	API_DTO_FIELD_DEFAULT(String, payer_obj_name, ZH_WORDS_GETTER("Bupayremind.field.payer_obj_name"));
	// 费用名称
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("Bupayremind.field.fee_name"));
	//催缴金额
	API_DTO_FIELD_DEFAULT(UInt64, amountd_owed, ZH_WORDS_GETTER("Bupayremind.field.amountd_owed"));
	//欠费时间段
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("Bupayremind.field.start_time"));
	// 催缴方式
	API_DTO_FIELD_DEFAULT(String, callable_way, ZH_WORDS_GETTER("Bupayremind.field.callable_way"));
	//催缴人
	API_DTO_FIELD_DEFAULT(String, staff_name, ZH_WORDS_GETTER("Bupayremind.field.staff_name"));
	//状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("Bupayremind.field.state"));
	//说明
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("Bupayremind.field.remark"));
	//创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("Bupayremind.field.create_time"));
	// 新增字段
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("common.field.community_id"));
	API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("bupayremind.field.owner_id"));
	API_DTO_FIELD_DEFAULT(String, payer_obj_id, ZH_WORDS_GETTER("bupayremind.field.payer_obj_id"));
	API_DTO_FIELD_DEFAULT(String, config_id, ZH_WORDS_GETTER("bupayremind.field.config_id"));
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("bupayremind.field.fee_id"));
	API_DTO_FIELD_DEFAULT(String, payer_obj_type, ZH_WORDS_GETTER("bupayremind.field.payer_obj_type"));
	API_DTO_FIELD_DEFAULT(String, staff_id, ZH_WORDS_GETTER("bupayremind.field.staff_id"));
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("bupayremind.field.end_time"));
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("bupayremind.field.status_cd"));
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * 分页传输对象
 */
class PayRemainBuPageDTO : public PageDTO<PayRemainBuDTO::Wrapper>
{
	DTO_INIT(PayRemainBuPageDTO, PageDTO<PayRemainBuDTO::Wrapper>);
};

/**
 *查询传输对象
 */
class CombinePayRemainBuDTO : public PayRemainBuDTO {
	DTO_INIT(CombinePayRemainBuDTO, DTO);
	API_DTO_FIELD_DEFAULT(List<PayRemainBuDTO::Wrapper>, DTOList, ZH_WORDS_GETTER("Bupayremind.DTOList"));
	API_DTO_FIELD_DEFAULT(Int64, total, ZH_WORDS_GETTER("Bupayremind.total"));
public:
	CombinePayRemainBuDTO() {
		this->DTOList = List<PayRemainBuDTO::Wrapper>::createShared();
		this->total = Int64(static_cast<int64_t>(0));
	}
	void addData(PayRemainBuDTO::Wrapper dto) {
		DTOList->push_back(dto);
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif 