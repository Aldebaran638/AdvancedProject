package com.zeroone.star.communitymanage.service.parking;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.communitymanage.entity.building.BuildingUnit;
import com.zeroone.star.communitymanage.entity.building.BusinessFloor;

/**
 * <p>
 *  BusinessFloor服务层
 * </p>
 *
 * @author hh
 * @since 2025-05-23
 */
public interface IBusinessFloorService extends IService<BusinessFloor> {

    BusinessFloor getfloornum(BuildingUnit buildingUnit);
}
