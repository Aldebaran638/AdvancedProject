package com.zeroone.star.patrolmgt.controller;


import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;

import com.zeroone.star.patrolmgt.entity.InspectionItemTitleValue;
import com.zeroone.star.patrolmgt.service.IInspectionItemTitleValueService;
import com.zeroone.star.patrolmgt.service.impl.MsInspectionItemTitleValueMapper;
import com.zeroone.star.project.j8.patrolmgt.item.dto.inspection.InspectionTitleValueAddDTO;
import com.zeroone.star.project.j8.patrolmgt.item.dto.inspection.InspectionTitleValueDTO;
import com.zeroone.star.project.j8.patrolmgt.item.inspection.InspectionTitleValueApis;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author 唐森权
 * @since 2025-05-16
 */
@RestController
@RequestMapping("j8-patrolmgt/inspectionTitle/inspection-item-title-value")
public class InspectionItemTitleValueController implements InspectionTitleValueApis {
    @Resource
    private IInspectionItemTitleValueService inspectionItemTitleValueService;

    @Resource
    private MsInspectionItemTitleValueMapper msInspectionItemTitleValueMapper;


    @Override
    @PostMapping("/add")
    public JsonVO<String> addInspectionTitleValue(@RequestBody InspectionTitleValueAddDTO dto) {
        InspectionItemTitleValue value = msInspectionItemTitleValueMapper.addDoTODo(dto);
        inspectionItemTitleValueService.save(value);
        return JsonVO.success(value.getValueId());
    }

    @Override
    @DeleteMapping("/delete/{valueId}")
    public JsonVO<String> deleteInspectionTitleValue(@PathVariable("valueId") String valueId) {
        if (inspectionItemTitleValueService.removeById(valueId)) {
            return JsonVO.success(valueId);
        }
        return JsonVO.fail("删除失败");
    }

    @Override
    @PutMapping("/update")
    public JsonVO<String> updateInspectionTitleValue(@RequestBody InspectionTitleValueDTO dto) {
        InspectionItemTitleValue value = msInspectionItemTitleValueMapper.dtoToDo(dto);
        if (inspectionItemTitleValueService.updateById(value)) {
            return JsonVO.success(value.getValueId());
        }
        return JsonVO.fail("更新失败");
    }

}

