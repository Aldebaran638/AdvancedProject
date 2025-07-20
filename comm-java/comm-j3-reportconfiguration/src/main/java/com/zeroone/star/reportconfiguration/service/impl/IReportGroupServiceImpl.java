package com.zeroone.star.reportconfiguration.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.date.DateUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.group.AddGroupDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.group.GroupDTO;
import com.zeroone.star.project.j3.reportconfiguration.group.ReportGroupApis;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.j3.reportconfiguration.group.ReportGroupQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.reportconfiguration.group.ReportGroupVO;
import com.zeroone.star.reportconfiguration.entity.ReportGroupDO;
import com.zeroone.star.reportconfiguration.mapper.ReportGroupMapper;
import com.zeroone.star.reportconfiguration.service.IReportGroupService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;
@Service
public class IReportGroupServiceImpl implements IReportGroupService {
    @Resource
    ReportGroupMapper reportGroupMapper;

    @Resource
    MsReportGroupMapper ms;

    @Override
    public PageDTO<ReportGroupVO> getGroupList(ReportGroupQuery query) {
        //分页查询对象
        Page<ReportGroupDO> page = new Page<ReportGroupDO>(query.getPageIndex(), query.getPageSize());
        //构建查询条件
        QueryWrapper<ReportGroupDO> wrapper=new QueryWrapper<>();
        wrapper.eq(query.getGroupId()!=null&&!query.getGroupId().isEmpty(),"group_id",query.getGroupId());
        wrapper.eq(query.getUrl()!=null&&!query.getUrl().isEmpty(),"url",query.getUrl());
        wrapper.eq(query.getName()!=null&&!query.getName().isEmpty(),"name",query.getName());
        Page<ReportGroupDO> resultPage=reportGroupMapper.selectPage(page,wrapper);
        return PageDTO.create(resultPage,src ->ms.GROUP_VO_DO_VO(src));
    }

    @Override
    public List<ReportGroupVO> getGroupNameList() {
        QueryWrapper<ReportGroupDO> wrapper = new QueryWrapper<>();
        wrapper.select("group_id","name");
        List<ReportGroupDO> list = reportGroupMapper.selectList(wrapper);
        return ms.toVOlist(list);
    }

    @Override
    public String saveGroup(AddGroupDTO addGroupDTO) {
        ReportGroupDO reportGroupDO = new ReportGroupDO();
        BeanUtil.copyProperties(addGroupDTO, reportGroupDO);
        reportGroupMapper.insert(reportGroupDO);
        return reportGroupDO.getGroupId();
    }

    @Override
    public Integer removeGroup(String groupId) {
        return reportGroupMapper.deleteById(groupId);
    }

    @Override
    public Integer updateGroup(GroupDTO groupDTO) {
        String id = groupDTO.getGroupId();
        ReportGroupDO dbGroup = reportGroupMapper.selectById(id);
        if(BeanUtil.isEmpty(dbGroup)) {
            return 0;
        }
        ReportGroupDO reportGroupDO = new ReportGroupDO();
        reportGroupDO.setGroupId(id);
        BeanUtil.copyProperties(groupDTO, reportGroupDO);
        return reportGroupMapper.updateById(reportGroupDO);
    }
}
