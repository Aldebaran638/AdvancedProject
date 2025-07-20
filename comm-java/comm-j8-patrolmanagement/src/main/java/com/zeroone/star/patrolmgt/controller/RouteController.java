package com.zeroone.star.patrolmgt.controller;

import com.zeroone.star.patrolmgt.service.QueryRouteService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.route.RouteApis;
import com.zeroone.star.project.j8.patrolmgt.route.dto.zhangyvsen_RouteDTO;
import com.zeroone.star.project.j8.patrolmgt.route.query.RouteNameQuery;
import com.zeroone.star.project.j8.patrolmgt.route.query.RouteQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

import com.zeroone.star.patrolmgt.entity.NiuJiaXu_InspectionRoute;
import com.zeroone.star.patrolmgt.service.IInspectionRouteService;
import com.zeroone.star.project.j8.patrolmgt.route.RouteApis;
import com.zeroone.star.project.j8.patrolmgt.route.dto.AddRouteDTO;
import com.zeroone.star.project.j8.patrolmgt.route.dto.RouteDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;

/**
 * <p>
 * 描述：巡检路线控制器
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Niu - 1,zhangyvsen - 2
 * @version 1.0.0
 */
@RestController
@RequestMapping("/j8-patrolmgt/route")
@Api(tags = "巡检路线")
public class RouteController implements RouteApis {
    @Autowired
    private IInspectionRouteService inspectionRouteService;


    @ApiOperation(value = "添加巡检路线，返回添加成功的id")
    @PostMapping("/add-route")
    @Override
    public JsonVO<String> addRoute(@RequestBody @Valid AddRouteDTO addRouteDTO) {
        NiuJiaXu_InspectionRoute niuJiaXuInspectionRoute = new NiuJiaXu_InspectionRoute();
        BeanUtils.copyProperties(addRouteDTO,niuJiaXuInspectionRoute);
        if (inspectionRouteService.save(niuJiaXuInspectionRoute)) {
            return JsonVO.success(niuJiaXuInspectionRoute.getInspectionRouteId());
        }
        return JsonVO.fail("添加巡检路线失败");
    }

    @ApiOperation(value = "修改巡检路线")
    @PutMapping("/modify-route")
    @Override
    public JsonVO<String> modifyRoute(@RequestBody @Valid RouteDTO routeDTO) {
        NiuJiaXu_InspectionRoute niuJiaXuInspectionRoute = new NiuJiaXu_InspectionRoute();
        BeanUtils.copyProperties(routeDTO,niuJiaXuInspectionRoute);
        int success = inspectionRouteService.updateInspectionRoute(niuJiaXuInspectionRoute);
        if(success == 1){
            return JsonVO.success("修改巡检路线成功");
        }
        return JsonVO.fail("修改巡检路线失败");

    }

    @ApiOperation(value = "删除巡检路线")
    @DeleteMapping ("/remove-route")
    @ApiImplicitParam(name = "inspectionRouteId", value = "巡检路线id", required = true, dataType = "String")
    @Override
    public JsonVO<String> removeRoute(String inspectionRouteId) {

        //return JsonVO.success(inspectionRouteService.deleteInspectionRouteByInspectionRouteId(inspectionRouteId));
        boolean success = inspectionRouteService.removeById(inspectionRouteId);
        if(success){
            return JsonVO.success("删除巡检路线成功");
        }else{
            return JsonVO.fail("删除巡检路线失败");
        }

    }

    @Resource
    QueryRouteService  queryRouteService;

    //2
    @ApiOperation(value = "获取巡检路线列表（条件+分页）")
    @GetMapping("/query-rout-list")
    @Override
    public JsonVO<PageDTO<zhangyvsen_RouteDTO>> queryRouteList(RouteQuery query) {

        return JsonVO.success(queryRouteService.listAll(query));
    }

    //2
    @ApiOperation( value = "获取巡检路线名称列表")
    @GetMapping("/query-name-rout")
    @Override
    public JsonVO<List<String>> queryRouteNameList(RouteNameQuery query) {

        return JsonVO.success(queryRouteService.listRouteName(query));
    }
}
