package com.zeroone.star.project.j8.housemgt.committee.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel("业委会成员详情数据模型")
public class CommitteeDetailDTO {

    // 不展示编号字段 - 移除ocId

    @ApiModelProperty(value = "姓名", example = "张三")
    private String name;

    @ApiModelProperty(value = "性别", example = "男")
    private String sex;

    @ApiModelProperty(value = "电话", example = "13782790901")
    private String link;

    @ApiModelProperty(value = "身份证号", example = "420823200909018626")
    private String idCard; // 添加身份证号

    @ApiModelProperty(value = "住址", example = "3单元101")
    private String address;

    @ApiModelProperty(value = "职位", example = "副会长")
    private String position;

    @ApiModelProperty(value = "岗位", example = "副会长")
    private String post; // 添加岗位字段

    @ApiModelProperty(value = "岗位描述", example = "负责日常管理工作")
    private String postDesc; // 添加岗位描述字段

    @ApiModelProperty(value = "届期", example = "2022-2025")
    private String appointTime; // 添加届期字段

    @ApiModelProperty(value = "任期", example = "3年")
    private String curTime; // 添加任期字段

    @ApiModelProperty(value = "状态", example = "在职")
    private String stateDesc; // 状态描述：在职/离职

    @ApiModelProperty(value = "备注", example = "工作认真负责")
    private String remark; // 添加备注字段

//    @ApiModelProperty(value = "小区ID", example = "202301315429059")
//    private String communityId; // 添加小区ID
//
//    @ApiModelProperty(value = "创建时间")
//    private LocalDateTime createTime; // 添加创建时间

    // 联系人列表
    @ApiModelProperty(value = "紧急联系人列表")
    private List<CommitteeContactDTO> contacts;
}