package com.zeroone.star.project.query.j4.orgmanager.orgmessage;

import com.zeroone.star.project.query.PageQuery;
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
@ApiModel("关联员工查询对象")
public class AssociatedStaffQuery extends PageQuery {
    //添加value信息 Altolia
    @ApiModelProperty(value = "组织ID,不是先点击组织再点击关联员工吗,组织ID就是一开始点击组织的ID",example = "102024022150736935",required = true)
    private String orgId;
    //就把value改成员工名称了 Altolia
    @ApiModelProperty(value = "员工名称",example = "维修工人")
    private String name;

}
