package com.zeroone.star.communitymanage.service.building;

import com.zeroone.star.communitymanage.entity.building.BuildingOwnerRoomRel;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j5.community.building.BuildingOwnerRoomRelDTO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author langzi
 * @since 2025-05-23
 */
public interface IBuildingOwnerRoomRelService extends IService<BuildingOwnerRoomRel> {

    BuildingOwnerRoomRelDTO getByRoomId(String roomId);
}
