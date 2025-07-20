package com.zeroone.star.parkmanage.mapper;

import com.zeroone.star.parkmanage.entity.BusinessOwnerCar;
import com.zeroone.star.parkmanage.entity.OwnerCar;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.factory.Mappers;

@Mapper
public interface BusinessOwnerCarStruct {
    BusinessOwnerCarStruct INSTANCE = Mappers.getMapper(BusinessOwnerCarStruct.class);

    @Mapping(target = "operate", source = "operate")
    BusinessOwnerCar toBusinessOwnerCar(OwnerCar car, String operate);
} 