package com.zeroone.star.project.query.j2.configmanager.dict;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

@Data
@EqualsAndHashCode(callSuper = true)
@ApiModel(value = "字典类型查询条件")
public class DictSpecQuery extends PageQuery {

    @ApiModelProperty(value = "请选择名称", example = "")
    private String specName;

}
