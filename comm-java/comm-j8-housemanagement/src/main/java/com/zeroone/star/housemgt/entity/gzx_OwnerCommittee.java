package com.zeroone.star.housemgt.entity;

import com.baomidou.mybatisplus.annotation.*;

import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 业主委员会实体类
 * </p>
 *
 * @author zeroone
 * @since 2025-05-24
 */
@Getter
@Setter
@TableName("owner_committee")  // 根据数据库表名设置
public class gzx_OwnerCommittee implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 编号（主键）
     */
    @TableId(type = IdType.ASSIGN_ID) // 改为雪花算法
    private Long ocId; // 改为Long类型

    /**
     * 姓名
     */
    private String name;

    /**
     * 性别
     */
    private String sex;

    /**
     * 电话
     */
    private String link;

    /**
     * 身份证号码
     */
    private String idCard;

    /**
     * 住址
     */
    private String address;

    /**
     * 职位
     */
    private String position;

    /**
     * 岗位
     */
    private String post;

    /**
     * 岗位描述
     */
    private String postDesc;

    /**
     * 届期
     */
    private String appointTime;

    /**
     * 任期
     */
    private String curTime;

    /**
     * 状态：1000 表示在职，2000 离职
     */
    private String state;

    /**
     * 备注
     */
    private String remark;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，0，在用 1失效
     */
    private String statusCd;
}