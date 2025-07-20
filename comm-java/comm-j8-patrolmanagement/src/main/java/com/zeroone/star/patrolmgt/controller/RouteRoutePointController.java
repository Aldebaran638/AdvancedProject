package com.zeroone.star.patrolmgt.controller;

import com.zeroone.star.patrolmgt.service.Imp.QueryRoutePointServiceImp;
import com.zeroone.star.patrolmgt.service.QueryRoutePointService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.point.RoutePointApis;
import com.zeroone.star.project.j8.patrolmgt.point.query.RoutePointQuery;
import com.zeroone.star.project.j8.patrolmgt.point.dto.RoutePointDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

@RestController
@RequestMapping("/j8-patrolmgt/route")
@Api(tags = "巡检路线")
public class RouteRoutePointController implements RoutePointApis {

    @Resource
    QueryRoutePointService queryRoutePointService;

    @ApiOperation(value = "获取巡检路线巡检点列表（条件+分页）")
    @GetMapping("/query-route-point-list")
    @Override
    public JsonVO<PageDTO<RoutePointDTO>> queryRoutePointList(RoutePointQuery query) {
        return JsonVO.success(queryRoutePointService.listAllPoint(query));
    }
}
