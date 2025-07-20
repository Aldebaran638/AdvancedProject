package com.zeroone.star.parkmanage.service.impl;

import com.alibaba.nacos.shaded.org.checkerframework.checker.units.qual.A;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.parkmanage.entity.ParkingAreaAttr;
import com.zeroone.star.parkmanage.mapper.ParkingAreaAttrMapper;
import com.zeroone.star.parkmanage.service.IParkingAreaAttrService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
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
public class ParkingAreaAttrServiceImpl extends ServiceImpl<ParkingAreaAttrMapper, ParkingAreaAttr> implements IParkingAreaAttrService {

    @Autowired
    private ParkingAreaAttrMapper parkingAreaAttrMapper;

    @Override
    public String getOutNum(String padId) {
        QueryWrapper<ParkingAreaAttr> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("pa_id", padId);
        ParkingAreaAttr parkingAreaAttr = parkingAreaAttrMapper.selectOne(queryWrapper);
        String num=parkingAreaAttr.getValue();
        return num;
    }
}
