package com.zeroone.star.orgmanager.service.impl;

import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import com.zeroone.star.orgmanager.config.PositiveSnowflakeGenerator;
import com.zeroone.star.orgmanager.entity.ClassesTime;
import com.zeroone.star.orgmanager.entity.ScheduleClasses;
import com.zeroone.star.orgmanager.entity.ScheduleClassesDay;
import com.zeroone.star.orgmanager.entity.ScheduleClassesTime;
import com.zeroone.star.orgmanager.mapper.ClassesTimeMapper;
import com.zeroone.star.orgmanager.mapper.ScheduleClassesDayMapper;
import com.zeroone.star.orgmanager.mapper.ScheduleClassesTimeMapper;
import com.zeroone.star.orgmanager.mapper.SchedulingMapper;
import com.zeroone.star.orgmanager.service.SchedulingService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AddScheduleDTO;
import com.zeroone.star.project.dto.j4.orgmanager.SaveScheduleDTO;
import com.zeroone.star.project.dto.j4.orgmanager.SettingNameDTO;
import com.zeroone.star.project.query.j4.orgmanager.ScheduleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.j4.orgmanager.ScheduleClassChangeVO;
import com.zeroone.star.project.vo.j4.orgmanager.ScheduleClassStaffVO;
import com.zeroone.star.project.vo.j4.orgmanager.ScheduleVO;
import lombok.Getter;
import lombok.Setter;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;

@Service
public class SchedulingServiceImpl implements SchedulingService {
    private static final AtomicInteger COUNTER = new AtomicInteger(0); // 原子计数器（处理同一毫秒内的并发）
    @Resource
    private SchedulingMapper schedulingMapper;
    @Autowired
    private ScheduleClassesDayMapper scheduleClassesDayMapper;
    @Autowired
    private ScheduleClassesTimeMapper scheduleClassesTimeMapper;
    @Autowired
    private ClassesTimeMapper classesTimeMapper;
    @Override
    public List<SettingNameDTO> listName() {
        //从数据库中读取排班设置名称列表
        List<SettingNameDTO> list=schedulingMapper.selectName();
        return list;
    }
    /**
     * 获取排版设置列表（条件+分页）
     * @return
     */
    @Override
    public PageDTO<ScheduleVO> listSchedule(ScheduleQuery query) {
        PageHelper.startPage(query.getPageIndex(), query.getPageSize());
        List<ScheduleVO> list= schedulingMapper.selectSchedule(query);
        PageDTO<ScheduleVO> pageResult = new PageDTO<>();
        //总条数
        Long total=schedulingMapper.countTotal(query);
        pageResult.setTotal(total);
        //每页条数
        Long size=query.getPageSize().longValue();
        pageResult.setPageSize(size);
        //页码
        Long index=query.getPageIndex().longValue();
        pageResult.setPageIndex(index);
        //总页码
        Long pages=total/size;
        pageResult.setPages(pages);
        //数据
        pageResult.setRows(list);
        return pageResult;
    }

    /**
     * 添加排班设置
     * @param addScheduleDTO
     */
    @Transactional
    @Override
    public void addSchedule(AddScheduleDTO addScheduleDTO)
    {
        //生成ScheduleClasses实体
        ScheduleClasses scheduleClassesEntity=createScheduleEntity(addScheduleDTO);
        //向schedule_classes插入数据
        schedulingMapper.insertScheduleClasses(scheduleClassesEntity);
        List<AddScheduleDTO.ScheduleDetail> details=addScheduleDTO.getDetails();
        for (AddScheduleDTO.ScheduleDetail detail:details)
        {
            //生成ScheduleClassesDay实体
            ScheduleClassesDay scheduleClassesDayEntity=createScheduleClassesDayEntity(scheduleClassesEntity,detail);
            scheduleClassesDayMapper.insertScheduleClassesDay(scheduleClassesDayEntity);
            if(scheduleClassesDayEntity.getWorkday()!="2002")
            {
                //获得对应这一天的班次id
                String classId=detail.getClassesId();
                //解析班次id的时间
                List<ClassesTime> classesTimes=classesTimeMapper.selectClassesTimeById(classId);
                for(ClassesTime classesTime:classesTimes)
                {
                    //生成ScheduleClassesTime实体
                    ScheduleClassesTime scheduleClassesTimeEntity=createScheduleClassesTimeEntity(scheduleClassesDayEntity,scheduleClassesEntity,classesTime);
                    scheduleClassesTimeMapper.insertScheduleClassesTime(scheduleClassesTimeEntity);
                }
            }
        }

    }

