package com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@ApiModel("修改停车场DTO")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class UpdateParkingLotDTO {

    @ApiModelProperty(value = "停车场id",example = "102025051959481447")
    private String pa_id;

    @ApiModelProperty(value = "停车场编号",example = "56",required = true)
    private String num;

    @ApiModelProperty(value = "停车场类型",example = "1002",required = true)
    private String type;

    @ApiModelProperty(value = "外部编码",example = "1",required = false)
    private String out_num;

    @ApiModelProperty(value = "备注",example = "1",required = false)
    private String remark;

}
