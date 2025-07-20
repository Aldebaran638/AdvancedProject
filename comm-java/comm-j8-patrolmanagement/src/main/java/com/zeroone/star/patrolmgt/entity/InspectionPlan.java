package com.zeroone.star.patrolmgt.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
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
import java.time.LocalDateTime;
import java.util.Date;

/**
* @author su
 */
@AllArgsConstructor
@NoArgsConstructor
@Builder
@Data
@ApiModel("巡检计划")
public class InspectionPlan implements Serializable {

    /**
    * 巡检计划ID
    */
    @NotBlank(message="[巡检计划ID]不能为空")
    @Size(max= 30,message="编码长度不能超过30")
    @ApiModelProperty("巡检计划ID")
    @Length(max= 30,message="编码长度不能超过30")
    @TableId(type=IdType.ASSIGN_ID)
    private String inspectionPlanId;
    /**
    * 业务ID
    */
    @Size(max= 30,message="编码长度不能超过30")
    @ApiModelProperty("业务ID")
    @Length(max= 30,message="编码长度不能超过30")
    private String bId;
    /**
    * 巡检计划名称
    */
    @NotBlank(message="[巡检计划名称]不能为空")
    @Size(max= 100,message="编码长度不能超过100")
    @ApiModelProperty("巡检计划名称")
    @Length(max= 100,message="编码长度不能超过100")
    private String inspectionPlanName;
    /**
    * 巡检路线ID
    */
    @NotBlank(message="[巡检路线ID]不能为空")
    @Size(max= 300,message="编码长度不能超过300")
    @ApiModelProperty("巡检路线ID")
    @Length(max= 300,message="编码长度不能超过300")
    private String inspectionRouteId;
    /**
    * 小区ID
    */
    @NotBlank(message="[小区ID]不能为空")
    @Size(max= 30,message="编码长度不能超过30")
    @ApiModelProperty("小区ID")
    @Length(max= 30,message="编码长度不能超过30")
    private String communityId;
    /**
    * 开始日期
    */
    @NotNull(message="[开始日期]不能为空")
    @ApiModelProperty("开始日期")
    private Date startDate;
    /**
    * 结束日期
    */
    @NotNull(message="[结束日期]不能为空")
    @ApiModelProperty("结束日期")
    private Date endDate;
    /**
    * 开始时间
    */
    @NotBlank(message="[开始时间]不能为空")
    @Size(max= 12,message="编码长度不能超过12")
    @ApiModelProperty("开始时间")
    @Length(max= 12,message="编码长度不能超过12")
    private String startTime;
    /**
    * 结束时间
    */
    @NotBlank(message="[结束时间]不能为空")
    @Size(max= 12,message="编码长度不能超过12")
    @ApiModelProperty("结束时间")
    @Length(max= 12,message="编码长度不能超过12")
    private String endTime;
    /**
    * 任务提前
    */
    @NotBlank(message="[任务提前]不能为空")
    @Size(max= 12,message="编码长度不能超过12")
    @ApiModelProperty("任务提前")
    @Length(max= 12,message="编码长度不能超过12")
    private String beforeTime;
    /**
    * 执行周期
    */
    @NotBlank(message="[执行周期]不能为空")
    @Size(max= 12,message="编码长度不能超过12")
    @ApiModelProperty("执行周期")
    @Length(max= 12,message="编码长度不能超过12")
    private String inspectionPlanPeriod;
    /**
    * 月份
    */
    @NotBlank(message="[月份]不能为空")
    @Size(max= 64,message="编码长度不能超过64")
    @ApiModelProperty("月份")
    @Length(max= 64,message="编码长度不能超过64")
    private String inspectionMonth;
    /**
    * 天
    */
    @NotBlank(message="[天]不能为空")
    @Size(max= 128,message="编码长度不能超过128")
    @ApiModelProperty("天")
    @Length(max= 128,message="编码长度不能超过128")
    private String inspectionDay;
    /**
    * 周
    */
    @NotBlank(message="[周]不能为空")
    @Size(max= 64,message="编码长度不能超过64")
    @ApiModelProperty("周")
    @Length(max= 64,message="编码长度不能超过64")
    private String inspectionWorkday;
    /**
    * 签到方式
    */
    @NotBlank(message="[签到方式]不能为空")
    @Size(max= 12,message="编码长度不能超过12")
    @ApiModelProperty("签到方式")
    @Length(max= 12,message="编码长度不能超过12")
    private String signType;
    /**
    * 允许补检  1000不允许  2000允许
    */
    @NotBlank(message="[允许补检  1000不允许  2000允许]不能为空")
    @Size(max= 4,message="编码长度不能超过4")
    @ApiModelProperty("允许补检  1000不允许  2000允许")
    @Length(max= 4,message="编码长度不能超过4")
    private String canReexamine;
    /**
    * 当前状态
    */
    @Size(max= 12,message="编码长度不能超过12")
    @ApiModelProperty("当前状态")
    @Length(max= 12,message="编码长度不能超过12")
    private String state;
    /**
    * 备注说明
    */
    @Size(max= 200,message="编码长度不能超过200")
    @ApiModelProperty("备注说明")
    @Length(max= 200,message="编码长度不能超过200")
    private String remark;
    /**
    * 制定人员ID
    */
    @NotBlank(message="[制定人员ID]不能为空")
    @Size(max= 30,message="编码长度不能超过30")
    @ApiModelProperty("制定人员ID")
    @Length(max= 30,message="编码长度不能超过30")
    private String createUserId;
    /**
    * 制定人员姓名
    */
    @NotBlank(message="[制定人员姓名]不能为空")
    @Size(max= 50,message="编码长度不能超过50")
    @ApiModelProperty("制定人员姓名")
    @Length(max= 50,message="编码长度不能超过50")
    private String createUserName;
    /**
    * 创建时间
    */
    @NotNull(message="[创建时间]不能为空")
    @ApiModelProperty("创建时间")
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;
    /**
    * 数据状态
    */
    @NotBlank(message="[数据状态]不能为空")
    @Size(max= 30,message="编码长度不能超过30")
    @ApiModelProperty("数据状态")
    @Length(max= 30,message="编码长度不能超过30")
    private String statusCd;
}
