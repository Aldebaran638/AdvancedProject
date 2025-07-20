package com.zeroone.star.project.dto.j1.menumana.menuitem;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.hibernate.validator.constraints.Range;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;
import javax.validation.constraints.Size;
import java.io.Serializable;

/**
 * @Description
 * @Author eu
 * @Date 2025/5/21
 */
@Data
@ApiModel("修改菜单项数据传输对象")
public class ModifyMenuItemDTO implements Serializable {
//    /* 菜单项编号*/
//    @Pattern(regexp = "^[0-9]+$",message = "菜单项ID必须是非负整数")
//    @NotBlank(message = "菜单项ID不能为空")
//    @Size(max=30, message = "菜单项ID长度不能超过30")
//    @ApiModelProperty(value = "菜单项ID", example = "700201904001",required = true)
//    private String mid;

    /* 菜单项名称*/
    @NotBlank(message = "菜单项名称不能为空")
    @Size(max=10, message = "菜单项名称长度不能超过10")
    @ApiModelProperty(value = "菜单项名称", example = "员工信息",required = true)
    private String name;

//    /*组id*/
//    @Pattern(regexp = "^[0-9]+$",message = "组ID必须是非负整数")
//    @NotBlank(message = "组ID不能为空")
//    @Size(max=30, message = "组ID长度不能超过30")
//    @ApiModelProperty(value = "组ID", example = "800201904001",required = true)
//    private String gid;

    /*访问路径*/
    @NotBlank(message = "访问路径不能为空")
    @ApiModelProperty(value = "访问路径", example = "/#/pages/frame/staff",required = true)
    private String url;

//    /*权限id*/
//    @Pattern(regexp = "^[0-9]+$",message = "权限ID必须是非负整数")
//    @NotBlank(message = "权限ID不能为空")
//    @Size(max=30, message = "权限ID长度不能超过30")
//    @ApiModelProperty(value = "权限ID", example = "500201904001",required = true)
//    private String pid;

    /*描述*/
    @NotBlank(message = "描述不能为空")
    @ApiModelProperty(value = "描述", example = "员工信息",required = true)
    private String description;

    /*排序*/
    @NotNull(message = "排序ID不能为空")
    @Range(min=1,message = "排序ID最小值为1")
    @ApiModelProperty(value = "排序ID", example = "1",required = true)
    private Integer seq;

//    /*状态*/
//    @Pattern(regexp = "0|1", message = "状态只能为0或1")
//     @ApiModelProperty(value = "状态", example = "0",required = true)
//    private String status;
    /*是否展示*/
    @Pattern(regexp = "Y|N", message = "是否展示只能为Y或N")
    @ApiModelProperty(value = "是否展示", example = "Y",required = true)
    private String isShow;
}
