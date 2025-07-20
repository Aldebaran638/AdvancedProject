package com.zeroone.star.project.vo.j6.contractmanagement.draftcontract;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;

@Data
@ApiModel("合同变更记录项视图对象")
public class ContractChangeListVO {

    @JsonProperty("contractId")
    @ApiModelProperty(value = "合同ID", example = "812025053117880067")
    private String contractId;

    @JsonProperty("changePerson")
    @ApiModelProperty(value = "变更人ID", example = "302025051666870011")
    private String changePerson;

    @JsonProperty("changePersonName")
    @ApiModelProperty(value = "变更人姓名", example = "jkun")
    private String changePersonName;

    @JsonProperty("operator")
    @ApiModelProperty(value = "经办人", example = "分公司电饭锅1")
    private String operator;

    @JsonProperty("operatorLink")
    @ApiModelProperty(value = "经办人联系电话", example = "13987898786")
    private String operatorLink;

    @JsonProperty("aContacts")
    @ApiModelProperty(value = "甲方联系人", example = "18234567890")
    private String aContacts;

    @JsonProperty("aLink")
    @ApiModelProperty(value = "甲方联系电话", example = "18234567890")
    private String aLink;

    @JsonProperty("bContacts")
    @ApiModelProperty(value = "乙方联系人", example = "18234567890")
    private String bContacts;

    @JsonProperty("bLink")
    @ApiModelProperty(value = "乙方联系电话", example = "18234567890")
    private String bLink;

    @JsonProperty("amount")
    @ApiModelProperty(value = "合同金额", example = "12323233.00")
    private String amount;

    @JsonProperty("contractCode")
    @ApiModelProperty(value = "合同编号", example = "12312")
    private String contractCode;

    @JsonProperty("contractName")
    @ApiModelProperty(value = "合同名称", example = "12123")
    private String contractName;

    @JsonProperty("contractType")
    @ApiModelProperty(value = "合同类型ID", example = "812025052032690004")
    private String contractType;

    @JsonProperty("contractTypeName")
    @ApiModelProperty(value = "合同类型名称", example = "jjj")
    private String contractTypeName;

    @JsonProperty("createTime")
    @ApiModelProperty(value = "创建时间", example = "2025-05-31 23:34:52")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime createTime;

    @JsonProperty("endTime")
    @ApiModelProperty(value = "结束时间", example = "2025-05-31 00:00:00")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime endTime;

    @JsonProperty("signingTime")
    @ApiModelProperty(value = "签订时间", example = "2025-05-31 15:10:00")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime signingTime;

    @JsonProperty("startTime")
    @ApiModelProperty(value = "开始时间", example = "2025-05-28 00:00:00")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime startTime;

    @JsonProperty("partyA")
    @ApiModelProperty(value = "甲方", example = "121")
    private String partyA;

    @JsonProperty("partyB")
    @ApiModelProperty(value = "乙方", example = "1212")
    private String partyB;

    @JsonProperty("planId")
    @ApiModelProperty(value = "计划ID", example = "242025053151100194")
    private String planId;

    @JsonProperty("planType")
    @ApiModelProperty(value = "计划类型", example = "1001")
    private String planType;

    @JsonProperty("planTypeName")
    @ApiModelProperty(value = "计划类型名称", example = "主体变更")
    private String planTypeName;

    @JsonProperty("remark")
    @ApiModelProperty(value = "备注", example = "131232423423442")
    private String remark;

    @JsonProperty("state")
    @ApiModelProperty(value = "状态", example = "22")
    private String state;

    @JsonProperty("stateName")
    @ApiModelProperty(value = "状态名称", example = "审核通过")
    private String stateName;

    @JsonProperty("statusCd")
    @ApiModelProperty(value = "状态代码", example = "0")
    private String statusCd;

    @JsonProperty("storeId")
    @ApiModelProperty(value = "店铺ID", example = "102025051658480005")
    private String storeId;
}
