package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.orgmanager.service.SchedulingService;
import com.zeroone.star.orgmanager.service.AssociatedPersonnelService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AddAssociatedPersonnelDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AddScheduleDTO;
import com.zeroone.star.project.dto.j4.orgmanager.SettingNameDTO;
import com.zeroone.star.project.j4.orgmanager.SchedulingApis;
import com.zeroone.star.project.query.j4.orgmanager.ScheduleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.orgmanager.ScheduleVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;
import com.zeroone.star.project.vo.j4.orgmanager.ScheduleClassChangeVO;
import com.zeroone.star.project.vo.j4.orgmanager.ScheduleClassStaffVO;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import javax.annotation.Resource;
import com.zeroone.star.project.dto.j4.orgmanager.SaveScheduleDTO;
import java.util.List;

/**
 * @Author: dashuai
 * @Description: 排班设置接口
 */
@RestController
@RequestMapping("/j4-orgmanager/scheduling")
@Api(tags = "排班设置接口")
public class SchedulingController implements SchedulingApis {
    /**
     * 获取排班设置名称列表
     * @return
     */
    @Resource
    private SchedulingService schedulingService;

    @Resource
    private AssociatedPersonnelService associatedPersonnelService;

    @ApiOperation("获取排班设置名称列表")
    @GetMapping("/queryName")
    @Override
    public JsonVO<List<SettingNameDTO>> queryName() {
        List<SettingNameDTO> list=schedulingService.listName();
        return JsonVO.success(list);
    }

    /**
     * 获取排版设置列表（条件+分页）
     * @param query
     * @return
     */
    @ApiOperation("获取排版设置列表（条件+分页）")
    @GetMapping("/listSchedule")
    @Override
    public JsonVO<PageDTO<ScheduleVO>> querySchedule(@ModelAttribute ScheduleQuery query) {
       PageDTO<ScheduleVO> list=schedulingService.listSchedule(query);
        return JsonVO.success(list);
    }

    /**
     * 添加排班设置
     * @param addScheduleDTO
     * @return
     */
    @ApiOperation("添加排班设置")
    @PostMapping("saveSchedule")
    @Override
    public JsonVO<String> addSchedule(@RequestBody AddScheduleDTO addScheduleDTO) {
        schedulingService.addSchedule(addScheduleDTO);
        return JsonVO.success("success");
    }

    @ApiOperation("修改排班设置")
    @PutMapping("updateSchedule")
    @Override
    public JsonVO<String> modifySchedule(@RequestBody SaveScheduleDTO saveScheduleDTO) {
        if(schedulingService.updateSchedule(saveScheduleDTO))
        {
            return JsonVO.success("success");
        }
        return JsonVO.fail("fail");
    }

    @Override
    @ApiOperation(value = "删除排班设置")
    @DeleteMapping("/delete/{scheduleId}")
    public JsonVO scheduleDelete(@PathVariable long scheduleId) {

       schedulingService.scheduleDelete(scheduleId);
        return JsonVO.success("success");
    }

    @Override
    @ApiOperation(value = "启用/停用排班设置")
    @PutMapping("/status/{scheduleId}")
    public JsonVO scheduleStatus(@PathVariable long scheduleId)
    {
        schedulingService.scheduleStatus(scheduleId);
        return JsonVO.success("success");
    }

    @Override
    @ApiOperation(value = "获取排班设置详情")
    @GetMapping("/schedule/{scheduleId}")
    public JsonVO<ScheduleClassChangeVO> scheduleChange(@PathVariable long scheduleId){

        return schedulingService.scheduleChange(scheduleId);
    }

    @Override
    @ApiOperation(value = "获取关联人员列表（条件+分页）")
    @GetMapping("/staff")
    public JsonVO<PageDTO<ScheduleClassStaffVO>> schedulePeople(@RequestParam long pageIndex,
                                                                @RequestParam long pageSize,
                                                                @RequestParam long scheduleId)
    {
        PageDTO<ScheduleClassStaffVO> pageDTO=schedulingService.schedulePeople(pageIndex,pageSize,scheduleId);
        return JsonVO.success(pageDTO);
    }

    @ApiOperation("添加排班关联人员")
    @PostMapping("/save-Associated-Personnel")
    @Override
    public JsonVO<String> addAssociatedPersonnel(@RequestBody AddAssociatedPersonnelDTO addAssociatedPersonnelDTO) {
        associatedPersonnelService.addAssociatedPersonnel(addAssociatedPersonnelDTO);
        return JsonVO.success("添加成功");
    }

    @ApiOperation("删除排班关联人员")
    @DeleteMapping("/delete-Associated-Personnel/{staffId}/{scheduleId}")
    @Override
    public JsonVO<String> deleteAssociatedPersonnel(@PathVariable String staffId, @PathVariable String scheduleId) {
        if (associatedPersonnelService.deleteAssociatedPersonnel(staffId, scheduleId)) {
            return JsonVO.success("删除成功");
        }
        return JsonVO.fail("删除失败");
    }
}
