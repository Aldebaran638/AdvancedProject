package com.zeroone.star.project.query.j4.orgmanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Author:zzw3867
 */
@ApiModel("班次查询对象")
@Data
public class ShiftSettingQuery extends PageQuery {
    @ApiModelProperty(value = "班次名称(可模糊)", example = "早班1")
    private String name;
}
