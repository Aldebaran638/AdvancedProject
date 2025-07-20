package com.zeroone.star.project.vo.j6.contractmanagement.draftcontract;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeSpecVO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeTemplateVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import java.util.List;

@Data
@ApiModel(value = "合同打印视图对象")
public class ContractPrintVO {

        @ApiModelProperty(value = "基础替换字段列表")
        @JsonProperty("baseReplace")
        private List<BaseReplaceItem> baseRepalce;

        @ApiModelProperty(value = "合同信息列表")
        @JsonProperty("contract")
        private List<ContractListVO> contract;

        @ApiModelProperty(value = "合同类型规格列表")
        @JsonProperty("contractTypeSpec")
        private List<ContractTypeSpecVO> contractTypeSpec;

        @ApiModelProperty(value = "合同类型模板列表")
        @JsonProperty("contractTypeTemplate")
        private List<ContractTypeTemplateVO> contractTypeTemplate;

}
