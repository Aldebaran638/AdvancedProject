package com.zeroone.star.parkmanage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.parkmanage.entity.ParkingAreaDO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinginfo.ParkingAreaDTO;
import com.zeroone.star.project.query.j7.parkmanage.parkinginfo.ListParkingAreaQuery;
import com.zeroone.star.project.vo.j7.parkmanage.parkinginfo.ParkingAreaVO;

public interface ParkingLotManagerService extends IService<ParkingAreaDO> {

    /**
     *获取停车场名称列表
     *
     * @param requestParam 请求参数
     * @return 停车场名称列表
     */
     ParkingAreaVO listParkingAreaName(ParkingAreaDTO requestParam);

}
