/*
 Copyright Zero One Star. All rights reserved.

 @Author: KBchulan
 @Date: 2025/5/20

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef DATASTATVO_H
#define DATASTATVO_H

#include <domain/GlobalInclude.h>
#include <domain/dto/datastat/DataStatDTO.h>

#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * 费用统计显示对象JsonVO
 */
class ExpenseStatJsonVO : public JsonVO<ExpenseStatDTO::Wrapper> {
	DTO_INIT(ExpenseStatJsonVO, JsonVO<ExpenseStatDTO::Wrapper>);
};

/*
 * 费用统计显示对象JsonVO(分页版本)
 */
class ExpenseStatPageJsonVO : public JsonVO<ExpenseStatPageDTO::Wrapper> {
	DTO_INIT(ExpenseStatPageJsonVO, JsonVO<ExpenseStatPageDTO::Wrapper>);
};

/*
 * 工单统计显示对象JsonVO
 */
class WorkOrderStatJsonVO : public JsonVO<WorkOrderStatDTO::Wrapper> {
	DTO_INIT(WorkOrderStatJsonVO, JsonVO<WorkOrderStatDTO::Wrapper>);
};

/*
 * 工单统计显示对象JsonVO(分页版本)
 */
class WorkOrderStatPageJsonVO : public JsonVO<WorkOrderStatPageDTO::Wrapper> {
	DTO_INIT(WorkOrderStatPageJsonVO, JsonVO<WorkOrderStatPageDTO::Wrapper>);
};

/*
 * 出入统计显示对象JsonVO
 */
class AccessStatJsonVO : public JsonVO<AccessStatDTO::Wrapper> {
	DTO_INIT(AccessStatJsonVO, JsonVO<AccessStatDTO::Wrapper>);
};

/*
 * 出入统计显示对象JsonVO(分页版本)
 */
class AccessStatPageJsonVO : public JsonVO<AccessStatPageDTO::Wrapper> {
	DTO_INIT(AccessStatPageJsonVO, JsonVO<AccessStatPageDTO::Wrapper>);
};

/*
 * 其他统计显示对象JsonVO
 */
class OtherStatJsonVO : public JsonVO<OtherStatDTO::Wrapper> {
	DTO_INIT(OtherStatJsonVO, JsonVO<OtherStatDTO::Wrapper>);
};

/*
 * 其他统计显示对象JsonVO(分页版本)
 */
class OtherStatPageJsonVO : public JsonVO<OtherStatPageDTO::Wrapper> {
	DTO_INIT(OtherStatPageJsonVO, JsonVO<OtherStatPageDTO::Wrapper>);
};


// 费用统计 VO
class DataStatCostVO : public JsonVO<DataStatCostDTO::Wrapper> {
	DTO_INIT(DataStatCostVO, JsonVO<DataStatCostDTO::Wrapper>)
};

// 实收统计 VO
class DataStatFinalCostVO : public JsonVO<DataStatFinalCostDTO::Wrapper> {
	DTO_INIT(DataStatFinalCostVO, JsonVO<DataStatFinalCostDTO::Wrapper>)
};
//分页版
class DataStatShishouPageVO : public JsonVO<DataStatShishouPageDTO::Wrapper> {
	DTO_INIT(DataStatShishouPageVO, JsonVO<DataStatShishouPageDTO::Wrapper>)
};

// 实收明细统计 VO
class DataStatDetailCostVO : public JsonVO<DataStatDetailCostDTO::Wrapper> {
	DTO_INIT(DataStatDetailCostVO, JsonVO<DataStatDetailCostDTO::Wrapper>)
};

//分页版
class DataStatShishouDetailPageVO : public JsonVO<DataStatShishouDetailPageDTO::Wrapper> {
	DTO_INIT(DataStatShishouDetailPageVO, JsonVO<DataStatShishouDetailPageDTO::Wrapper>)
};

