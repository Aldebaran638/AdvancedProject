package com.zeroone.star.communitymanage.mapper.parking;

import com.zeroone.star.communitymanage.entity.parking.OwnerCar;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author hh
 * @since 2025-05-23
 */
@Mapper
public interface OwnerCarMapper extends BaseMapper<OwnerCar> {

    @Select("select owner_id,ps_id,car_num from owner_car where community_id = #{communityId}")
    List<OwnerCar> selectcar(OwnerCar ownerCar);
}
