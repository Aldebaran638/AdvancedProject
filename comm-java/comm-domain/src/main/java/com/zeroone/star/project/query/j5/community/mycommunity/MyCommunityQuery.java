package com.zeroone.star.project.query.j5.community.mycommunity;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotNull;
import java.io.Serializable;

@Data
@ApiModel("查询单个我的小区查询参数")
public class MyCommunityQuery extends PageQuery {
    @ApiModelProperty(value = "小区id",example = "2023052267100146",required = true)
    @NotNull(message = "小区ID不能为空")
    private String communityId;
}
