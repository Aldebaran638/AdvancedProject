package com.zeroone.star.project.query.j5.info.communityinfo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

/**
 * <p>
 * 描述：数据管理——城市地名列表查询接口模型
 * </p>
 * @author yuezi
 * @version 1.0.0
 */
@ApiModel("城市地名列表查询接口模型")
@Data
public class CityAreaQuery {

    @ApiModelProperty(value = "需要获取的区域级别，101 省级 202 市州 303 区县", example = "202")
    @Pattern(regexp = "^(101|202|303)$", message = "查询的区域级别参数必须为101或202或303（省 市 区）")
    @NotBlank(message = "需要获取的区域级别不能为空")
    private String areaLevel;

    @ApiModelProperty(value = "需要获取的区域的父级城市编码，省级的父级为0", example = "120000")
    @Pattern(regexp = "^(\\d{6}|0)$", message = "查询的区域的父级城市编码必须是6位纯数字或0")
    @NotBlank(message = "查询的区域的父级城市编码不能为空")
    private String parentAreaCode;
}
