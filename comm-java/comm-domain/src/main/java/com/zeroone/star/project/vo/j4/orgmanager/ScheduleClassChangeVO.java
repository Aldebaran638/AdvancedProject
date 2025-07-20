package com.zeroone.star.project.vo.j4.orgmanager;

import com.zeroone.star.project.dto.j4.orgmanager.StaffWorkTime;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

@ApiModel("排班修改页展示类")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class ScheduleClassChangeVO {

    /**
     * 班次名称
     */
    @ApiModelProperty(value = "班次名称",example = "路南早班")
    private String name;

    /**
     * 排班类型
     *
     * @按日排班 1001
     * @按周排班 2002
     * @按月排班 3003
     */
    @ApiModelProperty(value = "排班类型",example = "按周排班")
    private String scheduleType;

    /**
     * 排班周期
     */
    @ApiModelProperty(value = "排班周期",example = "4")
    private int scheduleCycle;

    /**
     * 排班时间段
     */
    @ApiModelProperty(value = "排班时间段",example = "9:00-11:00")
    private List<List<String>> timeList;

}
