package com.zeroone.star.patrolmgt.service.impl;

import com.zeroone.star.patrolmgt.mapper.InspectionPointMapper;
import com.zeroone.star.patrolmgt.service.IInspectionPointService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;


/**
 * 巡检点Service业务层处理
 * 
 * @author ruoyi
 * @date 2025-05-24
 */
@Service
public class InspectionPointServiceImpl implements IInspectionPointService
{
    @Autowired
    private InspectionPointMapper inspectionPointMapper;
    /**
     * 删除巡检点信息
     *
     * @param inspectionId 巡检点主键
     * @return 结果
     */
    @Override
    @Transactional
    public int deleteInspectionPointByInspectionId(String inspectionId)
    {
        return inspectionPointMapper.deleteInspectionPointByInspectionId(inspectionId);
    }
}
