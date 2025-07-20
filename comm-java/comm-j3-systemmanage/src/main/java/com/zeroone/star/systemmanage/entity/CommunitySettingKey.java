package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import lombok.Data;

import java.util.Date;

/**
 * 
 * @TableName community_setting_key
 */
@Data
public class CommunitySettingKey {
    /**
     * 编号
     */
    @TableId(type = IdType.AUTO)
    private String keyId;

    /**
     * 设置类型
     */
    private String settingType;

    /**
     * 名称
     */
    private String settingName;

    /**
     * 设置key
     */
    private String settingKey;

    /**
     * 备注信息
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