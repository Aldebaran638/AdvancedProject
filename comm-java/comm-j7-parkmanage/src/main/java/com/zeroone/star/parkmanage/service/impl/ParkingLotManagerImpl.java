package com.zeroone.star.parkmanage.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.parkmanage.entity.ParkingAreaDO;
import com.zeroone.star.parkmanage.mapper.ParkingAreaDOMapper;
import com.zeroone.star.parkmanage.mapper.ParkingAreaMapper;
import com.zeroone.star.parkmanage.service.ParkingLotManagerService;
import com.zeroone.star.project.dto.j7.parkmanage.parkinginfo.ParkingAreaDTO;
import com.zeroone.star.project.query.j7.parkmanage.parkinginfo.ListParkingAreaQuery;
import com.zeroone.star.project.vo.j7.parkmanage.parkinginfo.ParkingAreaVO;
import lombok.RequiredArgsConstructor;
import lombok.SneakyThrows;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
@RequiredArgsConstructor
public class ParkingLotManagerImpl extends ServiceImpl<ParkingAreaDOMapper, ParkingAreaDO> implements ParkingLotManagerService {
    private final ParkingAreaDOMapper parkingAreaMapper;

    @SneakyThrows
    @Override
    public ParkingAreaVO listParkingAreaName(ParkingAreaDTO parkingAreaDTO) {
        ParkingAreaDO parkingAreaDO = ParkingAreaDO.builder()
                .typeCd(parkingAreaDTO.getTypeCd())
                .communityId(parkingAreaDTO.getCommunityId())
                .statusCd(parkingAreaDTO.getStatusCd())
                .build();

        List<String> parkingAreaNums = parkingAreaMapper.selectParkingAreaNums(parkingAreaDO);
        if (parkingAreaNums == null || parkingAreaNums.isEmpty()){
            throw new Exception("查询结果不存在");
        }

        ParkingAreaVO parkingAreaVO = ParkingAreaVO.builder()
                .names(parkingAreaNums)
                .build();
        return parkingAreaVO;
    }
}
