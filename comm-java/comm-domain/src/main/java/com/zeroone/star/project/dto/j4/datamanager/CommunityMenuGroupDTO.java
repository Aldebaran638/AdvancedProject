package com.zeroone.star.project.dto.j4.datamanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 *  小区功能
 */
@ApiModel("小区功能")
@Data
public class CommunityMenuGroupDTO {
    @ApiModelProperty(value = "小区id", example = "2022092200930358", required = true)
    private String communityId;
    @ApiModelProperty(value = "小区名称", example = "YF小区", required = true)
    private String communityName;
    @ApiModelProperty(value = "菜单组列表", required = true)
    private List<MenuGroup> menuGroups;

    @ApiModel(value = "菜单组")
    @Data
    public static class MenuGroup{
        @ApiModelProperty(value = "菜单组id", example = "800201904009", required = true)
        private String gId;
        @ApiModelProperty(value = "菜单组名称", example = "报表管理", required = true)
        private String name;
        @ApiModelProperty(value = "状态码", example = "0", required = true)
        private String statusCd;
    }
}
