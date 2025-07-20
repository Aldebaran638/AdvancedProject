package com.zeroone.star.project.query.j5.community.notepad;


import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

@ApiModel("查询该小区可以报修类型Query")
@Data
public class RepairTypeQuery extends PageQuery {


    @ApiModelProperty(value = "社区id" , example = "2023052267100146" ,required = true)
    @NotBlank(message = "社区id不能为空")
    private String communityId;
    @ApiModelProperty(value = "是否公共区 T为是 F为否" , example = "F" ,required = true)
    @NotBlank( message = "区域类型不能为空")
    private String publicArea;

}
