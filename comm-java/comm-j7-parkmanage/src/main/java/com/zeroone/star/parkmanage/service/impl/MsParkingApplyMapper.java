package com.zeroone.star.parkmanage.service.impl;

import com.zeroone.star.parkmanage.entity.ParkingApply;
import com.zeroone.star.parkmanage.entity.ParkingSpaceApply;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.AddApplyDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.ApplyDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.ReviewApplicationDTO;
import org.mapstruct.Mapper;


@Mapper(componentModel = "spring")
public interface MsParkingApplyMapper {
    /**
     * 将实体转换为DTO
     *
     * @param entity 实体
     * @return DTO
     */
    ApplyDTO toApplyDTO(ParkingApply entity);

    /**
     * 将DTO转换为实体
     *
     * @param dto DTO
     * @return 实体
     */
    ParkingApply toParkingApply(ApplyDTO dto);

    /**
     * 将Add DTO转换为实体类
     *
     * @param dto Add DTO
     * @return 转换结果
     */

    ParkingSpaceApply addDtoToDo(AddApplyDTO dto);

    /**
     * 将DTO转换为实体类
     *
     * @param dto DTO
     * @return 转换结果
     */

    ParkingSpaceApply dtoToDo(ApplyDTO dto);


    /**
     * 将DTO转换为实体类
     *
     * @param dto DTO
     * @return 转换结果
     */

    ParkingSpaceApply dtoToDo(ReviewApplicationDTO dto);

}
