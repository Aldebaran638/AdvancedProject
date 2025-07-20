package com.zeroone.star.parkmanage.service.impl;
import com.zeroone.star.parkmanage.entity.ParkingArea;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.GetParkingLotDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.InsertParkingLotDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.UpdateParkingLotDTO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.Mappings;

@Mapper(componentModel = "spring")
public interface MsParkingAreaMapper {

    /**
     * 将实体类转化为DTO
     * @param parkingArea
     * @return
     */
    @Mappings({
            @Mapping(source = "paId", target = "pa_id"),
            @Mapping(source = "num", target = "num"),
            @Mapping(source = "typeCd", target = "type"),
            @Mapping(source = "remark", target = "remark")
    })
    GetParkingLotDTO businessParkingAreaToGetParkingLotDTO(ParkingArea parkingArea);

    /**
     * 将DTO转化为实体
     * @param insertParkingLotDTO
     * @return
     */
    ParkingArea insertParkingLotDtoTOgetBusinessParkingArea(InsertParkingLotDTO insertParkingLotDTO);

    @Mappings({
            @Mapping(source = "pa_id", target = "paId"),
            @Mapping(source = "num", target = "num"),
            @Mapping(source = "type", target = "typeCd"),
            @Mapping(source = "remark", target = "remark")
    })
    ParkingArea updateParkingLotDtoTOBusinessParkingArea(UpdateParkingLotDTO updateParkingLotDTO);



}
