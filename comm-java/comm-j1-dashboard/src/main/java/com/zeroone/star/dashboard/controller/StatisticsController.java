package com.zeroone.star.dashboard.controller;

import com.zeroone.star.dashboard.service.DashboardService;
import com.zeroone.star.project.j1.dashboard.data.StatisticsApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.dashboard.data.CommunityPaymentStatisticsVO;
import com.zeroone.star.project.vo.j1.dashboard.data.CommunityRepairStatisticsVO;
import com.zeroone.star.project.vo.j1.dashboard.data.PlatformStatisticsVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

/**
 * 平台统计数据
 */
@RestController
@RequestMapping("/j1-dashboard/statistics")
@Api(tags = "平台数据统计")
public class StatisticsController implements StatisticsApis {

    @Resource
    private DashboardService dashboardService;

    @GetMapping("/platform")
    @ApiOperation(value = "获取平台统计数据")
    @Override
    public JsonVO<PlatformStatisticsVO> getPlatformStatistics() {
        return JsonVO.success(dashboardService.getPlatformStatistics());
    }

    @GetMapping("/community-payment")
    @ApiOperation(value = "获取小区缴费统计")
    @Override
    public JsonVO<List<CommunityPaymentStatisticsVO>> getCommunityPaymentStatistics() {
        return JsonVO.success(dashboardService.getCommunityPaymentStatistics());
    }

    @GetMapping("/community-repair")
    @ApiOperation(value = "获取小区报修统计")
    @Override
    public JsonVO<List<CommunityRepairStatisticsVO>> getCommunityRepairStatistics() {
        return JsonVO.success(dashboardService.getCommunityRepairStatistics());
    }

}