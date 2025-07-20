package com.zeroone.star.parkmanage.service.impl;

import com.zeroone.star.parkmanage.entity.OwnerCar;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.AddCarDTO;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.CarDTO;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface MsOwnerVehicleMapper {
    /**
     * 将DTO转换为实体类
     * @param addCarDTO
     * @return
     */
    OwnerCar addCarDTOToDo(AddCarDTO addCarDTO);
}
