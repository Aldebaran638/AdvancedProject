package com.zeroone.star.project.query.j6.contractmanagement.contractpartya;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

/**
 * <p>
 * 描述：示例查询对象
 * </p>
 * @author 永不言弃
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("合同甲方数据查询对象")
public class ContractPartyaQuery extends PageQuery {

    @ApiModelProperty(value = "合同甲方名称", example = "爱情物业公司1")
    @JsonProperty("partyA")
    private String partyA;

    @ApiModelProperty(value = "合同甲方联系人名称", example = "张菲菲")
    @JsonProperty("aContacts")
    private String aContacts;

    @ApiModelProperty(value = "联系人联系电话", example = "16732291923")
    @JsonProperty("aLink")
    private String aLink;

}
