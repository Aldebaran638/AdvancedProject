package com.zeroone.star.parkmanage.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.parkmanage.entity.OwnerCar;
import com.zeroone.star.parkmanage.entity.ParkingSpace;
import com.zeroone.star.parkmanage.mapper.ParkingSpaceMapper;
import com.zeroone.star.parkmanage.service.IParkingSpaceService;
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
public class ParkingSpaceServiceImpl extends ServiceImpl<ParkingSpaceMapper, ParkingSpace> implements IParkingSpaceService {

    @Override
    public String getPsNum(String communityId,String bId) {
        QueryWrapper<ParkingSpace> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("community_id", communityId).eq("b_id",bId);
        ParkingSpace parkingSpace = baseMapper.selectOne(queryWrapper);
        if(parkingSpace == null){
            return "null";
        }
        return parkingSpace.getNum();
    }
}
