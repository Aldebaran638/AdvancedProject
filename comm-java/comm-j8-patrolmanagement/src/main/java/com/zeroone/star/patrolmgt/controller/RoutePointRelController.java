package com.zeroone.star.patrolmgt.controller;

import com.zeroone.star.patrolmgt.service.RoutePointRelService;
import com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel.RemoveRoutePointDTO;
import com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel.RoutePointRelModifyImagesDTO;
import com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel.AddRoutePointRelListDTO;
import com.zeroone.star.project.j8.patrolmgt.route.routepointrel.RoutePointRelApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;


@RestController
@RequestMapping("/j8-patrolmgt/route")
@Api(tags="巡检路线巡检点")
public class RoutePointRelController implements RoutePointRelApis {

    @Autowired
    private RoutePointRelService routePointRelService;

    @ApiOperation(value = "新增巡检路线巡检点")
    @PostMapping("/addpointlist-routepointrel")
    @Override
    public JsonVO<List<String>> addRoutePointRelList(@RequestBody List<AddRoutePointRelListDTO> addRoutePointRelListDTO) {
        return routePointRelService.addRoutePointRelListService(addRoutePointRelListDTO);
    }

    @ApiOperation(value = "修改巡检路线巡检点")
    @PutMapping("/modify-routepointrel")
    @Override
    public JsonVO<String> modifyRoutePointRelImages(@RequestBody RoutePointRelModifyImagesDTO routePointRelModifyImagesDTO) {
        return routePointRelService.modifyRoutePointRelService(routePointRelModifyImagesDTO);
    }

    @ApiOperation(value = "删除巡检路线巡检点")
    @DeleteMapping("/remove-routepointrel")
    @Override
    public JsonVO<String> removeRoutePointRelImages( RemoveRoutePointDTO removeInspectionId) {
        return routePointRelService.removeRoutePointRelService(removeInspectionId);
    }
}
