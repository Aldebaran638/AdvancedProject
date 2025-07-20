package com.zeroone.star.project.query.j7.parkmanage.parkinginfo;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("车位信息查询模型")
@Data
public class ParkingInfoQuery extends PageQuery {
    @ApiModelProperty(value = "停车场ID", example = "1")
    private String paId;
    @ApiModelProperty(value = "车位编号", example = "102025051554120038")
    private String num;
    @ApiModelProperty(value = "车位状态", example = "S")
    private String state;
    @ApiModelProperty(value = "车位ID", example = "792025052062720004")
    private String psId;
}
