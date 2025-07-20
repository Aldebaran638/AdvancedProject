package com.zeroone.star.propertymanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

@Data
@TableName("file_rel")
@Builder
@AllArgsConstructor
@NoArgsConstructor
public class FileRelDO {
    /**
     * 文件关系ID，主键
     */
    private String fileRelId;

    /**
     * 业务Id
     */
    private String bId;

    /**
     * 文件类型，用来做分区，业主照片，商户照片，具体查看t_dict表
     */
    private String relTypeCd;

    /**
     * 存放方式，ftp table，fastdfs 具体查看t_dict表
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
    private Date createTime;

    /**
     * 数据状态，详细参考t_dict表，0， 在用 1失效
     */
    private String statusCd;

}
