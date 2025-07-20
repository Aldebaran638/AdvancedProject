package com.zeroone.star.communitymanage.entity.publicity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author wuguanfengyue
 * @since 2025-05-25
 */
@Getter
@Setter
@TableName("community_publicity")
public class CommunityPublicity implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 公示ID
     */
    private String pubId;

    /**
     * 公示标题
     */
    private String title;

    /**
     * 公示类型
     */
    private String pubType;

    /**
     * 头部照片,照片名称
     */
    private String headerImg;

    /**
     * 活动内容
     */
    private String context;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 阅读数
     */
    private Integer readCount;

    /**
     * 点赞数
     */
    private Integer likeCount;

    /**
     * 收藏数
     */
    private Integer collectCount;

    /**
     * 创建用户Id
     */
    private String createUserId;

    /**
     * 创建用户名称
     */
    private String createUserName;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private String statusCd;


}
