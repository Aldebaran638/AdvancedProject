package com.zeroone.star.project.dto.j5.community.building;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;

@Getter
@Setter
@ToString
@ApiModel("BuildingOwner数据传输对象")
public class BuildingOwnerDTO {
    @ApiModelProperty(value = "业主ID", example = "772024021975893605")
    @NotBlank(message = "业主ID不能为空")
    String ownerId;

    @ApiModelProperty(value = "业主名字", example = "张三")
    @NotBlank(message = "业主名字不能为空")
    String ownerName;

}
