#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _EXPEREM_DTO_
#define _EXPEREM_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例新增数据传输对象
 */
//class ExpeRemAddDTO : public oatpp::DTO
//{
//	DTO_INIT(ExpeRemAddDTO, DTO);
//	// 费用编号
//	API_DTO_FIELD_DEFAULT(Int32, seq, ZH_WORDS_GETTER("experem.field.seq"));
//	// 房号/车辆/合同
//	API_DTO_FIELD_DEFAULT(String, assets, ZH_WORDS_GETTER("experem.field.assets"));
//	// 费用项
//	API_DTO_FIELD_DEFAULT(String, item, ZH_WORDS_GETTER("experem.field.item"));
//	// 费用开始时间
//	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("experem.field.createTime"));
//	// 距离费用开始时间（天）
//	API_DTO_FIELD_DEFAULT(Int32, daysToStart, ZH_WORDS_GETTER("experem.field.daysToStart"));
//	
//};

/**
 * 示例传输对象
 */
class ExpeRemDTO : public oatpp::DTO
{
	DTO_INIT(ExpeRemDTO, DTO);
	// 费用编号  1
	API_DTO_FIELD_DEFAULT(String, feeId, ZH_WORDS_GETTER("experem.field.seq"));
	// 房号/车辆/合同
	API_DTO_FIELD_DEFAULT(String, payerObjType, ZH_WORDS_GETTER("experem.field.assets"));
	// 费用项
	API_DTO_FIELD_DEFAULT(String, feeName, ZH_WORDS_GETTER("experem.field.item"));
	// 费用开始时间
	API_DTO_FIELD_DEFAULT(String, startTime, ZH_WORDS_GETTER("experem.field.createTime"));
	// 距离费用开始时间（天）
	API_DTO_FIELD_DEFAULT(Int32, endTime, ZH_WORDS_GETTER("experem.field.daysToStart"));
};

/**
 * 示例分页传输对象
 */
class ExpeRemPageDTO : public PageDTO<ExpeRemDTO::Wrapper>
{
	DTO_INIT(ExpeRemPageDTO, PageDTO<ExpeRemDTO::Wrapper>);
};

/**
 * 示例传输对象
 */
class overExpeRemDTO : public oatpp::DTO
{
	DTO_INIT(overExpeRemDTO, DTO);

	DTO_FIELD(String, Feeid);
	DTO_FIELD_INFO(Feeid) {
		info->description = ZH_WORDS_GETTER("experem.field.Feeid");
	}

	DTO_FIELD(String, BuildingNo);
	DTO_FIELD_INFO(BuildingNo) {
		info->description = ZH_WORDS_GETTER("experem.field.BuildingNo");
	}

	DTO_FIELD(String, Expenses);
	DTO_FIELD_INFO(Expenses) {
		info->description = ZH_WORDS_GETTER("experem.field.Expenses");
	}

	DTO_FIELD(String, EndTime);
	DTO_FIELD_INFO(EndTime) {
		info->description = ZH_WORDS_GETTER("experem.field.EndTime");
	}

	DTO_FIELD(String, RemainingTime);
	DTO_FIELD_INFO(RemainingTime) {
		info->description = ZH_WORDS_GETTER("experem.field.RemainingTime");
	}

	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * 示例分页传输对象
 */
class overExpeRemPageDTO : public PageDTO<overExpeRemDTO::Wrapper>
{
	DTO_INIT(overExpeRemPageDTO, PageDTO<overExpeRemDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_