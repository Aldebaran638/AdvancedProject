package com.zeroone.star.communitymanage.mapper.parking;

import com.zeroone.star.communitymanage.entity.parking.ParkingSpace;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author hh
 * @since 2025-05-23
 */
@Mapper
public interface ParkingSpaceMapper extends BaseMapper<ParkingSpace> {

    @Select("select num,pa_id from parking_space where ps_id=#{psId}")
    ParkingSpace listparkingspace(String psId);
}
