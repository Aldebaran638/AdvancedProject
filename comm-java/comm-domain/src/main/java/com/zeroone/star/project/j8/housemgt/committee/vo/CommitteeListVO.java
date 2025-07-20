package com.zeroone.star.project.j8.housemgt.committee.vo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("业委会成员列表显示模型")

public class CommitteeListVO {
    @ApiModelProperty(value = "编号", example = "102024021974913720")
    private String oc_id;

    @ApiModelProperty(value = "姓名", example = "Mei001")
    private String name;

    @ApiModelProperty(value = "性别", example = "G")
    private String sex;

    @ApiModelProperty(value = "电话", example = "13782790901")
    private String link;

    @ApiModelProperty(value = "身份证", example = "420823200909018626")
    private String id_card;

    @ApiModelProperty(value = "住址", example = "3单元101")
    private String address;

    @ApiModelProperty(value = "职位", example = "副会长")
    private String position;

    @ApiModelProperty(value = "岗位", example = "副会长")
    private String post;

    @ApiModelProperty(value = "任期", example = "1")
    private String cur_time;

    @ApiModelProperty(value = "届期", example = "1")
    private String appoint_time;

    @ApiModelProperty(value = "状态", example = "1000")
    private String state;
}
