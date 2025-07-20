package com.zeroone.star.project.query.j5.community.building;


import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

@Data
@ApiModel("房间结构图传输对象")
public class BuildingRoomQuery extends PageQuery {
    @ApiModelProperty(value = "单元id", example = "742023120517690335", required = true)
    @Pattern(regexp = "^[0-9]*$", message = "单元id格式错误,只能是纯数字")
    @NotBlank(message = "单元不能为空")
    private String unitId;

    @ApiModelProperty(value = "小区id", example = "2023052267100146", required = true)
    @Pattern(regexp = "^[0-9]*$", message = "小区id格式错误,只能是纯数字")
    @NotBlank(message = "小区id不能为空")
    private String communityId;

}
