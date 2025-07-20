package com.zeroone.star.patrolmgt.service.Imp;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.patrolmgt.entity.zhangyvsen_InspectionPoint;
import com.zeroone.star.patrolmgt.entity.zhangyvsen_InspectionRoutePointRel;
import com.zeroone.star.patrolmgt.mapper.zhangyvsen_RoutePointRelMapper;
import com.zeroone.star.patrolmgt.mapper.RoutePointMapper;
import com.zeroone.star.patrolmgt.service.QueryRoutePointService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.point.query.RoutePointQuery;
import com.zeroone.star.project.j8.patrolmgt.point.dto.RoutePointDTO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

@Service
public class QueryRoutePointServiceImp extends
        ServiceImpl<RoutePointMapper, zhangyvsen_InspectionPoint>
         implements QueryRoutePointService {

    @Autowired
    zhangyvsen_RoutePointRelMapper zhangyvsen_RoutePointRelMapper;
    @Autowired
    MsInspectionPointMapper  msInspectionPointMapper;


    public PageDTO<RoutePointDTO> listAllPoint(RoutePointQuery query) {
        // 构建分页对象
        Page<zhangyvsen_InspectionPoint> page = new Page<>(query.getPageIndex(), query.getPageSize());

        // 调用联表查询
        Page<zhangyvsen_InspectionPoint> pageResult = baseMapper.selectPointsWithTimeByRoute(query, page);

       // 返回结果
        return PageDTO.create(pageResult, src -> msInspectionPointMapper.toDTO(src));


    }

}
