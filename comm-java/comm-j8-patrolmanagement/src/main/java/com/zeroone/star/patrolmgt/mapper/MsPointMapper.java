package com.zeroone.star.patrolmgt.mapper;

import com.zeroone.star.patrolmgt.entity.Susu_InspectionPoint;
import com.zeroone.star.project.j8.patrolmgt.point.dto.PointDTO;
// 根据需要引入其他巡检点相关的 DTO，比如 PointAddDTO
// import com.zeroone.star.project.dto.j8.patrolmgt.point.PointAddDTO;

import com.zeroone.star.project.j8.patrolmgt.point.dto.SelectPointDTO;
import org.mapstruct.Mapper;

/**
 * <p>
 * 描述：巡检点对应的MapStruct映射接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author Susu
 * @version 1.0.0
 */
@Mapper(componentModel = "spring") // componentModel = "spring" 让 MapStruct 生成的实现类作为 Spring Bean
public interface MsPointMapper {

    /**
     * 将 InspectionPoint 实体类转换为 PointDTO
     *
     * @param entity InspectionPoint 实体类
     * @return 转换结果 PointDTO
     */
    PointDTO toDto(Susu_InspectionPoint entity);

    /**
     * 将 InspectionPoint 实体类转换为 SelectPointDTO
     *
     * @param entity InspectionPoint 实体类
     * @return 转换结果 SelectPointDTO
     */
    SelectPointDTO inspectionPointToSelectPointDTO(Susu_InspectionPoint inspectionPoint);

}
