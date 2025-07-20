package com.zeroone.star.project.query.j4.orgmanager.orgmessage;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;
/**
 * <p>
 * 描述：获取组织名称树
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Alisa
 * @version 1.0.0
 */
@Data
@ToString
@Setter
@Getter
@ApiModel("组织名称树")

public class OrganizationQuery extends PageQuery{
    @ApiModelProperty(value = "组织id", example = "742023120517690335")
    @NotBlank(message = "组织名" +
            "称不能为空")
    private String orgId;
}


