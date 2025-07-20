package com.zeroone.star.dashboard.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import java.io.Serializable;
import java.time.LocalDateTime;

import lombok.*;

/**
 * <p>
 * 
 * </p>
 *
 * @author wunianwufeng
 * @since 2025-05-25
 */
@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor
@Data
public class Notepad implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * id
     */
    private String noteId;

    /**
     * 类型 t_dict表
     */
    private String noteType;

    /**
     * 简介
     */
    private String title;

    /**
     * 房屋ID
     */
    private String roomId;

    /**
     * 房屋名称
     */
    private String roomName;

    /**
     * 3309 对应业主 3308 员工
     */
    private String objType;

    /**
     * 业主
     */
    private String objId;

    /**
     * 业主名称
     */
    private String objName;

    /**
     * 登记人
     */
    private String createUserId;

    /**
     * 登记人
     */
    private String createUserName;

    /**
     * 其他关联ID 比如报修ID
     */
    private String thridId;

    /**
     * W 跟进中 F 完成
     */
    private String state;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0, 在用 1失效
     */
    private String statusCd;

    /**
     * 联系电话
     */
    private String link;


}
