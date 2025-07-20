package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.util.Date;

/**
 * 
 * @TableName community_setting
 */
@TableName(value ="community_setting")
@Data
public class CommunitySetting {
    /**
     * 主键ID
     */
    @TableId
    private String csId;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 名称
     */
    private String settingName;

    /**
     * 设置类型
     */
    private String settingType;

    /**
     * 设置key
     */
    private String settingKey;

    /**
     * 设置值
     */
    private String settingValue;

    /**
     * 备注
     */
    private String remark;

    /**
     * 创建时间
     */
    private Date createTime;

    /**
     * 数据状态0正常1失效
     */
    private String statusCd;

}