package com.zeroone.star.project.vo.j6.contractmanagement.draftcontract;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.ToString;

import java.time.LocalDateTime;

@Data
@ToString
@ApiModel("合同附件数据模型")
public class ContractFileVo {

    @JsonProperty("contractFileId")
    @ApiModelProperty(value = "合同附件ID")
    private String contractFileId;

    @JsonProperty("contractId")
    @ApiModelProperty(value = "合同ID")
    private String contractId;

    @JsonProperty("createTime")
    @ApiModelProperty(value = "创建时间")
    private LocalDateTime createTime;

    @JsonProperty("fileRealName")
    @ApiModelProperty(value = "文件真实名称")
    private String fileRealName;

    @JsonProperty("fileSaveName")
    @ApiModelProperty(value = "文件保存名称")
    private String fileSaveName;

    @JsonProperty("statusCd")
    @ApiModelProperty(value = "文件状态，0可用，1不可用")
    private int statusCd;
}
