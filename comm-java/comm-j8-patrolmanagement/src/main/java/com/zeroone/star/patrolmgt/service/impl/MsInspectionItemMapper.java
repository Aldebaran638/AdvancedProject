package com.zeroone.star.patrolmgt.service.impl;

import com.zeroone.star.patrolmgt.entity.InspectionItem;
import com.zeroone.star.project.j8.patrolmgt.item.vo.ItemVO;
import org.mapstruct.Mapper;

/**
 * InspectionItem对应的MapStruct接口
 */
@Mapper(componentModel = "spring")
public interface MsInspectionItemMapper {
    
    /**
     * 将巡检项目实体类 InspectionItem 转为 ItemVO
     * @param item 巡检项目实体类
     * @return  巡检项目VO
     */
    ItemVO itemToVo(InspectionItem item);
    
}
