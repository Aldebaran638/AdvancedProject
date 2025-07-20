package com.zeroone.star.communitymanage.service.parking.impl;

import com.zeroone.star.communitymanage.mapper.building.BuildingRoomMapper;
import com.zeroone.star.communitymanage.entity.building.BuildingRoom;
import com.zeroone.star.communitymanage.service.parking.IBuildingRoomService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author hh
 * @since 2025-05-24
 */
@Service
public class BuildingRoom4PServiceImpl extends ServiceImpl<BuildingRoomMapper, BuildingRoom> implements IBuildingRoomService {

    @Autowired
    private BuildingRoomMapper buildingRoomMapper;

    @Override
    public BuildingRoom getroom(String roomId) {
       BuildingRoom buildingRoom = buildingRoomMapper.listroom(roomId);
        return buildingRoom;
    }
}
