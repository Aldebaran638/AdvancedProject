package com.zeroone.star.patrolmgt.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.patrolmgt.entity.zhangyvsen_InspectionPoint;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.point.query.RoutePointQuery;
import com.zeroone.star.project.j8.patrolmgt.point.dto.RoutePointDTO;

public interface QueryRoutePointService extends IService<zhangyvsen_InspectionPoint> {
    /**
     * 查询巡检路线巡检点
     * @param
     * @return
     */
    PageDTO<RoutePointDTO> listAllPoint(RoutePointQuery query);
}
