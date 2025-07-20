package com.zeroone.star.project.dto.j5.community.renovation;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.Future;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.time.LocalDateTime;

/**
 * @className: RenovationAddDTO
 * @author: powfu
 * @date: 19/5/2025 下午9:14
 * @Version: 1.0
 * @description: 添加装修数据传输对象
 */
@Data
@ApiModel("添加装修模型")
public class RenovationAddDTO {
    @ApiModelProperty(value = "主键id", example = "172021092826300043", required = true)
    @NotBlank(message = "装修id不能为空")
    @JsonProperty("rId")
    private String rId;
    @ApiModelProperty(value = "小区id", example = "2023052267100146", required = true)
    @NotBlank(message = "小区id不能为空")
    private String communityId;
    @ApiModelProperty(value = "房屋id", example = "752021012579820036", required = true)
    @NotBlank(message = "房屋id不能为空")
    private String roomId;
    @ApiModelProperty(value = "房屋名称", example = "1-1-1021", required = true)
    @NotBlank(message = "房屋名称不能为空")
    private String roomName;
    @ApiModelProperty(value = "联系人", example = "朽木玲子", required = true)
    @NotBlank(message = "联系人不能为空")
    private String personName;
    @ApiModelProperty(value = "联系电话", example = "12333333333", required = true)
    @NotBlank(message = "联系电话不能为空")
    private String personTel;
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "装修开始时间", example = "2021-05-17 00:00:00", required = true)
    @NotNull(message = "装修开始时间不能为空")
    @Future(message = "装修开始时间只接受未来")
    private LocalDateTime startTime;
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "装修结束时间", example = "2021-12-19 23:59:59", required = true)
    @NotNull(message = "装修结束时间不能为空")
    @Future(message = "装修结束时间只接收未来")
    private LocalDateTime endTime;
    @ApiModelProperty(value = "装修单位", example = "chd装修大队", required = true)
    @NotBlank(message = "装修单位不能为空")
    private String renovationCompany;
    @ApiModelProperty(value = "装修负责人", example = "汤米谢尔比", required = true)
    @NotBlank(message = "装修负责人不能为空")
    private String personMain;
    @ApiModelProperty(value = "装修负责人联系电话", example = "18999999999", required = true)
    @NotBlank(message = "装修负责人电话不能为空")
    private String personMainTel;
    @ApiModelProperty(value = "备注", example = "这是备注")
    private String remark;
}
