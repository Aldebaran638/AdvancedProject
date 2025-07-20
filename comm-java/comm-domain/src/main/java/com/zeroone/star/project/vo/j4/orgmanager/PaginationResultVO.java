package com.zeroone.star.project.vo.j4.orgmanager;

import io.swagger.annotations.ApiModelProperty;
import org.apache.poi.ss.formula.functions.T;

import java.util.List;

public class PaginationResultVO<P> {
    @ApiModelProperty(value = "总记录数")
    private Integer totalCount;

    @ApiModelProperty(value = "当前页码")
    private Integer pageNo;

    @ApiModelProperty(value = "每页大小")
    private Integer pageSize;

    @ApiModelProperty(value = "总页数")
    private Integer pageTotal;

    @ApiModelProperty(value = "数据列表")
    private List<T> list;
}
