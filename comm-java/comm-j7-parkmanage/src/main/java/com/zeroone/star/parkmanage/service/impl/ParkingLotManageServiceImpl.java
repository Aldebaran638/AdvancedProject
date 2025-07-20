package com.zeroone.star.parkmanage.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.parkmanage.entity.BusinessParkingArea;
import com.zeroone.star.parkmanage.entity.ParkingArea;
import com.zeroone.star.parkmanage.entity.ParkingSpace;
import com.zeroone.star.parkmanage.mapper.BusinessParkingLotManageMapper;
import com.zeroone.star.parkmanage.mapper.ParkingLotManageMapper;
import com.zeroone.star.parkmanage.mapper.ParkingSpaceMapper;
import com.zeroone.star.parkmanage.service.IParkingLotManageService;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.GetParkingLotDTO;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;

@Service
public class ParkingLotManageServiceImpl extends ServiceImpl<ParkingLotManageMapper, ParkingArea> implements IParkingLotManageService {

    @Resource
    private BusinessParkingLotManageMapper businessParkingLotManageMapper;

    @Resource
    private ParkingSpaceMapper parkingSpaceMapper;
    @Transactional
    @Override
    public void removeById(String paId) {
        // 检查该停车场是否有车位
        QueryWrapper<ParkingSpace> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("pa_id", paId);
        if (parkingSpaceMapper.selectCount(queryWrapper) > 0) {
            throw new RuntimeException("该停车场有车位，请先删除车位！");
        }
        ParkingArea parkingArea = new ParkingArea();
        parkingArea.setPaId(paId);
        parkingArea.setStatusCd("1");
        baseMapper.updateById(parkingArea);
        //TODO 等businessParkingArea写完后再写
        BusinessParkingArea businessParkingArea = businessParkingLotManageMapper.selectById(paId);
        businessParkingArea.setOperate("DEL");
        businessParkingLotManageMapper.insert(businessParkingArea);
    }
}
