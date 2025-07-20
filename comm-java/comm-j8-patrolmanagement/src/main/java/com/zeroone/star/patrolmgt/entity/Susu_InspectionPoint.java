package com.zeroone.star.patrolmgt.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import java.time.LocalDateTime;
import java.io.Serializable;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 巡检点表对应的实体类
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Susu //
 * @since 2025-05-19 //
 */
@Data
@EqualsAndHashCode(callSuper = false)
@TableName("inspection_point")
public class Susu_InspectionPoint implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 唯一标识
     */
    @TableId(value = "inspection_id", type = IdType.ASSIGN_ID)
    private String inspectionId;

    /**
     * 业务ID，具体含义可能需要参考业务文档
     */
    private String bId;

    /**
     * 巡检点名称
     */
    private String inspectionName;

    /**
     * 社区ID
     */
    private String communityId;

    /**
     * 备注
     */
    private String remark;

    /**
     * 创建时间
     */
    private LocalDateTime createTime;

    /**
     * 状态码，可能与数据字典关联
     */
    private String statusCd;

    /**
     * 巡检对象类型编码，与 t_dict 表关联
     */
    private String pointObjType;

    /**
     * 巡检对象ID
     */
    private String pointObjId;

    /**
     * 巡检对象名称 (巡检位置)
     */
    private String pointObjName;

    /**
     * 巡检项目ID，与 inspection_item 表关联
     */
    private String itemId;

    /**
     * NFC编码
     */
    private String nfcCode;


}
