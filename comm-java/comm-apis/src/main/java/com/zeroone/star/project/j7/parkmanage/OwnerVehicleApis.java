package com.zeroone.star.project.j7.parkmanage;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.*;
import com.zeroone.star.project.query.j7.parkmanage.ownervehicle.*;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j7.parkmanage.ownervehicle.OwnerCarInfoVO;
import com.zeroone.star.project.vo.j7.parkmanage.ownervehicle.OwnerVehicleVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.ModifyOwnerVehicleDTO;

import java.util.Map;

/**
 * @author neko
 * #Description：业主车辆apis
 * #Date: 2025/5/19 17:55
 */
public interface OwnerVehicleApis {

    /**
     * 获取车辆修改信息列表（条件+分页）
     * @param query
     * @return
     */
    JsonVO<PageDTO<ModifyRecordDTO>> queryModifyRecordList(ModifyRecordQuery query);
    /**
     * 获取成员车辆信息（条件+分页）
     * @param query
     * @return
     */
    JsonVO<PageDTO<MemberVehicleDTO>> queryMemberVehicleList(MemberVehicleQuery query);
    /**
     * 添加成员车辆
     * @param memberVehicleDTO
     * @return
     */
    JsonVO<String> addMemberVehicle(AddMemberVehicleDTO memberVehicleDTO);







    /**
     * 获取车辆信息
     *
     * @param
     * @return
     */
    JsonVO<OwnerVehicleVO> getOwnerVehicleInfo(String carId);


    /**
     * 导入车辆
     * @param file
     * @return
     */
    JsonVO<String> importVehicle(MultipartFile file);


    /**
     * 导出车辆
     * @param query
     * @return
     */
    JsonVO<Map<String, String>> exportVehicle(ExportCarQuery query);
    /**
     *  添加车辆
     * @param addCarDTO 添加车辆数据对象
     * @return 添加结果
     */
    JsonVO<String> addCar(AddCarDTO addCarDTO);

    /**
     * 修改车辆
     * @param carDTO 修改车辆数据对象
     * @return 修改结果
     */
    JsonVO<String> modifyCar(CarDTO carDTO);

    /**
     * 分页查询车辆列表
     * @param carQuery 查询数据对象
     * @return 查询结果
     */
    JsonVO<PageDTO<OwnerCarInfoVO>> queryCarList(CarQuery carQuery);
    /**
     * 删除车辆
     * @param carId 业主车辆id
     * @return 删除车辆返回的结果
     */
    JsonVO<String> removeOwnerVehicle(String carId);

    /**
     * 释放车位
     * @param carId 业主车辆id
     * @return 释放车位返回的结果
     */
    JsonVO<String> modifyOwnerVehicleByReleaseParkingSpace(String carId);

    /**
     * 续租车位
     * @param  dto 续租车位数据对象
     * @return 续租车位返回的结果
     */
    JsonVO<String> modifyOwnerVehicleByRenewParkingSpaceLease(RenewParkingSpaceLeaseDTO dto);
  /**
     * 修改业主车辆信息
     * @param dto 修改业主车辆信息参数
     * @return 修改业主车辆信息结果
     */
    JsonVO<String> modifyOwnerVehicle(ModifyOwnerVehicleDTO dto);
   /**
     * 删除业主车辆信息
     * @param car_id 车辆id
     * @return 删除业主车辆信息结果
     */
    JsonVO<String> deleteOwnerVehicle(String car_id);
}
