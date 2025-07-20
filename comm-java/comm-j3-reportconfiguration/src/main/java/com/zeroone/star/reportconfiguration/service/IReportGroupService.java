package com.zeroone.star.reportconfiguration.service;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.group.AddGroupDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.group.GroupDTO;
import com.zeroone.star.project.query.j3.reportconfiguration.group.ReportGroupQuery;
import com.zeroone.star.project.vo.j3.reportconfiguration.group.ReportGroupVO;
import com.zeroone.star.reportconfiguration.entity.ReportGroupDO;

import java.util.List;

/**
报表组服务组件

 */
public interface IReportGroupService {

    PageDTO<ReportGroupVO> getGroupList(ReportGroupQuery query);

    List<ReportGroupVO> getGroupNameList();

    String saveGroup(AddGroupDTO addGroupDTO);
    Integer removeGroup(String groupId);
    Integer updateGroup(GroupDTO groupDTO);
}
