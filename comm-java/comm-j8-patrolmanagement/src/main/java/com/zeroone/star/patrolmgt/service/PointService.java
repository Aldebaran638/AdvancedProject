package com.zeroone.star.patrolmgt.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.patrolmgt.entity.RenYiFei_InspectionPoint;
import com.zeroone.star.patrolmgt.entity.Susu_InspectionPoint;
import com.zeroone.star.project.j8.patrolmgt.point.dto.AddPointDTO;
import com.zeroone.star.project.vo.JsonVO;

public interface PointService extends IService<Susu_InspectionPoint> {
    JsonVO<String> savePoint(AddPointDTO addPointDTO);
}
