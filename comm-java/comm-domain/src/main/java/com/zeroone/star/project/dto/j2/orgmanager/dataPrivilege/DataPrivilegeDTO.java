package com.zeroone.star.project.dto.j2.orgmanager.dataPrivilege;


import com.zeroone.star.project.dto.j2.orgmanager.DataPrivilegeAddDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：数据权限数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author hubery
 * @version 1.0.0
 */
@Data
@ApiModel("数据权限数据传输对象")
public class DataPrivilegeDTO extends DataPrivilegeAddDTO {

    @ApiModelProperty(value = "数据权限编号",example = "11111111111",required = true)
    private String dpId;

}
