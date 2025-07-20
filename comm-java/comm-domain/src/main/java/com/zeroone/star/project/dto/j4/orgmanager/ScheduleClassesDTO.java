package com.zeroone.star.project.dto.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

@ApiModel(value = "员工排班信息")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class ScheduleClassesDTO {

    /** 排班ID */
    @ApiModelProperty(value = "排班ID", example = "1")
    private String scheduleId;

    /** 班次名称 */
    @ApiModelProperty(value = "员工ID", example = "1")
    private String name;

    /** 排班类型（1001 按日排班，2002 按周排班，3003 按月排班） */
    @ApiModelProperty(value = "排班类型", example = "1")
    private String scheduleType;

    /** 排班周期 */
    @ApiModelProperty(value = "排班周期", example = "1")
    private String scheduleCycle;

    /** 状态（1001 启用，2002 停用） */
    @ApiModelProperty(value = "状态", example = "1")
    private String state;

    /** 备注说明 */
    @ApiModelProperty(value = "备注说明", example = "哈哈哈哈哈哈")
    private String remark;

    /** 计算时间 */
    @ApiModelProperty(value = "计算时间", example = "2021-01-01 00:00:00")
    private LocalDateTime computeTime;
}
