package com.zeroone.star.project.dto.j5.info.communityinfo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.DecimalMin;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;
import java.math.BigDecimal;

@ApiModel("添加小区模型")
@Data
public class AddCommunityDTO {
    @ApiModelProperty(value = "小区名称", example = "xx小区", required = true)
    @NotBlank(message = "小区名称不能为空")
    private String name;

    @ApiModelProperty(value = "城市编码", example = "110102", required = true)
    @Pattern(regexp = "\\d{6}", message = "城市编码必须是6位纯数字")
    @NotBlank(message = "城市编码不能为空")
    private String cityCode;

    @ApiModelProperty(value = "小区地址", example = "北京省北京市西城区北石槽镇阳光花园", required = true)
    @NotBlank(message = "小区地址不能为空")
    private String address;

    @ApiModelProperty(value = "附近地标", example = "东方明珠", required = true)
    @NotBlank(message = "附近地标不能为空")
    private String nearbyLandmarks;

    @ApiModelProperty(value = "客服电话", example = "12345678901", required = true)
    @NotBlank(message = "客服电话不能为空")
    private String tel;

    @ApiModelProperty(value = "缴费周期", example = "12", required = true)
    @NotNull(message = "缴费周期不能为空")
    private Long payFeeMonth;

    @ApiModelProperty(value = "每月单价", example = "0.00", required = true)
    @NotNull(message = "每月单价不能为空")
    @DecimalMin(value = "0.0", message = "单价不能为负数")
    private BigDecimal feePrice;

    @ApiModelProperty(value = "社区编码", example = "221221", required = true)
    @NotBlank(message = "社区编码不能为空")
    private String value;
}
