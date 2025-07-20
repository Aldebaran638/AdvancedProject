package com.zeroone.star.project.j8.patrolmgt.point.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;


@ApiModel("巡检路线巡检点数据传输模型")
@AllArgsConstructor
@NoArgsConstructor
@Data
public class RoutePointDTO {
    @ApiModelProperty(value = "巡检点id", example = "132025051993040006")
    String inspectionId;
    @ApiModelProperty(value = "巡检点名称", example = "教学楼")
    String inspectionName;
    @ApiModelProperty(value = "巡检点类型", example = "环境巡检")
    //1001 设备巡检，2002 环境巡检
    String pointObjType;
    @ApiModelProperty(value = "巡检位置", example = "a1")
    String pointObjName;
    @ApiModelProperty(value = "开始时间", example = "1")
    Date pointStartTime;
    @ApiModelProperty(value = "结束时间", example = "1")
    Date pointEndTime;

}
