package com.zeroone.star.project.query.j7.parkmanage.parkinginfo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

/**
 * 用于查询停车场列表的Query (不含分页和非必要字段)
 */
@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@ApiModel(value = "停车场")
public class ListParkingAreaQuery implements Serializable {

    @ApiModelProperty(value = "停车场类型")
    private String typeCd;

    @ApiModelProperty(value = "社区Id")
    private String communityId;

    @ApiModelProperty(value = "状态")
    private String statusCd;
}