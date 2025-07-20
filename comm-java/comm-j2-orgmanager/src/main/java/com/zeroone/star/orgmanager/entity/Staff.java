package com.zeroone.star.orgmanager.entity;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
@Data
public class Staff {
    @ApiModelProperty(value = "关联员工姓名", example = "张三", required = true)
    private String staffName;
    @ApiModelProperty(value = "关联员工手机号", example = "13800000000", required = true)
    private String tel;
    @ApiModelProperty(value = "关联员工邮箱", example = "zhangsan@zeroone.com", required = true)
    private String email;
    @ApiModelProperty(value = "关联员工地址", example = "上海市浦东新区", required = true)
    private String address;
    @ApiModelProperty(value = "关联员工性别", example = "1", required = true)
    private Integer sex;
}