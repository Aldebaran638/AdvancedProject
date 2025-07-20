package com.zeroone.star.project.dto.j5.community.building;

import com.zeroone.star.project.vo.j5.community.building.BuildingRoomVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;
import java.util.List;

@Getter
@Setter
@ToString
@ApiModel("BuildingUnit数据传输对象")
public class BuildingUnitDTO {
    @ApiModelProperty(value = "单元id", example = "742023120517690335")
    @NotBlank(message = "单元id不能为空")
    String unitId;

    @ApiModelProperty(value = "单元编号", example = "1")
    @NotBlank(message = "单元编号不能为空")
    String unitNum;

    @ApiModelProperty(value = "楼id", example = "732023120568080332")
    @NotBlank(message = "楼id不能为空")
    String floorId;

    @ApiModelProperty(value = "房子")
    List<BuildingRoomVO> buildingRoomVOList;
}
