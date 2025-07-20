package com.zeroone.star.project.dto.j5.community.renovation;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.lang.NonNull;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;
import java.util.List;

/**
 * <p>
 * 描述：添加房屋装修记录模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 天干物燥
 * @version 1.0.0
 */
@ApiModel("添加房屋装修记录模型")
@Data
public class AddRenovationRecordDTO {
    @ApiModelProperty(value = "装修id",example = "172024021839912170",required = true)
    @NotBlank(message = "装修id不能为空")
    private String renovationId;

    @ApiModelProperty(value = "房屋id",example = "752024010438310020",required = true)
    @NotBlank(message = "房屋id不能为空")
    private String roomId;

    @ApiModelProperty(value = "房屋名称",example = "1-1-1002",required = true)
    @NotBlank(message = "房屋名称不能为空")
    private String roomName;

    @ApiModelProperty(value = "小区id",example = "2023052267100146",required = true)
    @NotBlank(message = "小区id不能为空")
    private String communityId;

    @ApiModelProperty(value = "状态(1000-待审核 2000-审核不通过 3000-装修中 4000-待验收 5000-验收成功 6000-验收失败)",example = "3000",required = true)
    @NotBlank(message = "状态不能为空")
    @Pattern(regexp = "^(1000|2000|3000|4000|5000|6000)$",message = "状态只能是1000、2000...6000")
    private String state;

    @ApiModelProperty(value = "备注",example = "请准备XX材料至物业处填报")
    private String remark;

    @ApiModelProperty(value = "是否违规(true-是,false-否)",example = "true",required = true)
    @NotBlank(message = "是否违规不能为空")
    private String isViolation;

    @ApiModelProperty(value = "图片地址")
    private List<String> imgUrls;

    @ApiModelProperty(value = "视频地址")
    private List<String> videoUrls;
}
