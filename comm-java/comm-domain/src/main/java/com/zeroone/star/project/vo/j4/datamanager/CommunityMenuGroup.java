package com.zeroone.star.project.vo.j4.datamanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 展示小区功能
 * @author: 玺朽
 */
@ApiModel("小区功能菜单组")
@Data
public class CommunityMenuGroup {
        @ApiModelProperty(value = "菜单组id", example = "800201904009", required = true)
        private String gId;
        @ApiModelProperty(value = "菜单组名称", example = "报表管理", required = true)
        private String name;
        @ApiModelProperty(value = "状态码", example = "0", required = true)
        private String statusCd;

}
