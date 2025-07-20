package com.zeroone.star.project.query.j5.community.publicity;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import javax.validation.constraints.NotBlank;

/**
 * ClassName: PublicityDetailQuery
 * Package: com.zeroone.star.project.query.j5.community.publicity
 * Description:
 *
 * @Author wuguanfengyue
 * @Create 2025/5/21 12:39
 * @Version 1.0
 */

@ApiModel("分页查询公示详情")
@Data
public class PublicityDetailQuery extends PageQuery {

    @NotBlank
    @ApiModelProperty(value="公示ID", example = "102023040772260002",required = true)
    private  String pubId;

    @NotBlank
    @ApiModelProperty(value="小区id", example = "2023052267100146",required = true)
    private  String communityId;


}
