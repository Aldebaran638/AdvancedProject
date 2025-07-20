package com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

@ApiModel("添加停车场DTO")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class InsertParkingLotDTO {

    @ApiModelProperty(value = "停车场编号",example = "56",required = true)
    private String num;

    @ApiModelProperty(value = "停车场类型",example = "1001",required = true)
    private String type;

    @ApiModelProperty(value = "外部编码",example = "1",required = false)
    private String out_num;

    @ApiModelProperty(value = "备注",example = "1",required = false)
    private String remark;

    @ApiModelProperty(value = "小区id",required = true)
    private String communityId;

}


