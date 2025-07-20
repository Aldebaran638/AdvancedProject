package com.zeroone.star.patrolmgt.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.patrolmgt.entity.NiuJiaXu_InspectionRoute;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * 巡检路线Mapper接口
 * 
 * @author NiuJiaXu
 * @date 2025-05-24
 */
@Mapper
public interface InspectionRouteMapper  extends BaseMapper<NiuJiaXu_InspectionRoute>
{

    /**
     * 新增巡检路线
     * 
     * @param inspectionRoute 巡检路线
     * @return 结果
     */
    public int insertInspectionRoute(NiuJiaXu_InspectionRoute inspectionRoute);

    /**
     * 修改巡检路线
     * 
     * @param inspectionRoute 巡检路线
     * @return 结果
     */
    public int updateInspectionRoute(NiuJiaXu_InspectionRoute inspectionRoute);

    /**
     * 删除巡检路线
     * 
     * @param inspectionRouteId 巡检路线主键
     * @return 结果
     */
    public int deleteInspectionRouteByInspectionRouteId(String inspectionRouteId);


}
