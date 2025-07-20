package com.zeroone.star.project.vo.j6.contractmanagement.draftcontract;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.io.Serializable;
import java.time.LocalDateTime;

@Data
@ApiModel("合同变更明细视图对象")
public class ContractChangeDetailVO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "甲方联系人", example = "18234567890")
    @JsonProperty("aContacts")
    private String aContacts;

    @ApiModelProperty(value = "甲方联系电话", example = "18234567890")
    @JsonProperty("aLink")
    private String aLink;

    @ApiModelProperty(value = "合同金额", example = "12323233.00")
    @JsonProperty("amount")
    private String amount;

    @ApiModelProperty(value = "乙方联系人", example = "18234567890")
    @JsonProperty("bContacts")
    private String bContacts;

    @ApiModelProperty(value = "乙方联系电话", example = "18234567890")
    @JsonProperty("bLink")
    private String bLink;

    @ApiModelProperty(value = "合同编号", example = "12312")
    @JsonProperty("contractCode")
    private String contractCode;

    @ApiModelProperty(value = "合同ID", example = "812025053117880067")
    @JsonProperty("contractId")
    private String contractId;

    @ApiModelProperty(value = "合同名称", example = "12123")
    @JsonProperty("contractName")
    private String contractName;

    @ApiModelProperty(value = "合同类型", example = "812025052032690004")
    @JsonProperty("contractType")
    private String contractType;

    @ApiModelProperty(value = "明细ID", example = "912025053181690196")
    @JsonProperty("detailId")
    private String detailId;

    @ApiModelProperty(value = "结束时间", example = "2025-05-31 00:00:00")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonProperty("endTime")
    private LocalDateTime endTime;

    @ApiModelProperty(value = "操作类型", example = "ADD")
    @JsonProperty("operate")
    private String operate;

    @ApiModelProperty(value = "经办人", example = "分公司电饭锅1")
    @JsonProperty("operator")
    private String operator;

    @ApiModelProperty(value = "经办人联系电话", example = "13987898786")
    @JsonProperty("operatorLink")
    private String operatorLink;

    @ApiModelProperty(value = "甲方", example = "121")
    @JsonProperty("partyA")
    private String partyA;

    @ApiModelProperty(value = "乙方", example = "1212")
    @JsonProperty("partyB")
    private String partyB;

    @ApiModelProperty(value = "计划ID", example = "242025053151100194")
    @JsonProperty("planId")
    private String planId;

    @ApiModelProperty(value = "计划类型", example = "1001")
    @JsonProperty("planType")
    private String planType;

    @ApiModelProperty(value = "计划类型名称", example = "主体变更")
    @JsonProperty("planTypeName")
    private String planTypeName;

    @ApiModelProperty(value = "签订时间", example = "2025-05-31 15:10:00")
    @JsonProperty("signingTime")
    private LocalDateTime signingTime;

    @ApiModelProperty(value = "开始时间", example = "2025-05-28 00:00:00")
    @JsonProperty("startTime")
    private LocalDateTime startTime;

    @ApiModelProperty(value = "店铺ID", example = "102025051658480005")
    @JsonProperty("storeId")
    private String storeId;

    @ApiModelProperty(value = "合同对象", example = "772025052792870015")
    @JsonProperty("objId")
    private String objId;

    @ApiModelProperty(value = "合同对象类型", example = "(3333：房屋  ,1111:没有合同对象)")
    @JsonProperty("objType")
    private String objType;
}
