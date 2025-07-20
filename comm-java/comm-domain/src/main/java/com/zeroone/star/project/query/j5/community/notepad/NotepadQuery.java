package com.zeroone.star.project.query.j5.community.notepad;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
/**
 * <p>
 * 描述：查询业主反馈的参数
 * </p>
 * @author 人间理想
 * @since 2021-08-06
 */
@ApiModel("分页查询业主反馈")
@Data
public class NotepadQuery extends PageQuery {

    @ApiModelProperty(value="类型",example = "1")
    private String noteType;

    @ApiModelProperty(value="状态(W,跟进中),(F,完成),(如果有第三方id,(跟进中 (已转报修单)))",example = "W")
    private String state;

    @ApiModelProperty(value="创建人",example = "wuxw")
    private String createUserName;

    @ApiModelProperty(value = "业主id",example = "772022082070860017",required = true)
    private String objId;

    @ApiModelProperty(value = "业主名称",example = "张杰")
    private String objName;

    @ApiModelProperty(value = "小区CommunityId",example = "2025041251140067",required = true)
    private String communityId;

}
