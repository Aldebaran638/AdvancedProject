package com.zeroone.star.patrolmgt.service;

/**
 * 巡检点Service接口
 * 
 * @author ruoyi
 * @date 2025-05-24
 */

public interface IInspectionPointService 
{

    /**
     * 删除巡检点信息
     *
     * @param inspectionId 巡检点主键
     * @return 结果
     */
    public int deleteInspectionPointByInspectionId(String inspectionId);
}
