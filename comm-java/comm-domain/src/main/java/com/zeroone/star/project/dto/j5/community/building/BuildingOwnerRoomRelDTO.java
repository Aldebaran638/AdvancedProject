package com.zeroone.star.project.dto.j5.community.building;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
@ApiModel("BuildingOwnerRoomRel数据传输对象")
public class BuildingOwnerRoomRelDTO {
    @ApiModelProperty(value = "业主ID", example = "772025051466271142")
    String ownerId;
}
