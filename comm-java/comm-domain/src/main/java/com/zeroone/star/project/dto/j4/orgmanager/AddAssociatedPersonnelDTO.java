package com.zeroone.star.project.dto.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotNull;

import java.util.Date;


@ApiModel("添加关联员工")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class AddAssociatedPersonnelDTO {

    @NotNull(message = "班次ID不能为空")
    @ApiModelProperty(value = "班次ID", required = true, example = "426614174001")
    private String scheduleId;

    @NotNull(message = "员工ID不能为空")
    @ApiModelProperty(value = "员工ID", required = true, example = "426614174002")
    private String staffId;

    @NotNull(message = "员工姓名不能为空")
    @ApiModelProperty(value = "员工姓名", required = true, example = "张三")
    private String staffName;

    @NotNull(message = "组织ID不能为空")
    @ApiModelProperty(value = "组织ID", required = true, example = "426614174003")
    private String storeId;

    @ApiModelProperty(value = "状态", example = "1", notes = "0-无效，1-有效")
    private Integer statusCd;

    @ApiModelProperty(value = "创建时间", example = "2023-10-01 12:00:00")
    private Date createTime;
}
