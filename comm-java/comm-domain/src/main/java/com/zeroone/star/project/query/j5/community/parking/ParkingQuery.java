package com.zeroone.star.project.query.j5.community.parking;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

@Data
@ApiModel("车位结构图传输对象")
public class ParkingQuery extends PageQuery {

    @ApiModelProperty(value = "单元id", example = "742023120517690335" , required = true)
    @NotBlank(message = "单元不能为空")
    @Pattern(regexp = "^[0-9]+$", message = "单元ID必须为数字")
    private String unitId;

    @ApiModelProperty(value = "小区id", example = "2023052267100146" , required = true)
    @NotBlank(message = "小区id不能为空")
    @Pattern(regexp = "^[0-9]+$", message = "单元ID必须为数字")
    private String communityId;

}
