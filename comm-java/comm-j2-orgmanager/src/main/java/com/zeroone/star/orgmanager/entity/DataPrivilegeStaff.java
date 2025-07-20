package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
public class DataPrivilegeStaff {
    @TableId(value = "dps_id", type = IdType.ASSIGN_ID)
    private String dpsId;
    @ApiModelProperty(value = "数据权限ID", example = "102022092831060007", required = true)
    private String dpId;
    @ApiModelProperty(value = "关联员工姓名", example = "加加", required = true)
    private String staffName;
    @ApiModelProperty(value = "关联员工ID", example = "302022081831710053", required = true)
    private String staffId;
    @ApiModelProperty(value = "关联员工小区ID", example = "2022081539020475", required = true)
    private String communityId;
    @ApiModelProperty(value = "关联员工业务ID", example = "-1", required = true)
    @TableField(fill = FieldFill.INSERT)
    private String bId;
    @ApiModelProperty(value = "创建时间")
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;
    @ApiModelProperty(value = "关联员工数据状态")
    private String statusCd;
}
