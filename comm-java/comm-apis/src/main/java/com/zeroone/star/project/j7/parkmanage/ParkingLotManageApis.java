package com.zeroone.star.project.j7.parkmanage;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j7.parkmanage.parkinginfo.ListParkingAreaQuery;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.InsertParkingLotDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.UpdateParkingLotDTO;
import com.zeroone.star.project.vo.JsonVO;

import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.GetParkingLotDTO;
import com.zeroone.star.project.query.j7.parkmanage.parkinglotmanage.GetParkingLotQuery;
import com.zeroone.star.project.vo.j7.parkmanage.parkinginfo.ParkingAreaVO;

import java.util.List;

/**
 * @author neko
 * #Description：停车场管理apis
 * #Date: 2025/5/19 17:56
 */
public interface ParkingLotManageApis {

    /**
     *  获取停车场名称列表
      * @param requestParam 请求参数
     * @return 停车场名称
     */
    JsonVO<ParkingAreaVO> listParkingAreaName(ListParkingAreaQuery requestParam);

    /**
     * 删除停车场
     * @param paId
     * @return
     */
    JsonVO<String> removeParkingLot(String paId);

    /**
     * 获得停车场信息
     * @return 停车场信息列表
     */
    JsonVO<PageDTO<GetParkingLotDTO>> listParkingLots(GetParkingLotQuery query);

    /**
     * 添加停车场
     * @param insertParkingLotDTO 添加停车场DTO
     * @return 提示信息
     */
    JsonVO<String> insertParkingLot(InsertParkingLotDTO insertParkingLotDTO);

    /**
     * 修改停车场信息
     * @param updateParkingLotDTO 修改停车场DTO
     * @return 提示信息
     */
    JsonVO<String> updateParkingLot(UpdateParkingLotDTO updateParkingLotDTO);

}
