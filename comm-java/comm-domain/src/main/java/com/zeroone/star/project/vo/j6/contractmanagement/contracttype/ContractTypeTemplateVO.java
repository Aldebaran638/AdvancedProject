package com.zeroone.star.project.vo.j6.contractmanagement.contracttype;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("合同类型模板对象")
public class ContractTypeTemplateVO {
    @ApiModelProperty(value = "模板ID", example = "822021111065340002")
    @JsonProperty("templateId")
    private String templateId;

    @ApiModelProperty(value = "合同类型ID", example = "812021111097320001")
    @JsonProperty("contractTypeId")
    private String contractTypeId;

    @ApiModelProperty(value = "商户ID", example = "402021080402040153")
    @JsonProperty("storeId")
    private String storeId;

    @ApiModelProperty(value = "模板内容", example = "<h1 align=\"center\">...")
    @JsonProperty("context")
    private String context;

    @TableField(fill = FieldFill.INSERT)
    @ApiModelProperty(value = "创建时间", example = "2025-05-18 16:52:05")
    @JsonProperty("createTime")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "状态值", example = "0")
    @JsonProperty("statusCd")
    private String statusCd;
}
