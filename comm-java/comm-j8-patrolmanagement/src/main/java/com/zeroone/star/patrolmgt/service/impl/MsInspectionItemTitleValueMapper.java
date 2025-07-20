package com.zeroone.star.patrolmgt.service.impl;


import com.zeroone.star.patrolmgt.entity.InspectionItemTitleValue;
import com.zeroone.star.project.j8.patrolmgt.item.dto.inspection.InspectionTitleAddDTO;
import com.zeroone.star.project.j8.patrolmgt.item.dto.inspection.InspectionTitleValueAddDTO;
import com.zeroone.star.project.j8.patrolmgt.item.dto.inspection.InspectionTitleValueDTO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;

@Mapper(componentModel = "spring")
public interface MsInspectionItemTitleValueMapper {
    InspectionTitleValueDTO inspectionTitleValueToDTO(InspectionItemTitleValue entity);


    @Mapping(target = "createTime", ignore = true)
    @Mapping(target = "statusCd", ignore = true)
    @Mapping(target = "itemValue", source = "itemValue")
    InspectionItemTitleValue dtoToDo(InspectionTitleValueDTO dto);

    @Mapping(target = "valueId", ignore = true)
    @Mapping(target = "createTime", ignore = true)
    @Mapping(target = "statusCd", ignore = true)
    InspectionItemTitleValue addDoTODo(InspectionTitleAddDTO dto);


    @Mapping(target = "valueId", ignore = true)
    @Mapping(target = "createTime", ignore = true)
    @Mapping(target = "statusCd", ignore = true)
    InspectionItemTitleValue addDoTODo(InspectionTitleValueAddDTO dto);


}