    @Transactional
    @Override
    public boolean updateSchedule(SaveScheduleDTO saveScheduleDTO) {
        //先删除，后添加,包括schedule也是重新生成的
        String dId=saveScheduleDTO.getScheduleId();
        ScheduleClasses entity=schedulingMapper.selectScheduleById(dId);
        if(entity==null)
        {
            return false;
        }
        schedulingMapper.deleteByScheduleId(dId);
        scheduleClassesDayMapper.deleteByScheduleId(dId);
        scheduleClassesTimeMapper.deleteByScheduleId(dId);
        //添加
        AddScheduleDTO addScheduleDTO = new AddScheduleDTO();

        // 1. 复制基础字段（名称和类型相同的字段）
        BeanUtils.copyProperties(saveScheduleDTO, addScheduleDTO);

        // 2. 手动转换 details 列表（关键步骤）
        List<AddScheduleDTO.ScheduleDetail> targetDetails = new ArrayList<>();
        for (SaveScheduleDTO.ScheduleDetail sourceDetail : saveScheduleDTO.getDetails()) {
            AddScheduleDTO.ScheduleDetail targetDetail = new AddScheduleDTO.ScheduleDetail();
            // 复制内部类的字段（名称和类型相同）
            BeanUtils.copyProperties(sourceDetail, targetDetail);
            targetDetails.add(targetDetail);
        }
        addScheduleDTO.setDetails(targetDetails);
        //生成ScheduleClasses实体
        ScheduleClasses scheduleClassesEntity=createScheduleEntity(addScheduleDTO);
        //向schedule_classes插入数据
        schedulingMapper.insertScheduleClasses(scheduleClassesEntity);
        List<AddScheduleDTO.ScheduleDetail> details=addScheduleDTO.getDetails();
        for (AddScheduleDTO.ScheduleDetail detail:details)
        {
            //生成ScheduleClassesDay实体
            ScheduleClassesDay scheduleClassesDayEntity=createScheduleClassesDayEntity(scheduleClassesEntity,detail);
            scheduleClassesDayMapper.insertScheduleClassesDay(scheduleClassesDayEntity);
            if(scheduleClassesDayEntity.getWorkday()!="2002")
            {
                //获得对应这一天的班次id
                String classId=detail.getClassesId();
                //解析班次id的时间
                List<ClassesTime> classesTimes=classesTimeMapper.selectClassesTimeById(classId);
                for(ClassesTime classesTime:classesTimes)
                {
                    //生成ScheduleClassesTime实体
                    ScheduleClassesTime scheduleClassesTimeEntity=createScheduleClassesTimeEntity(scheduleClassesDayEntity,scheduleClassesEntity,classesTime);
                    scheduleClassesTimeMapper.insertScheduleClassesTime(scheduleClassesTimeEntity);
                }
            }
        }
        return true;
    }

    public ScheduleClassesTime createScheduleClassesTimeEntity(ScheduleClassesDay scheduleClassesDayEntity, ScheduleClasses scheduleClassesEntity,ClassesTime classesTime)
    {
        ScheduleClassesTime scheduleClassesTimeEntity=new ScheduleClassesTime();
        scheduleClassesTimeEntity.setScheduleId(scheduleClassesEntity.getScheduleId());
        scheduleClassesTimeEntity.setTimeId(createUUID());
        scheduleClassesTimeEntity.setStartTime(classesTime.getStartTime());
        scheduleClassesTimeEntity.setEndTime(classesTime.getEndTime());
        scheduleClassesTimeEntity.setCreateTime(scheduleClassesEntity.getCreateTime());
        scheduleClassesTimeEntity.setDayId(scheduleClassesDayEntity.getDayId());
        scheduleClassesTimeEntity.setStatusCd(scheduleClassesEntity.getStatusCd());
        return scheduleClassesTimeEntity;
    }

    public ScheduleClassesDay createScheduleClassesDayEntity(ScheduleClasses scheduleClassesEntity,AddScheduleDTO.ScheduleDetail detail)
    {
        ScheduleClassesDay scheduleClassesDayEntity=new ScheduleClassesDay();
        String dId=createUUID();
        scheduleClassesDayEntity.setDayId(dId);
        scheduleClassesDayEntity.setScheduleId(scheduleClassesEntity.getScheduleId());
        scheduleClassesDayEntity.setWeekFlag(detail.getWeekFlag());
        scheduleClassesDayEntity.setDay(detail.getDay());
        scheduleClassesDayEntity.setWorkday(detail.getWorkdayType());
        scheduleClassesDayEntity.setCreateTime(scheduleClassesEntity.getCreateTime());
        scheduleClassesDayEntity.setStatusCd(scheduleClassesEntity.getStatusCd());
        return scheduleClassesDayEntity;

    }




