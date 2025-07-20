#pragma once
#ifndef _ANALYSISARREARS_QUERY_H_
#define _ANALYSISARREARS_QUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询对象
 */
class AnalysisArrearsQuery : public PageQuery
{
	DTO_INIT(AnalysisArrearsQuery, PageQuery);
	// 收费类型 feeType
	// 定义位于store_fee_type表中
	DTO_FIELD(String, feeType);
	DTO_FIELD_INFO(feeType) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.fee-type");
	}
	// 楼栋 buildingNum
	DTO_FIELD(String, buildingNum);
	DTO_FIELD_INFO(buildingNum) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.building-num");
	}
	// 小区id communityId
	DTO_FIELD(String, communityId);
	DTO_FIELD_INFO(communityId) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.community-id");
	}
};

/**
 * 简单查询对象
 * 用于查询收费类型和楼栋编号列表
 */
class AnalysisArrearsQuerySimple : public PageQuery
{
	DTO_INIT(AnalysisArrearsQuery, PageQuery);
	// 小区id communityId
	DTO_FIELD(String, communityId);
	DTO_FIELD_INFO(communityId) {
		info->description = ZH_WORDS_GETTER("analysis-arrears.field.community-id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ANALYSISARREARS_QUERY_H_