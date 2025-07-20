package com.zeroone.star.project.vo.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;

/**
 * <p>
 * 描述：排班信息视图对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("排班信息视图对象")
public class ScheduleVO {
    @ApiModelProperty(value = "排班ID", example = "102022103028120105", notes = "对应 schedule_classes.schedule_id 主键字段")
    private String scheduleId; // 排班ID（主键）

    @ApiModelProperty(value = "班次名称", example = "早班")
    private String name; // 班次名称

    @ApiModelProperty(value = "排班类型", example = "1001(1001 按日排班 2002 按周排班 3003 按月排班)", notes = "对应 schedule_classes.schedule_type 字段")
    private String scheduleType; // 排班类型（对应 schedule_classes.schedule_type）

    @ApiModelProperty(value = "排班周期", example = "1", notes = "对应 schedule_classes.schedule_cycle 字段")
    private String scheduleCycle; // 排班周期（对应 schedule_classes.schedule_cycle）

    @ApiModelProperty(value = "生效时间", example = "2024-01-01 00:00:00", notes = "对应 schedule_classes.compute_time 字段，格式：yyyy-MM-dd")
    private String computeTime; // 生效时间（对应 schedule_classes.compute_time）

    @ApiModelProperty(value = "人员数量", example = "10", notes = "统计 schedule_classes_staff 中相同 schedule_id 的数量")
    private long staffCount; // 人员数量（统计 schedule_classes_staff 中相同 schedule_id 的数量）

    @ApiModelProperty(value = "状态", example = "启用", notes = "对应 schedule_classes.state 字段")
    private String state; // 状态（对应 schedule_classes.state）

    @ApiModelProperty(value = "创建时间", example = "2024-01-01 08:30:00", notes = "对应 schedule_classes.create_time 字段，格式：yyyy-MM-dd HH:mm:ss")
    private String createTime; // 创建时间（对应 schedule_classes.create_time）
}