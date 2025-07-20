package com.zeroone.star.communitymanage.service.building.impl;

import com.zeroone.star.communitymanage.entity.building.BuildingOwner;
import com.zeroone.star.communitymanage.mapper.building.BuildingOwnerMapper;
import com.zeroone.star.communitymanage.service.building.IBuildingOwnerService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j5.community.building.BuildingOwnerDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author langzi
 * @since 2025-05-23
 */
@Service
public class BuildingOwnerServiceImpl extends ServiceImpl<BuildingOwnerMapper, BuildingOwner> implements IBuildingOwnerService {

    @Resource
    BuildingOwnerMapper  buildingOwnerMapper;

    @Override
    public BuildingOwnerDTO getOwnerInfoByOwnerId(String ownerId) {
        return buildingOwnerMapper.getOwnerInfoByOwnerId(ownerId);
    }
}
