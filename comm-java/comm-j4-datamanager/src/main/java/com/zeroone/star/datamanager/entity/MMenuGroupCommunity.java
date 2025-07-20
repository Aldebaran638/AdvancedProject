package com.zeroone.star.datamanager.entity;
import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;
import org.springframework.format.annotation.DateTimeFormat;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 *
 * </p>
 *
 * @author 玺朽
 * @since 2025-05-21
 */
@TableName("m_menu_group_community")
@Getter
@Setter
public class MMenuGroupCommunity implements Serializable {
    private static final long serialVersionUID = 1L;
    /**
     * 菜单组社区关系id 主键
     */
    /**
     * 菜单组社区关系id 主键
     * 使用@TableId注解标识该字段为数据库表主键，自动进行SQL映射
     * 若使用MyBatis-Plus的雪花算法ID生成策略，可添加IdType.AUTO或指定type属性
     */
    @TableId(type = IdType.ASSIGN_ID)
    private String gcId;

    /**
     * 菜单组id
     */
    private String gId;

    /**
     * 菜单组名称
     */
    private String name;

    /**
     * 社区id
     */
    private String communityId;

    /**
     * 社区名称
     */
    private String communityName;

    /**
     * 创建时间
     */
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime createTime;

    /**
     * 状态码
     */
    private String statusCd;
}
