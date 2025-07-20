package com.zeroone.star.parkmanage.entity;

import com.baomidou.mybatisplus.annotation.*;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;
import java.util.Date;

@Data
@TableName("parking_space")
@ApiModel(value = "ParkingSpace对象", description = "车位信息表")
public class ParkingSpace {

    @TableId(value = "ps_id", type = IdType.ASSIGN_ID)
    @ApiModelProperty(value = "车位ID", example = "PS20230001", required = true)
    private String psId;

    @TableField(value = "b_id")
    @ApiModelProperty(value = "业务ID", example = "B20230501")
    private String bId;

    @TableField(value = "community_id")
    @ApiModelProperty(value = "小区ID", example = "COMM1001", required = true)
    private String communityId;

    @TableField(value = "num")
    @ApiModelProperty(value = "车位编号", example = "A-101", required = true)
    private String num;

    @TableField(value = "pa_id")
    @ApiModelProperty(value = "停车场ID", example = "PA001", required = true)
    private String paId;

    @TableField(value = "state")
    @ApiModelProperty(
            value = "车位状态: S(出售)/H(出租)/F(空闲)",
            example = "F",
            allowableValues = "S,H,F"
    )
    private String state;

    @TableField(value = "area")
    @ApiModelProperty(value = "车位面积（平方米）", example = "12.50", required = true)
    private BigDecimal area;

    @TableField(value = "remark")
    @ApiModelProperty(value = "备注", example = "靠近电梯口")
    private String remark;

    @TableField(value = "create_time", fill = FieldFill.INSERT)  // 自动填充创建时间
    @ApiModelProperty(value = "创建时间", example = "2023-05-01 10:00:00")
    private LocalDateTime createTime;

    @TableField(value = "status_cd")
    @ApiModelProperty(
            value = "数据状态: S(保存)/0(在用)/1(失效)",
            example = "0",
            allowableValues = "S,0,1"
    )
    private String statusCd;

    @TableField(value = "parking_type")
    @ApiModelProperty(
            value = "车位类型: 1(普通)/2(子母)/3(豪华)",
            example = "1",
            allowableValues = "1,2,3"
    )
    private String parkingType;
}
