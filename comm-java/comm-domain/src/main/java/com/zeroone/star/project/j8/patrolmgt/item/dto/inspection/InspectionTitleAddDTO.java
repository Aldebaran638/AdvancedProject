package com.zeroone.star.project.j8.patrolmgt.item.dto.inspection;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.Valid;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.util.List;

@Getter
@Setter
@ToString
@Data
@ApiModel("添加巡检题目")
@Valid
public class InspectionTitleAddDTO {

    @ApiModelProperty(value = "关联项目I，D必填前端不用显示，但要传值给后端", required = true, example = "102025051504330004")
    @NotBlank(message = "项目ID不能为空1")
    private String itemId ;

    @ApiModelProperty(value = "巡检题目",required = true,example = "楼道是否干净")
    @NotBlank(message = "巡检题目不能为空1")
    private String itemTitle;


    @ApiModelProperty(value = "显示顺序，显示顺序最小值为0",required = true,example = "0")
    @NotNull(message = "显示顺序不能为空1")
    @Min(value = 0,message = "显示顺序最小值为0")
    private Integer seq;
//
    @ApiModelProperty(value = "题目ID")
    private String titleId;

//
    @ApiModelProperty(value = "小区ID，必填前端不用显示，但要传值给后端", required = true,example = "2024022692080516")
    @NotBlank(message = "小区id不能为空")
    private String communityId;

    @ApiModelProperty(value = "题目类型，1001单选，2002多选，3003简答题",required = true,example = "1001")
    @NotBlank(message = "题目类型不能为空1")
    private String titleType;

    @Valid
    @ApiModelProperty(value = "选项列表(简答题可为空)")
    private List<InspectionTitleValueAddDTO> values;


}
