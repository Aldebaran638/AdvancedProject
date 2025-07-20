package com.zeroone.star.communitymanage.entity.mycommunity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

@Data
@AllArgsConstructor
@NoArgsConstructor
@TableName("city_area")
public class CityArea {
    /**
     * 主键Id
     */
    @TableId
    private Integer id;
    /**
     * 城市编码
     */
    private String areaCode;
    /**
     * 城市名称
     */
    private String areaName;
    /**
     * 101 省级 202 市州 303 区县
     */
    private String areaLevel;
    /**
     * 父级城市编码
     */
    private String parentAreaCode;
    /**
     * 父级城市名称
     */
    private String parentAreaName;
    /**
     * 经度
     */
    private String lon;
    /**
     * 纬度
     */
    private String lat;
    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;
    /**
     * 数据状态
     */
    private String statusCd;
}
