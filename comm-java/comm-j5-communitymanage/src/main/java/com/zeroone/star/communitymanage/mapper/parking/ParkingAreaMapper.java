package com.zeroone.star.communitymanage.mapper.parking;

import com.zeroone.star.communitymanage.entity.parking.ParkingArea;
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
public interface ParkingAreaMapper extends BaseMapper<ParkingArea> {

    @Select("select num  from parking_area where pa_id = #{paId}")
    ParkingArea listparkingarea(String paId);
}
