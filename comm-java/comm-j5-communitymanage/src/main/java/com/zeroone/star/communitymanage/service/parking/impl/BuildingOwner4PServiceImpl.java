package com.zeroone.star.communitymanage.service.parking.impl;

import com.zeroone.star.communitymanage.mapper.building.BuildingOwnerMapper;
import com.zeroone.star.communitymanage.entity.building.BuildingOwner;
import com.zeroone.star.communitymanage.service.parking.IBuildingOwnerService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author hh
 * @since 2025-05-24
 */
@Service
public class BuildingOwner4PServiceImpl extends ServiceImpl<BuildingOwnerMapper, BuildingOwner> implements IBuildingOwnerService {

    @Autowired
    private BuildingOwnerMapper buildingOwnerMapper;

    @Override
    public List<BuildingOwner> getname(String ownerId) {
      List<BuildingOwner> buildingOwners =  buildingOwnerMapper.listname(ownerId);
      return buildingOwners;
    }
}
