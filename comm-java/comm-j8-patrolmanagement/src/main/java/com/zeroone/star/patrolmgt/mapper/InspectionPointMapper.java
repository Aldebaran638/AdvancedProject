package com.zeroone.star.patrolmgt.mapper;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.patrolmgt.entity.Susu_InspectionPoint;
import com.zeroone.star.project.j8.patrolmgt.point.dto.PointDTO;
import com.zeroone.star.project.j8.patrolmgt.point.query.PointQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 巡检点表 Mapper 接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Susu
 * @since 2025-05-19
 * @author susu,NiuJiaXu
 * @since 2025-05-19 // TODO 修改为当前日期
 */


@Mapper // 标记这是一个 MyBatis Mapper 接口
public interface InspectionPointMapper extends BaseMapper<Susu_InspectionPoint> { // 继承 BaseMapper，指定操作的 Entity 为 InspectionPoint

    // TODO 在这里定义自定义的数据库操作方法，特别是关联查询方法
    // 例如，用于分页查询包含关联表字段的巡检点数据：
    // Page<PointDTO> selectPatrolPointDtoPage(@Param("page") Page<InspectionPoint> page, @Param("ew") QueryWrapper<InspectionPoint> queryWrapper);
    // 或者返回 Map 或自定义 VO 的分页方法，具体取决于你的关联查询结果映射方式
    /**
     * 分页查询巡检点列表，包含关联表的名称信息
     * @param page 分页对象
     * @param queryWrapper 查询条件包装器
     * @return 包含 PointDTO 列表的分页结果
     */
    Page<PointDTO> selectPatrolPointPageWithJoin(Page<Susu_InspectionPoint> page, @Param("ew") QueryWrapper<Susu_InspectionPoint> queryWrapper, @Param("query") PointQuery query);

    /**
     * 删除巡检点
     *
     * @param inspectionId 巡检点主键
     * @return 结果
     */
    public int deleteInspectionPointByInspectionId(String inspectionId);
}
