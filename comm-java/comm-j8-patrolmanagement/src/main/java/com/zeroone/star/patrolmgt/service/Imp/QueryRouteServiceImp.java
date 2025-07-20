package com.zeroone.star.patrolmgt.service.Imp;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.patrolmgt.entity.zhangyvsen_InspectionRoute;
import com.zeroone.star.patrolmgt.mapper.RouteMapper;
import com.zeroone.star.patrolmgt.service.QueryRouteService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.route.dto.zhangyvsen_RouteDTO;
import com.zeroone.star.project.j8.patrolmgt.route.query.RouteNameQuery;
import com.zeroone.star.project.j8.patrolmgt.route.query.RouteQuery;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class QueryRouteServiceImp extends ServiceImpl<RouteMapper, zhangyvsen_InspectionRoute> implements QueryRouteService {
    @Autowired
    MsInspectionRouteMapper msInspectionRouteMapper;

    @Override
    public PageDTO<zhangyvsen_RouteDTO> listAll(RouteQuery query) {
        //构建分页查询对象
        Page<zhangyvsen_InspectionRoute> page = new Page<zhangyvsen_InspectionRoute>(query.getPageIndex(),query.getPageSize());
        QueryWrapper<zhangyvsen_InspectionRoute> wrapper = new QueryWrapper<zhangyvsen_InspectionRoute>();
        //当查询条件为空时，查询所有数据
        if (query.getRouteName()==null&&query.getSeq()==null&&query.getInspectionRouteId()==null) {
            wrapper.eq("community_id", query.getCommunityId());
            Page<zhangyvsen_InspectionRoute> pageResult = baseMapper.selectPage(page,wrapper);
            return PageDTO.create(pageResult, src-> msInspectionRouteMapper.toDTO(src));
        }

        //构建查询条件
        //社区id不能为空
        if (StringUtils.isBlank(query.getCommunityId())) {
            throw new IllegalArgumentException("communityId 不能为空");
        }
        wrapper
                .eq(StringUtils.isNotBlank(query.getCommunityId()), "community_id", query.getCommunityId());
        // 路线ID不为空时加入查询条件
        if (StringUtils.isNotBlank(query.getInspectionRouteId())) {
            wrapper.eq("inspection_route_id", query.getInspectionRouteId());
        }

        // 路线名称不为空时加入查询条件
        if (StringUtils.isNotBlank(query.getRouteName())) {
            wrapper.eq("route_name", query.getRouteName());
        }

        // 序号不为空时加入查询条件
        if (query.getSeq() != null) {
            wrapper.eq("seq", query.getSeq());
        }

        //查询结果
        Page<zhangyvsen_InspectionRoute> pageResult = baseMapper.selectPage(page,wrapper);
        //返回结果
        return PageDTO.create(pageResult, src-> msInspectionRouteMapper.toDTO(src));
    }

    @Override
    public List<String> listRouteName(RouteNameQuery query) {
        //构建查询对象
        QueryWrapper wrapper=new QueryWrapper<>();
        wrapper
                .select("route_name")
                .eq("community_id",query.getCommunityId());
        // 查询结果并转换为 List<String>
        List<String> routeNames = baseMapper.selectObjs(wrapper);
        return routeNames;


    }
}
