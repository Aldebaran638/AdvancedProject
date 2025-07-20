package com.zeroone.star.project.vo.j6.contractmanagement.contracttype;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;

/*
 *描述 ：合同类型对象
 *Author:28768
 */
@ApiModel("合同类型对象")
@Data
public class ContractTypeVO {
    @ApiModelProperty(value = "合同类型编号", example = "1")
    @JsonProperty("contractTypeId")
    private String contractTypeId;

    @ApiModelProperty(value = "合同类型名称", example = "kunge8")
    @JsonProperty("typeName")
    private String typeName;

    @ApiModelProperty(value = "审核状态",example = "1001")
    @JsonProperty("audit")
    private String audit;

    @ApiModelProperty(value = "审核状态",example = "审核")
    @JsonProperty("auditName")
    private String auditName;

    @ApiModelProperty(value = "商户ID",example = "102025051658480005")
    @JsonProperty("storeId")
    private String storeId;

    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "创建时间", example = "2025-05-18 16:52:05")
    @JsonProperty("createTime")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "数据状态", example = "S")
    @JsonProperty("statusCd")
    private String statusCd;

    @ApiModelProperty(value = "备注",example = "dfasdfa")
    @JsonProperty("remark")
    private String remark;
}
