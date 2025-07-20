package com.zeroone.star.communitymanage.service.parking;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.communitymanage.entity.building.BuildingOwner;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author hh
 * @since 2025-05-24
 */
public interface IBuildingOwnerService extends IService<BuildingOwner> {

    List<BuildingOwner> getname(String ownerId);
}
