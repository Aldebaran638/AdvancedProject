#pragma once

#ifndef _ANALYSISARREARS_VO_H_
#define _ANALYSISARREARS_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/analysis_arrears/AnalysisArrearsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// 楼栋编号列表显示JsonVO，用于响应给客户端的Json对象
class AnalysisArrearsBuildingNumListJsonVO : public JsonVO<AnalysisArrearsBuildingNumListDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsBuildingNumListJsonVO, JsonVO<AnalysisArrearsBuildingNumListDTO::Wrapper>);
};

class AnalysisArrearsBuildingNumJsonVO : public JsonVO<AnalysisArrearsBuildingNumDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsBuildingNumJsonVO, JsonVO<AnalysisArrearsBuildingNumDTO::Wrapper>);
};

// 收费类型列表显示JsonVO，用于响应给客户端的Json对象
class AnalysisArrearsFeeTypeListJsonVO : public JsonVO<AnalysisArrearsFeeTypeListDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsFeeTypeListJsonVO, JsonVO<AnalysisArrearsFeeTypeListDTO::Wrapper>);
};

class AnalysisArrearsFeeTypeJsonVO : public JsonVO<AnalysisArrearsFeeTypeDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsFeeTypeJsonVO, JsonVO<AnalysisArrearsFeeTypeDTO::Wrapper>);
};

/**
 * 欠费分析未收情况表
 */

// 欠费分析未收情况表显示JsonVO，用于响应给客户端的Json对象
class AnalysisArrearsBasicJsonVO : public JsonVO<AnalysisArrearsBasicDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsBasicJsonVO, JsonVO<AnalysisArrearsBasicDTO::Wrapper>);
};

// 欠费分析未收情况表分页显示JsonVO，用于响应给客户端的Json对象
class AnalysisArrearsBasicPageJsonVO : public JsonVO<AnalysisArrearsBasicListPageDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsBasicPageJsonVO, JsonVO<AnalysisArrearsBasicListPageDTO::Wrapper>);
};

/**
 * 欠费分析未收明细表
 */

 // 欠费分析未收明细表显示JsonVO，用于响应给客户端的Json对象
class AnalysisArrearsDetailJsonVO : public JsonVO<AnalysisArrearsDetailDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsDetailJsonVO, JsonVO<AnalysisArrearsDetailDTO::Wrapper>);
};

// 欠费分析未收明细表分页显示JsonVO，用于响应给客户端的Json对象
class AnalysisArrearsDetailPageJsonVO : public JsonVO<AnalysisArrearsDetailListPageDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsDetailPageJsonVO, JsonVO<AnalysisArrearsDetailListPageDTO::Wrapper>);
};

/**
 * 欠费分析当月收费情况表
 */

 // 欠费分析当月收费情况表显示JsonVO，用于响应给客户端的Json对象
class AnalysisArrearsMonthJsonVO : public JsonVO<AnalysisArrearsMonthDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsMonthJsonVO, JsonVO<AnalysisArrearsMonthDTO::Wrapper>);
};

// 欠费分析当月收费情况表分页显示JsonVO，用于响应给客户端的Json对象
class AnalysisArrearsMonthPageJsonVO : public JsonVO<AnalysisArrearsMonthListPageDTO::Wrapper> {
	DTO_INIT(AnalysisArrearsMonthPageJsonVO, JsonVO<AnalysisArrearsMonthListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ANALYSISARREARS_VO_H_