    public String createUUID()
    {
        PositiveSnowflakeGenerator snowflakeUUIDGenerator=new PositiveSnowflakeGenerator(1);
        return snowflakeUUIDGenerator.createUUID();
    }
    public ScheduleClasses createScheduleEntity(AddScheduleDTO addScheduleDTO)
    {

        ScheduleClasses scheduleClassesEntity = new ScheduleClasses();
        //生成排班id
        String scheduleId = createUUID();
        //插入生成的排班id
        scheduleClassesEntity.setScheduleId(scheduleId);
        //默认值为-1
        scheduleClassesEntity.setBId("-1");
        //排版周期
        scheduleClassesEntity.setScheduleCycle(addScheduleDTO.getScheduleCycle());
        //排班名称
        scheduleClassesEntity.setName(addScheduleDTO.getName());
        //排班类型
        scheduleClassesEntity.setScheduleType(addScheduleDTO.getScheduleType());
        //这个商户id的设置应该是由登陆账号所解析出来的
        scheduleClassesEntity.setStoreId(addScheduleDTO.getStoreId());
        //添加状态，默认为1001即启用
        scheduleClassesEntity.setState("1001");
        //添加备注说明，默认为null
        scheduleClassesEntity.setRemark(null);
        //添加数据状态,默认为0
        scheduleClassesEntity.setStatusCd("0");
        //添加创建时间
        scheduleClassesEntity.setCreateTime(LocalDateTime.now());
        //添加计算时间
        LocalDateTime startOfDay = LocalDateTime.now().withHour(0).withMinute(0).withSecond(0);
        scheduleClassesEntity.setComputeTime(startOfDay);
        return scheduleClassesEntity;

    }

    @Override
    @Transactional(rollbackFor = Exception.class)
    public void scheduleDelete(long schedule_id) {
        schedulingMapper.schedulingDelete(schedule_id);
    }

    @Override
    @Transactional(rollbackFor = Exception.class)
    public void scheduleStatus(long scheduleId) {

        int nowState=schedulingMapper.selectSchedulingState(scheduleId);
        if(nowState==1001){
            schedulingMapper.schedulingState(2002, scheduleId);
        }else if(nowState==2002){
            schedulingMapper.schedulingState(1001, scheduleId);
        }
    }

    @Override
    public JsonVO<ScheduleClassChangeVO> scheduleChange(long scheduleId) {

        ScheduleClassChangeVO scheduleClassChangeVO=new ScheduleClassChangeVO();
        scheduleClassChangeVO=schedulingMapper.schedulingChange(scheduleId);

        List<List<String>> workTimeDTOList= new ArrayList<>();
        int typeTime=typeToDays(Integer.parseInt(scheduleClassChangeVO.getScheduleType()));
        int sumDays=scheduleClassChangeVO.getScheduleCycle()*typeTime;

        int week_flag_t=scheduleClassChangeVO.getScheduleCycle();
        if(!scheduleClassChangeVO.getScheduleType().equals("2002")){week_flag_t=1;}

        int week_flag=1;
        for(int i=1;i<=sumDays;i++){
            int day=i%typeTime;
            if(day==0){day=typeTime;}

            List<String> dayWorkTime = new ArrayList<>();

            DayToTime dayToTime=schedulingMapper.selectWorkDay(scheduleId,week_flag,day);
            if(dayToTime.workday == 2002){
                dayWorkTime.add("");
            }else{
                List<WorkTime> workTime = schedulingMapper.selectWorkTime(dayToTime.dayId);
                for (WorkTime wt : workTime) {
                    String time = wt.getStartTime().toString() + "-" + wt.getEndTime().toString();
                    dayWorkTime.add(time);
                }
            }
            workTimeDTOList.add(dayWorkTime);

            if(week_flag<week_flag_t && day==typeTime){
                week_flag++;
            }
        }

        scheduleClassChangeVO.setTimeList(workTimeDTOList);

        return JsonVO.create(scheduleClassChangeVO, ResultStatus.SUCCESS);

    }

    @Override
    public PageDTO<ScheduleClassStaffVO> schedulePeople(long pageIndex, long pageSize, long scheduleId) {
        PageDTO<ScheduleClassStaffVO> pageDTO = new PageDTO<>();
        pageDTO.setPageSize(pageSize);
        pageDTO.setPageIndex(pageIndex);

        PageHelper.startPage((int) pageIndex, (int) pageSize);
        List<ScheduleClassStaffVO> staffs = schedulingMapper.selectStaff(scheduleId);
        PageInfo<ScheduleClassStaffVO> pageInfo = new PageInfo<>(staffs);

        pageDTO.setTotal(pageInfo.getTotal()); // 设置总记录数
        pageDTO.setRows(pageInfo.getList());   // 设置当前页数据
        return pageDTO;
    }

    private int typeToDays(int scheduleType) {
        if(scheduleType==1001){
            return 1;
        }else if(scheduleType==2002){
            return 7;
        }
        return 31;

    }
    @Setter
    public static class DayToTime {
        long dayId;
        long workday;
    }

    @Getter
    public static class WorkTime {
        String startTime;
        String endTime;

    }
}
