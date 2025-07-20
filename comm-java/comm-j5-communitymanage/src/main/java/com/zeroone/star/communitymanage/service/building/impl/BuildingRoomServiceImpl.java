package com.zeroone.star.communitymanage.service.building.impl;

import com.zeroone.star.communitymanage.entity.building.BuildingRoom;
import com.zeroone.star.communitymanage.mapper.building.BuildingRoomMapper;
import com.zeroone.star.communitymanage.service.building.IBuildingRoomService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j5.community.building.BuildingRoomDTO;
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
public class BuildingRoomServiceImpl extends ServiceImpl<BuildingRoomMapper, BuildingRoom> implements IBuildingRoomService {

    @Resource
    BuildingRoomMapper buildingRoomMapper;

    @Override
    public List<BuildingRoomDTO> getRoomsByCommunityIdAndUnitId(String communityId, String unitId) {
        return buildingRoomMapper.getRoomsByCommunityIdAndUnitId(communityId, unitId);
    }
}
