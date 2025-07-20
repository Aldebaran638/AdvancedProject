package com.zeroone.star.project.dto.j2.orgmanager.dataPrivilege;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 添加关联单元模型
 * @author 噤玥
 * @version 1.0.0
 */
@Data
@ApiModel(value = "添加关联单元模型")
public class RelatedUnitAddDTO {
    @ApiModelProperty(value="楼栋编号",  example = "D", required = true)
    private String floorNum;

    @ApiModelProperty(value = "单元编号",  example = "1", required = true)
    private String unitNum;

    @ApiModelProperty(value = "数据权限ID",example = "102022122028720443",  required = true)
    private String dpId;

}
