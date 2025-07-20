package com.zeroone.star.reportconfiguration.service.impl;


import com.zeroone.star.project.vo.j3.reportconfiguration.message.ReportComponentRelVo;
import com.zeroone.star.reportconfiguration.entity.ReportCustomComponentRel;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface CustomComponentRelMapper {
    ReportComponentRelVo DO_VO(ReportComponentRelVo src);
}

