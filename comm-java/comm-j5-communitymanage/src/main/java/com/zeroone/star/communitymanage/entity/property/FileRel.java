package com.zeroone.star.communitymanage.entity.property;

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
 * @author Jungle
 * @since 2025-05-24
 */
@Getter
@Setter
@TableName("file_rel")
public class FileRel implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 文件关系ID，主键
     */
    private String fileRelId;

    /**
     * 业务Id
     */
    private String bId;

    /**
     * 文件类型,用来做分区,业主照片，商户照片，具体查看t_dict表
     */
    private String relTypeCd;

    /**
     * 存放方式，ftp table,fastdfs 具体查看t_dict表
     */
    private String saveWay;

    /**
     * 对象ID，及说明这个文件归宿于谁，业主则填写业主ID
     */
    private String objId;

    /**
     * 文件真实名称
     */
    private String fileRealName;

    /**
     * 文件存储名称
     */
    private String fileSaveName;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 数据状态，详细参考t_dict表，0, 在用 1失效
     */
    private String statusCd;


}
