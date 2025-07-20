package com.zeroone.star.parkmanage.service.impl;

import com.zeroone.star.parkmanage.entity.OwnerCar;
import com.zeroone.star.parkmanage.entity.OwnerCar1;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.AddMemberVehicleDTO;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.MemberVehicleDTO;
import org.mapstruct.Mapper;

/**
 * @Author：daimon
 * @Date：2025/5/31
 * @discription:
 */
@Mapper(componentModel = "spring")
public interface MsOwnerCarMapper {
    OwnerCar1 addDtoToOwnerCar1(AddMemberVehicleDTO addMemberVehicleDTO);
}
