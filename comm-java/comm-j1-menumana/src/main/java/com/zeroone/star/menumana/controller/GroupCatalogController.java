package com.zeroone.star.menumana.controller;

import com.zeroone.star.menumana.service.IGroupCatalogService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.menudir.GroupCatalogAddDTO;
import com.zeroone.star.project.dto.j1.menumana.menudir.GroupCatalogDelDTO;
import com.zeroone.star.project.j1.menumana.menudir.GroupCatalogApis;
import com.zeroone.star.project.query.j1.menumana.menudir.GroupCatalogQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.j1.menumana.menudir.GroupCatalogAddVO;
import com.zeroone.star.project.vo.j1.menumana.menudir.GroupCatalogDelVO;
import com.zeroone.star.project.vo.j1.menumana.menudir.GroupCatalogQueryVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.Valid;
import java.util.List;

@RestController
@RequestMapping("/j1-/groupCatalog")
@Api(tags = "菜单目录")
@Slf4j
public class GroupCatalogController implements GroupCatalogApis {
    @Resource
    private IGroupCatalogService groupCatalogService;

    @Override
    @GetMapping("/query")
    @ApiOperation(value = "获取对应菜单组")
    public JsonVO<PageDTO<GroupCatalogQueryVO>> queryGroupCatalog(@Valid GroupCatalogQuery groupCatalogQuery,BindingResult bindingResult) {
        if (bindingResult.hasErrors()) {
            return JsonVO.create(null,ResultStatus.PARAMS_INVALID);
        }
        PageDTO<GroupCatalogQueryVO> pageDTO = groupCatalogService.listMenuCatalogGroup(groupCatalogQuery);
        return JsonVO.success(pageDTO);
    }

    @Override
    @PostMapping("/add")
    @ApiOperation("添加对应菜单组")
    public JsonVO<GroupCatalogAddVO> addGroupCatalog(@RequestBody @Valid GroupCatalogAddDTO groupCatalogAddDTO, BindingResult bindingResult) {
        if (bindingResult.hasErrors()) {
            return JsonVO.create(null,ResultStatus.PARAMS_INVALID);
        }

        GroupCatalogAddVO groupCatalogAddVO = groupCatalogService.saveMenuCatalogGroup(groupCatalogAddDTO);
        if(groupCatalogAddVO != null) {
            return JsonVO.success(groupCatalogAddVO);
        }else{
            return JsonVO.fail(null);
        }
    }

    @Override
    @DeleteMapping("/delete")
    @ApiOperation("删除对应菜单组")
    public JsonVO<GroupCatalogDelVO> removeGroupCatalog(@RequestBody @Valid GroupCatalogDelDTO groupCatalogDelDTO,BindingResult bindingResult) {
        if (bindingResult.hasErrors()) {
            return JsonVO.create(null,ResultStatus.PARAMS_INVALID);
        }
        GroupCatalogDelVO groupCatalogDelVO = groupCatalogService.removeMenuCatalogGroup(groupCatalogDelDTO);
        if (groupCatalogDelVO != null){
            return JsonVO.success(groupCatalogDelVO);
        }else{
            return JsonVO.fail(null);
        }
    }
}
