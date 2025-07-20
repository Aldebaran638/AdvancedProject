package com.zeroone.star.patrolmgt.mapper;

import com.zeroone.star.patrolmgt.entity.yuxixia_DO;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel.AddRoutePointRelListDTO;
import com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel.RemoveRoutePointDTO;
import com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel.RoutePointRelModifyImagesDTO;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author 阿伟
 * @since 2025-05-20
 */
@Mapper
public interface RoutePointRelMapper extends BaseMapper<yuxixia_DO> {

    boolean modifyRoutePoint(RoutePointRelModifyImagesDTO routePointRelModifyImagesDTO);

    yuxixia_DO selectRoutePoint(AddRoutePointRelListDTO addRoutePointRel);

    void insertByRoutePointId(yuxixia_DO yuxixiaDO);

    yuxixia_DO selectRemoveRoutePoint(RemoveRoutePointDTO removeInspectionId);
}