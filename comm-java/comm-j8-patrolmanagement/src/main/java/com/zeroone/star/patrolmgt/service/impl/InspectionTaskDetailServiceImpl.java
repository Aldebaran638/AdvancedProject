package com.zeroone.star.patrolmgt.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.patrolmgt.entity.*;
import com.zeroone.star.patrolmgt.mapper.InspectionTaskDetailMapper;
import com.zeroone.star.patrolmgt.service.*;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.detail.dto.DetailDTO;
import com.zeroone.star.project.j8.patrolmgt.detail.query.DetailQuery;
import com.zeroone.star.project.vo.JsonVO;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;

import javax.annotation.Resource;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author yuanzijie
 * @since 2025-05-24
 */
@Service
public class InspectionTaskDetailServiceImpl extends ServiceImpl<InspectionTaskDetailMapper, InspectionTaskDetail> implements IInspectionTaskDetailService {

    @Resource
    MsDetailMapper ms;
    @Autowired
    detail_IInspectionTaskService detail_InspectionTaskService;
    @Autowired
    detail_IInspectionPlanService detail_InspectionPlanService;
    @Autowired
    detail_IInspectionPlanStaffService detail_InspectionPlanStaffService;
    @Autowired
    detail_IInspectionRouteService detail_InspectionRouteService;
    @Autowired
    detail_t_dictService detail_t_dictService;

