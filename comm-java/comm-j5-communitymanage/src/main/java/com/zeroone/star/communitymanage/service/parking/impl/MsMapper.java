package com.zeroone.star.communitymanage.service.parking.impl;

import com.zeroone.star.communitymanage.entity.building.BuildingUnit;
import com.zeroone.star.communitymanage.entity.building.BusinessFloor;
import com.zeroone.star.communitymanage.entity.parking.OwnerCar;
import com.zeroone.star.project.query.j5.community.parking.ParkingQuery;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface MsMapper {

    /**
     * 类型转换，将Parkingquery转换成buildingunit
     * @param query
     * @return
     */
    BuildingUnit toBuildingUnit(ParkingQuery query);

    /**
     * 类型转换，将parkingquery转换成businessfloor
     * @param unit
     * @return
     */
    BusinessFloor toBusinessFloor(BuildingUnit unit);

    OwnerCar toOwnerCar(ParkingQuery query);
}
