package com.zeroone.star.patrolmgt.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.fasterxml.jackson.annotation.JsonFormat;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


import java.io.Serializable;
import java.util.Date;

/**
 * 巡检点对象 inspection_point
 * 
 * @author NiuJiaXu
 * @date 2025-05-24
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class NiuJiaXu_InspectionPoint implements Serializable
{
    private static final long serialVersionUID = 1L;

    /** ID */
    private String inspectionId;

    /** 业务ID */

    private String bId;

    /** 巡检名称 */

    private String inspectionName;

    /** 小区ID */
    private String communityId;

    /** 备注说明 */
    private String remark;

    /** 创建时间 */
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date create_time;

    /** 数据状态 */
    private String statusCd;

    /** 1001 设备巡检，2002 环境巡检 */
    private String pointObjType;

    /** 对象ID，环境时写-1，设备时写设备ID */
    private String pointObjId;

    /** 对象名称 */
    private String pointObjName;

    /** 巡检项目 */
    private String itemId;

    /** nfc编码 */
    private String nfcCode;



}
