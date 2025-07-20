package com.zeroone.star.project.dto.j3.systemmanage.systemconfig;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.io.Serializable;


@Getter
@Setter
@ToString
@ApiModel("系统配置修改数据对象")
public class SystemInfoDTO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "静态url", example = "http://mallapp.homecommunity.cn")
    private String imgUrl;

    @ApiModelProperty(value = "业主标题", example = "HC智慧家园")
    private String ownerTitle;

    @ApiModelProperty(value = "默认小区编号", example = "2023052267100146")
    private String defaultCommunityId;

    @ApiModelProperty(value = "标题名称", example = "HC小区管理系统")
    private String systemTitle;

    @ApiModelProperty(value = "简写标题", example = "HC")
    private String systemSimpleTitle;

    @ApiModelProperty(value = "qq地图key", example = "123123")
    private String qqMapKey;

    @ApiModelProperty(value = "副标题", example = "智慧物业系统")
    private String subSystemTitle;

    @ApiModelProperty(value = "公司名称", example = "java110团队")
    private String companyName;

    @ApiModelProperty(value = "商城地址", example = "http://mallapp.homecommunity.cn")
    private String mallUrl;

    @ApiModelProperty(value = "Logo地址", example = "/img/logo.png")
    private String logoUrl;

    @ApiModelProperty(value = "物业手机标题", example = "HC掌上物业")
    private String propertyTitle;
}
