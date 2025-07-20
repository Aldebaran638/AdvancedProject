package com.zeroone.star.project.j8.patrolmgt.point; // 根据你的模块和业务功能调整包名，应位于 comm-apis 模块中

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.point.dto.AddPointDTO;
import com.zeroone.star.project.j8.patrolmgt.point.dto.PointDTO;
import com.zeroone.star.project.j8.patrolmgt.point.dto.SelectPointDTO;
import com.zeroone.star.project.j8.patrolmgt.point.query.PointQuery;
import com.zeroone.star.project.j8.patrolmgt.point.query.SelectPointQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.validation.annotation.Validated;
import com.zeroone.star.project.j8.patrolmgt.point.dto.AddPointDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：巡检点接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Susu Niu renyifei
 * @version 1.0.0
 */
public interface PointApis {

    /**Susu
     * 分页查询巡检点列表
     * @param query 查询条件和分页参数对象
     * @return 查询结果，包含分页信息和巡检点数据列表
     */
    JsonVO<PageDTO<PointDTO>> queryPointList(PointQuery query);

    /**Susu
     * 选择巡检点时分页查询巡检点列表
     * @param query 查询条件和分页参数对象
     * @return 查询结果，包含分页信息和巡检点数据列表
     */
    JsonVO<PageDTO<SelectPointDTO>> querySelectablePoints(SelectPointQuery query);


    /**Susu
     * 修改巡检点信息
     * @param pointDto 包含巡检点ID和待更新的字段信息的PointDTO对象
     * @return 操作结果消息
     */
    JsonVO<String> modifyPoint(@Validated PointDTO pointDto);

    /**Niu
     * 删除巡检点
     *
     * @param inspectionId 巡检点编号
     * @return 删除结果
     */
    ////
    JsonVO<String> removePoint(String inspectionId);

    /**renyifei
     * 添加巡检点
     * @param addPointDTO
     * @return
     */
    JsonVO<String> addPoint(AddPointDTO addPointDTO);
}
