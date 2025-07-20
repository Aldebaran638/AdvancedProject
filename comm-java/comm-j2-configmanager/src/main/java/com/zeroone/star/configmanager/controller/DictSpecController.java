package com.zeroone.star.configmanager.controller;

import com.zeroone.star.configmanager.entity.DictSpec;
import com.zeroone.star.configmanager.service.IDictSpecService;
import com.zeroone.star.configmanager.service.impl.MsDictSpecMapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.configmanager.dict.DictSpecAddDTO;
import com.zeroone.star.project.dto.j2.configmanager.dict.DictSpecDTO;
import com.zeroone.star.project.j2.configmanager.dict.DictSpecApis;
import com.zeroone.star.project.query.j2.configmanager.dict.DictSpecQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 *  字典类型控制器
 * </p>
 *
 * @author fish
 * @since 2025-05-19
 */
@RestController
@RequestMapping("/j2-configmanager/dict-spec")
@Api(tags = "配置管理-字典类型")
@Validated
public class DictSpecController implements DictSpecApis {


    @Resource
    private MsDictSpecMapper ms;

    @Resource
    private IDictSpecService service;


    @PostMapping("/add")
    @ApiOperation(value = "添加字典类型")
    @Override
    public JsonVO<String> addDictSpec(@Validated @RequestBody DictSpecAddDTO addDto) {
        int i = service.saveDictSpec(addDto);
        if (i == 0)
            return JsonVO.fail("添加失败");
        if (i == 2)
            return JsonVO.fail("名称重复");
        return JsonVO.success("添加成功");
    }

    @PutMapping ("/modify")
    @ApiOperation(value = "修改字典类型")
    @Override
    public JsonVO<String> modifyDictSpec(@Validated @RequestBody DictSpecDTO dto) {
        System.out.println(dto.getSpecId());
        DictSpec dictSpec = ms.dtoToDo(dto);
        if (service.updateById(dictSpec))
            return JsonVO.success(dto.getSpecId());
        return JsonVO.fail("修改失败");
    }

    @DeleteMapping("/delete")
    @ApiOperation(value = "删除字典类型")
    @ApiImplicitParam( name = "id", value = "字典类型编号", required = true, dataType = "String" )
    @Override
    public JsonVO<String> deleteDictSpec( String id) {
        if (service.removeById(id))
            return JsonVO.success("删除成功");
        return JsonVO.fail("删除失败");
    }

    @GetMapping("/query-names")
    @ApiOperation(value = "查询字典类型名称列表")
    @Override
    public JsonVO<List<DictSpecDTO>> queryListNames() {
        return JsonVO.success(service.queryListNames());
    }

    @GetMapping("/query-all")
    @ApiOperation(value = "查询字典类型列表(条件+分页)")
    @Override
    public JsonVO<PageDTO<DictSpecDTO>> queryAll(@Validated DictSpecQuery condition) {
        return JsonVO.success(service.queryAll(condition));
    }

}

