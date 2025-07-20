package com.zeroone.star.patrolmgt.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.zeroone.star.patrolmgt.entity.InspectionTask;
import com.zeroone.star.project.j8.patrolmgt.task.query.TaskQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * 巡检任务数据层接口
 * @author JIAN
 */
@Mapper
public interface TaskMapper extends BaseMapper<InspectionTask> {
    /**
     * 根据分页参数和查询条件查询巡检任务
     * @param page      分页参数
     * @param taskQuery 查询条件
     * @return 巡检任务对象序列(包括巡检计划名称)
     */
    List<InspectionTask> selectTaskByPage(@Param("page") IPage<InspectionTask> page,
                                          @Param("query") TaskQuery taskQuery);

    /**
     * 根据id查询巡检任务
     * @param id 巡检任务id
     * @return 巡检任务对象(包括巡检计划名称)
     */
    InspectionTask selectTaskById(@Param("id") Integer id);
}