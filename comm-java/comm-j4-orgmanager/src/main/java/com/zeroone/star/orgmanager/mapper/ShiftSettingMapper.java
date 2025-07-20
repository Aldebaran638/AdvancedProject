package com.zeroone.star.orgmanager.mapper;

import com.zeroone.star.orgmanager.entity.Classes;
import com.zeroone.star.orgmanager.entity.ClassesTime;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import java.util.List;
import java.util.Map;
import org.apache.ibatis.annotations.*;

@Mapper
public interface ShiftSettingMapper {

    List<Map<String, Object>> listClassWithTime(Classes classes);

    @Insert("insert into classes(classes_id, name, b_id, store_id, state, remark, create_time, status_cd) " +
            "values(#{classesId}, #{name}, #{bId}, #{storeId}, #{state}, #{remark}, #{createTime}, #{statusCd})")
    Boolean addClassesInfo(Classes classes);

    @Insert("insert into classes_time(time_id, classes_id, start_time, end_time, create_time, status_cd) " +
            "values(#{timeId}, #{classesId}, #{startTime}, #{endTime}, #{createTime}, #{statusCd})")
    Boolean addClassesTimeInfo(ClassesTime classesTime);

    /**
     * 查询classId对应的时间段
     * @param classId
     * @return
     */
    @Select("select * from classes_time where classes_id = #{classId}")
    List<ClassesTime> selectFromClassesTimeByClassId(String classId);

    /**
     * 查询相应的班次信息
     * @param classId
     * @return
     */
    @Select("select * from classes where classes_id = #{classId}")
    Classes selectFromClassesByClassId(String classId);

    /**
     * 删除classId对应的值班时间段
     * @param classId
     */
    @Delete("delete from classes_time where classes_id=#{classId}")
    void deleteClassesTimeByClassId(String classId);

    /**
     * 插入值班时间段
     * @param classesTimeList
     */
    void insertClassesTimeBatch(List<ClassesTime> classesTimeList);

    /**
     * 更新班次信息
     * @param classes
     */
    @Update("update classes set `name`=#{name},  remark=#{remark} where classes_id = #{classesId}")
    void updateClasses(Classes classes);

    /**
     * 删除班次信息
     * @param classId
     */
    @Delete("delete from classes where classes_id = #{classId}")
    void deleteClassesByClassId(String classId);

    @Update("update classes set state=#{state} where classes_id = #{classesId}")
    void updateClassesState(Classes classes);
}
