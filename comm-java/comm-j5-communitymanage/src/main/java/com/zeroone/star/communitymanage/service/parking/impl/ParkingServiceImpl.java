package com.zeroone.star.communitymanage.service.parking.impl;

import com.zeroone.star.communitymanage.entity.parking.ReportOweFee;
import com.zeroone.star.communitymanage.config.ParkingNameConfig;
import com.zeroone.star.communitymanage.mapper.parking.ParkingMapper;
import com.zeroone.star.communitymanage.mapper.parking.ReportOweFeeMapper;
import com.zeroone.star.communitymanage.service.parking.IParkingService;

import com.zeroone.star.project.query.j5.community.parking.ParkingQuery;
import com.zeroone.star.project.vo.j5.community.parking.ParkingVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.math.BigDecimal;
import java.util.List;


/**
 * 车位结构业务层
 */
@Service
public class ParkingServiceImpl implements IParkingService {

    @Autowired
    private ReportOweFeeMapper reportOweFeeMapper;

    @Autowired
    private ParkingMapper parkingMapper;

    @Override
    @Transactional
    public List<ParkingVO> listparking(ParkingQuery query) {

        List<ParkingVO> selectpark = parkingMapper.selectpark(query);
        for (int i = 0; i < selectpark.size(); i++) {
            ParkingVO parkingVO = selectpark.get(i);
            String carNum = parkingVO.getCarNum();
            String areaNum = parkingVO.getAreaNum();
            String num = parkingVO.getNum();
            //渝a13111-1停车场-16车位
            String name = carNum + "-" + areaNum + ParkingNameConfig.PARKING_NAME + "-" + num + ParkingNameConfig.AREA_NUM;
            System.out.println(name);
            ReportOweFee reportOweFee =reportOweFeeMapper.listfee(name);
            if(reportOweFee==null){
                parkingVO.setOweAmount(new BigDecimal("0.00"));
            }else {
                parkingVO.setOweAmount(reportOweFee.getAmountOwed());
            }
        }

        return selectpark;
    }
}
