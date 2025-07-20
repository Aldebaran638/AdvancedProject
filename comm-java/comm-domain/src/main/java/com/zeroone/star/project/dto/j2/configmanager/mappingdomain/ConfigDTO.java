package com.zeroone.star.project.dto.j2.configmanager.mappingdomain;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：配置项数据传输模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Laceration
 * @version 1.0.0
 */
@ApiModel("配置项数据传输模型")
@Data
@TableName("c_mapping_domain")
public class ConfigDTO extends AddConfigDTO{
    @TableId(type = IdType.ASSIGN_ID)
    @ApiModelProperty(value = "配置项编号", example = "102023012984550002", required = true)
    private String id;
}
