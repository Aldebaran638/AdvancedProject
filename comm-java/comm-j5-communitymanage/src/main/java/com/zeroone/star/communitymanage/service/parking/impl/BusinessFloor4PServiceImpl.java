package com.zeroone.star.communitymanage.service.parking.impl;

import com.zeroone.star.communitymanage.mapper.building.BusinessFloorMapper;
import com.zeroone.star.communitymanage.entity.building.BuildingUnit;
import com.zeroone.star.communitymanage.entity.building.BusinessFloor;
import com.zeroone.star.communitymanage.service.parking.IBusinessFloorService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author hh
 * @since 2025-05-23
 */
@Service
public class BusinessFloor4PServiceImpl extends ServiceImpl<BusinessFloorMapper, BusinessFloor> implements IBusinessFloorService {

    @Autowired
    private MsMapper msMapper;

    @Autowired
    private BusinessFloorMapper businessFloorMapper;

    /**
     * 从businessfloor获取楼编号
     * @param buildingUnit
     * @return
     */
    @Override
    public BusinessFloor getfloornum(BuildingUnit buildingUnit) {
        BusinessFloor businessFloor = msMapper.toBusinessFloor(buildingUnit);
        BusinessFloor businessFloor1 = businessFloorMapper.listfloornum(businessFloor);
        return businessFloor1;
    }
}
