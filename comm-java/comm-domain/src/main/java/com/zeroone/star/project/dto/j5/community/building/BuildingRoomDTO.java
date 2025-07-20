package com.zeroone.star.project.dto.j5.community.building;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.math.BigDecimal;

@Getter
@Setter
@ToString
@ApiModel("BuildingRoom数据传输对象")
public class BuildingRoomDTO {

    @ApiModelProperty(value = "房间ID", example = "752025051440581138")
    @NotBlank(message = "房间ID不能为空")
    String roomId;

    @ApiModelProperty(value = "房间编号", example = "1001")
    @NotBlank(message = "房间编号不能为空")
    String roomNum;


    @ApiModelProperty(value = "楼层", example = "1")
    @NotBlank(message = "楼层不能为空")
    String layer;


    @ApiModelProperty(value = "状态", example = "2002")
    @NotBlank(message = "状态不能为空")
    String state;


    @ApiModelProperty(value = "社区ID", example = "2025041251140067")
    @NotBlank(message = "社区ID不能为空")
    String communityId;

    @ApiModelProperty(value = "单元id", example = "742025051425621137")
    @NotBlank(message = "单元id不能为空")
    String unitId;
}
