package com.zeroone.star.parkmanage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.parkmanage.entity.*;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.parkmanage.entity.OwnerCar;
import com.zeroone.star.parkmanage.entity.VehicleDO;
import com.zeroone.star.project.query.j7.parkmanage.ownervehicle.CarQuery;
import com.zeroone.star.project.vo.j7.parkmanage.ownervehicle.OwnerCarInfoVO;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Param;
import java.util.List;

import java.util.List;

@Mapper
public interface OwnerVehicleMapper extends BaseMapper<OwnerCar> {

    /**
     * 根据业主id查询用户id
     * @param ownerId
     * @return 用户id
     */
    @Select("select user_id from building_owner where owner_id = #{ownerId}")
    String selectUserIdByOwnerId(String ownerId);

    /**
     * 添加，包含所有字段
     */
    @Insert("INSERT INTO owner_car (" +
            "car_id, owner_id, b_id, car_num, car_brand, car_type, car_color, " +
            "ps_id, user_id, remark, create_time, community_id, start_time, end_time, " +
            "state, lease_type, member_id, status_cd, car_type_cd" +
            ") VALUES (" +
            "#{carId}, #{ownerId}, #{bId}, #{carNum}, #{carBrand}, #{carType}, #{carColor}, " +
            "#{psId}, #{userId}, #{remark}, #{createTime}, #{communityId}, #{startTime}, #{endTime}, " +
            "#{state}, #{leaseType}, #{memberId}, #{statusCd}, #{carTypeCd}" +
            ")")
    int inserOwnerCar(OwnerCar ownerCar);

    /**
     * 获取车辆列表（条件+分页）
     * @param carQuery
     * @return 车辆信息
     */
    Page<OwnerCarInfoVO> selectOwnerCarInfoByPage(@Param("page") Page<OwnerCarInfoVO> page, @Param("carQuery") CarQuery carQuery);

    /**
     * 根据车辆id查询车辆信息
     * @param carId
     * @return
     */
    VehicleDO getVehicleInfoByCarId(String carId);

    /**
     * 根据业主姓名和手机号查询业主信息
     * @param name 业主姓名
     * @param tel 业主手机号
     * @return BuildingOwner 业主信息，如果不存在则返回 null
     */
    BuildingOwner getOwnerByNameAndTel(@Param("name") String name, @Param("tel") String tel);

    /**
     * 根据停车场区域和车位编号查询车位信息
     * @param areaNum 停车场区域编号
     * @param spaceNum 车位编号
     * @return ParkingSpace 车位信息，如果不存在则返回 null
     */
    ParkingSpace getParkingSpaceByNums(@Param("areaNum") String areaNum, @Param("spaceNum") String spaceNum);

    /**
     * 检查指定车牌号的车辆是否存在且状态不是"车位释放" (3003)
     * @param carNum 车牌号
     * @return 匹配到的车辆数量
     */
    @Select("SELECT COUNT(*) FROM owner_car WHERE car_num = #{carNum} AND state != '3003' AND status_cd = '0'")
    int checkCarNumberExistsActive(@Param("carNum") String carNum);

    /**
     * 检查指定车位ID是否已被占用且状态不是"车位释放" (3003)
     * @param psId 车位ID
     * @return 占用该车位的车辆数量
     */
    @Select("SELECT COUNT(*) FROM owner_car WHERE ps_id = #{psId} AND state != '3003' AND status_cd = '0'")
    int checkParkingSpaceOccupiedActive(@Param("psId") String psId);

    /**
     * 插入停车区域
     * @param parkingArea 停车区域信息
     * @return 影响行数
     */
    int insertParkingArea(ParkingArea parkingArea);

    /**
     * 插入车位信息
     * @param parkingSpace 车位信息
     * @return 影响行数
     */
    int insertParkingSpace(ParkingSpace parkingSpace);

    /**
     * 插入业务订单
     * @param order 订单信息
     * @return 影响行数
     */
    int insertOrder(COrders order);

    /**
     * 插入操作日志
     * @param log 日志信息
     * @return 影响行数
     */
    int insertLog(UnitemLog log);

    /**
     * 根据停车场编号和小区ID查询停车场信息
     * @param num 停车场编号
     * @param communityId 小区ID
     * @return ParkingArea 停车场信息，如果不存在则返回 null
     */
    ParkingArea getParkingAreaByNumAndCommunityId(@Param("num") String num, @Param("communityId") String communityId);

    /**
     * 根据车位编号和停车场ID查询车位信息
     * @param num 车位编号
     * @param paId 停车场ID
     * @return ParkingSpace 车位信息，如果不存在则返回 null
     */
    ParkingSpace getParkingSpaceByNumAndPaId(@Param("num") String num, @Param("paId") String paId);

    /**
     * 根据车牌号查询车辆记录列表
     * @param carNumber 车牌号
     * @return 车辆记录列表
     */
    @Select("SELECT oc.*, ps.num as spaceNum, pa.num as areaNum FROM owner_car oc " +
            "LEFT JOIN parking_space ps ON oc.ps_id = ps.ps_id " +
            "LEFT JOIN parking_area pa ON ps.pa_id = pa.pa_id " +
            "WHERE oc.car_num = #{carNumber} " +
            "AND oc.status_cd = '0' " +
            "ORDER BY oc.create_time DESC")
    List<OwnerCar> findCarsByCarNum(@Param("carNumber") String carNumber);

    /**
     * 根据车牌号和车位ID查询车辆的所有历史记录
     * @param carNumber 车牌号
     * @param psId 车位ID
     * @return 车辆历史记录列表
     */
    List<OwnerCar> findCarHistoryByCarNumAndPsId(@Param("carNumber") String carNumber, @Param("psId") String psId);

    /**
     * 插入业务车辆记录
     * @param businessOwnerCar 业务车辆记录
     * @return 影响行数
     */
    int insertBusinessOwnerCar(BusinessOwnerCar businessOwnerCar);

    /**
     * 获取指定车牌号的最后一条有效记录
     * @param carNum 车牌号
     * @return 最后一条有效记录
     */
    @Select("SELECT * FROM owner_car WHERE car_num = #{carNum} AND status_cd = '0' ORDER BY create_time DESC LIMIT 1")
    OwnerCar getLastValidCarByCarNum(@Param("carNum") String carNum);

    @Select("SELECT * FROM owner_car WHERE car_num = #{carNum} AND status_cd = '0'")
    OwnerCar getCarInfoByCarNum(String carNumber);

    /**
     * 根据车牌号和业主ID查询车辆信息
     * @param carNumber 车牌号
     * @param memberId 业主ID
     * @return OwnerCar 车辆信息，如果不存在则返回 null
     */
    @Select("SELECT * FROM owner_car WHERE car_num = #{carNumber} AND member_id = #{memberId} AND status_cd = '0'")
    OwnerCar getCarByNumberAndOwner(String carNumber, String memberId);

    /**
     * 根据车牌号和车位ID查询有效的、未释放的车辆记录
     * @param carNumber 车牌号
     * @param psId 车位ID
     * @return OwnerCar 车辆记录，如果不存在或状态不符则返回 null
     */
    @Select("SELECT * FROM owner_car WHERE car_num = #{carNumber} AND ps_id = #{psId} AND status_cd = '0' AND state = '1001'")
    OwnerCar getActiveCarByCarNumAndPsId(@Param("carNumber") String carNumber, @Param("psId") String psId);
}
