package com.zeroone.star.communitymanage.service.building.impl;

import com.zeroone.star.communitymanage.entity.building.BusinessFloor;
import com.zeroone.star.communitymanage.mapper.building.BusinessFloorMapper;
import com.zeroone.star.communitymanage.service.building.IBusinessFloorService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j5.community.building.BusinessFloorDTO;
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
public class BusinessFloorServiceImpl extends ServiceImpl<BusinessFloorMapper, BusinessFloor> implements IBusinessFloorService {

    @Resource
    BusinessFloorMapper businessFloorMapper;

    @Override
    public BusinessFloorDTO getFloorNumByCommunityIdAndFloorId(String communityId, String floorId) {
        return businessFloorMapper.getFloorNumByCommunityIdAndFloorId(communityId, floorId);
    }

    @Override
    public List<BusinessFloorDTO> getFloorDTOByCommunityId(String communityId) {
        return businessFloorMapper.getFloorDTOByCommunityId(communityId);
    }
}
