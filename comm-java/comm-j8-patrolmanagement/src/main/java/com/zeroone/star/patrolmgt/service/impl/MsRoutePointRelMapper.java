package com.zeroone.star.patrolmgt.service.impl;


import com.zeroone.star.patrolmgt.entity.yuxixia_DO;
import com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel.AddRoutePointRelListDTO;
import com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel.RoutePointRelModifyImagesDTO;
import org.mapstruct.Mapper;

/**
 * <p>
 * 描述：Sample对应的MapStruct映射接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
public interface MsRoutePointRelMapper {
    // 将RoutePointRel对象转换为RoutePointRelModifyImagesDTO对象
    RoutePointRelModifyImagesDTO routePointRelModifyImagesDto(yuxixia_DO yuxixiaDO);
    // 将RoutePointRelModifyImagesDTO对象转换为RoutePointRel对象
    yuxixia_DO routePointRel(RoutePointRelModifyImagesDTO routePointRelModifyImagesDTO);

    yuxixia_DO routePointRel(AddRoutePointRelListDTO addRoutePointRelListDTO);
    AddRoutePointRelListDTO addRoutePointRelListDTO(yuxixia_DO yuxixiaDO);
}
