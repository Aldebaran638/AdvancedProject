package com.zeroone.star.communitymanage.service.parking;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.communitymanage.entity.building.BuildingUnit;
import com.zeroone.star.project.query.j5.community.parking.ParkingQuery;

/**
 * <p>
 *  BuildingUnit服务层
 * </p>
 *
 * @author hh
 * @since 2025-05-23
 */
public interface IBuildingUnitService extends IService<BuildingUnit> {

    /**
     * 获取单元编号
     * @param query
     * @return
     */
    BuildingUnit getunitnum(ParkingQuery query);
}
