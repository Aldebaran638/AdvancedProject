package com.zeroone.star.project.query.j4.orgmanager.orgmessage;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：获取组织员工列表
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Altlia
 * @version 1.0.0
 */
@Data
@ToString
@Setter
@Getter
@ApiModel("组织员工信息查询对象")
public class OrgStaffQuery extends PageQuery {

    @ApiModelProperty(value = "组织ID",example = "84202305221014333415000178",required = true)
    private String orgId;

    @ApiModelProperty(value = "用户名称",example = "阿姨")
    private String name;
}
