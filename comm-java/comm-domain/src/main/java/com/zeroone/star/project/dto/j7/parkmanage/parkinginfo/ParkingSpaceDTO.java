package com.zeroone.star.project.dto.j7.parkmanage.parkinginfo;

import com.baomidou.mybatisplus.annotation.TableId;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

@ApiModel("车位保存DTO")
@Data
public class  ParkingSpaceDTO {
    @ApiModelProperty(value = "车位ID", example = "PS001", required = true)
    private String psId;

    @ApiModelProperty(value = "车位编号", example = "001", required = true)
    private String num;

    @ApiModelProperty(value = "停车场ID", example = "PA001", required = true)
    private String paId;

    /**
     * 1：普通车位  2：子母车位  3：豪华车位
     */
    @ApiModelProperty(value = "车位类型", example = "1", required = true)
    private String parkingType;

    @ApiModelProperty(value = "车位面积", example = "25.50", required = true)
    private BigDecimal area;

    @ApiModelProperty(value = "备注", example = "这是一个备注")
    private String remark;

    @ApiModelProperty(value = "小区id", example = "2024012252790005", required = true)
    private String communityId;
}
