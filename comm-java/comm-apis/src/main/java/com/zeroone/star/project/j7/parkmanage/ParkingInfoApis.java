package com.zeroone.star.project.j7.parkmanage;

import com.zeroone.star.project.dto.j7.parkmanage.parkinginfo.GetParkingSpaceDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinginfo.ParkingSpaceDTO;
import com.zeroone.star.project.vo.JsonVO;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinginfo.BatchAddParkingSpacesDTO;
import com.zeroone.star.project.query.j7.parkmanage.parkinginfo.ParkingInfoQuery;

/**
 * @author neko
 * #Description：车位信息apis
 * #Date: 2025/5/19 17:56
 */
public interface ParkingInfoApis {
	/**
	 * 新增车位接口
	 * @param parkingSpaceDTO 保存的数据
	 */
	JsonVO<String> save(ParkingSpaceDTO parkingSpaceDTO);

	/**
	 * 修改车位信息
	 * @param parkingSpaceDTO 新修改的数据
	 */
	JsonVO<String> update(ParkingSpaceDTO parkingSpaceDTO);

	/**
	 * 删除车位接口
	 * @param psId 车位id
	 */
	JsonVO<String> remove(Long psId);


    /**
     * 分页查询车位信息
     * @param query 查询参数
     * @return 车位信息
     */
    JsonVO<PageDTO<GetParkingSpaceDTO>> queryParkingInfo(ParkingInfoQuery query);

    /**
     * 批量添加车位
     * @param batchAddParkingSpacesDTO 批量添加车位参数
     * @return 添加结果
     */
    JsonVO<String> batchAddParkingSpaces(BatchAddParkingSpacesDTO batchAddParkingSpacesDTO);
}
