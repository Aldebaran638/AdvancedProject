package com.zeroone.star.project.vo.j4.orgmanager;


import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


/**
 * @作者: 尘缘
 * @描述: 根据排班信息返回排班人员列表
 *
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class ScheduleClassSatff_VO {

    /**
     * 排班id
     */
    private Long scheduleId;

    /**
     * 员工id
     */
    private Long staffId;
    /**
     * 员工名称
     */
    private String staffName;

    /**
     * 创建时间
     */
    private java.time.LocalTime createTime;


}
