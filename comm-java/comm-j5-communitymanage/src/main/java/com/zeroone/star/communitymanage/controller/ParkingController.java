package com.zeroone.star.communitymanage.controller;

import com.zeroone.star.communitymanage.service.parking.IParkingService;
import com.zeroone.star.project.j5.community.parking.ParkingApis;
import com.zeroone.star.project.query.j5.community.parking.ParkingQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.community.parking.ParkingVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * <p>
 * 描述：车位结构图的控制器
 * </p>
 * @author hh
 * @version 1.0.0
 */
@RestController
@RequestMapping("/j5-community/parking")
@Api(tags = "车位结构图")
@Validated
public class ParkingController implements ParkingApis {

    @Autowired
    IParkingService parkingService;

    @Override
    @GetMapping("query-parking")
    @ApiOperation("获取指定单元车位结构")
    public JsonVO<List<ParkingVO>> queryParking(@Validated ParkingQuery query) {
        List<ParkingVO> parkingvo = parkingService.listparking(query);
        System.out.println(parkingvo);
        return JsonVO.success(parkingvo);
    }
}
