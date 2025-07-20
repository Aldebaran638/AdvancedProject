package com.zeroone.star.project.dto.j5.community.building;

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
@ApiModel("BusinessFloor数据传输对象")
public class BusinessFloorDTO {

    @ApiModelProperty(value = "楼编号", example = "1")
    @NotBlank(message = "楼编号不能为空")
    String floorNum;

    @ApiModelProperty(value = "楼名称", example = "1号楼")
    @NotBlank(message = "楼名称不能为空")
    String floorName;

//    @ApiModelProperty(value = "序号", example = "1")
//    String seq;

//    @ApiModelProperty(value = "所属社区编号", example = "1")
//    String communityId;

    @ApiModelProperty(value = "楼id", example = "1")
    String floorId;

    @ApiModelProperty(value = "单元")
    List<BuildingUnitDTO> buildingUnitDTOList;
}