    @Override
    public PageDTO<DetailDTO> queryAll(DetailQuery query) {
        try {
            // 构建分页查询对象
            Page<InspectionTaskDetail> page = new Page<>(query.getPageIndex(), query.getPageSize());
            // 构建查询条件
            QueryWrapper<InspectionTaskDetail> wrapper = new QueryWrapper<>();
            // 添加计划巡检人可选查询（关联 inspection_task 表）
            if (!StringUtils.isEmpty(query.getPlanUserName())) {
                wrapper.apply("EXISTS (SELECT 1 FROM inspection_task t WHERE t.task_id = inspection_task_detail.task_id AND t.plan_user_name = {0})", query.getPlanUserName());
            }
            //添加实际巡检开始时间可选查询
            wrapper.eq(!StringUtils.isEmpty(query.getPointStartTime()),"point_start_time",query.getPointStartTime());
            //添加实际巡检结束时间可选查询
            wrapper.eq(!StringUtils.isEmpty(query.getPointEndTime()),"point_end_time",query.getPointEndTime());
            //查询分页数据，查询出来的数据符合以上条件
            Page<InspectionTaskDetail> pageResult = baseMapper.selectPage(page, wrapper);
            List<DetailDTO> processdList = new ArrayList<>();
            //对查询出来的每条实体类数据进行处理
            for(InspectionTaskDetail detail:pageResult.getRecords()){
                DetailDTO detailDTO = ms.detailToDto(detail);
                //1.查询inspection_task表,获得detail_InspectionTask巡检任务实体类
                detail_InspectionTask inspectionTask = detail_InspectionTaskService.getById(detail.getTaskId());

                if (inspectionTask == null) {
                    log.warn("未找到 taskId={} 对应的巡检任务");
                    continue; // 跳过该条数据
                }

                //2.查询inspection_plan表,获得detail_InspectionPlan巡检计划实体类
                detail_InspectionPlan inspectionPlan = detail_InspectionPlanService.getById(inspectionTask.getInspectionPlanId());
                //3.查询inspection_plan_staff表,获得detail_InspectionPlanStaff巡检人实体类
                detail_InspectionPlanStaff inspectionPlanStaff = detail_InspectionPlanStaffService.getById(inspectionTask.getIpStaffId());
                //4.查询inspection_route表，获得detail_inspection_route巡检路线实体类
                detail_InspectionRoute inspectionRoute = detail_InspectionRouteService.getById(inspectionPlan.getInspectionRouteId());

                //能在inspection_task_detail直查到的都可以由DetailDTO detailDTO = ms.detailToDto(detail);转化而来
                //下面是需要联表查询的字段
                //3.巡检计划名称 --- 通过任务ID查到计划ID --- 直查
                detailDTO.setInspectionPlanName(inspectionPlan.getInspectionPlanName());
                //4.巡检路线名称 --- 通过任务ID查到计划ID --- 通过计划ID查到路线ID --- 直查
                detailDTO.setInspectionRouteName(inspectionRoute.getRouteName());
                //5.巡检人开始/结束时间 --- 通过任务ID查到巡检人ID --- 直查start_time和end_time
                LocalDateTime personStartTime = inspectionTask.getPlanInsTime();
                if(personStartTime != null){
                    Date startTimeDate = Date.from(personStartTime.atZone(ZoneId.systemDefault()).toInstant());
                    detailDTO.setInspectionPersonStartTime(startTimeDate);
                }
                LocalDateTime personEndTime = inspectionTask.getPlanEndTime();
                if(personEndTime != null){
                    Date endTimeDate = Date.from(personEndTime.atZone(ZoneId.systemDefault()).toInstant());
                    detailDTO.setInspectionPersonEndTime(endTimeDate);
                }
                /*SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss"); //!!硬编码问题!!!
                Date startTimeDate = sdf.parse(inspectionTask.getPlanInsTime());
                detailDTO.setInspectionPersonStartTime(startTimeDate);
                Date endTimeDate = sdf.parse(inspectionTask.getPlanEndTime());
                detailDTO.setInspectionPersonEndTime(endTimeDate);*/
                /*SimpleDateFormat sdf = new SimpleDateFormat("HH:mm");

                String startTimeStr = inspectionPlanStaff.getStartTime(); // 如 "02:05"
                String endTimeStr = inspectionPlanStaff.getEndTime();     // 如 "03:10"

                Date startTimeDate = null;
                Date endTimeDate = null;

                if (startTimeStr != null && !startTimeStr.isEmpty()) {
                    startTimeDate = sdf.parse(startTimeStr);
                }
                if (endTimeStr != null && !endTimeStr.isEmpty()) {
                    endTimeDate = sdf.parse(endTimeStr);
                }

                detailDTO.setInspectionPersonStartTime(startTimeDate);
                detailDTO.setInspectionPersonEndTime(endTimeDate);*/


                //7.实际巡检时间 --- 通过任务ID -- 直查act_ins_time
                LocalDateTime actInsTime = inspectionTask.getActInsTime();
                if (actInsTime != null) {
                    Date actInsDate = Date.from(actInsTime.atZone(ZoneId.systemDefault()).toInstant());
                    detailDTO.setActPatrolTime(actInsDate);
                } else {
                    detailDTO.setActPatrolTime(null);
                }
                //8.实际签到状态 --- 直查state
                //detailDTO.setInspectionActualSignStatus(inspectionTask.getState());
                //9.计划巡检人 ---   通过任务ID -- 直查plan_user_name
                detailDTO.setInspectionPlanPersonName(inspectionTask.getPlanUserName());
                // 11. 巡检方式 --- 通过计划ID -- 直查sign_type  字典值转化
                String dictValue1 = inspectionTask.getSignType();
                detail_t_dict dict1 = detail_t_dictService.getOne(
                        new QueryWrapper<detail_t_dict>().eq("status_cd", dictValue1).last("LIMIT 1"));
                detailDTO.setInspectionMethod(dict1 != null ? dict1.getName() : null);

                // 12. 任务状态 --- 通过任务ID -- 直查state   字典值转化
                String dictValue2 = inspectionTask.getState();
                detail_t_dict dict2 = detail_t_dictService.getOne(
                        new QueryWrapper<detail_t_dict>().eq("status_cd", dictValue2).last("LIMIT 1"));
                detailDTO.setInspectionTaskStatus(dict2 != null ? dict2.getName() : null);

                //15.巡检照片 !!!数据库中未找到
                detailDTO.setInspectionPhoto(null);

                //添加到List
                processdList.add(detailDTO);
            }

            //构造返回值
            PageDTO<DetailDTO> result = new PageDTO<>();
            result.setPageIndex(pageResult.getCurrent());
            result.setPageSize(pageResult.getSize());
            result.setTotal(pageResult.getTotal());
            result.setPages(pageResult.getPages());
            result.setRows(processdList);

            return result;

        } catch (Exception e){
            log.error("查询巡检明细发生异常", e);
            throw new RuntimeException("查询巡检明细失败", e);
        }

    }
}
