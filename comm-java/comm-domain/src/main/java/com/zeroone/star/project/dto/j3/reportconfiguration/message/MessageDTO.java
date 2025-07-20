package com.zeroone.star.project.dto.j3.reportconfiguration.message;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 描述：添加报表信息数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@Getter
@Setter
@ApiModel("报表信息DTO")
public class MessageDTO extends MessageAddDTO {
    @ApiModelProperty(value = "报表编号", example = "102021111204870302",required = true)
    private String customId;

}
