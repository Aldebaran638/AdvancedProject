package com.zeroone.star.contractmanagement.entity;

import lombok.Data;
import java.time.LocalDateTime;

@Data
public class ContractFile {
    /** 文件ID，主键 */
    private String contractFileId;

    /** 合同ID */
    private String contractId;

    /** 文件真实名称 */
    private String fileRealName;

    /** 文件存储名称 */
    private String fileSaveName;

    /** 创建时间 */
    private LocalDateTime createTime;

    /** 状态码 */
    private String statusCd;

    /** 状态时间 */
    private LocalDateTime statusDate;
}
