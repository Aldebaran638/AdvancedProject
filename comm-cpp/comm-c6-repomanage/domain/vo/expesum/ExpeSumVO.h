#pragma once
#ifndef _FEERATEVO_H_
#define _FEERATEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/expesum/ExpeSumDTO.h"// 楼栋收费率DTO
#include OATPP_CODEGEN_BEGIN(DTO)

//--------------- 楼栋收费率响应对象 ---------------
/**
 * 楼栋收费率单条数据响应体
 * 包含状态码、消息和单条楼栋收费数据
 */
class BuildingRateJsonVO : public JsonVO<BuildingRateDTO::Wrapper> {
    DTO_INIT(BuildingRateJsonVO, JsonVO<BuildingRateDTO::Wrapper>);
};

/**
 * 楼栋收费率分页响应体
 * 包含分页元数据及楼栋收费数据集
 */
class BuildingRatePageJsonVO : public JsonVO<BuildingRatePageDTO::Wrapper> {
    DTO_INIT(BuildingRatePageJsonVO, JsonVO<BuildingRatePageDTO::Wrapper>);
};

//--------------- 费用项收费率响应对象 ---------------
/**
 * 费用项收费率单条数据响应体
 * 包含状态码、消息和单条费用项分析数据
 */
class FeeItemRateJsonVO : public JsonVO<FeeItemRateDTO::Wrapper> {
    DTO_INIT(FeeItemRateJsonVO, JsonVO<FeeItemRateDTO::Wrapper>);
};

/**
 * 费用项收费率分页响应体
 * 支持多维度收费分析结果分页展示
 */
class FeeItemRatePageJsonVO : public JsonVO<FeeItemRatePageDTO::Wrapper> {
    DTO_INIT(FeeItemRatePageJsonVO, JsonVO<FeeItemRatePageDTO::Wrapper>);
};




////////////////
/**
* 费用汇总显示 JsonVO，用于响应给客户端的单个记录对象
*/
class ExpeSumJsonVO : public JsonVO<ExpeSumDTO::Wrapper>
{
    DTO_INIT(ExpeSumJsonVO, JsonVO<ExpeSumDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FEERATEVO_H_