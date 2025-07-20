package com.zeroone.star.propertymanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

@Data
@TableName("hc_file")
@Builder
@AllArgsConstructor
@NoArgsConstructor
public class HcFileDO {
    /**
     * 文件ID
     */
    private String fileId;

    /**
     * 小区ID
     */
    private String communityId;

    /**
     * 文件名称
     */
    private String fileName;

    /**
     * 文件内容
     */
    private String context;

    /**
     * 创建时间
     */
    private Date createTime;

    /**
     * 数据状态，详细参考c_status表，S 保存，0， 在用 1失效
     */
    private String statusCd;

    /**
     * 文件后缀
     */
    private String suffix;

}
