package com.zeroone.star.project.vo.j7.parkmanage.parkinginfo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.List;

/**
 * 简化的停车场信息VO (用于不分页列表展示)
 */
@Data
@Builder
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("停车场名称VO模型")
public class ParkingAreaVO implements Serializable {

    @ApiModelProperty("停车场名称列表")
    private List<String> names;
}