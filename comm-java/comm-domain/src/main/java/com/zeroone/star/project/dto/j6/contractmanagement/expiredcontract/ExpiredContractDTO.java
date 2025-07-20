package com.zeroone.star.project.dto.j6.contractmanagement.expiredcontract;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.fasterxml.jackson.annotation.JsonFormat;
import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;

/**
 * @author HASEE
 * @date 2025/5/19
 * @description: 到期合同请求操作对象
 */
@Data
@ApiModel("到期合同请求操作对象")
public class ExpiredContractDTO {

    @ApiModelProperty("合同id")
    @TableId(value = "id", type = IdType.ASSIGN_ID)
    @JsonProperty("contractId")
    private String contractId;

    @ApiModelProperty("合同编码")
    @JsonProperty("contractCode")
    private String contractCode;

    @ApiModelProperty("合同名称")
    @JsonProperty("contractName")
    private String contractName;

    @ApiModelProperty("合同类型")
    @JsonProperty("contractType")
    private String contractType;

    @ApiModelProperty("甲方")
    @JsonProperty("partyA")
    private String partyA;

    @ApiModelProperty("乙方")
    @JsonProperty("partyB")
    private String partyB;

    @ApiModelProperty("甲方联系人")
    @JsonProperty("aContacts")
    private String aContacts;

    @ApiModelProperty("甲方联系电话")
    @JsonProperty("aLink")
    private String aLink;

    @ApiModelProperty("乙方联系人")
    @JsonProperty("bContacts")
    private String bContacts;

    @ApiModelProperty("乙方联系电话")
    @JsonProperty("bLink")
    private String bLink;

    @ApiModelProperty("经办人")
    @JsonProperty("operator")
    private String operator;

    @ApiModelProperty("经办人联系电话")
    @JsonProperty("operatorLink")
    private String operatorLink;

    @ApiModelProperty("合同金额")
    @JsonProperty("amount")
    private String amount;

    @ApiModelProperty("开始时间")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonProperty("startTime")
    private LocalDateTime startTime;

    @ApiModelProperty("结束时间")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonProperty("endTime")
    private LocalDateTime endTime;

    @ApiModelProperty("签订时间")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy‑MM‑dd HH:mm:ss")
    @JsonProperty("signingTime")
    private LocalDateTime signingTime;

    /**
     * 合同状态编号
     * 待审核：11
     * 审核通过：22
     * 审核失败：33
     * 合同结束：44
     */
    @ApiModelProperty("合同状态编号")
    @JsonProperty("state")
    private String state;

    @ApiModelProperty("审核意见")
    @JsonProperty("stateDesc")
    private String stateDesc;

    @ApiModelProperty("父合同编号")
    @JsonProperty("contractParentId")
    private String contractParentId;
}
