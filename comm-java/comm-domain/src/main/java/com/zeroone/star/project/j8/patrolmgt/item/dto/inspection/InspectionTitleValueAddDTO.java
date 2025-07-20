package com.zeroone.star.project.j8.patrolmgt.item.dto.inspection;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;

@Data
@Getter
@Setter
@ToString
@ApiModel("巡检项目选项DTO")
public class InspectionTitleValueAddDTO {

    @ApiModelProperty(value = "选项ID")
    private String valueId;

    @ApiModelProperty(value = "题目ID")
    private String titleId;

    @ApiModelProperty(value = "选项说明", required = true,example = "选项A")
    @NotBlank(message = "选项说明不能为空3")
    private String itemValue;

    @ApiModelProperty(value = "选项顺序", required = true)
    @NotNull(message = "选项顺序不能为空3")
    private Integer seq;

    @ApiModelProperty(value = "小区ID，必填前端不用显示，但要传值给后端", required = true,example = "2024022692080516")
    private String communityId;


}
