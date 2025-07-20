package com.zeroone.star.project.query.j7.parkmanage.parkinglotmanage;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("停车场查询条件")
public class GetParkingLotQuery extends PageQuery {

    @ApiModelProperty(value = "停车场编号",example = "1")
    private String num;

    @ApiModelProperty(value = "停车场类型",example = "1001")
    private String type_cd;


}
