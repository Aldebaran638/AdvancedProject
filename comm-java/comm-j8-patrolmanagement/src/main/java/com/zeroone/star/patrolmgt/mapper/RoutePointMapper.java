package com.zeroone.star.patrolmgt.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.patrolmgt.entity.zhangyvsen_InspectionPoint;
import com.zeroone.star.project.j8.patrolmgt.point.query.RoutePointQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

@Mapper
public interface RoutePointMapper extends BaseMapper<zhangyvsen_InspectionPoint> {
    @Select({
            "<script>",
            "SELECT p.*, r.point_start_time, r.point_end_time",
            "FROM inspection_point p",
            "LEFT JOIN inspection_route_point_rel r ON p.inspection_id = r.inspection_id",
            "WHERE r.community_id = #{query.communityId}",
            "AND r.inspection_route_id = #{query.inspectionRouteId}",
            "</script>"
    })
    Page<zhangyvsen_InspectionPoint> selectPointsWithTimeByRoute(
            @Param("query") RoutePointQuery query,
            Page<zhangyvsen_InspectionPoint> page
    );
}
