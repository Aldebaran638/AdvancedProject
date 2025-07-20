package com.zeroone.star.project.j1.dashboard.console;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.dashboard.console.*;


import java.util.List;


/**
 * 控制台API接口
 */
public interface ConsoleApis {


    JsonVO<List<RepairStatisticsVO>> getAllRepairStats();


    JsonVO<List<ComplaintStatisticsVO>> getAllComplaintStats();


    JsonVO<List<ResidentRegistrationStatisticsVO>> getAllRegistrationStats();




    JsonVO<List<BusinessCommunityInfoVO>> getAllBusinessCommunitys();


    JsonVO<List<OwnerFeedbackVO>> getAllOwnerFeedback();
}