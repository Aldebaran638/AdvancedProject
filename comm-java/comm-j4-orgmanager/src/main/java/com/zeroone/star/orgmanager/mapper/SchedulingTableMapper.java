package com.zeroone.star.orgmanager.mapper;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.zeroone.star.project.query.j4.orgmanager.PersonnelScheduleQuery;
import com.zeroone.star.project.vo.j4.orgmanager.PersonnelSchedulingVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.time.LocalDate;
import java.util.List;

@Mapper
public interface SchedulingTableMapper {
    /**
     * 根据员工ID和年月查询排班表信息
     *
     * @return 排班表列表
     */
    IPage<PersonnelSchedulingVO> selectAttendanceSchedule(
            Page<PersonnelSchedulingVO> page,
            @Param("query") PersonnelScheduleQuery query
    );
}
