package com.zeroone.star.project.vo.j3.systemmanage.communitysetting;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

/**
 * 小区相关设置数据层封装
 **/
@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("修改小区相关设置")
public class CommunitySettingVo implements Serializable {

    private static final long serialVersionUID = 949787676153998300L;

    @ApiModelProperty(value = "主键ID",  example = "362021102061720025")
    private String csId;

    @ApiModelProperty(value = "名称",  example = "收据开始编号")
    private String settingName;

    @ApiModelProperty(value = "设置值",  example = "061", required = true)
    private String settingValue;

    @ApiModelProperty(value = "备注")
    private String remark;

}