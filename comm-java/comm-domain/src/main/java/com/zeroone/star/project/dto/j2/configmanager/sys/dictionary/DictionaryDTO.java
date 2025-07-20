package com.zeroone.star.project.dto.j2.configmanager.sys.dictionary;

import com.baomidou.mybatisplus.annotation.TableId;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


/**
 * <p>
 * 字典名称列表模型
 * </p>
 *
 * @author wp
 * @since 2023-05-29
 */

@Data
@ApiModel("字典名称列表模型")
public class DictionaryDTO extends AddDictionaryDTO{
    //id
    @TableId(value = "id")
    @ApiModelProperty(value = "编号", example = "25",
            required = true)
    private Integer id;
}
