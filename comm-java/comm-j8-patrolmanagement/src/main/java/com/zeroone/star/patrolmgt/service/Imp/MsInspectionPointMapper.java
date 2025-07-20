package com.zeroone.star.patrolmgt.service.Imp;

import com.zeroone.star.patrolmgt.entity.zhangyvsen_InspectionPoint;
import com.zeroone.star.project.j8.patrolmgt.point.dto.RoutePointDTO;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface MsInspectionPointMapper
{
    RoutePointDTO toDTO(zhangyvsen_InspectionPoint entity);

}
