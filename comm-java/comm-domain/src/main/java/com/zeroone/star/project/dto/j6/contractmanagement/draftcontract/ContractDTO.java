package com.zeroone.star.project.dto.j6.contractmanagement.draftcontract;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.zeroone.star.project.dto.j6.contractmanagement.contractmodification.ContractRoomDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.NotBlank;
import java.time.LocalDateTime;

@Getter
@Setter
@ApiModel("获取合同详情数据传输对象")
public class ContractDTO {

    @ApiModelProperty(value = "甲方名称", required = true, example = "甲方1")
    @NotBlank(message = "甲方名称不能为空")
    @JsonProperty("partyA")
    private String partyA;

    @ApiModelProperty(value = "甲方联系人", required = true, example = "甲方联系人1")
    @NotBlank(message = "甲方联系人不能为空")
    @JsonProperty("aContacts")
    private String aContacts;

    @ApiModelProperty(value = "甲方联系电话", required = true, example = "18812117833")
    @NotBlank(message = "甲方联系电话不能为空")
    @JsonProperty("aLink")
    private String aLink;

    @ApiModelProperty(value = "是否需要审核", required = true, example = "4444")
    @JsonProperty("audit")
    private String audit;

    @ApiModelProperty(value = "乙方名称", required = true, example = "业主1")
    @NotBlank(message = "乙方名称不能为空")
    @JsonProperty("partyB")
    private String partyB;

    @ApiModelProperty(value = "乙方联系人", required = true, example = "业主1")
    @NotBlank(message = "乙方联系人不能为空")
    @JsonProperty("bContacts")
    private String bContacts;

    @ApiModelProperty(value = "乙方联系电话", required = true, example = "18812117888")
    @NotBlank(message = "乙方联系电话不能为空")
    @JsonProperty("bLink")
    private String bLink;

    @ApiModelProperty(value = "社区id", required = true, example = "2024022692080516")
    @JsonProperty("communityId")
    private String communityId;

    @ApiModelProperty(value = "附件")
    @JsonProperty("contractFilePo")
    private Object[] contractFilePo;

    @ApiModelProperty(value = "甲方主键")
    @JsonProperty("partyaId")
    private String partyaId;

    @ApiModelProperty(value = "商户id")
    @JsonProperty("storeId")
    private String storeId;

    @ApiModelProperty(value = "合同名称", required = true, example = "123")
    @NotBlank(message = "合同名称不能为空")
    @JsonProperty("contractName")
    private String contractName;

    @ApiModelProperty(value = "合同编号", required = true, example = "123213")
    @NotBlank(message = "合同编号不能为空")
    @JsonProperty("contractCode")
    private String contractCode;

    @ApiModelProperty(value = "合同类型id", required = true, example = "类型2")
    @NotBlank(message = "合同类型不能为空")
    @JsonProperty("contractType")
    private String contractType;

    @ApiModelProperty(value = "合同类型名称")
    @JsonProperty("typeName")
    private String typeName;

    @ApiModelProperty(value = "合同类型备注")
    @JsonProperty("remark")
    private String remark;

    @ApiModelProperty(value = "经办人", required = true, example = "经办人3")
    @NotBlank(message = "经办人不能为空")
    @JsonProperty("operator")
    private String operator;

    @ApiModelProperty(value = "经办人电话", required = true, example = "18812117777")
    @NotBlank(message = "经办人电话不能为空")
    @JsonProperty("operatorLink")
    private String operatorLink;

    @ApiModelProperty(value = "合同金额", required = true, example = "123.00")
    @NotBlank(message = "合同金额不能为空")
    @JsonProperty("amount")
    private String amount;

    @ApiModelProperty(value = "开始时间", required = true, example = "2025-05-13 00:00")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonProperty("startTime")
    private LocalDateTime startTime;

    @ApiModelProperty(value = "结束时间", required = true, example = "2025-05-21 00:01")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonProperty("endTime")
    private LocalDateTime endTime;

    @ApiModelProperty(value = "签订时间", required = true, example = "2025-05-16 22:11")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonProperty("signingTime")
    private LocalDateTime signingTime;

    @ApiModelProperty(value = "合同对象")
    @JsonProperty("objId")
    private String objId;

    @ApiModelProperty(value = "合同对象类型", example = "3333")
    @JsonProperty("objType")
    private String objType;

    @ApiModelProperty(value = "关联房屋")
    @JsonProperty("rooms")
    private ContractRoomDTO[] rooms;

    @ApiModelProperty(value = "审批人姓名", example = "zs")
    @JsonProperty("staffName")
    private String staffName;

    @ApiModelProperty(value = "合同id", example = "812025060211780065")
    @JsonProperty("contractId")
    private String contractId;

    @ApiModelProperty(value = "合同状态", example = "2002")
    @JsonProperty("status")
    private String status;

    @ApiModelProperty(value = "合同状态码", example = "0")
    @JsonProperty("statusCd")
    private String statusCd;
}
