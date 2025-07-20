package com.zeroone.star.project.j8.patrolmgt.task;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.task.dto.TaskDTO;
import com.zeroone.star.project.j8.patrolmgt.task.dto.UpdateTaskUserDTO;
import com.zeroone.star.project.j8.patrolmgt.task.query.TaskQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * 巡检任务相关接口
 * @author JIAN
 */
public interface TaskApi {
    /**
     * 分页查询巡检任务信息
     * @param taskQuery 分页参数及其他查询条件
     * @return 分页结果数据
     */
    JsonVO<PageDTO<TaskDTO>> queryTaskList(TaskQuery taskQuery);

    /**
     * 流转巡检任务
     * @param updateTaskUserDTO 流转信息
     * @return 成功返回巡检任务id否则为空值
     */
    JsonVO<String> modifyTaskUser(UpdateTaskUserDTO updateTaskUserDTO);

    /**
     * 查询巡检任务详情
     * @param taskId 巡检任务id
     * @return 巡检任务详情(巡检任务不存在时返回属性值为空的对象)
     */
    JsonVO<TaskDTO> queryTaskDetail(Integer taskId);
}