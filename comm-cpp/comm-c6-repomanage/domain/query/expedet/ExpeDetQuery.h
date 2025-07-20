#pragma once

#ifndef _EXPEDETQUERY_H_
#define _EXPEDETQUERY_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 房屋费用明细查询对象
 */
class ExpedetBuildingFeeDetailQuery : public PageQuery
{
	DTO_INIT(ExpedetBuildingFeeDetailQuery, PageQuery);
	//起始时间
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("expedet.field.query.startTime"));
	//结束时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("expedet.field.query.endTime"));
	//房屋编号
	API_DTO_FIELD_DEFAULT(String, room_name, ZH_WORDS_GETTER("expedet.field.query.HourseID"));
	//业主姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("expedet.field.query.ProprietorName"));
	//手机号
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("expedet.field.query.PhoneNumber"));
};

/**
 * 业主费用明细查询对象
 */
class ExpedetOwnerFeeDetailQuery : public PageQuery
{
	DTO_INIT(ExpedetOwnerFeeDetailQuery, PageQuery);
	//起始时间
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("expedet.field.query.startTime"));
	//结束时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("expedet.field.query.endTime"));
	//房屋编号
	API_DTO_FIELD_DEFAULT(String, room_name, ZH_WORDS_GETTER("expedet.field.query.HourseID"));
	//业主姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("expedet.field.query.ProprietorName"));
	//手机号
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("expedet.field.query.PhoneNumber"));
};

/**
 * 合同费用明细查询对象
 */
class ExpedetContractFeeDetailQuery : public PageQuery
{
	DTO_INIT(ExpedetContractFeeDetailQuery, PageQuery);
	//起始时间
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("expedet.field.query.startTime"));
	//结束时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("expedet.field.query.endTime"));
	//合同名称
	API_DTO_FIELD_DEFAULT(String, contract_name, ZH_WORDS_GETTER("expedet.field.query.ContractName"));
	//业主姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("expedet.field.query.PlateNumber"));
	//手机号
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("expedet.field.query.PhoneNumber"));
};

/**
 * 车辆费用明细查询对象
 */
class ExpedetCarFeeDetailQuery : public PageQuery
{
	DTO_INIT(ExpedetCarFeeDetailQuery, PageQuery);
	//起始时间
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("expedet.field.query.startTime"));
	//结束时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("expedet.field.query.endTime"));
	//车牌号
	API_DTO_FIELD_DEFAULT(String, car_num, ZH_WORDS_GETTER("expedet.field.query.PlateNumber"));
	//业主姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("expedet.field.query.ProprietorName"));
	//手机号
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("expedet.field.query.PhoneNumber"));
};
#include OATPP_CODEGEN_END(DTO)

#endif
