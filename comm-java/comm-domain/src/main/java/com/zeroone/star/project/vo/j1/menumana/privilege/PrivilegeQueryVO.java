package com.zeroone.star.project.vo.j1.menumana.privilege;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

/**
 \* @author cv 
 \* Time: 2025/5/23 + 10:47
 \* Description: 
 \*/

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel(value = "权限查询返回参数")
public class PrivilegeQueryVO extends JsonVO {
    @ApiModelProperty(value="权限ID",example = "500201904001")
    private String pId;
    @ApiModelProperty(value="权限名称",example = "员工信息")
    private String name;
    @ApiModelProperty(value="权限描述",example = "员工信息")
    private String description;
    @ApiModelProperty(value="资源路径",example = "/staff")
    private String resource;
    @ApiModelProperty(value="商户ID",example = "80090000003")
    private String domain;
    @ApiModelProperty(value="商家名称",example = "运营团队")
    private String storeTypeName;
    @ApiModelProperty(value="创建时间",example = "2019-04-01 10:24:53")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime createTime;

}
