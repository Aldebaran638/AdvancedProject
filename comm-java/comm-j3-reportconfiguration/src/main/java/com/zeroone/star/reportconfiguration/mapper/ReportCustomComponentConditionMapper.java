package com.zeroone.star.reportconfiguration.mapper;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.reportconfiguration.entity.ReportCustomComponentCondition;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author 丁香与醋栗
 * @since 2025-06-10
 */
@Mapper
public interface ReportCustomComponentConditionMapper extends BaseMapper<ReportCustomComponentCondition> {

    Page<ReportCustomComponentCondition> selectByComponentId(Page<ReportCustomComponentCondition> page, String componentId,int seq);
}
