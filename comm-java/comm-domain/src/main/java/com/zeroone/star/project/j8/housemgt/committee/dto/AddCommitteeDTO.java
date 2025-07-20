package com.zeroone.star.project.j8.housemgt.committee.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;
import javax.validation.constraints.Size;
import java.util.List;

/**
 * 添加业委会数据传输模型
 */
@ApiModel("添加业委会")
@Data
public class AddCommitteeDTO {

    @ApiModelProperty(value = "姓名", example = "张三", required = true)
    @NotBlank(message = "姓名不能为空")
    private String name;

    @ApiModelProperty(value = "性别", example = "B", required = true)
    @NotBlank(message = "性别不能为空")
    private String sex;

    @ApiModelProperty(value = "联系方式", example = "13333333333", required = true)
    @NotBlank(message = "联系方式不能为空")
    @Pattern(regexp = "\\d{11}", message = "联系方式必须是11位数字")
    private String link;

    @ApiModelProperty(value = "身份证号", example = "420403199911117323", required = true)
    @NotBlank(message = "身份证号不能为空")
    @Size(min = 15, max = 18, message = "身份证号长度应当在 15 到 18 位之间")
    private String idCard;

    @ApiModelProperty(value = "地址", example = "01社区01栋", required = true)
    @NotBlank(message = "地址不能为空")
    private String address;

    @ApiModelProperty(value = "职位", example = "保安", required = true)
    @NotBlank(message = "职位不能为空")
    private String position;

    @ApiModelProperty(value = "岗位", example = "保安", required = true)
    @NotBlank(message = "岗位不能为空")
    private String post;

    @ApiModelProperty(value = "岗位描述", example = "负责小区门口安全巡逻", required = false)
    private String postDesc;

    @ApiModelProperty(value = "届期", example = "2022", required = true)
    @NotBlank(message = "届期不能为空")
    private String appointTime;

    @ApiModelProperty(value = "任期", example = "1", required = true)
    @NotBlank(message = "任期不能为空")
    private String curTime;

    @ApiModelProperty(value = "状态", example = "1000", required = true)
    @NotBlank(message = "状态不能为空")
    private String state;

    @ApiModelProperty(value = "备注", example = "无", required = false)
    private String remark;

    @ApiModelProperty(value = "所属社区", example = "2024022655510404", required = false)
    private String communityId;

    @ApiModelProperty(value = "紧急联系人列表", required = false)
    private List<CommitteeContactDTO> contacts;

}
