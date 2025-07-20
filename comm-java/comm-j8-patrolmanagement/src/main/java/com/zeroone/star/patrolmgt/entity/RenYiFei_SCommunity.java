package com.zeroone.star.patrolmgt.entity;

import com.baomidou.mybatisplus.annotation.*;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.math.BigDecimal;
import java.time.LocalDateTime;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel(value="社区DO")
@TableName("s_community")
public class RenYiFei_SCommunity {
    @ApiModelProperty(value="小区ID",required = true,example = "2024012252790005")
    @TableId(value="community_id",type= IdType.ASSIGN_ID)
    private String communityId;

    @ApiModelProperty(value="业务ID",required = false,example = "202024012217270006")
    private String bId;

    @ApiModelProperty(value="小区名称",required = true,example = "物联网同步小区")
    private String name;

    @ApiModelProperty(value="小区地址",required = true,example = "河北省秦皇岛市北戴河区无")
    private String address;

    @ApiModelProperty(value="地标，如王府井北60米",required = false,example = "无")
    private String nearbyLandmarks;

    @ApiModelProperty(value="根据定位获取城市编码",required = true,example = "130304")
    private String cityCode;

    @ApiModelProperty(value="地区 x坐标",required=true,example="101.33")
    private String mapX;

    @ApiModelProperty(value="地区 y坐标",required=true,example="101.33")
    private String mapY;

    @ApiModelProperty(value="创建时间",required=false,example="2024-01-22 15:06:00")
    private LocalDateTime createTime;

    @ApiModelProperty(value="数据状态，详细参考c_status表，S 保存，0, 在用 1失效",required = false,example="0")
    @TableLogic(value="0",delval="1")
    private String statusCd;

    @ApiModelProperty(value="业务状态 1000 为待审核 1200审核拒绝",required = false,example="1100")
    private String state;

    @ApiModelProperty(value="小区面积",required = false,example="0.00")
    private BigDecimal communityArea;

    @ApiModelProperty(value="联系方式",required = false,example="18966665555")
    private String tel;

    @ApiModelProperty(value="缴费周期",required = false,example = "12")
    private Long payFeeMonth;

    @ApiModelProperty(value="费用",required = false,example = "0.00")
    private BigDecimal feePrice;

    @ApiModelProperty(value="客服二维码",required = false,example = "NULL")
    private String qrCode;
}
