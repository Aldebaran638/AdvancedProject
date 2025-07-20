package com.zeroone.star.reportconfiguration.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.message.ComponentRelDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.message.ReportComponentRelDTO;
import com.zeroone.star.project.query.j3.reportconfiguration.message.ReportComponentRelQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.reportconfiguration.message.ReportComponentRelVo;

import java.util.List;

public interface IReportCustomComponentRelService {
    PageDTO<ReportComponentRelVo> ComponentRelPageList(ReportComponentRelQuery query);

    JsonVO<String>  saveComponentRel(ComponentRelDTO componentRelDTO);

    JsonVO<String> deleteComponentRel(ReportComponentRelDTO reportComponentRelDTO);
}
