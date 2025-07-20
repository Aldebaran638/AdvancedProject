package com.zeroone.star.dashboard.service;

import com.zeroone.star.project.vo.j1.dashboard.data.CommunityPaymentStatisticsVO;
import com.zeroone.star.project.vo.j1.dashboard.data.CommunityRepairStatisticsVO;
import com.zeroone.star.project.vo.j1.dashboard.data.PlatformStatisticsVO;

import java.util.List;

/**
 * 平台数据统计服务接口
 */
public interface DashboardService {
    /**
     * 获取平台统计数据
     * 包含：小区数、业主数、物业数、车辆数、商家数、今日缴费数、
     * 店铺数、今日报修数、房屋数、今日巡检数、商铺数、今日投诉数等指标
     *
     * @return 平台统计数据VO
     */
    PlatformStatisticsVO getPlatformStatistics();

    /**
     * 获取小区缴费统计数据
     * 每个小区的缴费次数和缴费金额统计
     *
     * @return 小区缴费统计数据VO列表
     */
    List<CommunityPaymentStatisticsVO> getCommunityPaymentStatistics();

    /**
     * 获取小区报修统计数据
     * 每个小区的报修单数统计
     *
     * @return 小区报修统计数据VO列表
     */
    List<CommunityRepairStatisticsVO> getCommunityRepairStatistics();




}