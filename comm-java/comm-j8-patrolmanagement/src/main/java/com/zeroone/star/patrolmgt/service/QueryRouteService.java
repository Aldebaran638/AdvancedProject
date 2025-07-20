package com.zeroone.star.patrolmgt.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.patrolmgt.entity.zhangyvsen_InspectionRoute;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.route.dto.zhangyvsen_RouteDTO;
import com.zeroone.star.project.j8.patrolmgt.route.query.RouteNameQuery;
import com.zeroone.star.project.j8.patrolmgt.route.query.RouteQuery;

import java.util.List;

public interface QueryRouteService extends IService<zhangyvsen_InspectionRoute> {

/**
 *  分页查询
 * param query 查询对象
 * return 分页结果
 */
    PageDTO<zhangyvsen_RouteDTO> listAll(RouteQuery query);

    /**
     * 查询该小区所有路线
     * @param query
     * @return
     */
    List<String> listRouteName(RouteNameQuery query);
}
