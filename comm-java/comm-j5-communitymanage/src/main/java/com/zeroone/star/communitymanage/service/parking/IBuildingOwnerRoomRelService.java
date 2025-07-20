package com.zeroone.star.communitymanage.service.parking;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.communitymanage.entity.building.BuildingOwnerRoomRel;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author hh
 * @since 2025-05-24
 */
public interface IBuildingOwnerRoomRelService extends IService<BuildingOwnerRoomRel> {

    List<BuildingOwnerRoomRel> listroomid(String ownerId);
}
