package com.zeroone.star.patrolmgt.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.patrolmgt.entity.InspectionItemTitleValue;


import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author 唐森权
 * @since 2025-05-16
 */
public interface IInspectionItemTitleValueService extends IService<InspectionItemTitleValue> {
    List<InspectionItemTitleValue> getValuesByTitleId(String titleId);
}
