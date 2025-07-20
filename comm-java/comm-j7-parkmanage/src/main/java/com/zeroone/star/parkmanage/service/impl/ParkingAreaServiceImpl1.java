package com.zeroone.star.parkmanage.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.parkmanage.entity.ParkingArea1;
import com.zeroone.star.parkmanage.mapper.ParkingAreaMapper1;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.parkmanage.service.IParkingAreaService1;
import org.springframework.stereotype.Service;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author wuven
 * @since 2025-05-26
 */
@Service
public class ParkingAreaServiceImpl1 extends ServiceImpl<ParkingAreaMapper1, ParkingArea1> implements IParkingAreaService1 {
    @Override
    public String getPaNum(String communityId,String bId) {
        QueryWrapper<ParkingArea1> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("community_id", communityId).eq("b_id",bId);
        ParkingArea1 parkingArea = baseMapper.selectOne(queryWrapper);
        if(parkingArea == null){
            return "null";
        }
        return parkingArea.getNum();
    }
}



