package com.zeroone.star.project.dto.j5.community.building;

import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.List;

@Getter
@Setter
@ToString
public class BuildingStructureRoomDTO {

    @ApiModelProperty(value = "所属社区编号", example = "1")
    String communityId;

    @ApiModelProperty(value = "所属社区楼栋信息")
    List<BusinessFloorDTO> businessFloorDTOList;
}
