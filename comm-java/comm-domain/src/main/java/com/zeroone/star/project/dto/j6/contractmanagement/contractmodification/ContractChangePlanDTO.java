package com.zeroone.star.project.dto.j6.contractmanagement.contractmodification;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import com.fasterxml.jackson.annotation.JsonProperty;

import javax.validation.constraints.*;
import java.math.BigDecimal;
import java.util.List;

/**
 * <p>
 * 合同主体变更数据传输对象
 * </p>
 */
@Getter
@Setter
@ToString
@ApiModel("合同主体变更数据传输对象")
public class ContractChangePlanDTO {

    @ApiModelProperty(value = "合同ID（主键）", example = "812025051620220182", required = true)
    @NotBlank(message = "合同ID不能为空")
    @JsonProperty("contractId")
    private String contractId;

    @ApiModelProperty(value = "合同编码", example = "001", required = true)
    @NotBlank(message = "合同编码不能为空")
    @JsonProperty("contractCode")
    private String contractCode;

    @ApiModelProperty(value = "变更后的合同名称", example = "小克变更合同主体", required = true)
    @NotBlank(message = "合同名称不能为空")
    @JsonProperty("contractName")
    private String contractName;

    @ApiModelProperty(value = "合同类型ID", example = "812025051667530143", required = true)
    @NotBlank(message = "合同类型不能为空")
    @JsonProperty("contractType")
    private String contractType;

    @ApiModelProperty(value = "合同类型名称", example = "测试合同类型RC1")
    @JsonProperty("contractTypeName")
    private String contractTypeName;

    @ApiModelProperty(value = "甲方（变更后）", example = "小李", required = true)
    @NotBlank(message = "甲方不能为空")
    @JsonProperty("partyA")
    private String partyA;

    @ApiModelProperty(value = "乙方（变更后）", example = "晓雪", required = true)
    @NotBlank(message = "乙方不能为空")
    @JsonProperty("partyB")
    private String partyB;

    @ApiModelProperty(value = "甲方联系人（变更后）", example = "小李", required = true)
    @NotBlank(message = "甲方联系人不能为空")
    @JsonProperty("aContacts")
    private String aContacts;

    @ApiModelProperty(value = "甲方联系电话（变更后）", example = "18812345678", required = true)
    @Pattern(regexp = "^1[3-9]\\d{9}$", message = "甲方联系电话格式不正确（需11位手机号）")
    @JsonProperty("aLink")
    private String aLink;

    @ApiModelProperty(value = "乙方联系人（变更后）", example = "晓雪", required = true)
    @NotBlank(message = "乙方联系人不能为空")
    @JsonProperty("bContacts")
    private String bContacts;

    @ApiModelProperty(value = "乙方联系电话（变更后）", example = "13812345678", required = true)
    @Pattern(regexp = "^1[3-9]\\d{9}$", message = "乙方联系电话格式不正确（需11位手机号）")
    @JsonProperty("bLink")
    private String bLink;

    @ApiModelProperty(value = "经办人", example = "暗示法", required = true)
    @NotBlank(message = "经办人不能为空")
    @JsonProperty("operator")
    private String operator;

    @ApiModelProperty(value = "经办人电话", example = "18812345678", required = true)
    @Pattern(regexp = "^1[3-9]\\d{9}$", message = "经办人电话格式不正确（需11位手机号）")
    @JsonProperty("operatorLink")
    private String operatorLink;

    @ApiModelProperty(value = "合同金额", example = "1000.00")
    @Digits(integer = 10, fraction = 2, message = "合同金额格式应为最多10位整数和2位小数")
    @JsonProperty("amount")
    private String amount;

    @ApiModelProperty(value = "合同开始时间（变更后）", example = "2025-05-16 00:00:00", required = true)
    @NotBlank(message = "合同开始时间不能为空")
    @JsonProperty("startTime")
    private String startTime;

    @ApiModelProperty(value = "合同结束时间（变更后）", example = "2025-05-27 00:00:00", required = true)
    @NotBlank(message = "合同结束时间不能为空")
    @JsonProperty("endTime")
    private String endTime;

    @ApiModelProperty(value = "签订时间（变更后）", example = "2025-05-16 10:33:54", required = true)
    @NotBlank(message = "签订时间不能为空")
    @JsonProperty("signingTime")
    private String signingTime;

    @ApiModelProperty(value = "变更备注", example = "合同变更测试2", notes = "描述变更原因或说明")
    @Size(max = 200, message = "变更备注最多200字")
    @JsonProperty("changeRemark")
    private String changeRemark;

    @ApiModelProperty(value = "审核流程参数", example = "contractChangeMainBody", notes = "标识变更类型（如主体变更）")
    @Pattern(regexp = "contractChangeMainBody|.*", message = "参数需符合变更类型规范")
    @JsonProperty("param")
    private String param;

    @ApiModelProperty(value = "下一步审核用户ID", example = "")
    @JsonProperty("nextUserId")
    private String nextUserId;

    @ApiModelProperty(value = "计划类型", example = "1001", notes = "可选固定值，如1001代表常规计划")
    @JsonProperty("planType")
    private String planType;

    @ApiModelProperty(value = "关联房间列表", example = "[]", notes = "合同涉及的房间ID集合")
    @JsonProperty("rooms")
    private List<ContractRoomDTO> rooms;

    @ApiModelProperty(value = "员工姓名（可选）", example = "")
    @JsonProperty("staffName")
    private String staffName;

    @ApiModelProperty(value = "审核标识", example = "2002", notes = "审核流程中的状态码")
    @JsonProperty("audit")
    private String audit;

}
