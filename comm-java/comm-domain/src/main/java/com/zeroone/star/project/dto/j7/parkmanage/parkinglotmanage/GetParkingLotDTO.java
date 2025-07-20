package com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

@ApiModel("停车场信息")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class GetParkingLotDTO {

    @ApiModelProperty(value = "停车场id",example = "102025051959481447")
    private String pa_id;

    @ApiModelProperty(value = "停车场编号",example = "56")
    private String num;

    @ApiModelProperty(value = "停车场类型",example = "地上停车场")
    private String type;

    @ApiModelProperty(value = "外部编码",example = "1")
    private String out_num;

    @ApiModelProperty(value = "备注",example = "1")
    private String remark;

    @ApiModelProperty(value = "创建时间",example = "2025-05-20 15:37:05")
    private LocalDateTime create_time;
}
