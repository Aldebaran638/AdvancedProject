package com.zeroone.star.orgmanager.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AddScheduleDTO;
import com.zeroone.star.project.dto.j4.orgmanager.SaveScheduleDTO;
import com.zeroone.star.project.dto.j4.orgmanager.SettingNameDTO;
import com.zeroone.star.project.query.j4.orgmanager.ScheduleQuery;
import com.zeroone.star.project.vo.j4.orgmanager.ScheduleVO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.orgmanager.ScheduleClassChangeVO;
import com.zeroone.star.project.vo.j4.orgmanager.ScheduleClassStaffVO;
import java.util.List;

public interface SchedulingService {
    /**
     * 获取排班设置名称列表
     * @return
     */
    List<SettingNameDTO> listName();

    /**
     * 获取排版设置列表（条件+分页）
     * @return
     */
    PageDTO<ScheduleVO> listSchedule(ScheduleQuery query);

    /**
     * 添加排班设置
     * @param addScheduleDTO
     */
    void addSchedule(AddScheduleDTO addScheduleDTO);

    /**
     * 修改排班设置
     * @param saveScheduleDTO
     */
    boolean updateSchedule(SaveScheduleDTO saveScheduleDTO);


    void scheduleDelete(long schedule_id);

    void scheduleStatus(long scheduleId);

    JsonVO<ScheduleClassChangeVO> scheduleChange(long scheduleId);

    PageDTO<ScheduleClassStaffVO> schedulePeople(long pageIndex, long pageSize, long scheduleId);

}
