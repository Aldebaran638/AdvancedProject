package com.zeroone.star.project.dto.j2.orgmanager.rolePermission;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("员工列表传输数据模型")
public class EmpListDTO {
    @ApiModelProperty(value ="主键ID",required = true)
    private String id;
    @ApiModelProperty(value ="用户ID",required = true)
    private String userId;
    @ApiModelProperty(value ="名称",required = true)
    private String name;
    @ApiModelProperty(value ="手机号",required = true)
    private String tel;
    @ApiModelProperty(value ="邮箱")
    private String email;
    @ApiModelProperty(value ="地址")
    private String address;
    @ApiModelProperty(value ="性别")
    private String sex;

}
