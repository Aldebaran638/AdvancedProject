package com.zeroone.star.patrolmgt.service.Imp;

import com.zeroone.star.patrolmgt.entity.zhangyvsen_InspectionRoute;
import com.zeroone.star.project.j8.patrolmgt.route.dto.zhangyvsen_RouteDTO;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface MsInspectionRouteMapper {
    /**
     *
     */

    zhangyvsen_RouteDTO toDTO(zhangyvsen_InspectionRoute entity);

}
