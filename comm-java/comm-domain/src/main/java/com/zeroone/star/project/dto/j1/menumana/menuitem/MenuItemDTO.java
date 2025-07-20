package com.zeroone.star.project.dto.j1.menumana.menuitem;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;
import javax.validation.constraints.Size;
import java.io.Serializable;

/**
 * @Description
 * @Author eu
 * @Date 2025/5/21
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("菜单项数据对象")
public class MenuItemDTO implements Serializable {
    private static final long serialVersionUID = 1L;
    /* 菜单项编号*/
    @Pattern(regexp = "^[0-9]+$",message = "菜单ID必须是非负整数")
    @NotBlank(message = "菜单项ID不能为空")
    @Size(max=30, message = "菜单项ID长度不能超过30")
    @ApiModelProperty(value = "菜单项ID", example = "700201904001",required = true)
    private String mid;

    /* 菜单项名称*/
    @NotBlank(message = "菜单项名称不能为空")
    @Size(max=10, message = "菜单项名称长度不能超过10")
    @ApiModelProperty(value = "菜单项名称", example = "员工信息",required = true)
    private String menuName;

    /* 组名*/
    @NotBlank(message = "组名不能为空")
    @Size(max=10, message = "组名长度不能超过10")
    @ApiModelProperty(value = "组名", example = "员工管理",required = true)
    private String groupName;

    /*归属商户*/
    @NotBlank(message = "归属商户不能为空")
    @Size(max=10, message = "归属商户长度不能超过10")
    @ApiModelProperty(value = "归属商户", example = "商户",required = true)
    private String storeType;
    /*组id*/
//    @Pattern(regexp = "^[0-9]+$",message = "组ID必须是非负整数")
//    @NotBlank(message = "组ID不能为空")
//    @Size(max=30, message = "组ID长度不能超过30")
//    @ApiModelProperty(value = "组ID", example = "800201904001",required = true)
//    private String gid;

    /*访问路径*/
    @NotBlank(message = "访问路径不能为空")
    @ApiModelProperty(value = "访问路径", example = "/#/pages/frame/staff",required = true)
    private String url;

    /*权限id*/
//    @Pattern(regexp = "^[0-9]+$",message = "权限ID必须是非负整数")
//    @NotBlank(message = "权限ID不能为空")
//    @Size(max=30, message = "权限ID长度不能超过30")
//    @ApiModelProperty(value = "权限ID", example = "500201904001",required = true)
//    private String pid;

    /*描述*/
//    @NotBlank(message = "描述不能为空")
//    @ApiModelProperty(value = "描述", example = "员工信息",required = true)
//    private String description;
        @ApiModelProperty(value = "排序", example = "1",required = true)
    private Integer seq;
    /*创建时间*/
//    private String createTime;
    /*状态*/
//    @ApiModelProperty(value = "状态", example = "0",required = true)
//    private String status;
    /*是否展示*/
    @Pattern(regexp = "Y|N", message = "是否展示只能为Y或N")
    @ApiModelProperty(value = "是否展示", example = "Y",required = true)
    private String isShow;
}
