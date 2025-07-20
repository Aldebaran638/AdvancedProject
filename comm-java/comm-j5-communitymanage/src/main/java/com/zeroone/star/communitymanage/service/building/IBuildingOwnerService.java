package com.zeroone.star.communitymanage.service.building;

import com.zeroone.star.communitymanage.entity.building.BuildingOwner;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j5.community.building.BuildingOwnerDTO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author langzi
 * @since 2025-05-23
 */
public interface IBuildingOwnerService extends IService<BuildingOwner> {

    public BuildingOwnerDTO getOwnerInfoByOwnerId(String ownerId);
}
