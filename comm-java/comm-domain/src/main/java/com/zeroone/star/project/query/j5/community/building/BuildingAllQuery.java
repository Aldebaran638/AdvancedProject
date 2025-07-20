package com.zeroone.star.project.query.j5.community.building;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

@Data
@ApiModel("小区房子结构图查询对象")
public class BuildingAllQuery {
    @ApiModelProperty(value = "小区id", example = "2023052267100146", required = true)
    @Pattern(regexp = "^[0-9]*$", message = "小区id格式错误,只能是纯数字")
    @NotBlank(message = "小区id不能为空")
    String communityId;
}
