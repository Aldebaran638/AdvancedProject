package com.zeroone.star.reportconfiguration.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.CollectionUtils;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.RCCAddDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.RCCDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.RCCDeleteDTO;
import com.zeroone.star.project.query.j3.reportconfiguration.component.RCCQuery;
import com.zeroone.star.project.vo.j3.reportconfiguration.component.RCCVO;
import com.zeroone.star.reportconfiguration.entity.RCCDO;
import com.zeroone.star.reportconfiguration.mapper.RCCMapper;
import com.zeroone.star.reportconfiguration.service.IReportCustomComponentService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

@Service
public class IReportCustomComponentServiceImpl extends ServiceImpl<RCCMapper, RCCDO> implements IReportCustomComponentService {

    @Autowired
    private RCCMapper rccMapper;

    @Autowired
    private MsRCCMapper msRCCMapper;

    /**
     * 分页查询RCC数据（带条件）
     * @param query 包含分页参数和查询条件（componentId/name）
     * @return 分页结果VO（自动转换DO→VO）
     * @throws IllegalArgumentException 如果分页参数非法
     */
    public PageDTO<RCCVO> queryRCC(RCCQuery query) {
        // 1. 参数校验
        if (query == null) {
            return null;
        }

        // 2. 构建分页和查询条件
        Page<RCCDO> page = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<RCCDO> wrapper = new QueryWrapper<>();

        // 3. 非空字段才加入查询条件
        if (StringUtils.isNotBlank(query.getComponentId())) {
            wrapper.and(wrapper1 -> wrapper1.eq("component_id", query.getComponentId()));
        }
        if (StringUtils.isNotBlank(query.getName())) {
            wrapper.and(wrapper1 -> wrapper1.like("name", query.getName()));
        }

        // 对 componentType 进行严格校验
        if (StringUtils.isNotBlank(query.getComponentType())) {
            Set<String> validTypes = new HashSet<>(Arrays.asList("1001", "2002", "3003", "4004", "5005"));
            if (!validTypes.contains(query.getComponentType())) {
                return null;
            }
            wrapper.and(wrapper1 -> wrapper1.eq("component_type", query.getComponentType()));
        }

        // 4. 执行查询并转换
        Page<RCCDO> resultPage = rccMapper.selectPage(page, wrapper);
        if (resultPage.getTotal() <= 0 || CollectionUtils.isEmpty(resultPage.getRecords())) {
            return null; // 建议返回空分页对象而不是null
        }
        return PageDTO.create(resultPage, src -> msRCCMapper.DO_VO(src));
    }

    /**
     * 实现添加逻辑
     *
     * @param rcc 前端传递给后端添加的表
     * @return
     */
    @Transactional
    @Override
    public String saveRCC(RCCAddDTO rcc) {
        if (StringUtils.isNotBlank(rcc.getComponentType())) {
            Set<String> validTypes = new HashSet<>(Arrays.asList("1001", "2002", "3003", "4004", "5005"));
            if (!validTypes.contains(rcc.getComponentType())) {
                return "组件类型错误";
            }
        }
        if(StringUtils.isBlank(rcc.getComponentGroup()) || !
                (rcc.getComponentGroup().equals("C") || rcc.getComponentGroup().equals("Q"))){
            return "组件组错误";
        }
        if(StringUtils.isBlank(rcc.getQueryModel()) || !(rcc.getQueryModel().equals("1") || rcc.getQueryModel().equals("2"))){
            return "查询模型错误";
        }
        if(StringUtils.isBlank(rcc.getStatusCd()) || !(rcc.getStatusCd().equals("S") ||
                rcc.getStatusCd().equals("1")|| rcc.getStatusCd().equals("0"))){
            return "查询状态错误";
        }

        // 转换为DO并插入
        RCCDO rccDO = msRCCMapper.AddDTO_DO(rcc);



        if (rccMapper.insert(rccDO) <= 0) {
            return "添加失败";
        }
        // 直接返回组件ID（假设componentId是主键或业务ID）
        return rccDO.getComponentId();
    }

    /**
     * 实现更新逻辑
     * @param rcc 前端传递给后端更新的表
     * @return
     */
    @Override
    public String updateRCC(RCCDTO rcc) {
        if (StringUtils.isNotBlank(rcc.getComponentType())) {
            Set<String> validTypes = new HashSet<>(Arrays.asList("1001", "2002", "3003", "4004", "5005"));
            if (!validTypes.contains(rcc.getComponentType())) {
                return "组件类型错误";
            }
        }
        if(StringUtils.isBlank(rcc.getComponentGroup()) || !
                (rcc.getComponentGroup().equals("C") || rcc.getComponentGroup().equals("Q"))){
            return "查询组错误";
        }
        if(StringUtils.isBlank(rcc.getQueryModel()) || !(rcc.getQueryModel().equals("1") || rcc.getQueryModel().equals("2"))){
            return "查询模型错误";
        }
        if(StringUtils.isBlank(rcc.getStatusCd()) || !(rcc.getStatusCd().equals("S") ||
                rcc.getStatusCd().equals("1")|| rcc.getStatusCd().equals("0"))){
            return "查询状态错误";
        }
        if (rcc == null || StringUtils.isBlank(rcc.getComponentId())) {
            return "组件id错误";
        }

        // 执行更新
        RCCDO rccDO = msRCCMapper.DTO_DO(rcc);
        int updated = rccMapper.update(rccDO,
                Wrappers.<RCCDO>lambdaUpdate()
                        .eq(RCCDO::getComponentId, rcc.getComponentId()));

        if (updated <= 0) {
            return "修改失败";
        }

        return rcc.getComponentId();
    }


    /**
     * 实现删除的逻辑
     * @param id 要删除的id
     * @return
     */
    @Override
    public String deleteRCC(RCCDeleteDTO rcc) {
        if (StringUtils.isBlank(rcc.getComponentId())) {
            return "";
        }

        // 执行删除
        int deleted = rccMapper.delete(
                Wrappers.<RCCDO>lambdaQuery()
                        .eq(RCCDO::getComponentId, rcc.getComponentId()));

        if (deleted <= 0) {
            return "删除失败";
        }

        return rcc.getComponentId();
    }
}