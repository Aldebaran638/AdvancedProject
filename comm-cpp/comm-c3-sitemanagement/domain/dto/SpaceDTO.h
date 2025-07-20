#pragma once

#ifndef _SPACEDTO_H_
#define _SPACEDTO_H_
#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// 添加场地的数据传输对象
class SpaceAddDTO : public oatpp::DTO
{
	DTO_INIT(SpaceAddDTO, DTO);

	// 名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("space.field.name"));
	// 每小时费用
	API_DTO_FIELD_DEFAULT(Float64, feeMoney, ZH_WORDS_GETTER("space.field.feeMoney"));
	// 管理员
	API_DTO_FIELD_DEFAULT(String, adminName, ZH_WORDS_GETTER("space.field.adminName"));
	// 管理员电话
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("space.field.adminTel"));
	// 状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("space.field.statusCd"));

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

// 修改场地的数据传输对象
class SpaceUpdateDTO : public SpaceAddDTO
{
	DTO_INIT(SpaceUpdateDTO, SpaceAddDTO);
	// 场地id
	API_DTO_FIELD_DEFAULT(String, spaceId, ZH_WORDS_GETTER("space.field.spaceId"));
};

// 完整的场地信息
class SpaceDTO : public SpaceUpdateDTO
{
	DTO_INIT(SpaceDTO, SpaceUpdateDTO);

	// 预约开始时间
	API_DTO_FIELD_DEFAULT(String, startTime, ZH_WORDS_GETTER("space.field.startTime"));
	// 预约结束时间
	API_DTO_FIELD_DEFAULT(String, endTime, ZH_WORDS_GETTER("space.field.endTime"));
	// 小区ID
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("space.field.communtiyId"));
	// 创建时间
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("space.field.createTime"));
	// 数据状态
	API_DTO_FIELD_DEFAULT(String, statusCd, ZH_WORDS_GETTER("space.field.statusCd"));
	// 场馆ID
	API_DTO_FIELD_DEFAULT(String, venueId, ZH_WORDS_GETTER("space.field.venueId"));
};

// 分页传输对象
class SpacePageDTO : public PageDTO<SpaceDTO::Wrapper>
{
	DTO_INIT(SpacePageDTO, PageDTO<SpaceDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif