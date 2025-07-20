package com.zeroone.star.dashboard.service;
import com.zeroone.star.project.vo.j1.dashboard.console.*;

import java.util.List;

/**
 * 控制台服务接口
 */
public interface IConsoleService {

    /**
     * 查询所有报修统计信息
     *
     * @return
     */
    RepairStatisticsVO getAllRepairStats(String userId);

    /**
     * 查询所有投诉信息
     * @return
     */
    ComplaintStatisticsVO getAllComplaintStats(String communityId);



    /**
     * 查询所有住户注册信息
     *
     * @return 返回住户注册统计信息的集合
     */
    ResidentRegistrationStatisticsVO getAllRegistrationStats(String userId);

    /**
     * 查询所有小区信息
     * @return
     */
    BusinessCommunityInfoVO getAllBusinessCommunitys(String userId);


    /**
     * 查询业主反馈信息
     * @return
     */
    List<OwnerFeedbackVO> getAllOwnerFeedback(String userId);


}