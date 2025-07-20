package com.zeroone.star.project.dto.j7.parkmanage.parkinginfo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("批量添加车位")
@Data
public class BatchAddParkingSpacesDTO {
    @ApiModelProperty(value = "编号前缀", example = "A")
    private String numberPrefix;
    @ApiModelProperty(value = "开始编号", example = "1", required = true)
    private Integer startNumber;
    @ApiModelProperty(value = "结束编号", example = "9", required = true)
    private Integer endNumber;
    @ApiModelProperty(value = "停车场ID", example = "102025051554120038", required = true)
    private String paId;
    @ApiModelProperty(value = "车位类型", example = "1", required = true)
    private String parkingType;

}
