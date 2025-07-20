package com.zeroone.star.reportconfiguration.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.condition.RCCCDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.condition.RCCCUpdateDTO;
import com.zeroone.star.project.query.j3.reportconfiguration.component.condition.RCCCQuery;
import com.zeroone.star.project.vo.j3.reportconfiguration.component.condition.RCCCVO;
import com.zeroone.star.reportconfiguration.entity.ReportCustomComponentCondition;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author 丁香与醋栗
 * @since 2025-06-10
 */
public interface IReportCustomComponentConditionService extends IService<ReportCustomComponentCondition> {

    public PageDTO<RCCCVO> getConditionList(RCCCQuery query);

    public String updateCondition(RCCCUpdateDTO condition);

    public String saveCondition(RCCCDTO condition);

    public RCCCVO getId(String id);

    public void removeCondition(String id);

}
