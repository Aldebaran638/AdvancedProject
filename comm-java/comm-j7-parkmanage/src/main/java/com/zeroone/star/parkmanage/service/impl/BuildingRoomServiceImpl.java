package com.zeroone.star.parkmanage.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.parkmanage.entity.BuildingRoom;
import com.zeroone.star.parkmanage.mapper.BuildingRoomMapper;
import com.zeroone.star.parkmanage.service.IBuildingRoomService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author daimon
 * @since 2025-06-02
 */
@Service
public class BuildingRoomServiceImpl extends ServiceImpl<BuildingRoomMapper, BuildingRoom> implements IBuildingRoomService {

    @Override
    public String getRoomNum(String communityId,String bId) {
        QueryWrapper<BuildingRoom> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("community_id", communityId).eq("b_id",bId);
        BuildingRoom buildingRoom = baseMapper.selectOne(queryWrapper);
        if (buildingRoom == null) {
            return "";
        }
        return buildingRoom.getRoomNum();
    }
}
