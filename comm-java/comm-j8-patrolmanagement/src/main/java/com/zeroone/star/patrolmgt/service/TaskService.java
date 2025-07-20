package com.zeroone.star.patrolmgt.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.patrolmgt.entity.InspectionTask;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.task.dto.TaskDTO;
import com.zeroone.star.project.j8.patrolmgt.task.dto.UpdateTaskUserDTO;
import com.zeroone.star.project.j8.patrolmgt.task.query.TaskQuery;

/**
 * 巡检任务业务层接口
 * @author JIAN
 */
public interface TaskService extends IService<InspectionTask> {
    /**
     * 分页查询巡检任务
     * @param taskQuery 分页查询条件
     * @return 巡检任务分页对象
     */
    PageDTO<TaskDTO> listAllTask(TaskQuery taskQuery);

    /**
     * 流转巡检任务
     * @param updateTaskUserDTO 流转信息
     * @return 是否成功流转
     */
    boolean updateTaskUser(UpdateTaskUserDTO updateTaskUserDTO);

    /**
     * 获取巡检任务详情
     * @param taskId 巡检任务id
     * @return 巡检任务对象
     */
    TaskDTO getTaskById(Integer taskId);
}