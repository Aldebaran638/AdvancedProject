package com.zeroone.star.project.vo.j6.contractmanagement.draftcontract;

import com.zeroone.star.project.dto.j6.contractmanagement.contractmodification.ContractChangePlanDTO;
import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
import java.time.LocalDateTime;

/**
 * <p>
 * 描述：获取合同修改记录数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 5544
 * @version 1.0.0
 */
@Data
@ToString
@ApiModel("获取合同修改记录数据传输对象")
public class ContractChangePlanVO extends ContractChangePlanDTO {

    @JsonProperty("changePerson")
    @ApiModelProperty(value = "修改人id")
    private String changePerson;

    @JsonProperty("changePersonName")
    @ApiModelProperty(value = "修改人名称")
    private String changePersonName;

    @JsonProperty("planId")
    @ApiModelProperty(value = "计划id")
    private String planId;

    @JsonProperty("planTypeName")
    @ApiModelProperty(value = "计划类型名称")
    private String planTypeName;

    @JsonProperty("remark")
    @ApiModelProperty(value = "计划备注")
    private String remark;

    @JsonProperty("state")
    @ApiModelProperty(value = "计划状态")
    private String state;

    @JsonProperty("stateName")
    @ApiModelProperty(value = "计划状态名称")
    private String stateName;

    @JsonProperty("storeId")
    @ApiModelProperty(value = "不知道")
    private String storeId;

    @JsonProperty("statusCd")
    @ApiModelProperty(value = "状态")
    private String statusCd;

    @JsonProperty("createTime")
    @ApiModelProperty(value = "创建时间")
    private LocalDateTime createTime;

}
