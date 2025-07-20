package com.zeroone.star.reportconfiguration.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.condition.RCCCDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.condition.RCCCUpdateDTO;
import com.zeroone.star.project.query.j3.reportconfiguration.component.condition.RCCCQuery;
import com.zeroone.star.project.vo.j3.reportconfiguration.component.condition.RCCCVO;
import com.zeroone.star.reportconfiguration.entity.ReportCustomComponentCondition;
import com.zeroone.star.reportconfiguration.mapper.ReportCustomComponentConditionMapper;
import com.zeroone.star.reportconfiguration.service.IReportCustomComponentConditionService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author 丁香与醋栗
 * @since 2025-06-10
 */
@Service
public class ReportCustomComponentConditionServiceImpl extends ServiceImpl<ReportCustomComponentConditionMapper, ReportCustomComponentCondition> implements IReportCustomComponentConditionService
{

    @Resource
    private MsRCCCMapper ms;
    @Resource
    private ReportCustomComponentConditionMapper baseMapper;

    @Override
    public PageDTO<RCCCVO> getConditionList(RCCCQuery query) {
        //构建分页查询对象
        Page<ReportCustomComponentCondition> page = new Page<>(query.getPageIndex(), query.getPageSize());
        //构建查询条件，根据seq进行排序
        QueryWrapper<ReportCustomComponentCondition> wrapper = new QueryWrapper<>();
        if(query.getComponentId()==null)
        {
            return null;
        }

        Page<ReportCustomComponentCondition> resultPage =  baseMapper.selectByComponentId(page, query.getComponentId(),  query.getSeq());
        return PageDTO.create(resultPage, src -> ms.DO_VO(src));
    }


    @Override
    public String updateCondition(RCCCUpdateDTO condition)
    {
        ReportCustomComponentCondition ReportCustomComponentCondition = ms.DTO_DO(condition);
        QueryWrapper<ReportCustomComponentCondition> wrapper = new QueryWrapper<>();
        wrapper.eq("condition_id",ReportCustomComponentCondition.getConditionId());
        if(baseMapper.selectOne(wrapper)==null)
        {
            throw new RuntimeException("条件不存在");
        }
        baseMapper.update(ReportCustomComponentCondition, wrapper);
        return ReportCustomComponentCondition.getConditionId();
    }

    @Override
    public String saveCondition(RCCCDTO condition)
    {

        ReportCustomComponentCondition ReportCustomComponentCondition = ms.DTO_DO(condition);
        //log.info("保存条件：{}",ReportCustomComponentCondition);
        //查询数据库获取组件id
        baseMapper.insert(ReportCustomComponentCondition);
        return ReportCustomComponentCondition.getConditionId();
    }

    @Override
    public RCCCVO getId(String id)
    {
        ReportCustomComponentCondition condition = baseMapper.selectById(id);
        RCCCVO vo = ms.DO_VO(condition);
        return vo;
    }

    @Override
    public void removeCondition(String id) {

        //根据id查询condition_id
        ReportCustomComponentCondition condition = baseMapper.selectOne(new QueryWrapper<ReportCustomComponentCondition>().eq("condition_id", id));
        if( condition == null)
        {
            throw  new RuntimeException("条件不存在");
        }
        baseMapper.delete(new QueryWrapper<ReportCustomComponentCondition>().in("condition_id", id));

    }


}
