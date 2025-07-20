package com.zeroone.star.patrolmgt.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.patrolmgt.entity.InspectionTask;
import com.zeroone.star.patrolmgt.mapper.TaskMapper;
import com.zeroone.star.patrolmgt.service.TaskService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.task.dto.TaskDTO;
import com.zeroone.star.project.j8.patrolmgt.task.dto.UpdateTaskUserDTO;
import com.zeroone.star.project.j8.patrolmgt.task.query.TaskQuery;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.Mappings;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * 转换巡检任务的DO对象和DTO对象
 * @author JIAN
 */
@Mapper(componentModel = "spring")
interface TaskDTOMapper {
    /**
     * 将InspectionTask对象转换为TaskDTO对象
     */
    @Mappings({
            @Mapping(target = "planId", source = "inspectionPlanId"),
            @Mapping(target = "planName", source = "inspectionPlanName")
    })
    TaskDTO InspectionTaskToTaskDTO(InspectionTask inspectionTask);
}
/**
 * 巡检任务业务层接口实现类
 * @author JIAN
 */


@Service
public class TaskServiceImpl extends ServiceImpl<TaskMapper, InspectionTask> implements TaskService {
    @Resource
    private TaskDTOMapper fieldMapper;

    @Override
    public PageDTO<TaskDTO> listAllTask(TaskQuery taskQuery) {
        // 构造分页参数
        Page<InspectionTask> page = new Page<>(taskQuery.getPageIndex(), taskQuery.getPageSize());
        // 使用原生SQL查询(需要联表)
        List<InspectionTask> taskList = baseMapper.selectTaskByPage(page, taskQuery);
        page.setRecords(taskList);
        // 构造分页对象
        return PageDTO.create(page, fieldMapper::InspectionTaskToTaskDTO);
    }

    @Override
    public boolean updateTaskUser(UpdateTaskUserDTO updateTaskUserDTO) {
        InspectionTask inspectionTask = baseMapper.selectById(updateTaskUserDTO.getTaskId());
        if (inspectionTask == null) throw new RuntimeException("任务不存在无法修改");

        // TODO 查找被转移人id

        return lambdaUpdate()
                .eq(InspectionTask::getTaskId, updateTaskUserDTO.getTaskId())
                .set(InspectionTask::getActUserId, updateTaskUserDTO.getNewUserId())
                .set(InspectionTask::getActUserName, null) // TODO
                .set(InspectionTask::getOriginalPlanUserId, inspectionTask.getPlanUserId())
                .set(InspectionTask::getOriginalPlanUserName, inspectionTask.getPlanUserName())
                .set(InspectionTask::getTransferDesc, updateTaskUserDTO.getTransferDesc())
                .set(InspectionTask::getTaskType, "2000")
                .update();
    }

    @Override
    public TaskDTO getTaskById(Integer taskId) {
        InspectionTask inspectionTask = baseMapper.selectTaskById(taskId);

        if (inspectionTask == null) return new TaskDTO();
        return fieldMapper.InspectionTaskToTaskDTO(inspectionTask);
    }
}