package com.zeroone.star.reportconfiguration.mapper;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.query.j3.reportconfiguration.message.ReportComponentRelQuery;
import com.zeroone.star.project.vo.j3.reportconfiguration.message.ReportComponentRelVo;
import com.zeroone.star.reportconfiguration.entity.ReportCustomComponentRel;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author Arr
 * @since 2025-05-20
 */
@Mapper
public interface ReportCustomComponentRelMapper extends BaseMapper<ReportCustomComponentRel> {

   Page<ReportComponentRelVo> ComponentRelPageList(Page<ReportComponentRelVo> page, ReportComponentRelQuery query);
}
