package com.zeroone.star.communitymanage.service.parking.impl;

import com.zeroone.star.communitymanage.mapper.building.BuildingOwnerRoomRelMapper;
import com.zeroone.star.communitymanage.entity.building.BuildingOwnerRoomRel;
import com.zeroone.star.communitymanage.service.parking.IBuildingOwnerRoomRelService;
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
public class BuildingOwnerRoomRel4PServiceImpl extends ServiceImpl<BuildingOwnerRoomRelMapper, BuildingOwnerRoomRel> implements IBuildingOwnerRoomRelService {

    @Autowired
    private BuildingOwnerRoomRelMapper buildingOwnerRoomRelMapper;

    @Override
    public List<BuildingOwnerRoomRel> listroomid(String ownerId) {
        List<BuildingOwnerRoomRel> list = buildingOwnerRoomRelMapper.selectroomid(ownerId);
        return list;
    }
}
