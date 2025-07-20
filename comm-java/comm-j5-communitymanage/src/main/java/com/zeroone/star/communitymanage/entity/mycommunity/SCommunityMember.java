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
@TableName("s_community_member")
public class SCommunityMember {
    /**
     * 主键id
     */
    @TableId("community_member_id")
    private String communityMemberId;
    /**
     * 业务id
     */
    private String bId;
    /**
     * 小区id
     */
    private String communityId;
    /**
     * 商户id
     */
    private String memberId;
    /**
     * 商户类型
     */
    private String memberTypeCd;
    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;
    /**
     * 数据状态
     */
    private String statusCd;
    /**
     * 审核状态
     */
    private String auditStatusCd;
    /**
     * 开始时间
     */
    private LocalDateTime startTime;
    /**
     * 结束时间
     */
    private LocalDateTime endTime;
}
