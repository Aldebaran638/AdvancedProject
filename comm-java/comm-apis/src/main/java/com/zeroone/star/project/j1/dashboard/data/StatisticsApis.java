package com.zeroone.star.project.j1.dashboard.data;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.dashboard.data.CommunityPaymentStatisticsVO;
import com.zeroone.star.project.vo.j1.dashboard.data.CommunityRepairStatisticsVO;
import com.zeroone.star.project.vo.j1.dashboard.data.PlatformStatisticsVO;

import java.util.List;

/**
 * 平台数据统计API接口
 */
public interface StatisticsApis {

    /**
     * 获取平台统计数据
     * 包含：小区数、业主数、物业数、车辆数、商家数、今日缴费数、
     * 店铺数、今日报修数、房屋数、今日巡检数、商铺数、今日投诉数等指标
     *
     * @return 平台统计数据
     */
    JsonVO<PlatformStatisticsVO> getPlatformStatistics();

    /**
     * 获取小区缴费统计数据
     * 包含各小区的缴费次数和缴费金额统计
     *
     * @return 小区缴费统计数据列表
     */
    JsonVO<List<CommunityPaymentStatisticsVO>> getCommunityPaymentStatistics();

    /**
     * 获取小区报修统计数据
     * 包含各小区的报修单数统计
     *
     * @return 小区报修统计数据列表
     */
    JsonVO<List<CommunityRepairStatisticsVO>> getCommunityRepairStatistics();
} 