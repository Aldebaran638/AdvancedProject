package com.zeroone.star.reportconfiguration.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.message.ComponentRelDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.message.ReportComponentRelDTO;
import com.zeroone.star.project.query.j3.reportconfiguration.message.ReportComponentRelQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.reportconfiguration.message.ReportComponentRelVo;
import com.zeroone.star.reportconfiguration.entity.ReportCustomComponentRel;
import com.zeroone.star.reportconfiguration.mapper.ReportCustomComponentRelMapper;
import com.zeroone.star.reportconfiguration.service.IReportCustomComponentRelService;
import lombok.SneakyThrows;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.util.StringUtils;
import javax.annotation.Resource;
import java.util.Random;

@Service
public class IReportCustomComponentRelServiceImpl implements IReportCustomComponentRelService {
    @Resource
    private ReportCustomComponentRelMapper reportCustomComponentRelMapper;

    @Resource
    private CustomComponentRelMapper customComponentRelMapper;

    @SneakyThrows
    @Override
    public PageDTO<ReportComponentRelVo> ComponentRelPageList(ReportComponentRelQuery query) {
        //构建分页条件
        Page<ReportComponentRelVo> page = new Page<>(query.getPageIndex(), query.getPageSize());

        if(StringUtils.isEmpty(query.getCustomId())){
            return PageDTO.create(new Page<>());
        }

        //查询数据
        Page<ReportComponentRelVo> resultPage = reportCustomComponentRelMapper.ComponentRelPageList(page,query);

        return PageDTO.create(resultPage, src -> customComponentRelMapper.DO_VO(src));
    }

    @SneakyThrows
    @Transactional
    @Override
    public JsonVO<String> saveComponentRel(ComponentRelDTO componentRelDTO) {
        //转成ReportCustomComponentRel
        ReportCustomComponentRel reportCustomComponentRel = new ReportCustomComponentRel();
        BeanUtils.copyProperties(componentRelDTO,reportCustomComponentRel);
        String relId = "";
        if(componentRelDTO.getComponentId().length() > 10){
            String preId = componentRelDTO.getComponentId().substring(0,10);
            Random random = new Random();
            int randomNumber = 10000000 + random.nextInt(90000000);
            relId = preId + String.valueOf(randomNumber);
        }
        reportCustomComponentRel.setRelId(relId);
        int insert = reportCustomComponentRelMapper.insert(reportCustomComponentRel);
        if(insert > 0){
            return JsonVO.success( "添加成功");
        }
        return JsonVO.fail( "添加失败");
    }
    @SneakyThrows
    @Transactional
    @Override
    public JsonVO<String> deleteComponentRel(ReportComponentRelDTO reportComponentRelDTO) {
        QueryWrapper<ReportCustomComponentRel> queryWrapper = new QueryWrapper<>();
        if(!StringUtils.isEmpty(reportComponentRelDTO.getRelId())){
            queryWrapper.eq("rel_id",reportComponentRelDTO.getRelId());
        }else{
            return JsonVO.fail("报表组件关系不存在");
        }
        if(!StringUtils.isEmpty(reportComponentRelDTO.getCustomId())){
            queryWrapper.eq("custom_id",reportComponentRelDTO.getCustomId());
        }else{
            return JsonVO.fail("报表id错误");
        }
        if(!StringUtils.isEmpty(reportComponentRelDTO.getComponentId())){
            queryWrapper.eq("component_id",reportComponentRelDTO.getComponentId());
        }else{
            return JsonVO.fail("组件不存在");
        }
        int delete = reportCustomComponentRelMapper.delete(queryWrapper);
        if(delete > 0){
            return JsonVO.success( "删除成功");
        }
        return JsonVO.fail("删除失败");
    }
}
