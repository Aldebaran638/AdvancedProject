package com.zeroone.star.patrolmgt.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.patrolmgt.entity.InspectionItem;
import com.zeroone.star.patrolmgt.entity.Susu_InspectionItem; // 确保InspectionItem实体类已定义
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface InspectionItemMapper extends BaseMapper<InspectionItem> {
    // 通常不需要额外方法
}