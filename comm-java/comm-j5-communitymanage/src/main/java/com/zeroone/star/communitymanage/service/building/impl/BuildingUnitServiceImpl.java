package com.zeroone.star.communitymanage.service.building.impl;

import com.zeroone.star.communitymanage.entity.building.BuildingUnit;
import com.zeroone.star.communitymanage.mapper.building.BuildingUnitMapper;
import com.zeroone.star.communitymanage.service.building.IBuildingUnitService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j5.community.building.BuildingUnitDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author langzi
 * @since 2025-05-23
 */
@Service
public class BuildingUnitServiceImpl extends ServiceImpl<BuildingUnitMapper, BuildingUnit> implements IBuildingUnitService {
    @Resource
    BuildingUnitMapper buildingUnitMapper;

    @Override
    public BuildingUnitDTO getUnitInfoByUnitId(String unitId) {
        System.out.println(buildingUnitMapper.getUnitInfoByUnitId(unitId));
        return buildingUnitMapper.getUnitInfoByUnitId(unitId);
    }

    @Override
    public List<BuildingUnitDTO> getUnitInfoByFloorId(String floorId) {
        return buildingUnitMapper.getUnitInfoByFloorId(floorId);
    }
}
