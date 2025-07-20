package com.zeroone.star.parkmanage.service.impl;

import com.zeroone.star.parkmanage.entity.MemberVehicle;
import com.zeroone.star.parkmanage.entity.OwnerCar;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.AddMemberVehicleDTO;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.MemberVehicleDTO;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.ModifyOwnerVehicleDTO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.Mappings;

/**
 * <p>
 * 会员车辆信息转换 Mapper
 * </p>
 *
 * @author yourName
 * @since 2025-06-04
 */
@Mapper(componentModel = "spring")
public interface MsMemberVehicleMapper {

    /**
     * 将实体转换为 DTO
     *
     * @param entity 实体
     * @return DTO
     */
    ModifyOwnerVehicleDTO toMemberVehicleDTO(MemberVehicle entity);

    /**
     * 将 DTO 转换为 实体
     *
     * @param dto DTO
     * @return 实体
     */

    MemberVehicle toMemberVehicle(ModifyOwnerVehicleDTO dto);
}
