package com.zeroone.star.patrolmgt.service.impl;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.zeroone.star.patrolmgt.entity.TangSenQuan_InspectionItemTitle;
import com.zeroone.star.project.j8.patrolmgt.item.dto.inspection.InspectionTitleAddDTO;
import com.zeroone.star.project.j8.patrolmgt.item.dto.inspection.InspectionTitleDTO;
import org.mapstruct.Mapper;


import com.zeroone.star.project.j8.patrolmgt.item.vo.ItemTitleVO;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface MsInspectionItemTitleMapper {
    /**
     * 将实体类转换为DTO
     * @param ido 实体类
     * @return 转换结果
     */
    InspectionTitleDTO inspectionTitleToDTO(TangSenQuan_InspectionItemTitle ido);

    /**
     * 将Add DTO转换为实体类
     * @param dto Add DTO
     * @return 转换结果
     */
    default TangSenQuan_InspectionItemTitle addDoToDo(InspectionTitleAddDTO dto){
        if (dto == null) return null;

        TangSenQuan_InspectionItemTitle entity = new TangSenQuan_InspectionItemTitle();
        // 强制设置默认值（如果itemId为空）
        entity.setItemId(StringUtils.isBlank(dto.getItemId()) ? "default_project" : dto.getItemId());
        entity.setItemTitle(dto.getItemTitle());
        entity.setTitleType(dto.getTitleType());
        entity.setCommunityId(dto.getCommunityId());
        entity.setSeq(dto.getSeq());
        return entity;
    }

    /**
     * 将DTO转换为实体类
     * @param dto DTO
     * @return 转换结果
     */
    TangSenQuan_InspectionItemTitle dtoToDo(InspectionTitleDTO dto);

    /**
     * 将巡检题目实体类 InspectionItemTitle 转为 ItemVO
     *
     * @param itemTitle 巡检题目实体类
     * @return 巡检题目VO
     */
    ItemTitleVO itemTitleToVO(TangSenQuan_InspectionItemTitle itemTitle);

}
