package com.zeroone.star.project.dto.j1.menumana.menuitem;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
import org.hibernate.validator.constraints.Range;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;
import javax.validation.constraints.Size;
import java.io.Serializable;

@ToString
@Getter
@Setter
@ApiModel("添加菜单项数据传输对象")
public class AddMenuItemDTO implements Serializable {
    @NotBlank(message = "菜单组名称不能为空")
    @ApiModelProperty(value="组名称", example = "小区")
    private String groupName;

    @NotBlank
    @ApiModelProperty(value="图标", example = "fa fa-th-large")
    private String icon;

    @NotBlank
    @ApiModelProperty(value="标签", example = "TOP")
    private String label;

    @NotNull
    @ApiModelProperty(value="列序", example = "1")
    private Integer gSeq;

    @NotBlank
    @ApiModelProperty(value="组类型", example = "P_WEB")
    private String groupType;

    @ApiModelProperty(value="描述", example = "小区管理")
    private String gDescription;

    @NotBlank
    @ApiModelProperty(value="菜单名称", example = "商户管理")
    private String menuName;

    @NotBlank
    @ApiModelProperty(value="菜单地址", example = "/#/pages/frame/staff")
    private String mUrl;

    @NotNull
    @ApiModelProperty(value="列序", example = "1")
    private Integer mSeq;

    @Pattern(regexp = "Y|N", message = "状态码必须为Y或N")
    @ApiModelProperty(value="显示", example = "Y")
    private String isShow;

    @ApiModelProperty(value="描述", example = "小区管理")
    private String mDescription;

    @NotBlank
    @ApiModelProperty(value="权限名称",example = "员工信息")
    private String priName;

    @ApiModelProperty(value="权限描述",example = "员工信息")
    private String description;
    @NotBlank
    @ApiModelProperty(value="资源路径",example = "/staff")
    private String pUrl;
    @NotBlank
    @ApiModelProperty(value="商家名称",example = "运营团队")
    private String storeTypeName;
}
