package com.zeroone.star.project.vo.j3.systemmanage.communitysetting;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

/**
 * 小区配置数据层封装
 **/
@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("获取小区配置值")
public class CommunitySettingKeyVo implements Serializable {

    private static final long serialVersionUID = 949787676153998300L;

    @ApiModelProperty(value = "名称",  example = "费用")
    private String name;

    @ApiModelProperty(value = "数据状态0正常1失效",  example = "0")
    private String statusCd = "0";

    @ApiModelProperty(value = "设置类型",  example = "2002")
    private String settingType;

}