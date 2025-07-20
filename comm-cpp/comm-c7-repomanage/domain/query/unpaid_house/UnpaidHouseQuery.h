#pragma once

#ifndef _UNPAIDHOUSEQUERY_
#define _UNPAIDHOUSEQUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class UnpaidHouseQuery : public PageQuery
{
	DTO_INIT(UnpaidHouseQuery, PageQuery);
	// 楼栋ID
	API_DTO_FIELD_DEFAULT(String, floorId, ZH_WORDS_GETTER("unpaid-house.field.floor-id"));
	// 楼栋编号
	API_DTO_FIELD_DEFAULT(String, floorNum, ZH_WORDS_GETTER("unpaid-house.field.floor-num"));
	// 单元ID
	API_DTO_FIELD_DEFAULT(String, unitId, ZH_WORDS_GETTER("unpaid-house.field.unit-id"));
	// 单元编号
	API_DTO_FIELD_DEFAULT(String, unitNum, ZH_WORDS_GETTER("unpaid-house.field.unit-num"));
	// 房屋ID
	API_DTO_FIELD_DEFAULT(String, roomId, ZH_WORDS_GETTER("unpaid-house.field.room-id"));
	// 房屋编号
	API_DTO_FIELD_DEFAULT(String, roomNum, ZH_WORDS_GETTER("unpaid-house.field.room-num"));
	// 业主名称
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("unpaid-house.field.owner-name"));
	// 联系电话
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("unpaid-house.field.link"));
	// 小区ID
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("unpaid-house.field.community-id"));
	// 定位标签页？：pagePath，reportNoFeeRoom
	//API_DTO_FIELD_DEFAULT(String, pagePath, ZH_WORDS_GETTER("unpaid-house.field.page-path"));

};

// 查询条件
class FloorQuery : public oatpp::DTO
{
	// 初始化定义
	DTO_INIT(FloorQuery, DTO);
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("unpaid-house.field.community-id"));

};

class UnitQuery : public oatpp::DTO
{
	// 初始化定义
	DTO_INIT(UnitQuery, DTO);
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("unpaid-house.field.community-id"));
	API_DTO_FIELD_DEFAULT(String, floorId, ZH_WORDS_GETTER("unpaid-house.field.floor-id"));

};

class RoomQuery : public oatpp::DTO
{
	// 初始化定义
	DTO_INIT(RoomQuery, DTO);
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("unpaid-house.field.community-id"));
	API_DTO_FIELD_DEFAULT(String, unitId, ZH_WORDS_GETTER("unpaid-house.field.unit-id"));

};
#include OATPP_CODEGEN_END(DTO)

#endif // !_UNPAIDHOUSEQUERY_
