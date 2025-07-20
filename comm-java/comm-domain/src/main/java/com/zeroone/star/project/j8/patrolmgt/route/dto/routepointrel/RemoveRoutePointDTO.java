package com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("删除巡检路线巡检点")
@Data
public class RemoveRoutePointDTO {
    @ApiModelProperty(value = "巡检路线id",  example = "502025052939550002" , required = true )
    private  String inspectionRouteId;//巡检路线
    @ApiModelProperty(value = "巡检点id",  example = "132025051679800029" , required = true )
    private  String inspectionId;//巡检点id
}
