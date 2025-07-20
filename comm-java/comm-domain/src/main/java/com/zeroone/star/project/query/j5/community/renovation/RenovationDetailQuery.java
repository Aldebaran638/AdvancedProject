package com.zeroone.star.project.query.j5.community.renovation;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

/**
 * <p>
 * 描述：房屋装修记录分页详情查询
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 天干物燥
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true)  //用于自动生成 equals() 和 hashCode() 方法时包含父类的字段
@Data
@ApiModel(value = "装修记录详情查询对象")
public class RenovationDetailQuery extends PageQuery {

    @ApiModelProperty(value = "装修跟踪记录ID",example = "172024021547940360",required = true)
    @NotBlank(message = "装修记录id不能为空")
    private String recordId;

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
