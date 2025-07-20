package com.zeroone.star.communitymanage.service.building;

import com.zeroone.star.communitymanage.entity.building.BusinessFloor;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j5.community.building.BusinessFloorDTO;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author langzi
 * @since 2025-05-23
 */
public interface IBusinessFloorService extends IService<BusinessFloor> {
    BusinessFloorDTO getFloorNumByCommunityIdAndFloorId(String communityId, String floorId);

    List<BusinessFloorDTO> getFloorDTOByCommunityId(String communityId);
}
