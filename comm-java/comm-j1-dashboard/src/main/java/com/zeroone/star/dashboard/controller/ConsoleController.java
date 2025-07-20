package com.zeroone.star.dashboard.controller;

import com.zeroone.star.dashboard.service.IConsoleService;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.dashboard.console.*;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;



/**
 * 控制台
 */
@RestController
@RequestMapping("/j1-dashboard/console")
@Api(tags = "控制台")
public class ConsoleController {

    @Resource
    private IConsoleService consoleService;


    // ===== 报修统计相关接口 =====

    /**
     * 查询所有报修统计信息
     *
     * @return 返回报修统计信息的集合
     */
    @GetMapping("/repair-stats")
    @ApiOperation(value = "报修统计")
    public JsonVO<RepairStatisticsVO> getAllRepairStats(@RequestParam("CommunityIdOrTel") String tel){
        RepairStatisticsVO allRepairStats = consoleService.getAllRepairStats(tel);
        return JsonVO.success(allRepairStats);
    }



    // ===== 投诉统计相关接口 =====

    /**
     * 查询所有投诉统计信息
     *
     * @return 返回投诉统计信息的集合
     */
    @GetMapping("/complaint-stats")
    @ApiOperation(value = "投诉统计")
    public JsonVO<ComplaintStatisticsVO> getAllComplaintStats(@RequestParam("CommunityIdOrTel") String tel){
        ComplaintStatisticsVO allComplaintStats = consoleService.getAllComplaintStats(tel);
        return JsonVO.success(allComplaintStats);
    }



    // ===== 住户注册统计相关接口 =====
    /**
     * 查询所有住户注册统计信息
     *
     * @return 返回住户注册统计信息的集合
     */
    @GetMapping("/register-stats")
    @ApiOperation(value = "住户注册统计")
    public JsonVO<ResidentRegistrationStatisticsVO> getAllRegistrationStats(@RequestParam("CommunityIdOrTel") String tel){
        //TODO: 调用service 获取所有住户注册统计数据
        ResidentRegistrationStatisticsVO allRegistrationStats = consoleService.getAllRegistrationStats(tel);
        return JsonVO.success(allRegistrationStats);
    }



    // ===== 社区信息统计相关接口 =====
    /**
     * 查询所有社区信息统计
     *
     * @return 返回社区信息信息的集合
     */
    @GetMapping("/business-community")
    @ApiOperation(value ="小区信息")
    public JsonVO<BusinessCommunityInfoVO> getAllBusinessCommunitys(@RequestParam("CommunityIdOrTel") String tel){
        BusinessCommunityInfoVO allBusinessCommunitys = consoleService.getAllBusinessCommunitys(tel);
        return JsonVO.success(allBusinessCommunitys);
    }


    @GetMapping("/Feedback")
    @ApiOperation(value = "业主反馈")
    public JsonVO<List<OwnerFeedbackVO>> getAllOwnerFeedback(@RequestParam("CommunityIdOrTel") String tel){
        List<OwnerFeedbackVO> allOwnerFeedback = consoleService.getAllOwnerFeedback(tel);
        return JsonVO.success(allOwnerFeedback);
    }



}
