package com.zeroone.star.orgmanager.mapper;

import com.zeroone.star.orgmanager.entity.ScheduleClassesTime;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface ScheduleClassesTimeMapper {

    void insertScheduleClassesTime(ScheduleClassesTime scheduleClassesTimeEntity);

    void deleteByScheduleId(String dId);
}
