package com.zeroone.star.project.query.j5.info.communityinfo;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Pattern;

/**
 * <p>
 * 描述：数据管理——小区信息查询数据查询模型
 * </p>
 * @author yuezi
 * @version 1.0.0
 */
@ApiModel("小区信息查询模型")
@Data
public class CommunityInfoQuery extends PageQuery {

    @ApiModelProperty(value = "小区ID", example = "2023052267100146")
    private String communityId;

    @ApiModelProperty(value = "小区名称", example = "HC演示小区3")
    private String name;

    @ApiModelProperty(value = "城市编码", example = "630103")
    @Pattern(regexp = "\\d{6}", message = "城市编码必须是6位纯数字")
    private String cityCode;

}
