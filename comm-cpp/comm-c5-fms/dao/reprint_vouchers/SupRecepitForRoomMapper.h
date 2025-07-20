#pragma once
#ifndef SUP_RECEPIT_FOR_ROOM_MAPPER
#define SUP_RECEPIT_FOR_ROOM_MAPPER

#include"Mapper.h"
#include"../../domain/do/reprint_vouchers/SupRecepitForRoomDO.h"

class SupRecepitForRoomMapper : public Mapper<SupRecepitForRoomDO> {
public:
	SupRecepitForRoomDO mapper(ResultSet* resultset)const override {
		SupRecepitForRoomDO data;
		data.setFloor(resultset->getString(1));
		data.setUnit(resultset->getString(2));
		data.setRoom(resultset->getString(3));
		return data;
	}
};

class PtrSupRecepitForRoomMapper : public Mapper<PtrSupRecepitForRoomDO> {
public:
	PtrSupRecepitForRoomDO mapper(ResultSet* resultset)const override {
		PtrSupRecepitForRoomDO data;
		data->setFloor(resultset->getString(1));
		data->setUnit(resultset->getString(2));
		data->setRoom(resultset->getString(3));
		return data;
	}
};

#endif // !SUP_RECEPIT_FOR_ROOM_MAPPER
