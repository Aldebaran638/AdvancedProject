package com.zeroone.star.project.query.j2.orgmanager.dataPrivilege;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
/**
 * 分页查询楼栋单元
 * @author 噤玥
 * @version 1.0.0
 */
@ApiModel(value = "楼栋单元查询模型")
@Data
public class RelatedUnitQuery extends PageQuery {
    @ApiModelProperty(value = "数据状态",example = "0")
    String statusCd="0";
    @ApiModelProperty(value = "数据权限",example = "102025051938291445",required = true)
    String dpId;
}