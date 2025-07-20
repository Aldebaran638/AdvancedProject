package com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("修改巡检路线巡检点信息")
@Data
public class RoutePointRelModifyImagesDTO {

    @ApiModelProperty(value = "巡检路线id",  example = "502025052939550002" , required = true )
    private  String inspectionRouteId;//巡检路线
    @ApiModelProperty(value = "巡检点id",  example = "132025051679800029" , required = true )
    private  String inspectionId;//巡检点id
    @ApiModelProperty(value = "巡检点开始的时间",example = "06:30",required = true)
    private String pointStartTime;//巡检点开始时间
    @ApiModelProperty(value = "巡检点结束时间",example = "12:30",required = true)


    private String pointEndTime;//巡检点结束时间
    @ApiModelProperty(value = "排序",example = "1",required = true)
    private String sortNumber;//排序



}
