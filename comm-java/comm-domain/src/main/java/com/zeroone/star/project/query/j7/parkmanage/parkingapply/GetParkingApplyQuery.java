package com.zeroone.star.project.query.j7.parkmanage.parkingapply;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("获取申请列表查询模型")
@Data
public class GetParkingApplyQuery extends PageQuery {
    @ApiModelProperty(value = "申请id", example = "102024022231540412")
    private String id;

    @ApiModelProperty(value = "车辆品牌", example = "宝马")
    private String carBrand;


    @ApiModelProperty(value = "申请人名称", example = "成龙")
    private String applyPersonName;


}
