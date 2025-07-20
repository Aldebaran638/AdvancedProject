package com.zeroone.star.project.vo.j2.orgmanager.functionAuth;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import java.util.ArrayList;
import java.util.List;


@ApiModel("返回菜单名称树对象")
@Data
@NoArgsConstructor
@AllArgsConstructor

public class GetMenuTreeVO {

    @ApiModelProperty(value = "菜单ID", example = "7002019040001")
    private String mId;

    @ApiModelProperty(value = "菜单名称", example = "员工信息")
    private String name;

    @ApiModelProperty(value = "权限ID", example = "5002019040001")
    private String pId;

    @ApiModelProperty(value = "菜单组ID", example = "8002019040001")
    private String gId;

    @ApiModelProperty(value = "菜单URL", example = "/admin.html#/staff")
    private String url;

    @ApiModelProperty(value = "排序", example = "2")
    private Integer seq;


    @ApiModelProperty(value = "创建时间", example = "2019-04-01 02:19:51")
    private String createTime;


    @ApiModelProperty(value = "是否显示（Y=显示，N=不显示）", example = "Y")
    private String isShow;

    @ApiModelProperty(value = "子菜单", example = "--")
    private List<GetMenuTreeVO> children;
}


