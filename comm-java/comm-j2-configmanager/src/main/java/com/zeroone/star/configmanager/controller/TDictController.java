package com.zeroone.star.configmanager.controller;


import com.zeroone.star.configmanager.service.ITDictService;
import com.zeroone.star.configmanager.service.impl.MSTDictMapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.configmanager.sys.dictionary.*;
import com.zeroone.star.project.j2.configmanager.dict.TDictApis;
import com.zeroone.star.project.query.j2.configmanager.sys.dictionary.DictionaryQuery;
import com.zeroone.star.project.query.j2.configmanager.sys.dictionary.TDictQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;


/**
 * 菜单目录控制器
 */
@RestController
@RequestMapping("/j2-configmanager/sys")
@Api(tags = "配置管理-字典")
public class TDictController implements TDictApis {
    @Resource
    ITDictService service;

    @Resource
    MSTDictMapper ms;

    @ApiOperation(value = "获取字典名称列表")
    @GetMapping("/query-dictionary")
    @Override
    public JsonVO<PageDTO<AddDictionaryDTO>> queryDictionary(
            @Validated DictionaryQuery query) {
        return JsonVO.success(service.listByConditions(query));
    }

    @ApiOperation(value = "获取字典列表(条件+分页)")
    @GetMapping("/query-t_dict")
    @Override
    public JsonVO<PageDTO<AddTDictResDTO>> queryTDict(
            @Validated TDictQuery condition) {
        return JsonVO.success(service.listAll(condition));
    }

    @ApiOperation(value = "添加字典")
    @PostMapping("/add-t_dict")
    @Override
    public JsonVO<Boolean> addTDict(
            @Validated @RequestBody AddTDictDTO dto) {
        ResultStatus result = service.addTDict(dto);
        return JsonVO.create(result.getCode() == 10000, result);
    }

    @ApiOperation(value = "修改字典")
    @PutMapping("/modify-t_dict")
    @Override
    public JsonVO<Boolean> modifyTDict(@Validated @RequestBody ModifyTDictDTO tDictDTO) {
        ResultStatus result = service.modifyTDict(tDictDTO);
        return JsonVO.create(result.getCode() == 10000, result);
    }

    @ApiOperation(value = "删除字典")
    @ApiImplicitParam(name = "id",required = true,value = "字典编号")
    @DeleteMapping("/remove-t_dict")
    @Override
    public JsonVO<String> removeTDict(Integer id) {
        Boolean result = service.removeById(id);
        return result?JsonVO.success("删除成功"):JsonVO.fail("删除失败");
    }
}
