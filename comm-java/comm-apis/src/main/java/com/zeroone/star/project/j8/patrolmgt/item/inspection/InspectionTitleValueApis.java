package com.zeroone.star.project.j8.patrolmgt.item.inspection;

import com.zeroone.star.project.j8.patrolmgt.item.dto.inspection.InspectionTitleValueAddDTO;
import com.zeroone.star.project.j8.patrolmgt.item.dto.inspection.InspectionTitleValueDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;

import java.util.List;

@Api(tags = "巡检项目选项管理")
public interface InspectionTitleValueApis {
    @ApiOperation(value = "添加巡检项目选项")
    JsonVO<String> addInspectionTitleValue(@RequestBody InspectionTitleValueAddDTO dto);

    @ApiOperation(value = "删除巡检项目选项")
    JsonVO<String> deleteInspectionTitleValue(@PathVariable("valueId") String valueId);

    @ApiOperation(value = "修改巡检项目选项")
    JsonVO<String> updateInspectionTitleValue(@RequestBody InspectionTitleValueDTO dto);


}
