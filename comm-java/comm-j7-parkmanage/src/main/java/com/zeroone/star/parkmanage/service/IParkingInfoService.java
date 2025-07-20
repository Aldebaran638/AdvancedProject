package com.zeroone.star.parkmanage.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinginfo.BatchAddParkingSpacesDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinginfo.GetParkingSpaceDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinginfo.ParkingSpaceDTO;
import com.zeroone.star.project.query.j7.parkmanage.parkinginfo.ParkingInfoQuery;

/**
 * 车位管理接口
 */
public interface IParkingInfoService {
    /**
     * 保存车位信息
     * @param parkingSpaceDTO 停车信息传输对象
     */
    void save(ParkingSpaceDTO parkingSpaceDTO);

    /**
     * 更新车位信息
     * @param parkingSpaceDTO 停车信息传输对象
     */
    void update(ParkingSpaceDTO parkingSpaceDTO);

    /**
     * 删除车位信息
     * @param psId 车位信息ID
     */
    void remove(Long psId);

    /**
     * 分页查询车位信息
     * @param query
     * @return
     */
    PageDTO<GetParkingSpaceDTO> listParkingSpace(ParkingInfoQuery query);

    String saveBatch(BatchAddParkingSpacesDTO batchAddParkingSpacesDTO);
}
