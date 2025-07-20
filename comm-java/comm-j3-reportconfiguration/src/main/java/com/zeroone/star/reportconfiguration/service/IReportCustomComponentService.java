package com.zeroone.star.reportconfiguration.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.RCCAddDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.RCCDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.RCCDeleteDTO;
import com.zeroone.star.project.query.j3.reportconfiguration.component.RCCQuery;
import com.zeroone.star.project.vo.j3.reportconfiguration.component.RCCVO;
import com.zeroone.star.reportconfiguration.entity.RCCDO;

/**
 * 报表组件服务接口
 *
 * 该接口定义了与“报表自定义组件”相关的业务逻辑操作，包括分页查询、新增、修改、按ID查询和删除等核心功能。
 * 实现类为 `IReportCustomComponentServiceImpl`，负责具体的数据库交互和数据转换。
 *
 * @author huicheng
 * @version 1.0
 * @date 2025-05-20
 */
public interface IReportCustomComponentService extends IService<RCCDO>{
    /**
     * 分页查询报表组件，参数query携带约束条件
     * @param query
     * @return
     */
    PageDTO<RCCVO> queryRCC(RCCQuery query);

    /**
     * 添加报表组件
     *
     * @param rcc
     * @return
     */
    String saveRCC(RCCAddDTO rcc);

    /**
     * 修改报表组件
     * @param rcc
     * @returns
     */
    String updateRCC(RCCDTO rcc);

    /**
     * 删除报表组件
     * @param rccDeleteDTO
     * @return
     */
    String deleteRCC(RCCDeleteDTO rccDeleteDTO);
}