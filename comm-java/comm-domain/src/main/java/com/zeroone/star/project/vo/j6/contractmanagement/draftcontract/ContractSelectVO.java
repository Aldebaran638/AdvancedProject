package com.zeroone.star.project.vo.j6.contractmanagement.draftcontract;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.NotBlank;
import java.time.LocalDateTime;

/**
 * <p>
 * 描述：选择合同列表数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Getter
@Setter
@ApiModel("选择合同列表数据传输对象")
public class ContractSelectVO  {
    @ApiModelProperty(value = "合同名称", required = true, example = "合同1")
    @NotBlank(message = "合同名称不能为空")
    @JsonProperty("contractName")
    private String contractName;

    @ApiModelProperty(value = "合同编号", required = true, example = "123213")
    @NotBlank(message = "合同编号不能为空")
    @JsonProperty("contractCode")
    private String contractCode;

    /**
     * 需要id转名称
     */
    @ApiModelProperty(value = "合同类型", required = true, example = "类型1")
    @NotBlank(message = "合同类型不能为空")
    @JsonProperty("contractType")
    private String contractType;

    @ApiModelProperty(value = "甲方", required = true, example = "张三")
    @NotBlank(message = "甲方不能为空")
    @JsonProperty("partyA")
    private String partyA;

    @ApiModelProperty(value = "乙方", required = true, example = "李四")
    @NotBlank(message = "乙方不能为空")
    @JsonProperty("partyB")
    private String partyB;

    @ApiModelProperty(value = "签订时间", required = true, example = "2023-03-15")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @JsonFormat(pattern = "yyyy-MM-dd")
    @JsonProperty("signingTime")
    private LocalDateTime signingTime;
}
