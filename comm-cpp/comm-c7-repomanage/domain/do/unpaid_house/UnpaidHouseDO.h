#pragma once

#ifndef _UNPAIDHOUSEDO_
#define _UNPAIDHOUSEDO_

class UnpaidHouseDO
{
	CC_SYNTHESIZE(string, roomId, RoomId);          // 房屋ID
	CC_SYNTHESIZE(string, floorNum, FloorNum);      // 楼栋编号
	CC_SYNTHESIZE(string, unitNum, UnitNum);        // 单元编号
	CC_SYNTHESIZE(string, roomNum, RoomNum);        // 房间编号
	CC_SYNTHESIZE(string, ownerId, OwnerId);        // 业主ID
	CC_SYNTHESIZE(string, ownerName, OwnerName);    // 业主姓名
	CC_SYNTHESIZE(string, link, Link);              // 联系电话
public:
	UnpaidHouseDO() : roomId(""), floorNum(""), unitNum(""), roomNum(""), ownerId(""), ownerName(""), link("") {

	}
};

class FloorDO
{
	CC_SYNTHESIZE(string, floorId, FloorId);          // 楼栋ID
	CC_SYNTHESIZE(string, floorNum, FloorNum);      // 楼栋编号
public:
	FloorDO() : floorId(""), floorNum(""){

	}
};

class UnitDO
{
	CC_SYNTHESIZE(string, unitId, UnitId);         
	CC_SYNTHESIZE(string, unitNum, UnitNum);      
public:
	UnitDO() : unitId(""), unitNum("") {

	}
};

class RoomDO
{
	CC_SYNTHESIZE(string, roomId, RoomId);         
	CC_SYNTHESIZE(string, roomNum, RoomNum);     
public:
	RoomDO() : roomId(""), roomNum("") {

	}
};

#endif // !_UNPAIDHOUSEDO_