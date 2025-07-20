package com.zeroone.star.project.vo.j2.orgmanager.dataPriviledge;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


@Data
@ApiModel("关联单元显示模型")
public class RelatedUnitVO {
    @ApiModelProperty(value="楼栋编号",  example = "D")
    private String floorNum;

    @ApiModelProperty(value = "单元编号",  example = "1")
    private String unitNum;

    @ApiModelProperty(value = "主键ID",  example = "1928087619657793536")
    private String dpUnitId;

}