// 支付方式 VO
class DataStatMethodVO : public JsonVO<DataStatMethodDTO::Wrapper> {
	DTO_INIT(DataStatMethodVO, JsonVO<DataStatMethodDTO::Wrapper>)
};
//分页
class DataStatMethodPageVO : public JsonVO<DataStatMethodPageDTO::Wrapper> {
	DTO_INIT(DataStatMethodPageVO, JsonVO<DataStatMethodPageDTO::Wrapper>)
};

// 欠费统计 VO
class DataStatQianfeiVO : public JsonVO<DataStatQianfeiDTO::Wrapper> {
	DTO_INIT(DataStatQianfeiVO, JsonVO<DataStatQianfeiDTO::Wrapper>)
};
//分页版
class DataStatQianfeiPageVO : public JsonVO<DataStatQianfeiPageDTO::Wrapper> {
	DTO_INIT(DataStatQianfeiPageVO, JsonVO<DataStatQianfeiPageDTO::Wrapper>)
};

// 宏观查询
class DataStatALLSearchVO : public JsonVO<DataStatALLSearchQuery::Wrapper> {
	DTO_INIT(DataStatALLSearchVO, JsonVO<DataStatALLSearchQuery::Wrapper>)
};

//明细查询
class DataStatDetailSearchVO : public JsonVO<DataStatDetailSearchQuery::Wrapper> {
	DTO_INIT(DataStatDetailSearchVO, JsonVO<DataStatDetailSearchQuery::Wrapper>)
};

/*              数据统计-3            */
/**
 * 欠费明细VO对象
 */
class DataStatFeeDetailJsonVO : public JsonVO<DatastatFeeDetailDTO::Wrapper>
{
	DTO_INIT(DataStatFeeDetailJsonVO, JsonVO<DatastatFeeDetailDTO::Wrapper>);
};

/**
 * 欠费明细分页显示JsonVO对象，用于响应给客户端
 */
class DataStatFeeDetailPageJsonVO : public JsonVO<DatastatFeeDetailPageDTO::Wrapper>
{
	DTO_INIT(DataStatFeeDetailPageJsonVO, JsonVO<DatastatFeeDetailPageDTO::Wrapper>);
};

/**
 * 收缴情况VO对象
 */
class DatastatChargeDetailJsonVO : public JsonVO<DatastatChargeDetailDTO::Wrapper>
{
	DTO_INIT(DatastatChargeDetailJsonVO, JsonVO<DatastatChargeDetailDTO::Wrapper>);
};


/**
 * 收缴情况分页显示JsonVO对象，用于响应给客户端
 */
class DatastatChargeDetailPageJsonVO : public JsonVO<DatastatChargeDetailPageDTO::Wrapper>
{
	DTO_INIT(DatastatChargeDetailPageJsonVO, JsonVO<DatastatChargeDetailPageDTO::Wrapper>);
};

/**
 * 月实收明细VO对象
 */
class DatastatMonthDetailJsonVO : public JsonVO<DatastatMonthDetailDTO::Wrapper>
{
	DTO_INIT(DatastatMonthDetailJsonVO, JsonVO<DatastatMonthDetailDTO::Wrapper>);
};

/**
 * 月实收明细分页显示JsonVO对象，用于响应给客户端
 */
class DatastatMonthDetailPageJsonVO : public JsonVO<DatastatMonthDetailPageDTO::Wrapper>
{
	DTO_INIT(DatastatMonthDetailPageJsonVO, JsonVO<DatastatMonthDetailPageDTO::Wrapper>);
};

/**
 * 月欠费明细VO对象
 */
class DatastatMonthFeeJsonVO : public JsonVO<DatastatMonthFeeDTO::Wrapper>
{
	DTO_INIT(DatastatMonthFeeJsonVO, JsonVO<DatastatMonthFeeDTO::Wrapper>);
};

/**
 * 月欠费明细分页显示JsonVO对象，用于响应给客户端
 */
class DatastatMonthFeePageJsonVO : public JsonVO<DatastatMonthFeePageDTO::Wrapper>
{
	DTO_INIT(DatastatMonthFeePageJsonVO, JsonVO<DatastatMonthFeePageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !DATASTATVO_H
