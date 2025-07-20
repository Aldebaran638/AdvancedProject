package com.zeroone.star.patrolmgt.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.patrolmgt.entity.InspectionPlan;
import com.zeroone.star.patrolmgt.entity.InspectionPlanStaff;
import com.zeroone.star.patrolmgt.mapper.InspectionPlanMapper;
import com.zeroone.star.patrolmgt.mapper.InspectionPlanStaffMapper;
import com.zeroone.star.patrolmgt.service.InspectionPlanService;
import com.zeroone.star.project.j8.patrolmgt.plan.dto.InspectionPlanDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.dto.InspectionPlanModifyDTO;
import org.springframework.stereotype.Service;

import java.util.Collection;
import java.util.Collections;
import java.util.Map;
import java.util.function.Function;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.patrolmgt.entity.InspectionPlan;
import com.zeroone.star.patrolmgt.entity.InspectionPlanStaff;
import com.zeroone.star.patrolmgt.mapper.InspectionPlanMapper;
import com.zeroone.star.patrolmgt.service.InspectionPlanService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.dto.PlanDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.dto.PlanHeadDetailDTO;
import com.zeroone.star.project.j8.patrolmgt.plan.query.PlanQuery;
import org.apache.commons.lang.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;


@Service
public class InspectionPlanServiceImpl implements InspectionPlanService {

    @Autowired
    private InspectionPlanMapper mapper;
    @Override
    @Transactional
    public IPage<PlanDTO> queryPlanList(Page<InspectionPlan> page, PlanQuery query) {

        return mapper.queryPlanList(page,query);
    }

    @Override
    @Transactional
    public PlanHeadDetailDTO getPlanDetail(String planId) {
        if (StringUtils.isEmpty(planId)) {
            return null;
        }

        return mapper.getPlanDetail(planId);
    }


    private InspectionPlanMapper inspectionPlanMapper;

    private final InspectionPlanStaffMapper inspectionPlanStaffMapper;

    public InspectionPlanServiceImpl(InspectionPlanMapper inspectionPlanMapper, InspectionPlanStaffMapper inspectionPlanStaffMapper) {
        this.inspectionPlanMapper = inspectionPlanMapper;
        this.inspectionPlanStaffMapper = inspectionPlanStaffMapper;
    }


    @Override
    public void addInspectionPlan(InspectionPlanDTO inspectionPlanDTO) {
        InspectionPlan plan = BeanUtil.copyProperties(inspectionPlanDTO, InspectionPlan.class);
        plan.setState("2020025");
        inspectionPlanMapper.insert(plan);
        InspectionPlanStaff staff = BeanUtil.copyProperties(inspectionPlanDTO, InspectionPlanStaff.class);
        // TODO 有多名巡检人员，需要批量更新
        staff.setInspectionPlanId(plan.getInspectionPlanId());
        inspectionPlanStaffMapper.insert(staff);
    }


    @Override
    public void updateInspectionPlan(InspectionPlanModifyDTO inspectionPlanModifyDTO) {
        InspectionPlan plan = BeanUtil.copyProperties(inspectionPlanModifyDTO, InspectionPlan.class);
        inspectionPlanMapper.updateById(plan);
        InspectionPlanStaff staff = BeanUtil.copyProperties(inspectionPlanModifyDTO, InspectionPlanStaff.class);
        LambdaQueryWrapper<InspectionPlanStaff> wrapper = new LambdaQueryWrapper<InspectionPlanStaff>()
                .eq(InspectionPlanStaff::getInspectionPlanId, plan.getInspectionPlanId());
        inspectionPlanStaffMapper.delete(wrapper);
        // TODO 有多名巡检人员，需要批量更新
        staff.setInspectionPlanId(plan.getInspectionPlanId());
        inspectionPlanStaffMapper.insert(staff);
    }

    @Override
    public void removeInspectionPlan(String inspectionPlanId) {
        inspectionPlanMapper.deleteById(inspectionPlanId);
        LambdaQueryWrapper<InspectionPlanStaff> wrapper = new LambdaQueryWrapper<InspectionPlanStaff>()
                .eq(InspectionPlanStaff::getInspectionPlanId, inspectionPlanId);
        inspectionPlanStaffMapper.delete(wrapper);
    }

    @Override
    public void updateInspectionPlanState(String inspectionPlanId, String state) {
        LambdaUpdateWrapper<InspectionPlan> wrapper = new LambdaUpdateWrapper<>();
        wrapper.eq(InspectionPlan::getInspectionPlanId, inspectionPlanId)
                .set(InspectionPlan::getState, state);
        inspectionPlanMapper.update(null, wrapper);
    }

    @Override
    public boolean saveBatch(Collection<InspectionPlan> entityList, int batchSize) {
        return false;
    }

    @Override
    public boolean saveOrUpdateBatch(Collection<InspectionPlan> entityList, int batchSize) {
        return false;
    }

    @Override
    public boolean updateBatchById(Collection<InspectionPlan> entityList, int batchSize) {
        return false;
    }

    @Override
    public boolean saveOrUpdate(InspectionPlan entity) {
        return false;
    }

    @Override
    public InspectionPlan getOne(Wrapper<InspectionPlan> queryWrapper, boolean throwEx) {
        return null;
    }

    @Override
    public Map<String, Object> getMap(Wrapper<InspectionPlan> queryWrapper) {
        return null;
    }

    @Override
    public <V> V getObj(Wrapper<InspectionPlan> queryWrapper, Function<? super Object, V> mapper) {
        return null;
    }

    @Override
    public BaseMapper<InspectionPlan> getBaseMapper() {
        return null;
    }

    @Override
    public Class<InspectionPlan> getEntityClass() {
        return null;
    }
}
