package com.zeroone.star.project.dto.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：排班设置名称列表数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("排班设置名称列表数据传输对象")
public class SettingNameDTO {
    @ApiModelProperty(value = "排班ID", example = "schedule_001", required = true)
    @NotBlank(message = "排班ID不能为空")
    private String scheduleId; //排班ID

    @ApiModelProperty(value = "业务ID", example = "biz_001", required = true)
    @NotBlank(message = "业务ID不能为空")
    private String bId; //业务ID

    @ApiModelProperty(value = "班次名称", example = "早班", required = true)
    @NotBlank(message = "班次名称不能为空")
    private String name; //班次名称
}
