package com.zeroone.star.project.j8.patrolmgt.item.inspection;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.item.dto.inspection.InspectionTitleAddDTO;
import com.zeroone.star.project.j8.patrolmgt.item.dto.inspection.InspectionTitleDTO;
import com.zeroone.star.project.j8.patrolmgt.item.query.ItemTitleQuery;
import com.zeroone.star.project.j8.patrolmgt.item.vo.ItemTitleVO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

/**
 * 巡检题目接口定义
 */
@Api(tags = "巡检项目题目管理")
@RequestMapping("/inspection-item-titles")
public interface InspectionTitleApis {
    @GetMapping("/query-inspection-item-list")
    @ApiOperation(value = "获取巡检题目列表（条件＋分页")
    JsonVO<PageDTO<ItemTitleVO>> queryItemTitleList(ItemTitleQuery query);

    /**
     * 巡检题目添加
     * @param addDTO 巡检题目新增数据
     * @return 新增结果
     */
    @PostMapping("/add-inspection-item")
    @ApiOperation(value = "增加巡检题目")
    JsonVO<String> addInspectionTitle(InspectionTitleAddDTO addDTO);

    /**
     * 巡检题目修改
     * @param dto 巡检题目修改数据
     * @return 修改结果
     */
    @PutMapping("/modify-inspection-item")
    @ApiOperation(value = "修改巡检题目")
    JsonVO<String> modifyInspectionTitle(InspectionTitleDTO dto);

    /**
     * 巡检题目删除
     * @param titleId 巡检题目删除id
     * @return 删除结果
     */
    @DeleteMapping("/{titleId}")
    @ApiOperation(value = "删除巡检题目")
    JsonVO<String> removeInspectionTitle(String titleId);
}
