package com.zeroone.star.reportconfiguration.service.impl;


import com.zeroone.star.project.dto.j3.reportconfiguration.component.condition.RCCCDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.condition.RCCCUpdateDTO;
import com.zeroone.star.project.vo.j3.reportconfiguration.component.condition.RCCCVO;
import com.zeroone.star.reportconfiguration.entity.ReportCustomComponentCondition;
import org.mapstruct.Mapper;

/**
 * @ClassName MsRCCCMapper
 * @Description 接口转换
 * @Author 丁香与醋栗
 * @Date 2025/5/19 17:08
 * @Version 1.0
 * @describe:
 */
@Mapper(componentModel = "spring")
public interface MsRCCCMapper {
    //将DTO转换为DO

    ReportCustomComponentCondition DTO_DO(RCCCDTO dto);

    RCCCVO DO_VO(ReportCustomComponentCondition _do);

    ReportCustomComponentCondition DTO_DO(RCCCUpdateDTO dto);
}
