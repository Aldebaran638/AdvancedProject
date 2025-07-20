package com.zeroone.star.parkmanage.mapper;


import com.zeroone.star.parkmanage.entity.VehicleDO;
import com.zeroone.star.project.vo.j7.parkmanage.ownervehicle.OwnerVehicleVO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.Mappings;
import org.mapstruct.factory.Mappers;

import java.text.SimpleDateFormat;
import java.util.Date;

@Mapper
public interface VehicleStructMapper {

    /**
     * 映射器
     */
    VehicleStructMapper INSTANCE = Mappers.getMapper(VehicleStructMapper.class);

    /**
     * 转换车辆DO为VO
     * @param vehicleDO
     * @return
     */
    @Mappings({
            // 时间类型转换
            @Mapping(target = "startTime", expression = "java(formatDate(vehicleDO.getStartTime()))"),
            @Mapping(target = "endTime", expression = "java(formatDate(vehicleDO.getEndTime()))")
    })
    OwnerVehicleVO toVO(VehicleDO vehicleDO);

    // 时间格式化方法
    default String formatDate(Date date) {
        if (date == null) return null;
        return new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(date);
    }
}
