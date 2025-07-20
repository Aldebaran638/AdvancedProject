package com.zeroone.star.parkmanage.service;

import com.zeroone.star.parkmanage.entity.BuildingRoom;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author daimon
 * @since 2025-06-02
 */
public interface IBuildingRoomService extends IService<BuildingRoom> {
    String getRoomNum(String communityId,String bId);
}
