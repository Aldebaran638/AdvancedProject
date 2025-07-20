package com.zeroone.star.patrolmgt.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;

import com.zeroone.star.patrolmgt.entity.InspectionItemTitleValue;
import com.zeroone.star.patrolmgt.mapper.InspectionItemTitleValueMapper;
import com.zeroone.star.patrolmgt.service.IInspectionItemTitleValueService;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author 唐森权
 * @since 2025-05-16
 */
@Service
public class InspectionItemTitleValueServiceImpl extends ServiceImpl<InspectionItemTitleValueMapper, InspectionItemTitleValue> implements IInspectionItemTitleValueService {
    @Override
    public List<InspectionItemTitleValue> getValuesByTitleId(String titleId) {
        return this.list(new LambdaQueryWrapper<InspectionItemTitleValue>()
                .eq(InspectionItemTitleValue::getTitleId, titleId));
    }

}
