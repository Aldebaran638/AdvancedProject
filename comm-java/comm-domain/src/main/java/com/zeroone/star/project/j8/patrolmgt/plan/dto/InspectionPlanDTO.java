package com.zeroone.star.project.j8.patrolmgt.plan.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.hibernate.validator.constraints.Length;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Size;
import java.io.Serializable;
import java.util.Date;

/**
* @author su
 */
@AllArgsConstructor
@NoArgsConstructor
@Builder
@Data
@ApiModel("巡检计划")
public class InspectionPlanDTO implements Serializable {

    /**
    * 巡检计划名称
    */
    @NotBlank(message="[巡检计划名称]不能为空")
    @Size(max= 100,message="编码长度不能超过100")
    @ApiModelProperty(value = "巡检计划名称", required = true)
    @Length(max= 100,message="编码长度不能超过100")
    private String inspectionPlanName;

    /**
    * 巡检路线ID
    */
    @NotBlank(message="[巡检路线ID]不能为空")
    @Size(max= 300,message="编码长度不能超过300")
    @ApiModelProperty(value = "巡检路线ID", required = true)
    @Length(max= 300,message="编码长度不能超过300")
    private String inspectionRouteId;

    /**
    * 小区ID
    */
    @NotBlank(message="[小区ID]不能为空")
    @Size(max= 30,message="编码长度不能超过30")
    @ApiModelProperty(value = "小区ID", required = true)
    @Length(max= 30,message="编码长度不能超过30")
    private String communityId;

    /**
     * 巡检人ID
     */
    @NotBlank(message="[巡检人]不能为空")
    @Size(max= 30,message="编码长度不能超过30")
    @ApiModelProperty(value = "巡检人ID", required = true)
    @Length(max= 30,message="编码长度不能超过30")
    private String staffId;

    /**
     * 巡检人名称
     */
    @NotBlank(message="[巡检人名称]不能为空")
    @Size(max= 200,message="编码长度不能超过200")
    @ApiModelProperty(value = "巡检人名称", required = true)
    @Length(max= 200,message="编码长度不能超过200")
    private String staffName;

    /**
    * 开始日期
    */
    @NotNull(message="[开始日期]不能为空")
    @ApiModelProperty(value = "开始日期", required = true)
    private Date startDate;

    /**
    * 结束日期
    */
    @NotNull(message="[结束日期]不能为空")
    @ApiModelProperty(value = "结束日期", required = true)
    private Date endDate;

    /**
    * 开始时间
    */
    @NotBlank(message="[开始时间]不能为空")
    @Size(max= 12,message="编码长度不能超过12")
    @ApiModelProperty(value = "开始时间", required = true)
    @Length(max= 12,message="编码长度不能超过12")
    private String startTime;

    /**
    * 结束时间
    */
    @NotBlank(message="[结束时间]不能为空")
    @Size(max= 12,message="编码长度不能超过12")
    @ApiModelProperty(value = "结束时间", required = true)
    @Length(max= 12,message="编码长度不能超过12")
    private String endTime;

    /**
    * 任务提前
    */
    @NotBlank(message="[任务提前]不能为空")
    @Size(max= 12,message="编码长度不能超过12")
    @ApiModelProperty(value = "任务提前", required = true)
    @Length(max= 12,message="编码长度不能超过12")
    private String beforeTime;

    /**
    * 执行周期
    */
    @NotBlank(message="[执行周期]不能为空")
    @Size(max= 12,message="编码长度不能超过12")
    @ApiModelProperty(value = "执行周期", required = true)
    @Length(max= 12,message="编码长度不能超过12")
    private String inspectionPlanPeriod;

    /**
    * 月份
    */
    @NotBlank(message="[月份]不能为空")
    @Size(max= 64,message="编码长度不能超过64")
    @ApiModelProperty(value = "月份", required = true)
    @Length(max= 64,message="编码长度不能超过64")
    private String inspectionMonth;

    /**
    * 天
    */
    @NotBlank(message="[天]不能为空")
    @Size(max= 128,message="编码长度不能超过128")
    @ApiModelProperty(value = "天", required = true)
    @Length(max= 128,message="编码长度不能超过128")
    private String inspectionDay;

    /**
    * 周
    */
    @NotBlank(message="[周]不能为空")
    @Size(max= 64,message="编码长度不能超过64")
    @ApiModelProperty(value = "周", required = true)
    @Length(max= 64,message="编码长度不能超过64")
    private String inspectionWorkday;

    /**
    * 签到方式
    */
    @NotBlank(message="[签到方式]不能为空")
    @Size(max= 12,message="编码长度不能超过12")
    @ApiModelProperty(value = "签到方式", required = true)
    @Length(max= 12,message="编码长度不能超过12")
    private String signType;

    /**
    * 允许补检  1000不允许  2000允许
    */
    @NotBlank(message="[允许补检  1000不允许  2000允许]不能为空")
    @Size(max= 4,message="编码长度不能超过4")
    @ApiModelProperty(value = "允许补检  1000不允许  2000允许", required = true)
    @Length(max= 4,message="编码长度不能超过4")
    private String canReexamine;

    /**
    * 当前状态
    */
    @Size(max= 12,message="编码长度不能超过12")
    @ApiModelProperty(value = "当前状态", required = true)
    @Length(max= 12,message="编码长度不能超过12")
    private String state;

    /**
    * 制定人员ID
    */
    @NotBlank(message="[制定人员ID]不能为空")
    @Size(max= 30,message="编码长度不能超过30")
    @ApiModelProperty(value = "制定人员ID", required = true)
    @Length(max= 30,message="编码长度不能超过30")
    private String createUserId;

    /**
    * 制定人员姓名
    */
    @NotBlank(message="[制定人员姓名]不能为空")
    @Size(max= 50,message="编码长度不能超过50")
    @ApiModelProperty(value = "制定人员姓名", required = true)
    @Length(max= 50,message="编码长度不能超过50")
    private String createUserName;
}