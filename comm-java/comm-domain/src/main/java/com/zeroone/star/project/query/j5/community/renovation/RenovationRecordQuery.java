package com.zeroone.star.project.query.j5.community.renovation;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

/**
 * <p>
 * 描述：房屋装修记录分页查询
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 天干物燥
 * @version 1.0.0
 */
@Data
@ApiModel(description = "房屋装修记录分页查询")
public class RenovationRecordQuery extends PageQuery {

    @ApiModelProperty(value = "装修id",example = "172024021592960348",required = true)
    @NotBlank(message = "装修id不能为空")
    private String renovationId;

    @ApiModelProperty(value = "房屋id",example = "752024010438310020",required = true)
    @NotBlank(message = "房屋id不能为空")
    private String roomId;

    @ApiModelProperty(value = "房屋名称",example = "1-1-1002",required = true)
    @NotBlank(message = "房屋名称不能为空")
    private String roomName;

    @ApiModelProperty(value = "小区id",example = "2023052267100146",required = true)
    @NotBlank(message = "小区id不能为空")
    private String communityId;

}
