package com.zeroone.star.patrolmgt.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.patrolmgt.entity.NiuJiaXu_InspectionRoute;

/**
 * 巡检路线Service接口
 * 
 * @author NiuJiaXu
 * @date 2025-05-24
 */
public interface IInspectionRouteService extends IService<NiuJiaXu_InspectionRoute>
{

    /**
     * 修改巡检路线
     *
     * @param inspectionRoute 巡检路线
     * @return 结果
     */
    public int updateInspectionRoute(NiuJiaXu_InspectionRoute inspectionRoute);


    /**
     * 删除巡检路线信息
     * 
     * @param inspectionRouteId 巡检路线主键
     * @return 结果
     */
    public String deleteInspectionRouteByInspectionRouteId(String inspectionRouteId);
}
