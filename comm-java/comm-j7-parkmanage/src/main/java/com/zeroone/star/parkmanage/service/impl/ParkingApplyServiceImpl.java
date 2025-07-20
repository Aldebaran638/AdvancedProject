package com.zeroone.star.parkmanage.service.impl;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.parkmanage.entity.ParkingApply;
import com.zeroone.star.parkmanage.mapper.ParkingApplyMapper;
import com.zeroone.star.parkmanage.service.IParkingApplyService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.AddApplyDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.ApplyDTO;
import com.zeroone.star.project.query.j7.parkmanage.parkingapply.GetParkingApplyQuery;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 车位申请记录表 服务实现类
 * </p>
 *
 * @author zhangjiaqi
 * @since 2025-05-25
 */
@Service
public class ParkingApplyServiceImpl extends ServiceImpl<ParkingApplyMapper, ParkingApply> implements IParkingApplyService {
    @Resource
    com.zeroone.star.parkmanage.service.impl.MsParkingApplyMapper msParkingApplyMapper;


    @Override
    public PageDTO<ApplyDTO> queryParkingApplyQuery(GetParkingApplyQuery query, String id, String apply_person_name, String car_brand) {
        Page<ParkingApply> page = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<ParkingApply> wrapper = new QueryWrapper<>();

        // 如果 id 不为空，则添加精确查询条件
        if (StringUtils.isNotEmpty(id)) {
            wrapper.eq("id", id);
        }

        // 如果 apply_person_name 不为空，则添加模糊查询条件
        if (StringUtils.isNotEmpty(apply_person_name)) {
            wrapper.like("apply_person_name", apply_person_name);
        }

        // 如果 car_brand 不为空，则添加模糊查询条件
        if (StringUtils.isNotEmpty(car_brand)) {
            wrapper.like("car_brand", car_brand);
        }

        // 按照 id 降序排序
        wrapper.orderBy(true, false, "id");

        // 执行分页查询
        Page<ParkingApply> pageResult = baseMapper.selectPage(page, wrapper);

        // 返回分页 DTO 结果
        return PageDTO.create(pageResult, src -> msParkingApplyMapper.toApplyDTO(src));
    }

}
