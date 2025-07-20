package com.zeroone.star.reportconfiguration.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.count.CountAddDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.count.CountDTO;
import com.zeroone.star.reportconfiguration.entity.RCCCFooter;
import com.zeroone.star.reportconfiguration.mapper.RCCCFooterMapper;
import com.zeroone.star.reportconfiguration.service.IReportCustomComponentCountService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.LocalDateTime;

/**
 * <p>
 * 报表组件统计服务实现类
 * </p>
 * 实现了IReportCustomComponentCountService接口，提供报表组件底层统计的业务逻辑实现
 *
 * @author Arthur
 * @version 1.0
 * @date 2025-05-20
 */
@Service
public class IReportCustomComponentCountServiceImpl implements IReportCustomComponentCountService {
    
    @Resource
    private RCCCFooterMapper rcccFooterMapper;
    
    @Override
    public PageDTO<RCCCFooter> listCoountFooterList(PageDTO pageDTO, String componentId) {
        // 创建分页对象
        Page<RCCCFooter> page = new Page<>(pageDTO.getPageIndex(), pageDTO.getPageSize());
        // 构建查询条件
        LambdaQueryWrapper<RCCCFooter> queryWrapper = new LambdaQueryWrapper<>();
        // 如果组件ID不为空，则添加组件ID筛选条件
        if (componentId != null && !componentId.isEmpty()) {
            queryWrapper.eq(RCCCFooter::getComponentId, componentId);
        }
        // 按创建时间降序排序
        queryWrapper.orderByDesc(RCCCFooter::getCreateTime);
        // 执行分页查询
        Page<RCCCFooter> resultPage = rcccFooterMapper.selectPage(page, queryWrapper);
        // 封装结果
        PageDTO<RCCCFooter> result = new PageDTO<>();
        result.setPageIndex(pageDTO.getPageIndex());
        result.setPageSize(pageDTO.getPageSize());
        result.setRows(resultPage.getRecords());
        result.setTotal(resultPage.getTotal());
        return result;
    }
    
    @Override
    public boolean updateCondition(CountDTO updateCount) {
        // 创建实体对象
        RCCCFooter footer = new RCCCFooter();
        // 设置ID
        footer.setFooterId(updateCount.getFooterId());
        footer.setComponentId(updateCount.getComponentId());
        // 复制属性
        footer.setName(updateCount.getName());
        footer.setQueryModel(updateCount.getQueryModel());
        footer.setRemark(updateCount.getFooterDescription());
        // 执行更新操作
        return rcccFooterMapper.updateById(footer) > 0;
    }
    
    @Override
    public boolean saveCondition(CountAddDTO saveCount) {
        // 创建实体对象
        RCCCFooter footer = new RCCCFooter();
        // 生成随机的三位数（旨在补齐位数）
        int random = (int) (Math.random() * 1000);
        //将random转化为字符串
        String randomStr = String.valueOf(random);
        // 设置ID
        footer.setFooterId("10" + System.currentTimeMillis()+randomStr);
        // 设置组件ID
        footer.setComponentId(saveCount.getComponentId());
        // 复制属性
        footer.setName(saveCount.getName());
        footer.setQueryModel(saveCount.getQueryModel());
        footer.setRemark(saveCount.getFooterDescription());
        // 设置创建时间
        footer.setCreateTime(LocalDateTime.now());
        // 设置状态
        footer.setStatusCd("0");
        // 执行插入操作
        return rcccFooterMapper.insert(footer) > 0;
    }
    
    @Override
    public boolean deleteCondition(String id) {
        // 执行删除操作
        return rcccFooterMapper.deleteById(id) > 0;
    }
}
