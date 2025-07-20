package com.zeroone.star.project.dto.j2.configmanager.dict;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotNull;


/**
 * <p>
 * 描述：字典数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author fish
 * @version 1.0.0
 */
@Data
@ApiModel("字典类型传输数据对象")
public class DictSpecDTO extends DictSpecAddDTO {

    @ApiModelProperty(value = "编号", example = "4", required = true)
    @NotNull(message = "编号不能为空")
    private String specId;


}
