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
#ifndef _TELL_REPAIR_DTO_
#define _TELL_REPAIR_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 电话报修新增数据传输对象
 */
class TellRepairAddDTO : public oatpp::DTO
{
	DTO_INIT(TellRepairAddDTO, DTO);

	// 小区id
	API_DTO_FIELD(String, community_id, ZH_WORDS_GETTER("tell-repair.field.community_id"), true, "2024022647620054");
	// 报修范围
	API_DTO_FIELD(String, repair_obj_type, ZH_WORDS_GETTER("tell-repair.field.repair_obj_type"), true, "001");
	// 报修对象名称
	API_DTO_FIELD(String, repair_obj_name, ZH_WORDS_GETTER("tell-repair.field.repair_obj_name"), true, "对象名称示例");
	// 报修类型
	API_DTO_FIELD(String, repair_type, ZH_WORDS_GETTER("tell-repair.field.repair_type"), true, "102023053136440010");
	// 报修人
	API_DTO_FIELD(String, repair_name, ZH_WORDS_GETTER("tell-repair.field.repair_name"), true ,"张三");
	// 联系方式
	API_DTO_FIELD(String, tel, ZH_WORDS_GETTER("tell-repair.field.tel"), true, "13111011002");
	// 预约时间
	API_DTO_FIELD(String, appointment_time, ZH_WORDS_GETTER("tell-repair.field.appointment_time"), true, "2023-10-01 10:00:00");
	// 报修内容
	API_DTO_FIELD(String, context, ZH_WORDS_GETTER("tell-repair.field.context"), true, "报修内容示例");

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * 电话报修查询传输对象
 */
class TellRepairDTO : public TellRepairAddDTO
{
	DTO_INIT(TellRepairDTO, TellRepairAddDTO);
	// 编号
	DTO_FIELD(String, repair_id);
	DTO_FIELD_INFO(repair_id)
	{
		info->description = ZH_WORDS_GETTER("tell-repair.field.repair_id");
	}
	// 小区id √
	// 报修对象名称 √
	// 报修类型 √
	// 报修类型文本
	DTO_FIELD(String, repair_type_txt);
	DTO_FIELD_INFO(repair_type_txt)
	{
		info->description = ZH_WORDS_GETTER("tell-repair.field.repair_type_txt");
	}
	// 报修人 √
	// 联系方式 √
	// 预约时间 √
	// 超时时间
	DTO_FIELD(String, timeout_time);
	DTO_FIELD_INFO(timeout_time)
	{
		info->description = ZH_WORDS_GETTER("tell-repair.field.timeout_time");
	}
	// 提交时间.数据库新增数据时自动设置默认值
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time)
	{
		info->description = ZH_WORDS_GETTER("tell-repair.field.create_time");
	}
	// 工单状态
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state)
	{
		info->description = ZH_WORDS_GETTER("tell-repair.field.state");
	}
	//工单状态文本
	DTO_FIELD(String, state_txt);
	DTO_FIELD_INFO(state_txt)
	{
		info->description = ZH_WORDS_GETTER("tell-repair.field.state_txt");
	}
};

/**
 * 电话报修修改数据传输对象
 */
class TellRepairUpdateDTO : public oatpp::DTO
{
	DTO_INIT(TellRepairUpdateDTO, DTO);

	// 报修类型
	API_DTO_FIELD(String, repair_type, ZH_WORDS_GETTER("tell-repair.field.repair_type"), true, "102023053136440010");
	// 报修人
	API_DTO_FIELD(String, repair_name, ZH_WORDS_GETTER("tell-repair.field.repair_name"), true, "张三");
	// 联系方式
	API_DTO_FIELD(String, tel, ZH_WORDS_GETTER("tell-repair.field.tel"), true, "13111011002");
	// 预约时间
	API_DTO_FIELD(String, appointment_time, ZH_WORDS_GETTER("tell-repair.field.appointment_time"), true, "2023-10-01 10:00:00");
	// 报修内容
	API_DTO_FIELD(String, context, ZH_WORDS_GETTER("tell-repair.field.context"), true, "报修内容示例");
	// 编号
	API_DTO_FIELD(String, repair_id, ZH_WORDS_GETTER("tell-repair.field.repair_id"), true, "822023080257540003");

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};


/**
 * 分页传输对象
 */
class TellRepairPageDTO : public PageDTO<TellRepairDTO::Wrapper>
{
	DTO_INIT(TellRepairPageDTO, PageDTO<TellRepairDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TELL_REPAIR_DTO_