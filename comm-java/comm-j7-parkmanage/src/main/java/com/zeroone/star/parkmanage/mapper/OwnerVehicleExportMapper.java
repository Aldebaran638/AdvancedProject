package com.zeroone.star.parkmanage.mapper;

import com.zeroone.star.parkmanage.entity.VehicleDO;
import com.zeroone.star.project.query.j7.parkmanage.ownervehicle.ExportCarQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * @author 岚图
 * #Description：业主车辆Mapper接口
 * #Date: 2025/5/22
 */
@Mapper
public interface OwnerVehicleExportMapper {

    /**
     * 根据条件查询导出车辆数据
     * @param query 查询条件 (ExportCarQuery)
     * @return 包含导出字段的PO列表
     */
    List<VehicleDO> selectVehiclesForExport(@Param("query") ExportCarQuery query);

} 