package com.zeroone.star.contractmanagement.entity;

import com.baomidou.mybatisplus.annotation.*;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

@Data
@TableName("contract_type_spec")
public class ContractTypeSpec implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "规格ID", example = "822025051998170008")
    @TableId(value = "spec_cd",type = IdType.ASSIGN_ID)
    private String specCd;
    @ApiModelProperty(value = "合同类型ID", example = "812025051612450095")
    private String contractTypeId;
    @ApiModelProperty(value = "合同id", example = "102025051622920020")
    private String storeId;
    @ApiModelProperty(value = "字段填写说明", example = "装修时需缴纳的押金")
    private String specName;
    @ApiModelProperty(value = "是否必填", example = "true")
    private String specHoldplace;
    @ApiModelProperty(value = "是否展示",
            allowableValues = "allowableValues = 是否必填 Y 必填，N非必填",
            example = "Y")
    private String required;
    @ApiModelProperty(value = "是否展示", example = "Y")
    private String specShow;
    @ApiModelProperty(value = "值类型",
            allowableValues = "1001 字符串 2002 整数 3003 金额 4004 日期 5005 时间",
            example = "1001"
    )
    private String specValueType;
    @ApiModelProperty(value = "是否参与查询",
            allowableValues = "2233 input 3344 select 4455 日期",
            example = "3344"
    )
    private String specType;
    @ApiModelProperty("创建时间")
    private LocalDateTime createTime;
    @ApiModelProperty(
            value = "数据状态（参考c_status表）",
            allowableValues = "S: 保存, 0: 在用, 1: 失效",
            example = "0"
    )
    @TableLogic(value = "0", delval = "1")
    private String statusCd;
    @ApiModelProperty("是否展示")
    private String listShow;
}
