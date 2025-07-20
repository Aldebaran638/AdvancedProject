package com.zeroone.star.project.query.j4.datamanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.io.Serializable;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel(value = "物业公司查询条件")
public class CompanyQuery extends PageQuery implements Serializable {

    @ApiModelProperty(value = "编号", example = "102025051526950478")
    private String storeId;

    @ApiModelProperty(value = "名称", example = "坤坤物业")
    private String storeName;

    @ApiModelProperty(value = "电话", example = "111111111")
    private String tel;
}
