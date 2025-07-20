package com.zeroone.star.orgmanager.mapper;

import com.zeroone.star.orgmanager.entity.ClassesTime;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface ClassesTimeMapper {

    List<ClassesTime> selectClassesTimeById(String id);
}
