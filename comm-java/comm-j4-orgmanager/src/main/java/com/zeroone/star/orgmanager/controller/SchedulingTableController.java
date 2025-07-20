package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.orgmanager.service.AssociatedPersonnelService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.orgmanager.SchedulingTableApis;
import com.zeroone.star.project.query.j4.orgmanager.PersonnelScheduleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.orgmanager.PersonnelSchedulingVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.AllArgsConstructor;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;


/**
 * @Author: dashuai
 * @Description: 排班表controller
 */
@AllArgsConstructor
@RestController
@RequestMapping("/j4-orgmanager/schedulingTable")
@Api(tags = "排班表接口")
public class SchedulingTableController implements SchedulingTableApis {
    @Resource
    private AssociatedPersonnelService associatedPersonnelService;
    @ApiOperation("获取人员排班列表（条件+分页）")
    @GetMapping("/getpagePersonnelSchedulingList")
    @Override
    public PageDTO<PersonnelSchedulingVO> getpagePersonnelSchedulingList(@ModelAttribute PersonnelScheduleQuery query) {
        PageDTO<PersonnelSchedulingVO> list=associatedPersonnelService.listPersonnelScheduling(query);
        return JsonVO.success(list).getData();
    }
}