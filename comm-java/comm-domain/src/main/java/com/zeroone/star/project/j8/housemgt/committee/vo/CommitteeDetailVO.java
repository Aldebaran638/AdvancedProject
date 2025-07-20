package com.zeroone.star.project.j8.housemgt.committee.vo;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;
import java.util.Date;
import java.util.List;
import com.zeroone.star.project.j8.housemgt.committee.dto.CommitteeContactDTO; // 导入DTO

@Data
@ApiModel("业委会成员详情显示模型")
public class CommitteeDetailVO {

    @ApiModelProperty(value = "姓名", example = "Mei001")
    private String name;

    @ApiModelProperty(value = "性别", example = "G")
    private String sex;

    @ApiModelProperty(value = "电话", example = "13782790901")
    private String link;

    @ApiModelProperty(value = "身份证号", example = "420823200909018626")
    private String id_card;

    @ApiModelProperty(value = "住址", example = "3单元101")
    private String address;

    @ApiModelProperty(value = "职位", example = "副会长")
    private String position;

    @ApiModelProperty(value = "岗位", example = "副会长")
    private String post;

    @ApiModelProperty(value = "岗位描述", example = "null")
    private String post_desc;

    @ApiModelProperty(value = "届期", example = "1年")
    private String appoint_time;

    @ApiModelProperty(value = "任期", example = "1")
    private String cur_time;

    @ApiModelProperty(value = "状态", example = "1000")
    private String state;

    @ApiModelProperty(value = "备注", example = "null")
    private String remark;

    @ApiModelProperty(value = "成员关系", example = "父子")
    private String rel_name;

    // 删除原来的单个字段，改为：
    @ApiModelProperty(value = "紧急联系人列表")
    private List<CommitteeContactDTO> contacts;
}