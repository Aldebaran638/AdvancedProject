package com.zeroone.star.patrolmgt.controller;


import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.zeroone.star.patrolmgt.entity.InspectionItemTitleValue;
import com.zeroone.star.patrolmgt.entity.TangSenQuan_InspectionItemTitle;
import com.zeroone.star.patrolmgt.service.IInspectionItemTitleService;
import com.zeroone.star.patrolmgt.service.IInspectionItemTitleValueService;
import com.zeroone.star.patrolmgt.service.impl.MsInspectionItemTitleMapper;
import com.zeroone.star.patrolmgt.service.impl.MsInspectionItemTitleValueMapper;
import com.zeroone.star.project.j8.patrolmgt.item.dto.inspection.InspectionTitleAddDTO;
import com.zeroone.star.project.j8.patrolmgt.item.dto.inspection.InspectionTitleDTO;
import com.zeroone.star.project.j8.patrolmgt.item.inspection.InspectionTitleApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.item.query.ItemTitleQuery;
import com.zeroone.star.project.j8.patrolmgt.item.vo.ItemTitleVO;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author 唐森权
 * @since 2025-05-16
 */
@RestController
@RequestMapping("j8-patrolmgt/item")
@Api(tags = "巡检项目")
public class InspectionItemTitleController implements InspectionTitleApis {

    @Resource
    IInspectionItemTitleService service;

    @Override
    @GetMapping("/query-inspection-item-list")
    @ApiOperation(value = "获取巡检题目列表（条件＋分页")
    public JsonVO<PageDTO<ItemTitleVO>> queryItemTitleList(ItemTitleQuery query) {
        return JsonVO.success(service.queryItemTitleList(query));
    }

    @Resource
    MsInspectionItemTitleMapper ms;

    @Resource
    private IInspectionItemTitleValueService inspectionItemTitleValueService;

    @Resource
    private MsInspectionItemTitleValueMapper msInspectionItemTitleValueMapper;

    @PostMapping("/add-inspection-item")
    @Override
    @ApiOperation(value = "增加巡检题目")
    public JsonVO<String> addInspectionTitle(@Validated @RequestBody InspectionTitleAddDTO addDTO) {
//        TangSenQuan_InspectionItemTitle inspectionItemTitle = ms.addDoToDo(addDTO);
//        if (service.save(inspectionItemTitle)){
//            return JsonVO.success(inspectionItemTitle.getTitleId());
//        }
//        return JsonVO.fail(null);
        // 保存主表
        TangSenQuan_InspectionItemTitle inspectionItemTitle = ms.addDoToDo(addDTO);
        if (service.save(inspectionItemTitle)){
            // 保存选项列表（如果有）
            if (addDTO.getValues() != null && !addDTO.getValues().isEmpty()) {
                List<InspectionItemTitleValue> values = addDTO.getValues().stream()
                        .map(dto -> {
                            InspectionItemTitleValue value = msInspectionItemTitleValueMapper.addDoTODo(dto);
                            value.setTitleId(inspectionItemTitle.getTitleId());
                            return value;
                        }).collect(Collectors.toList());
                inspectionItemTitleValueService.saveBatch(values);
            }
            return JsonVO.success(inspectionItemTitle.getTitleId());
        }
        return JsonVO.fail(null);
//        // 保存主表
//        InspectionItemTitle inspectionItemTitle = ms.addDoToDo(addDTO);
//        if (service.save(inspectionItemTitle)){
//            // 保存选项列表（如果有）
//            if (addDTO.getValues() != null && !addDTO.getValues().isEmpty()) {
//                List<InspectionItemTitleValue> values = addDTO.getValues().stream()
//                        .map(dto -> {
//                            InspectionItemTitleValue value = msInspectionItemTitleValueMapper.addDoTODo(dto);
//                            value.setTitleId(inspectionItemTitle.getTitleId());
//                            return value;
//                        }).collect(Collectors.toList());
//                inspectionItemTitleValueService.saveBatch(values);
//            }
//            return JsonVO.success(inspectionItemTitle.getTitleId());
//        }
//        return JsonVO.fail(null);
    }

    @Override
    @PutMapping("/modify-inspection-item")
    @ApiOperation(value = "修改巡检题目")
    public JsonVO<String> modifyInspectionTitle(@Validated @RequestBody InspectionTitleDTO dto) {
        service.updateById(ms.dtoToDo(dto));

        // 处理选项列表更新（先删后增）
        if (dto.getValues() != null) {
            LambdaQueryWrapper<InspectionItemTitleValue> wrapper = new LambdaQueryWrapper<>();
            wrapper.eq(InspectionItemTitleValue::getTitleId, dto.getTitleId());
            inspectionItemTitleValueService.remove(wrapper);

            List<InspectionItemTitleValue> values = dto.getValues().stream()
                    .map(valueDto -> {
                        InspectionItemTitleValue value = msInspectionItemTitleValueMapper.dtoToDo(valueDto);
                        value.setTitleId(dto.getTitleId());
                        return value;
                    }).collect(Collectors.toList());
            inspectionItemTitleValueService.saveBatch(values);
        }

        return JsonVO.success(dto.getTitleId());
    }

    @Override
    @DeleteMapping("/remove-inspection-item/{titleId}")
    @ApiOperation(value = "删除巡检题目")
    @ApiImplicitParam(name = "titleId",value = "题目id",required = true,example = "123456")
    public JsonVO<String> removeInspectionTitle(@PathVariable("titleId") String titleId) {
        if (service.removeById(titleId)){
            return JsonVO.success(titleId);
        }
        return JsonVO.fail(null);
    }
}

