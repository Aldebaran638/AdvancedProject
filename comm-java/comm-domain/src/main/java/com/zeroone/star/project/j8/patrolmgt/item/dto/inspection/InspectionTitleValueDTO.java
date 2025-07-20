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
public class InspectionTitleValueDTO extends InspectionTitleValueAddDTO{

    @ApiModelProperty(value = "题目ID,必填前端不用显示，但要传值给后端", required = true,example = "1930243903590158338")
    private String titleId;



}
