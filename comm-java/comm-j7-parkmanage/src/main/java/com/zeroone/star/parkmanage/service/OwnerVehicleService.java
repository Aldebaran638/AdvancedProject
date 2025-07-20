package com.zeroone.star.parkmanage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.parkmanage.entity.OwnerCar;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.AddCarDTO;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.RenewParkingSpaceLeaseDTO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j7.parkmanage.ownervehicle.CarQuery;
import com.zeroone.star.project.query.j7.parkmanage.ownervehicle.ExportCarQuery;
import com.zeroone.star.project.vo.j7.parkmanage.ownervehicle.ExportVehicleVO;
import com.zeroone.star.project.vo.j7.parkmanage.ownervehicle.OwnerCarInfoVO;
import com.zeroone.star.project.vo.j7.parkmanage.ownervehicle.OwnerVehicleVO;

import java.util.List;

public interface OwnerVehicleService extends IService<OwnerCar> {

    /**
     * 获取添加车辆所需的userId
     * @param ownerId
     * @return 用户id
     */
    String selectUserIdByOwnerId(String ownerId);

    PageDTO<OwnerCarInfoVO> selectOwnerCarInfoByPage(CarQuery carQuery);

    void save(AddCarDTO addCarDTO);

    /**
     * 触发车辆导出任务
     * @param query 筛选条件 (使用CarQuery)
     * @return 生成的Excel文件字节数组
     */
    byte[] triggerExport(ExportCarQuery query);

    /**
     * 根据条件获取需要导出的车辆数据 (内部方法)
     * @param query 筛选条件 (使用CarQuery)
     * @return 车辆导出数据列表
     */
    List<ExportVehicleVO> getExportVehicleData(ExportCarQuery query);

    /**
     * 根据车辆ID获取车辆详细信息
     * @param carId 车辆ID
     * @return 车辆详细信息VO
     */
    OwnerVehicleVO getVehicleInfoByCarId(String carId);

    /**
     * 导入车辆
     * @param tempFilePath 临时文件路径
     * @return 导入结果信息（成功/失败原因）
     */
    String importVehicleData(String tempFilePath);

    /**
     * 删除车辆
     * @param carId 车辆ID
     * @return 删除结果信息（成功/失败原因）
     */
    String removeVehicle(String carId);

     /**
     * 释放车位
     * @param   carId 车辆ID
     * @return 释放车位结果信息（成功/失败原因）
     */
    String updateOwnerVehicleByReleaseParkingSpace( String carId);

     /**
     * 续租车位
     * @param dto 续租车位参数
     * @return 续租车位结果信息（成功/失败原因）
     */
    String updateOwnerVehicleByRenewParkingSpaceLease(RenewParkingSpaceLeaseDTO dto);
}

