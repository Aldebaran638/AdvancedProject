package com.zeroone.star.project.query.j2.configmanager.sys.dictionary;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Pattern;

@Data
public class DictionaryQuery extends PageQuery {
    @ApiModelProperty(value = "员工岗位", example = "普通员工",required = false)
    @Pattern(regexp = "普通员工|部门经理|部门副经理|部门组长|分公司总经理" +
            "|分公司副总经理|总经理助理|总公司总经理|总公司副总经理|管理员",
            message = "岗位格式不正确")
    private String name;
}
