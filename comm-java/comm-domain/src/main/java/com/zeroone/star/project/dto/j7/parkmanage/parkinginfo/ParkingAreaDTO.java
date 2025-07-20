package com.zeroone.star.project.dto.j7.parkmanage.parkinginfo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

/**
 * 用于查询停车场列表的DTO (不含分页和非必要字段)
 */
@Data
@Builder
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("获取停车场名称模型")
public class ParkingAreaDTO implements Serializable {

    @ApiModelProperty("停车场类型")
    private String typeCd;

    @ApiModelProperty("社区ID")
    private String communityId;

    @ApiModelProperty("状态")
    private String statusCd;
}