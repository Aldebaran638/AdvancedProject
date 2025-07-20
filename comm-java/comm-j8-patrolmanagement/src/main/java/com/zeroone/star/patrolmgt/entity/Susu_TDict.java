package com.zeroone.star.patrolmgt.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import java.time.LocalDateTime; // 根据你的数据库时间类型和项目规范选择
import java.io.Serializable; // 推荐实现 Serializable 接口
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 数据字典表对应的实体类
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Susu
 * @since 2025-05-19
 */
@Data
@EqualsAndHashCode(callSuper = false)
@TableName("t_dict") // 映射到数据库的 t_dict 表
public class Susu_TDict implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键ID
     */
    @TableId(value = "id", type = IdType.ASSIGN_ID) // 映射主键字段，根据你提供的SQL，id是整数，如果数据库是自增主键，可以考虑使用 IdType.AUTO
    private Integer id; // 根据数据库字段类型调整，这里使用 Integer

    /**
     * 状态码/字典编码
     */
    private String statusCd;

    /**
     * 名称
     */
    private String name;

    /**
     * 描述
     */
    private String description;

    /**
     * 创建时间
     */
    private LocalDateTime createTime; // 根据实际数据库字段类型调整

    /**
     * 关联表名
     */
    private String tableName;

    /**
     * 关联表字段名
     */
    private String tableColumns;

    // 如果表中还有其他字段，请根据需要添加
}
