package com.zeroone.star.project.query.j5.community.publicity;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * ClassName: PublicityQuery
 * Package: com.zeroone.star.project.query.j5.community.publicity
 * Description:
 *
 * @Author wuguanfengyue
 * @Create 2025/5/20 21:41
 * @Version 1.0
 */
@ApiModel("分页查询公示")
@Data
public class PublicityQuery extends PageQuery {


    @ApiModelProperty(value="公示标题", example = "测试公告")
    private String title;

    @ApiModelProperty(value="公示类型 公共收益=100 规章制度=2000 政策相关=3000", example = "1000",required = true)
    private String pubType;

    @ApiModelProperty(value="小区ID", example = "2023052267100146",required = true)
    private String communityId;
}
