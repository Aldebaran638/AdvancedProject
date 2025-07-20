package com.zeroone.star.orgmanager.mapper;

import com.zeroone.star.orgmanager.entity.ScheduleClassesDay;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface ScheduleClassesDayMapper {

    void insertScheduleClassesDay(ScheduleClassesDay scheduleClassesDayEntity);

    void deleteByScheduleId(String dId);
}
