package com.zeroone.star.project.dto.j5.community.publicity;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @description: 添加公示dto
 * @author: yu
 * @data 2025年05月20日 09:19
 */


@ApiModel(description = "新增公示DTO")
@Data
public class AddPublicityDTO extends PublicityBaseDTO {

    @ApiModelProperty(value = "创建人ID", hidden = true, example = "30202305221014327189000174")
    private String createUserId;

    @ApiModelProperty(value = "创建人名称", hidden = true, example = "HC演示物业2")
    private String createUserName;


}
