package com.zeroone.star.project.vo.j5.info.communityinfo;


import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

/**
 * <p>
 * 描述：数据管理——小区信息查询数据响应模型
 * </p>
 * @author yuezi
 * @version 1.0.0
 */
@ApiModel("小区信息查询响应模型")
@Data
public class CommunityInfoVO {

    @ApiModelProperty(value = "小区ID", example = "2023052267100146")
    private String communityId;
    @ApiModelProperty(value = "小区名称", example = "HC演示小区3")
    private String communityName;
    @ApiModelProperty(value = "物业公司名称", example = "HC演示物业2")
    private String propertyName;
    @ApiModelProperty(value = "附近地标，如王府井北60米", example = "无")
    private String nearbyLandmarks;
    @ApiModelProperty(value = "城市编码", example = "630103")
    private String cityCode;
    @ApiModelProperty(value = "创建时间", example = "2024-01-22 15:06:00")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss", timezone = "GMT+8") // 添加 Jackson 格式化注解
    private LocalDateTime createTime;
    @ApiModelProperty(value = "社区编码", example = "123456")
    private String value;

    @ApiModelProperty(value = "小区地址", example = "青海省西宁市城中区无")
    private String address;
    @ApiModelProperty(value = "缴费周期", example = "12")
    private Long payFeeMonth;
    @ApiModelProperty(value = "每月单价（保留两位小数)", example = "0")
    private BigDecimal feePrice;
    @ApiModelProperty(value = "客服电话", example = "18909711443")
    private String tel;
    @ApiModelProperty(value = "业务状态 1000 为待审核 1100为审核通过 1200审核拒绝", example = "1000")
    private String state;

}
