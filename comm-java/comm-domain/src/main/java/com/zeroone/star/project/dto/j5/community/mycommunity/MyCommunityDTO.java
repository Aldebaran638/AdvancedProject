package com.zeroone.star.project.dto.j5.community.mycommunity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.validation.annotation.Validated;

import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;
import javax.validation.constraints.Size;
import java.math.BigDecimal;

@Data
@ApiModel("修改我的小区数据模型")
public class MyCommunityDTO {
    @ApiModelProperty(value = "小区id",example = "2023052267100146",required = true)
    @NotNull(message = "小区ID不能为空")
    private String communityId;
    @ApiModelProperty(value = "客服电话",example = "18909711443")
    @Pattern(regexp = "^1(3|4|5|7|8)\\d{9}$", message = "手机号码格式错误")
    private String tel;
    @ApiModelProperty(value = "小区面积",example = "0.00")
    private BigDecimal communityArea;
    @ApiModelProperty(value = "客服二维码",example = "http://192.168.88.135:8888/group1/M00/00/00/oYYBAGg3uneAF2b1ABlDoPCCwso590.jpg?token=01028c66161ea1f19bb87cfc25bb4d23&ts=1748482679")
    private String qrCode;
}
