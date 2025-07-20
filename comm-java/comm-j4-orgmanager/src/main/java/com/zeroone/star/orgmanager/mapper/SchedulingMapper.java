package com.zeroone.star.orgmanager.mapper;

import com.zeroone.star.orgmanager.entity.ScheduleClasses;
import com.zeroone.star.project.dto.j4.orgmanager.SettingNameDTO;
import com.zeroone.star.project.query.j4.orgmanager.ScheduleQuery;
import com.zeroone.star.orgmanager.service.impl.SchedulingServiceImpl;
import com.zeroone.star.project.vo.j4.orgmanager.ScheduleClassChangeVO;
import com.zeroone.star.project.vo.j4.orgmanager.ScheduleClassStaffVO;
import com.zeroone.star.project.vo.j4.orgmanager.ScheduleVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;
import java.util.List;

@Mapper
public interface SchedulingMapper {

    @Select("select schedule_id,b_id,name from schedule_classes")
    List<SettingNameDTO> selectName();


    List<ScheduleVO> selectSchedule(ScheduleQuery query);

    void insertScheduleClasses(ScheduleClasses scheduleClassesEntity);

    void deleteByScheduleId(String dId);

    @Select("select * from schedule_classes where schedule_id=#{dId}")
    ScheduleClasses selectScheduleById(String dId);

    @Update("update schedule_classes set status_cd=1 where schedule_id=#{scheduleId}")
    void schedulingDelete(long scheduleId);

    @Select("select state from schedule_classes where schedule_id=#{scheduleId}")
    int selectSchedulingState(long scheduleId);

    @Update("update schedule_classes set state=#{i} where schedule_id=#{scheduleId}")
    void schedulingState(int i, long scheduleId);

    @Select("select name,schedule_type,schedule_cycle from schedule_classes where schedule_id=#{scheduleId}")
    ScheduleClassChangeVO schedulingChange(long scheduleId);

    @Select("select day_id,workday from schedule_classes_day where schedule_id=#{scheduleId} and status_cd = 0 and week_flag=#{weekFlag} and day=#{day}")
    SchedulingServiceImpl.DayToTime selectWorkDay(long scheduleId, int weekFlag, int day);

    @Select("select start_time,end_time from schedule_classes_time where day_id=#{dayId}")
    List<SchedulingServiceImpl.WorkTime> selectWorkTime(long dayId);

    @Select("SELECT schedule_id, staffId, staff_name,create_time FROM schedule_staff WHERE schedule_id = #{scheduleId}")
    List<ScheduleClassStaffVO> selectStaff(long scheduleId);

    Long countTotal(ScheduleQuery query);
}
