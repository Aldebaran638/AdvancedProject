package com.zeroone.star.project.dto.j2.configmanager.sys.dictionary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


/**
 * <p>
 * 菜单目录数据传输模型
 * </p>
 *
 * @author wp
 * @since 2023-05-29
 */
@Data
@ApiModel("菜单目录数据传输模型")
public class TDictDTO extends AddTDictDTO{
    //id
    @ApiModelProperty(value = "id", example = "1")
    private Integer id;

    @ApiModelProperty(value = "表名称", example = "u_org_staff_rel")
    private String tableName;

    //类名称
    @ApiModelProperty(value = "类名称", example = "rel_cd")
    private String tableColumns;
}
