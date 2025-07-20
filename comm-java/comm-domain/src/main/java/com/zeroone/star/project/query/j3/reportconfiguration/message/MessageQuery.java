package com.zeroone.star.project.query.j3.reportconfiguration.message;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("报表信息查询条件")
public class MessageQuery extends PageQuery {

    @ApiModelProperty(value = "报表编号", example = "1020211112807918355")
    private String customId;

    @ApiModelProperty(value = "组编号", example = "102021111007300001")
    private String groupId;

    @ApiModelProperty(value = "选项标题", example = "报修分项表")
    private String title;

}
