package com.zeroone.star.dashboard.entity;

import com.baomidou.mybatisplus.annotation.*;

import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author fayff
 * @since 2025-05-21
 */
@Getter
@Setter
@TableName("r_repair_setting")
public class RRepairSetting implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 工单设置ID
     */
    @TableId(value = "setting_id", type = IdType.ASSIGN_ID)
    private String settingId;

    /**
     * 业务ID
     */
    @TableField("b_id")
    private String bId;

    /**
     * 报修类型
     */
    @TableField("repair_type")
    private String repairType;

    /**
     * 报修类型名称
     */
    @TableField("repair_type_name")
    private String repairTypeName;

    /**
     * 派单方式 t_dict 100 抢单 200 指派 300 轮训
     */
    @TableField("repair_way")
    private String repairWay;

    /**
     * 小区分片ID
     */
    @TableField("community_id")
    private String communityId;

    /**
     * 备注
     */
    @TableField("remark")
    private String remark;

    /**
     * 数据状态
     */
    @TableField("status_cd")
    private String statusCd;

    /**
     * 创建时间
     */
    @TableField(value = "create_time", fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 是否为公共区域
     */
    @TableField("public_area")
    private String publicArea;

    /**
     * 是否收费 T为是 F为否
     */
    @TableField("pay_fee_flag")
    private String payFeeFlag;

    /**
     * 收费范围，如30元至50元
     */
    @TableField("price_scope")
    private String priceScope;

    /**
     * 回访标识 001 都不回访 002 已评价不回访 003 都回访
     */
    @TableField("return_visit_flag")
    private String returnVisitFlag;

    /**
     * 报修设置类型
     */
    @TableField("repair_setting_type")
    private String repairSettingType;

    /**
     * 业主端是否展示  Y 是  N 否
     */
    @TableField("is_show")
    private String isShow;

    /**
     * 通知方式，SMS 短信 WECHAT 微信
     */
    @TableField("notify_way")
    private String notifyWay;


}
