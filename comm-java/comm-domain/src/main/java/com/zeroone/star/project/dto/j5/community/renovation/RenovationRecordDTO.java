package com.zeroone.star.project.dto.j5.community.renovation;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * <p>
 * 描述：房屋装修记录传输模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 天干物燥
 * @version 1.0.0
 */
@ApiModel("房屋装修记录传输模型")
@Data
public class RenovationRecordDTO extends AddRenovationRecordDTO{


    @ApiModelProperty(value = "装修跟踪记录ID",example = "172021111350580555")
    private String recordId;

    @ApiModelProperty(value = "操作人员id",example = "30202305221014327189000174")
    private String staffId;

    @ApiModelProperty(value = "操作人员",example = "HC演示物业")
    private String staffName;

    @ApiModelProperty(value = "创建时间",example = "2024-02-19 21:59:48")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "状态名称",example = "装修中")
    private String stateName;

}
