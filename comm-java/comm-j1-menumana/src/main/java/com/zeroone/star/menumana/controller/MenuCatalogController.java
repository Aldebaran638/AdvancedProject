package com.zeroone.star.menumana.controller;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.menumana.entity.MenuCatalog;
import com.zeroone.star.menumana.service.IMenuCatalogService;
import com.zeroone.star.menumana.mapper.MsMenuCatalogMapper;
import com.zeroone.star.project.dto.j1.menumana.menudir.*;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j1.menumana.menudir.MenuCatalogApis;
import com.zeroone.star.project.query.j1.menumana.menudir.MenuCatalogQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.Valid;

@RestController
@RequestMapping("/j1-menumana")
@Api(tags = "菜单目录")
public class MenuCatalogController implements MenuCatalogApis {

    @Resource
    private IMenuCatalogService service;

    @Resource
    private MsMenuCatalogMapper ms;

    @Override
    @GetMapping("/query-menucatalogpage")
    @ApiOperation("分页查询菜单目录")
    public JsonVO<PageDTO<MenuCatalogDTO>> queryMenuCatalogPage(
            @Validated MenuCatalogQuery query) throws Exception {
        Page<MenuCatalog> page = new Page<>(query.getPageIndex(), query.getPageSize());
        return JsonVO.success(service.listMenuCatalogPage(page, query));
    }

    @Override
    @PostMapping("/add-menucatalog")
    @ApiOperation(value = "添加菜单目录")
    public JsonVO<String> addMenuCatalog(@RequestBody AddMenuCatalogDTO addMenuCatalogDTO) throws Exception {
        MenuCatalog menuCatalog = ms.addDtoToDo(addMenuCatalogDTO);
        if (service.saveMenuCatalog(menuCatalog)) {
            return JsonVO.success(menuCatalog.getCaId());
        }
        return JsonVO.fail(null);
    }

    @Override
    @PutMapping("/modify-menucatalog")
    @ApiOperation(value = "修改菜单目录")
    public JsonVO<String> modifyMenuCatalog(
            @Valid @RequestBody UpdateMenuCatalogDTO updateMenuCatalogDTO) throws Exception {
            if (StringUtils.isBlank(updateMenuCatalogDTO.getCaId())) {
                return JsonVO.fail("菜单目录ID不能为空");
            }
            if(service.updateMenuCatalog(updateMenuCatalogDTO)){
                return JsonVO.success(updateMenuCatalogDTO.getCaId());
            }
        return JsonVO.fail("更新失败,ID可能不存在或数据无效");
    }

    @Override
    @DeleteMapping("/remove-menucatalog/{id}")
    @ApiOperation(value = "删除菜单目录")
    public JsonVO<String> removeMenuCatalog(@PathVariable String id) throws Exception {
        if (service.removeMenuCatalog(id)) {
            return JsonVO.success(id);
        }
        return JsonVO.fail("删除失败");
    }
}