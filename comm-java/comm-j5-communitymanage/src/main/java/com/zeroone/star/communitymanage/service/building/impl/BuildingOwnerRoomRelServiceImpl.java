package com.zeroone.star.communitymanage.service.building.impl;

import com.zeroone.star.communitymanage.entity.building.BuildingOwnerRoomRel;
import com.zeroone.star.communitymanage.mapper.building.BuildingOwnerRoomRelMapper;
import com.zeroone.star.communitymanage.service.building.IBuildingOwnerRoomRelService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j5.community.building.BuildingOwnerRoomRelDTO;
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
public class BuildingOwnerRoomRelServiceImpl extends ServiceImpl<BuildingOwnerRoomRelMapper, BuildingOwnerRoomRel> implements IBuildingOwnerRoomRelService {

    @Resource
    BuildingOwnerRoomRelMapper buildingOwnerRoomRelMapper;

    @Override
    public BuildingOwnerRoomRelDTO getByRoomId(String roomId) {
        return buildingOwnerRoomRelMapper.getByRoomId(roomId);
    }
}
