package com.zeroone.star.project.query.j2.configmanager.sys.dictionary;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述 菜单目录查询数据类型
 * </p>
 *
 * @author wxs
 * @since 2023-04-13
 */
@Data
public class TDictQuery extends PageQuery {
    @ApiModelProperty(value = "字典类型对应编号",
            example = "6",
            required = false)
    private String specId;

    @ApiModelProperty(value = "名称", example = "上门服务",
            required = false)
    private String name;

    @ApiModelProperty(value = "值", example = "3",
            required = false)
    private String statusCd;
}
