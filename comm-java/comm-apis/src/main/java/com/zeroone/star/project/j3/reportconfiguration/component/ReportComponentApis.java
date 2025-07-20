package com.zeroone.star.project.j3.reportconfiguration.component;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.RCCAddDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.RCCDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.RCCDeleteDTO;
import com.zeroone.star.project.query.j3.reportconfiguration.component.RCCQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.reportconfiguration.component.RCCVO;

public interface ReportComponentApis {
    //分页查询报表组件
    JsonVO<PageDTO<RCCVO>>queryComponent(RCCQuery query);

    //添加报表组件
    JsonVO<String> addComponent(RCCAddDTO addComponentDTO);

    //修改报表组件
    JsonVO<String> modifyComponent(RCCDTO componentDTO);

    //删除报表组件
    JsonVO<String> removeComponent(RCCDeleteDTO deleteComponentDTO);

}
