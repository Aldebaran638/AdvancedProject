package com.zeroone.star.patrolmgt.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import java.time.LocalDateTime; // 根据你的数据库时间类型和项目规范选择
import java.io.Serializable; // 推荐实现 Serializable 接口
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 巡检项目表对应的实体类
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Susu
 * @since 2025-05-19
 */
@Data
@EqualsAndHashCode(callSuper = false)
@Getter
@Setter
@TableName("inspection_item") // 映射到数据库的 inspection_item 表
public class Susu_InspectionItem implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 巡检项目ID
     */
    @TableId(value = "item_id", type = IdType.ASSIGN_ID) // 映射主键字段，使用 ASSIGN_ID 与项目其他ID生成策略保持一致
    private String itemId;

    /**
     * 巡检项目名称
     */
    private String itemName;

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
    private LocalDateTime createTime; // 根据实际数据库字段类型调整

    /**
     * 状态码
     */
    private String statusCd;

    // 如果表中还有其他字段，请根据需要添加
}
