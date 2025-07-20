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

/**
* 
* @author su
*/

@AllArgsConstructor
@NoArgsConstructor
@Builder
@Data
@ApiModel("巡检计划人员")
//
public class InspectionPlanStaff implements Serializable {

    /**
    * 主键ID
    */
    @NotBlank(message="[主键ID]不能为空")
    @Size(max= 30,message="编码长度不能超过30")
    @ApiModelProperty("主键ID")
    @Length(max= 30,message="编码长度不能超过30")
    @TableId(type= IdType.ASSIGN_ID)
    private String ipStaffId;
    /**
    * 巡检计划ID
    */
    @NotBlank(message="[巡检计划ID]不能为空")
    @Size(max= 30,message="编码长度不能超过30")
    @ApiModelProperty("巡检计划ID")
    @Length(max= 30,message="编码长度不能超过30")
    private String inspectionPlanId;
    /**
    * 业务ID
    */
    @Size(max= 30,message="编码长度不能超过30")
    @ApiModelProperty("业务ID")
    @Length(max= 30,message="编码长度不能超过30")
    private String bId;
    /**
    * 小区ID
    */
    @NotBlank(message="[小区ID]不能为空")
    @Size(max= 30,message="编码长度不能超过30")
    @ApiModelProperty("小区ID")
    @Length(max= 30,message="编码长度不能超过30")
    private String communityId;
    /**
    * 巡检人ID
    */
    @NotBlank(message="[巡检人]不能为空")
    @Size(max= 30,message="编码长度不能超过30")
    @ApiModelProperty("巡检人")
    @Length(max= 30,message="编码长度不能超过30")
    private String staffId;
    /**
    * 巡检人名称
    */
    @NotBlank(message="[巡检人名称]不能为空")
    @Size(max= 200,message="编码长度不能超过200")
    @ApiModelProperty("巡检人名称")
    @Length(max= 200,message="编码长度不能超过200")
    private String staffName;
    /**
    * 开始时间
    */
    @NotBlank(message="[开始时间]不能为空")
    @Size(max= 20,message="编码长度不能超过20")
    @ApiModelProperty("开始时间")
    @Length(max= 20,message="编码长度不能超过20")
    private String startTime;
    /**
    * 结束时间
    */
    @NotBlank(message="[结束时间]不能为空")
    @Size(max= 20,message="编码长度不能超过20")
    @ApiModelProperty("结束时间")
    @Length(max= 20,message="编码长度不能超过20")
    private String endTime;
    /**
    * 创建时间
    */
    @NotNull(message="[]不能为空")
    @ApiModelProperty("")
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
