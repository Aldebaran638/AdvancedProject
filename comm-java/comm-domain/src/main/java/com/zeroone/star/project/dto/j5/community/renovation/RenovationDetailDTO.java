package com.zeroone.star.project.dto.j5.community.renovation;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import java.time.LocalDateTime;

/**
 * @author gaojunhao
 * @version 1.0
 * @date 2025/5/30
 */
@ApiModel("房屋装修记录详情传输模型")
@Data
public class RenovationDetailDTO {

    @ApiModelProperty(value = "房屋名称",example = "1-1-1002",required = true)
    @NotBlank(message = "房屋名称不能为空")
    private String roomName;

    @ApiModelProperty(value = "房屋id",example = "752024010438310020",required = true)
    @NotBlank(message = "房屋id不能为空")
    private String roomId;

    @ApiModelProperty(value = "图片/视频地址")
    private String url;

    @ApiModelProperty(value = "创建时间",example = "2024-02-19 21:59:48")
    private LocalDateTime createTime;

}
