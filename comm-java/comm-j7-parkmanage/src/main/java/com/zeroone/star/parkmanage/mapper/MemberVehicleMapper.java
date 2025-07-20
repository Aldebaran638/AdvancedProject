package com.zeroone.star.parkmanage.mapper;

import com.zeroone.star.parkmanage.entity.MemberVehicle;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.ModifyOwnerVehicleDTO;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 会员车辆信息表 Mapper 接口
 * </p>
 *
 * @author yourName
 * @since 2025-06-04
 */
@Mapper
public interface MemberVehicleMapper extends BaseMapper<MemberVehicle> {

}
