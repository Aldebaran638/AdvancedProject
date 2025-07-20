#pragma once
#pragma once

#ifndef _Car_Payment_QUERY_
#define _Car_Payment_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个获取缴费记录的数据传输模型
 */
class GetPaymentRecordsQuery : public PageQuery
{
	DTO_INIT(GetPaymentRecordsQuery, PageQuery);

	// 费用项
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("fee.feeName.summary"));
	// 收费对象
	API_DTO_FIELD_DEFAULT(String, value, ZH_WORDS_GETTER("usr.fee.value"));
	// 建账时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("time.filed.creatTime"));
};

class GetFeeModificationRecordsQuery : public PageQuery
{
	DTO_INIT(GetFeeModificationRecordsQuery, PageQuery);

	// 费用项
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("fee.feeName.summary"));
	// 建账时间
	API_DTO_FIELD_DEFAULT(String, creat_time, ZH_WORDS_GETTER("time.filed.creatTime"));
	// 应收开始时间
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("time.filed.startTime"));
	// 操作人
	API_DTO_FIELD_DEFAULT(String, create_user_name, ZH_WORDS_GETTER("usr.fee.createUserName"));
};
/**
 * 车辆费用分页查询对象
 */
class CarPaymentQuery : public PageQuery
{
	
	DTO_INIT(CarPaymentQuery, PageQuery);
	/* 这段好像写错了
	//停车场—车位名称
	DTO_FIELD(String, payer_obj_name);
	DTO_FIELD_INFO(payer_obj_name) {
		info->description = ZH_WORDS_GETTER("carpayment.field.payer_obj_name");
	}
	// 车牌号
	DTO_FIELD(String, car_num);
	DTO_FIELD_INFO(car_num) {
		info->description = ZH_WORDS_GETTER("carpayment.field.car_num");
	}
	// 业主名称
	DTO_FIELD(String, owner_name);
	DTO_FIELD_INFO(owner_name) {
		info->description = ZH_WORDS_GETTER("carpayment.field.owner_name");
	}
	*/
	DTO_FIELD(String, payer_obj_id);
	DTO_FIELD_INFO(payer_obj_id) {
		info->description = ZH_WORDS_GETTER("carpayment.field.payer_obj_id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 