package com.zeroone.star.orgmanager.mapper;

import com.zeroone.star.orgmanager.entity.AssociatedPersonnelClasses;

import org.apache.ibatis.annotations.Mapper;

import java.util.Map;

@Mapper
public interface AssociatedPersonnelMapper {
    void insertAssociatedPersonnel(AssociatedPersonnelClasses associatedPersonnelClasses);
    // 只删除有效状态的记录
    int deleteByClassesAndStaffId(Map<String, Object> params);
}
