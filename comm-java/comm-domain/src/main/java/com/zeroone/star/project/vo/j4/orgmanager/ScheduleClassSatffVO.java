package com.zeroone.star.project.vo.j4.orgmanager;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


/**
 * @作者: 尘缘
 * @描述: 根据排班信息返回排班人员列表
 *
 */
@ApiModel("排班人员展示类")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class ScheduleClassSatffVO {

    /**
     * 排班id
     */
    @ApiModelProperty(value = "排班id",example = "00001")
    private Long scheduleId;

    /**
     * 员工id
     */
    @ApiModelProperty(value = "员工id",example="0000021")
    private Long staffId;
    /**
     * 员工名称
     */
    @ApiModelProperty(value="员工名称",example = "张三")
    private String staffName;

    /**
     * 创建时间
     */
    @ApiModelProperty(value="创建时间",example = "2020-6-27")
    private java.time.LocalTime createTime;


}
