package com.zeroone.star.patrolmgt.service;

import com.zeroone.star.patrolmgt.entity.InspectionTaskDetail;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.detail.dto.DetailDTO;
import com.zeroone.star.project.j8.patrolmgt.detail.query.DetailQuery;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author yuanzijie
 * @since 2025-05-24
 */
public interface IInspectionTaskDetailService extends IService<InspectionTaskDetail> {

    PageDTO<DetailDTO> queryAll(DetailQuery query);
}
