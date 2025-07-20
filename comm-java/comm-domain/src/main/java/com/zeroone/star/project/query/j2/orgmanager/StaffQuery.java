package com.zeroone.star.project.query.j2.orgmanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：关联员工查询数据模型
 * </p>
 *
 * @author 瓜田里犯了错
 * @version 1.0
 */

@ApiModel(description = "关联员工查询数据模型")
@Data
public class StaffQuery extends PageQuery {
    @ApiModelProperty(value = "关联员工姓名", example = "张三")
    private String staffName;
    @ApiModelProperty(value = "关联员工手机号", example = "13800000000")
    private String tel;
    @ApiModelProperty(value = "关联员工数据权限ID", example = "102022092831060007")
    private  String dpId;
}
