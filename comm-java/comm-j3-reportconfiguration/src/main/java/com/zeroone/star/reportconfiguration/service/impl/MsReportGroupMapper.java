package com.zeroone.star.reportconfiguration.service.impl;

import com.zeroone.star.project.dto.j3.reportconfiguration.group.ReportGroupDTO;
import com.zeroone.star.project.vo.j3.reportconfiguration.group.ReportGroupVO;
import com.zeroone.star.reportconfiguration.entity.ReportGroupDO;
import org.mapstruct.Mapper;

import java.util.List;

@Mapper(componentModel = "spring")
public interface MsReportGroupMapper {
    ReportGroupDO GROUP_DO_DTO_DO(ReportGroupDTO dto);
    ReportGroupVO GROUP_VO_DO_VO(ReportGroupDO _do);
    List<ReportGroupVO> toVOlist(List<ReportGroupDO> list);
}
