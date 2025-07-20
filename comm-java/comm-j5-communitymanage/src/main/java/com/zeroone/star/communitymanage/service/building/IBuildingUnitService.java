package com.zeroone.star.communitymanage.service.building;

import com.zeroone.star.communitymanage.entity.building.BuildingUnit;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j5.community.building.BuildingUnitDTO;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author langzi
 * @since 2025-05-23
 */
public interface IBuildingUnitService extends IService<BuildingUnit> {
    BuildingUnitDTO getUnitInfoByUnitId(String unitId);
    List<BuildingUnitDTO> getUnitInfoByFloorId(String floorId);
}
