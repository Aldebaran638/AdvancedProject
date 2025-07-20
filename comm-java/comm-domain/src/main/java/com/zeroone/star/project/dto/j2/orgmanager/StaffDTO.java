package com.zeroone.star.project.dto.j2.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：关联员工数据传输模型
 * </p>
 *
 * @author wxs
 * @version 1.0.0
 */

@ApiModel(description = "关联员工数据传输模型")
@Data
public class StaffDTO {
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
