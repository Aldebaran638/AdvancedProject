package com.zeroone.star.project.dto.j2.orgmanager;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：添加数据权限数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author hubery
 * @version 1.0.0
 */
@Data
@ApiModel("添加数据权限数据传输对象")
public class DataPrivilegeAddDTO {
    @ApiModelProperty(value = "小区id",example = "123456",required = true)
    private String communityId;
    @ApiModelProperty(value = "名称",example = "测试数据权限",required = true)
    private String name;
    @ApiModelProperty(value = "编号",example = "111111",required = true)
    private String code;
    @ApiModelProperty(value = "备注",example = "测试",required = true)
    private String remark;
}
