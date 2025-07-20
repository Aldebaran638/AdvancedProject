package com.zeroone.star.reportconfiguration.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.count.CountAddDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.count.CountDTO;
import com.zeroone.star.reportconfiguration.entity.RCCCFooter;

import java.util.List;

/**
 * <p>
 * 报表组件统计服务接口
 * </p>
 * 该接口定义了与“报表组件统计列表”相关的业务逻辑操作，包括分页查询、新增、修改、按ID删除
 * 负责具体的数据库交互和数据转换。
 *
 * @author Arthur
 * @version 1.0
 * @date 2025-05-20
 */
public interface IReportCustomComponentCountService {
    /**
     * <p>
     * 分页查询条件列表
     *</p>
     * 根据传入的查询参数 PageDTO 获取对应的分页数据，并将结果封装为 PageDTO<RCCCFooter> 返回。
     *
     * @param pageDTO 包含查询参数的分页对象
     * @param componentId 组件ID，用于筛选特定组件的统计数据
     * @return 返回封装后的分页视图对象 PageDTO<RCCCFooter>
     */
    PageDTO<RCCCFooter> listCoountFooterList(PageDTO pageDTO, String componentId);
    
    /**
     * <p>
     * 更新底层统计
     * </p>
     * 根据传入的 CountDTO 对象更新已有的统计数据。
     *
     * @param updateCount 包含更新数据的 DTO 对象
     * @return 操作是否成功（true 成功，false 失败）
     */
    boolean updateCondition(CountDTO updateCount);
    
    /**
     * <p>
     * 新增底层统计
     * </p>
     * 将传入的 CountAddDTO 数据保存到数据库中。
     *
     * @param saveCount 包含新增数据的 DTO 对象
     * @return 操作是否成功（true 成功，false 失败）
     */
    boolean saveCondition(CountAddDTO saveCount);
    
    /**
     * <p>
     * 根据 id 删除底层统计
     * </p>
     * 根据传入的统计 id 单条删除底层统计数据
     *
     * @param id 需要删除的条件ID列表
     * @return 操作是否成功（true 成功，false 失败）
     */
    boolean deleteCondition(String id);
}
