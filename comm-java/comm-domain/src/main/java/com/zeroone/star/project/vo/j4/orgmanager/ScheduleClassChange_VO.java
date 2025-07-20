package com.zeroone.star.project.vo.j4.orgmanager;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class ScheduleClassChange_VO {
    /**
     * 班次名称
     */
    private String name;

    /**
     * 排班类型
     *
     * @按日排班 1001
     * @按周排班 2002
     * @按月排班 3003
     */
    private int scheduleType;

    /**
     * 排班周期
     */
    private int scheduleCycle;

    /**
     * 排班时间段
     */
    private List timeList;

}
