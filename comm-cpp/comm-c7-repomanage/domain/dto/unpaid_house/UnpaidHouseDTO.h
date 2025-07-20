#pragma once

#ifndef _UNPAIDHOUSEDTO_
#define _UNPAIDHOUSEDTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 下拉条件选项：楼栋、单元、房屋（房号）
 * floor.queryFloors
 * unit.queryUnits
 * room.queryRooms
 * 填写条件：业主、业主电话
 */

/**
 * 未收费房屋，条件
 */
class UnpaidHouseDTO : public oatpp::DTO
{
	DTO_INIT(UnpaidHouseDTO, DTO);

	// 带默认值版
	// API_DTO_FIELD(_TYPE_, _NAME_, _DESCRIPTION_, _REQUIRE_, _DEFAULT_);
	API_DTO_FIELD(String, roomId, ZH_WORDS_GETTER("unpaid-house.field.room-id"), true, "752025051406311175");
	API_DTO_FIELD(String, floorNum, ZH_WORDS_GETTER("unpaid-house.field.floor-num"), true, "Building1");
	API_DTO_FIELD(String, unitNum, ZH_WORDS_GETTER("unpaid-house.field.unit-num"), true, "Unit1");
	API_DTO_FIELD(String, roomNum, ZH_WORDS_GETTER("unpaid-house.field.room-num"), true, "Room101");
	API_DTO_FIELD(String, ownerId, ZH_WORDS_GETTER("unpaid-house.field.owner-id"), false, "772025050800790085");
	API_DTO_FIELD(String, ownerName, ZH_WORDS_GETTER("unpaid-house.field.owner-name"), false, "Li Hua");
	API_DTO_FIELD(String, link, ZH_WORDS_GETTER("unpaid-house.field.link"), false, "13111111111");
	
	//// 房屋ID
	//API_DTO_FIELD_DEFAULT(String, roomId, ZH_WORDS_GETTER("unpaid-house.field.room-id"));
	//// 楼栋编号
	//API_DTO_FIELD_DEFAULT(String, floorNum, ZH_WORDS_GETTER("unpaid-house.field.floor-num"));
	//// 单元编号
	//API_DTO_FIELD_DEFAULT(String, unitNum, ZH_WORDS_GETTER("unpaid-house.field.unit-num"));
	//// 房屋编号
	//API_DTO_FIELD_DEFAULT(String, roomNum, ZH_WORDS_GETTER("unpaid-house.field.room-num"));
	//// 业主ID 
	//API_DTO_FIELD_DEFAULT(String, ownerId, ZH_WORDS_GETTER("unpaid-house.field.owner-id"));
	//// 业主姓名
	//API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("unpaid-house.field.owner-name"));
	//// 联系电话（业主手机号）
	//API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("unpaid-house.field.link"));
	//// 没找到对应的数据库字段
	////API_DTO_FIELD_DEFAULT(Int32, records, ZH_WORDS_GETTER("unpaid-house.field.records"));
	//// 数据状态（0正常 1失效）
	////API_DTO_FIELD_DEFAULT(String, statusCd, ZH_WORDS_GETTER("unpaid-house.field.status-cd"));
	
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * 未收费房屋，分页
 */
class UnpaidHousePageDTO : public PageDTO<UnpaidHouseDTO::Wrapper>
{
	DTO_INIT(UnpaidHousePageDTO, PageDTO<UnpaidHouseDTO::Wrapper>);
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

// 查询条件
class FloorDTO : public oatpp::DTO
{
	// 初始化定义
	DTO_INIT(FloorDTO, DTO);
	API_DTO_FIELD(String, floorId, ZH_WORDS_GETTER("unpaid-house.field.floor-id"), true, "732025052809640133");
	API_DTO_FIELD(String, floorNum, ZH_WORDS_GETTER("unpaid-house.field.floor-num"), true, "Building1");
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

class UnitDTO : public oatpp::DTO
{
	// 初始化定义
	DTO_INIT(UnitDTO, DTO);
	API_DTO_FIELD(String, unitId, ZH_WORDS_GETTER("unpaid-house.field.unit-id"), true, "742025052876120134");
	API_DTO_FIELD(String, unitNum, ZH_WORDS_GETTER("unpaid-house.field.unit-num"), true, "Unit1");
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

class RoomDTO : public oatpp::DTO
{
	// 初始化定义
	DTO_INIT(RoomDTO, DTO);
	API_DTO_FIELD(String, roomId, ZH_WORDS_GETTER("unpaid-house.field.room-id"), true, "752025052884790135");
	API_DTO_FIELD(String, roomNum, ZH_WORDS_GETTER("unpaid-house.field.room-num"), true, "Room101");
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_UNPAIDHOUSEDTO_