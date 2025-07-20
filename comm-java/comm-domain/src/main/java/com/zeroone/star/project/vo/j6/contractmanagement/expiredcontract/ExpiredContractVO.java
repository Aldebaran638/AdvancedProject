package com.zeroone.star.project.vo.j6.contractmanagement.expiredcontract;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;

/**
 * @author HASEE
 * @date 2025/5/19 15:12
 * @description: TODO
 */
@Data
@ApiModel("到期合同显示对象")
public class ExpiredContractVO {

    @ApiModelProperty("合同编号")
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

    @ApiModelProperty("经办人")
    @JsonProperty("operator")
    private String operator;

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

    @ApiModelProperty("状态")
    @JsonProperty("stateName")
    private String stateName;
}
