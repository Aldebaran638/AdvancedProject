package com.zeroone.star.communitymanage.service.renovation.impl;

import com.zeroone.star.project.dto.j5.community.renovation.RenovationAddDTO;
import com.zeroone.star.project.dto.j5.community.renovation.RenovationDTO;
import com.zeroone.star.communitymanage.entity.renovation.RoomRenovation;
import org.mapstruct.Mapper;

/**
 * <p>
 * 描述：房屋装修(RoomRenovation)对应的MapStruct映射接口
 * </p>
 * @author 西班牙馅饼
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
public interface MsRenovationMapper {
    /**
     * 将实体类转换为DTO类
     * @param renovation 实体类
     * @return 转换结果
     */
    RenovationDTO renovationToDTO(RoomRenovation renovation);

    /**
     * 将AddDTO转换为实体类
     * @param renovationAddDTO AddDTO
     * @return 转换结果
     */
    RoomRenovation addDtoToRenovation(RenovationAddDTO renovationAddDTO);

    /**
     * 将DTO转换为实体类
     * @param renovationDTO DTO
     * @return 转换结果
     */
    RoomRenovation DtoToRenovation(RenovationDTO renovationDTO);
}
