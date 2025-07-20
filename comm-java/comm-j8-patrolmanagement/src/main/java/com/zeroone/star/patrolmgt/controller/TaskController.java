package com.zeroone.star.patrolmgt.controller;

import com.zeroone.star.patrolmgt.service.TaskService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.task.TaskApi;
import com.zeroone.star.project.j8.patrolmgt.task.dto.TaskDTO;
import com.zeroone.star.project.j8.patrolmgt.task.dto.UpdateTaskUserDTO;
import com.zeroone.star.project.j8.patrolmgt.task.query.TaskQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * 巡检任务前端控制器
 * @author JIAN
 */

@RestController
@RequestMapping("/j8-patrolmgt/task")
@Api(tags = "巡检任务")
public class TaskController implements TaskApi {
    @Resource
    private TaskService taskService;

    @Override
    @GetMapping("/query-task-list")
    @ApiOperation("获取巡检任务列表（条件+分页）")
    public JsonVO<PageDTO<TaskDTO>> queryTaskList(TaskQuery taskQuery) {
        return JsonVO.success(taskService.listAllTask(taskQuery));
    }

    @Override
    @PostMapping("/user")
    @ApiOperation("流转")
    public JsonVO<String> modifyTaskUser(@RequestBody UpdateTaskUserDTO updateTaskUserDTO) {
        return taskService.updateTaskUser(updateTaskUserDTO)
                ? JsonVO.create(null, ResultStatus.SUCCESS.getCode(), "流转任务成功")
                : JsonVO.create(null, ResultStatus.FAIL.getCode(), "数据库更新错误请重试");
    }

    @Override
    @GetMapping("/query-task-detail/{taskId}")
    @ApiOperation("获取巡检任务详情")
    @ApiImplicitParam(name = "taskId", value = "巡检任务id", required = true)
    public JsonVO<TaskDTO> queryTaskDetail(@PathVariable Integer taskId) {
        return JsonVO.success(taskService.getTaskById(taskId));
    }
}