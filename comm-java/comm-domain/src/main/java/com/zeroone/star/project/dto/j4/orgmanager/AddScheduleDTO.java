package com.zeroone.star.project.dto.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;
import org.hibernate.validator.constraints.Range;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.Pattern;

import java.util.List;

/**
 * <p>
 * 描述：排班添加数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("排班添加数据传输对象")
public class AddScheduleDTO {
    @ApiModelProperty(value = "排班名称", example = "123123", required = true)
    @NotBlank(message = "排班名称不能为空")
    private String name;              // 排班名称（必填）

    @ApiModelProperty(value = "排班类型", example = "1001", required = true, notes = "可选值：按日/周/月")
    @NotBlank(message = "排班类型不能为空")
    private String scheduleType;      // 排班类型（按日/周/月，必填）

    @ApiModelProperty(value = "排班周期", example = "3", required = true)
    @NotBlank(message = "排班周期不能为空")
    private String scheduleCycle;     // 排班周期（如"每周一、三"，必填）

    @ApiModelProperty(value = "店铺ID", example = "store_001", required = true)
    @NotBlank(message = "店铺ID不能为空")
    private String storeId;           // 店铺ID（必填）

    @ApiModelProperty(value = "排班详情数组", required = true)
    @NotEmpty(message = "排班详情数组不能为空")
    private List<ScheduleDetail> details;  // 排班详情数组（必填）

    @Data
    @ApiModel("排班详情子对象")
    @AllArgsConstructor
    @NoArgsConstructor
    public static class ScheduleDetail {
        @ApiModelProperty(value = "周标识（一个月的第几周）", example = "1", required = true, notes = "范围：1-4周")
        @Range(min = 1, max = 4, message = "周标识范围在1-4周之间")
        private Integer weekFlag;     // 周标识（一个月的第几周，如1-4周，必填）

        @ApiModelProperty(value = "一周的第几天", example = "1", required = true, notes = "1-7对应周一到周日")
        @Range(min = 1, max = 7, message = "一周的第几天范围在1-7之间")
        private Integer day;          // 一周的第几天（1-7，对应周一到周日，必填）

        @ApiModelProperty(value = "工作日类型", example = "2002(2002表示休息，不是2002的话传递过来一个班次id)", required = true, notes = "默认'2002'表示休息")
        @NotBlank(message = "工作日类型不能为空")
        private String workdayType;       // 工作日类型（默认"2002"表示休息，必填）

        @ApiModelProperty(value = "班次id", example = "102024022711320386（当这一天不休息时候需要指定一个班次id）",notes = "当这一天不休息时候需要指定一个班次id")
        @NotBlank(message = "工作日类型不能为空")
        private String classesId;
    }
}