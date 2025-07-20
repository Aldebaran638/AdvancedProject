package com.zeroone.star.project.dto.j2.configmanager.sys.dictionary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 添加菜单目录模型
 * </p>
 *
 * @author wp
 * @since 2023-05-29
 */

@Getter
@Setter
@ToString
@ApiModel("添加菜单目录模型")
public class AddTDictDTO {
    //类型
    @ApiModelProperty(value = "字典类型对应编号", example = "6",
            required = true)
    private String specId;
    //名称
    @ApiModelProperty(value = "名称", example = "商务拜访",
            required = true)
    private String name;
    //值
    @ApiModelProperty(value = "值", example = "3",
            required = false)
    private String statusCd;
    //描述
    @ApiModelProperty(value = "描述", example = "上门服务",
            required = false)
    private String description;
}
