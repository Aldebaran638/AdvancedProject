package com.zeroone.star.project.query.j2.orgmanager.dataPrivilege;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel(value = "未关联单元查询模型")
public class NoRelatedUnitQuery extends RelatedUnitQuery{
    @ApiModelProperty(value = "楼栋编号",example = "1",required = true)
    String floorNum;
    @ApiModelProperty(value = "单元编号",example = "1",required = true)
    String unitNum;
    @ApiModelProperty(value = "小区ID",example = "2024022692080516")
    String communityId;

}
