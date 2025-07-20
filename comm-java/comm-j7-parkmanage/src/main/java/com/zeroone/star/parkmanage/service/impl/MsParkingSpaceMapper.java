package com.zeroone.star.parkmanage.service.impl;

import com.zeroone.star.parkmanage.entity.ParkingSpace;
import com.zeroone.star.project.dto.j7.parkmanage.parkinginfo.GetParkingSpaceDTO;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface MsParkingSpaceMapper {
    /**
     * 将ParkingSpace转换为GetParkingSpaceDTO
     * @param parkingSpace
     * @return
     */
    GetParkingSpaceDTO GetParkingSpaceToDTO(ParkingSpace parkingSpace);
}
