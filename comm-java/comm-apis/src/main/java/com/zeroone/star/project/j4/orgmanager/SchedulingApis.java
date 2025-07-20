package com.zeroone.star.project.j4.orgmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AddAssociatedPersonnelDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AddScheduleDTO;
import com.zeroone.star.project.dto.j4.orgmanager.SaveScheduleDTO;
import com.zeroone.star.project.dto.j4.orgmanager.SettingNameDTO;
import com.zeroone.star.project.query.j4.orgmanager.ScheduleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.orgmanager.ScheduleVO;
import com.zeroone.star.project.vo.j4.orgmanager.ScheduleClassChangeVO;
import com.zeroone.star.project.vo.j4.orgmanager.*;

import java.util.List;

/**
 * @Author: dashuai
 * @Description:
 * 包含获取排班设置名称列表、获取排班设置列表、添加排班设置、修改排班设置、删除排班设置
 * 启用/停用排班设置、获取排班设置详情、获取关联人员列表
// * 添加关联人员、删除关联人员、获取人员排班列表
 *
 * 负责人：
 * ……、♛尘缘♞、頹
 */
public interface SchedulingApis {

    /**
     * 功能：
     * 获取排班设置名称列表
     *
     * 关联的数据库表：
     * schedule_classes
     *
     * 说明：
     * 查询数据库schedule_classes获取：排班ID，业务ID，班次名称
     *
     * 返回值：
     * 在数据库查到的所有的排班设置的名称
     */
    JsonVO<List<SettingNameDTO> > queryName();

    /**
     * 功能：
     * 获取排班设置列表（条件 + 分页）
     *
     * 关联的数据库表：
     * schedule_classes，schedule_classes_staff
     *
     * 说明：
     * schedule_classes中的部分字段，
     * 其中人员字段需要与schedule_classes_staff进行连表查询，
     * 统计schedule_classes_staff中的排班id与schedule_classes
     * 的排班id相同的人数来进行统计并传输，最后可以构成满足原型图需求的数据集
     *
     * 返回值：
     * 在数据库中查询与统计的排版设置列表
     */
    JsonVO<PageDTO<ScheduleVO>> querySchedule(ScheduleQuery query);


    /**
     * 功能：
     * 添加排班设置
     *
     * 关联的数据库表：
     * schedule_classes表，schedule_classes_day表，schedule_classes_time表
     *
     * 说明：
     * 排班名称，排班类型，排班周期，以及具体信息，其中排班名称，
     * 排班类型，排班周期在schedule_classes表，然后
     * schedule_classes再自己生成一个schedule_id主键，
     * 接下来在schedule_classes_day中存储天的信息，
     * 通过week_flag字段标注一个月的第几周，通过work_day（默认为1）
     * 字段标注一周的第几天，接下来通过workday 来确定这一天休息不休息，
     * schedule_classes_day还需要生成一个主键day_id,如果休息就是2002
     * （默认的也是2002），那就不再向schedule_classes_time表中写，
     * 如果是其他值那就需要向schedule_classes_time
     * （通过day_id与schedule_id来确认是具体哪个工作的哪一天）
     * 表写工作的开始时间与结束时间，自己也生成一个主键time_id
     *
     * 返回值：
     * 返回值为String类型，成功为success，失败为fail
     */
    JsonVO<String> addSchedule(AddScheduleDTO addScheduleDTO);


    /**
     * 功能：
     * 添加排班设置
     *
     * 关联的数据库表：
     * schedule_classes表，schedule_classes_day表，schedule_classes_time表
     *
     * 说明：
     * 与添加排班设置类似
     *
     * 返回值：
     * 更新成功返回true，失败返回false
     */
    JsonVO<String> modifySchedule(SaveScheduleDTO saveScheduleDTO);

    /**
     * @描述 排班删除
     * @param scheduleId
     * @return
     */
    JsonVO scheduleDelete(long  scheduleId);

    /**
     * @param scheduleId
     * @param status
     * @return
     * @描述 修改排班状态(启用 / 停用)
     */
    JsonVO scheduleStatus(long  scheduleId);

    /**
     * @描述 查询排班详细信息
     * @param scheduleId
     * @return
     */
    JsonVO<ScheduleClassChangeVO> scheduleChange(long  scheduleId);

    /**
     * @描述 查询排班人员列表
     * @param scheduleId
     * @return
     */
    JsonVO<PageDTO<ScheduleClassStaffVO>> schedulePeople( long pageIndex, long pageSize, long scheduleId);

    /* 1. 添加关联人员
    *@param AssociatedPersonnelDTO 添加员工信息
    *@return ture or false
     */
    JsonVO<String> addAssociatedPersonnel(AddAssociatedPersonnelDTO addAssociatedPersonnelDTO);

    /*2. 删除关联人员
    *@param 工作人员id
    *@return ture or false
     */
    JsonVO deleteAssociatedPersonnel(String staff_id,String scheduleId);
}
