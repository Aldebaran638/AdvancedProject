package com.zeroone.star.patrolmgt.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.patrolmgt.entity.Susu_InspectionPoint;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.point.dto.PointDTO;
import com.zeroone.star.project.j8.patrolmgt.point.dto.SelectPointDTO;
import com.zeroone.star.project.j8.patrolmgt.point.query.PointQuery;
import com.zeroone.star.project.j8.patrolmgt.point.query.SelectPointQuery;

/**
 * <p>
 * 巡检点服务接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Susu
 * @since 2025-05-19
 */
public interface IPatrolPointService extends IService<Susu_InspectionPoint> { // 继承 IService，指定主实体为 InspectionPoint

    /**
     * 分页查询巡检点列表
     * 根据查询条件和分页参数，获取巡检点列表数据，包含巡检点类型和项目名称。
     * @param query 查询条件和分页参数
     * @return 封装了分页信息和 PointDTO 列表的 PageDTO
     */
    PageDTO<PointDTO> listPatrolPoints(PointQuery query);

    /**
     * 选择巡检点时分页查询巡检点列表
     * 根据查询条件和分页参数，获取巡检点列表数据，包含巡检点类型和项目名称。
     * @param query 查询条件和分页参数
     * @return 封装了分页信息和 PointDTO 列表的 PageDTO
     */
    PageDTO<SelectPointDTO> listSelectablePoints(SelectPointQuery query);

    /**
     * 更新已存在的巡检点信息。
     * @param pointDto 包含更新信息的巡检点DTO
     * @return 受影响的行数 (例如 1 表示成功, 0 表示未找到或无变化, <0 表示错误 - though updateById usually returns 0 or 1)
     * Or throw business exceptions for specific error conditions.
     */
    int updateExistingPatrolPoint(PointDTO pointDto);

}
