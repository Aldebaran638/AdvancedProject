package com.zeroone.star.communitymanage.service.property.impl;

import com.zeroone.star.communitymanage.entity.property.*;
import com.zeroone.star.project.dto.j5.community.property.*;
import org.mapstruct.Mapper;

/**
 * <p>
 * 描述：对象转换
 * </p>
 *
 * @author Jungle&supoman
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
public interface MsPropertyMapper {

    /**
     * 将实体类转换为PropertyPageDTO
     * @param propertyRightRegistration 房屋产权列表实体类
     * @return 转换结果
     */
    PropertyPageDTO propertyRightRegistrationToDTO(PropertyRightRegistration propertyRightRegistration);



    /**
     * 将实体类转换为PropertyDetailDTO
     * @param propertyRightRegistrationDetail 房屋产权详情实体类
     * @return 转换结果
     */
    PropertyDetailDTO propertyRightRegistrationDetailToDTO(PropertyRightRegistrationDetail propertyRightRegistrationDetail);



    //addDtoToDo
    PropertyRightRegistration addPropertyDtoToPrr(AddPropertyDTO addPropertyDTO);

    PropertyRightRegistrationDetail addPropertyDtoToPrrd(AddPropertyDTO addPropertyDTO);

    BusinessPropertyRightRegistration addPropertyDtoToBprr(AddPropertyDTO addPropertyDTO);

    FileRel addPropertyDtoToFileRel(AddPropertyDTO addPropertyDTO);

    BusinessPropertyRightRegistrationDetail addPropertyDtoToBprrd(AddPropertyDTO dto);

    BuildingUnit addPropertyDtoToUnit(AddPropertyDTO addPropertyDTO);

    BuildingRoom addPropertyDtoToRoom(AddPropertyDTO addPropertyDTO);

    FFloor addPropertyDtoToFloor(AddPropertyDTO addPropertyDTO);

    //dtoToDo
    FileRel dtoToFileRel(PropertyDTO dto);
    FFloor dtoToFFloor(PropertyDTO dto);
    BuildingUnit dtoToBuildingUnit(PropertyDTO dto);
    BuildingRoom dtoToBuildingRoom(PropertyDTO dto);
    PropertyRightRegistration dtoToPrr(PropertyDTO dto);


    PropertyRightRegistrationDetail PrrddtoToDo(PropertyDetailDTO propertyDetailDTO);
}
