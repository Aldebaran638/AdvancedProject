package com.zeroone.star.project.dto.j2.configmanager.sys.dictionary;

import com.baomidou.mybatisplus.annotation.TableId;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 添加字典名称列表模型
 * </p>
 *
 * @author wp
 * @since 2023-05-29
 */

@Getter
@Setter
@ToString
@ApiModel("添加字典名称列表模型")
public class AddDictionaryDTO {
    //id
    @TableId(value = "id")
    @ApiModelProperty(value = "唯一标识", example = "25",
            required = true)
    private Integer id;
    //表字段状态 取值
    @ApiModelProperty(value = "编码", example = "25")
    private String statusCd;

    //名称
    @ApiModelProperty(value = "名称", example = "普通员工")
    private String name;
}
