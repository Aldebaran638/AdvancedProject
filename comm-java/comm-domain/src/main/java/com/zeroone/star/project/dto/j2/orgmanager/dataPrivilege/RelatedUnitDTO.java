package com.zeroone.star.project.dto.j2.orgmanager.dataPrivilege;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;



@Data
@ApiModel("关联单元传输模型")
public class RelatedUnitDTO {
    @ApiModelProperty(value = "单元ID",  example = "742022082058950007")
    String unitId;
    @ApiModelProperty(value="楼栋编号",  example = "D", required = true)
    private String floorNum;

    @ApiModelProperty(value = "单元编号",  example = "1", required = true)
    private String unitNum;

    private String floorId;

    @ApiModelProperty(value = "数据权限ID",example = "102022122028720443",  required = true)
    private String dpId;

    private String statusCd;

    private String createTime;

    private String communityId;

    private String bId;

    private String dpUnitId;
}
