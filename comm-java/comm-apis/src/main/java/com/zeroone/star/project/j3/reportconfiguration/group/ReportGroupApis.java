package com.zeroone.star.project.j3.reportconfiguration.group;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.group.ReportGroupDTO;
import com.zeroone.star.project.query.j3.reportconfiguration.group.ReportGroupQuery;
import com.zeroone.star.project.vo.JsonVO;

import com.zeroone.star.project.dto.j3.reportconfiguration.group.AddGroupDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.group.GroupDTO;
import com.zeroone.star.project.vo.j3.reportconfiguration.group.ReportGroupVO;
import org.springframework.web.bind.annotation.RequestBody;

import java.util.List;

public interface ReportGroupApis {
    /**
     * 获取报表组列表（条件+分页）
     */
    JsonVO<PageDTO<ReportGroupVO>> queryAll(ReportGroupQuery query);

    /**
     * 获取报表组名称列表
     */
    JsonVO<List<ReportGroupVO>> queryReportConfigurationName();
    /**
     * 添加报表组
     * @param addGroupDTO
     * @return
     */
    JsonVO<String> addGroup(AddGroupDTO addGroupDTO);

    /**
     * 修改报表组
     * @param groupDTO
     * @return
     */
    JsonVO<String> modifyGroup(GroupDTO groupDTO);

    /**
     * 删除报表组
     * @param groupId
     * @return
     */
    JsonVO<String> removeGroup(String groupId);

}
