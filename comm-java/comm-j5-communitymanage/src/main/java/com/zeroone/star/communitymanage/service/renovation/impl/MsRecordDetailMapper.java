package com.zeroone.star.communitymanage.service.renovation.impl;

import com.zeroone.star.project.dto.j5.community.renovation.AddRenovationRecordDTO;
import com.zeroone.star.project.dto.j5.community.renovation.RenovationRecordDTO;
import com.zeroone.star.communitymanage.entity.renovation.RoomRenovationDetail;
import com.zeroone.star.communitymanage.entity.renovation.RoomRenovationRecord;
import org.mapstruct.Mapper;

/**
 * <p>
 * RenovationRecord对应的MapStruct映射接口
 * </p>
 *
 * @author cheng
 * @since 2023-04-27
 */
@Mapper(componentModel = "spring")
public interface MsRecordDetailMapper {
    /**
     * 将实体类转换为DTO
     *
     * @param entity 实体类
     * @return DTO
     */
    RenovationRecordDTO  doToDTO(RoomRenovationRecord entity);
    /**
     * 将add DTO转换为实体类
     *
     * @param dto DTO
     * @return 实体类
     */
    RoomRenovationRecord addDtoToDo(AddRenovationRecordDTO dto);

    /**
     * 将DTO转换为实体类
     *
     * @param dto DTO
     * @return 实体类
     */
    RoomRenovationRecord dtoToDo(RenovationRecordDTO dto);

    /**
     * 将装修实体类转换为DTO
     *
     * @param entity 详情实体类
     * @return DTO
     */
    RenovationRecordDTO detailDoToDTO(RoomRenovationDetail entity);
    /**
     * 将add DTO转换为实体类
     *
     * @param dto DTO
     * @return 实体类
     */
    RoomRenovationDetail addDtoToDetailDo(AddRenovationRecordDTO dto);
}
