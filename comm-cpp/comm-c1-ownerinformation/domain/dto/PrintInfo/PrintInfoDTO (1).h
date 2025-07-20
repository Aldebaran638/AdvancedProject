#pragma once
#ifndef _PRINTINFO_DTO_
#define _PRINTINFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PrintInfoAddDTO : public oatpp::DTO
{
	DTO_INIT(PrintInfoAddDTO, DTO);

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * 打印预存收据传输对象
 */
class PrintInfoDTO : public oatpp::DTO
{
	DTO_INIT(PrintInfoDTO, oatpp::DTO);

	// 单号（主键）
	API_DTO_FIELD_DEFAULT(String, ar_id, ZH_WORDS_GETTER("PrintInfo.field.ar_id"));
	// 时间 
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("PrintInfo.field.create_time"));
	// 账户名称
	API_DTO_FIELD_DEFAULT(String, acct_name, ZH_WORDS_GETTER("PrintInfo.field.acct_name"));
	// 账户类型
	API_DTO_FIELD_DEFAULT(String, acct_type, ZH_WORDS_GETTER("PrintInfo.field.acct_type"));
	// 业主
	API_DTO_FIELD_DEFAULT(String, owner_name, ZH_WORDS_GETTER("PrintInfo.field.owner_name"));
	// 预存金额
	API_DTO_FIELD_DEFAULT(String, receivable_amount, ZH_WORDS_GETTER("PrintInfo.field.receivable"));
	// 预存方式
	API_DTO_FIELD_DEFAULT(String, prime_rate, ZH_WORDS_GETTER("PrintInfo.field.prime_rate"));
	// 当前余额
	API_DTO_FIELD_DEFAULT(String, received_amount, ZH_WORDS_GETTER("PrintInfo.field.received_amount"));
	// 备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("PrintInfo.field.remark"));
	// 总计
	API_DTO_FIELD_DEFAULT(String, amount, ZH_WORDS_GETTER("PrintInfo.field.amount"));
	// 开票人
	API_DTO_FIELD_DEFAULT(String, page_name, ZH_WORDS_GETTER("PrintInfo.field.page_name"));
	// 小区名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("PrintInfo.field.name"));
};

/**
 * 打印预存收据传输对象
 */
class PrintInfoPageDTO : public PageDTO<PrintInfoDTO::Wrapper>
{
	DTO_INIT(PrintInfoPageDTO, PageDTO<PrintInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif