package com.zeroone.star.patrolmgt.service.impl;


import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.patrolmgt.entity.NiuJiaXu_InspectionRoute;
import com.zeroone.star.patrolmgt.mapper.InspectionRouteMapper;
import com.zeroone.star.patrolmgt.service.IInspectionRouteService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;



/**
 * 巡检路线Service业务层处理
 * 
 * @author NiuJiaXu
 * @date 2025-05-24
 */
@Service
public class InspectionRouteServiceImpl extends ServiceImpl<InspectionRouteMapper, NiuJiaXu_InspectionRoute> implements IInspectionRouteService
{
    @Autowired
    private InspectionRouteMapper inspectionRouteMapper;


    /**
     * 修改巡检路线
     *
     * @param inspectionRoute 巡检路线
     * @return 提示信息
     */
    @Override
    @Transactional
    public int updateInspectionRoute(NiuJiaXu_InspectionRoute inspectionRoute)
    {
        return inspectionRouteMapper.updateInspectionRoute(inspectionRoute);

    }


    /**
     * 删除巡检路线信息
     * 
     * @param inspectionRouteId 巡检路线主键
     * @return 结果
     */
    @Override
    @Transactional
    public String deleteInspectionRouteByInspectionRouteId(String inspectionRouteId)
    {
        int success = inspectionRouteMapper.deleteInspectionRouteByInspectionRouteId(inspectionRouteId);
        // 空结果判断
        if(success == 1){
            return "删除巡检路线成功";
        }else{
            return "删除的路线不存在";
        }

    }
}
