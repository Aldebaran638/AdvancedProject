package com.zeroone.star.project.dto.j5.community.renovation;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import java.time.LocalDateTime;

/**
 * @className: RenovationDTO
 * @author: powfu
 * @date: 19/5/2025 下午9:39
 * @Version: 1.0
 * @description: 装修数据传输对象
 */
@Data
@ApiModel("装修模型")
public class RenovationDTO extends RenovationAddDTO{
    @ApiModelProperty(value = "状态", example = "待审核 审核不通过 装修中 待验收 验收成功 验收失败", required = true)  //1000 待审核 2000 审核不通过 3000 装修中 4000 待验收 5000 验收成功 6000 验收失败
    @NotBlank(message = "状态必填,不能为空")
    private String state;
    @ApiModelProperty(value = "是否违规", example = "是", required = true)  //Y违规 N正常
    @NotBlank(message = "是否违规必填,不能为空")
    private String isViolation;
    @ApiModelProperty(value = "违规说明", example = "这是违规说明")
    private String violationDesc;
    @ApiModelProperty(value = "是否延期", example = "否", required = true)  //Y延期 N正常
    @NotBlank(message = "是否延期必填,不能为空")
    private String isPostpone;
    @ApiModelProperty(value = "延期时间", example = "2021-11-30")
    private String postponeTime;
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "创建时间/申请时间", example = "2021-06-03 13:17:39")
    private LocalDateTime createTime;
}
