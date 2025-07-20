package com.zeroone.star.menumana.controller;


import com.zeroone.star.menumana.service.IMenuGroupService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.menugroup.MenuGroupDTO;
import com.zeroone.star.project.dto.j1.menumana.menugroup.UpdateMenuGroupDTO;
import com.zeroone.star.project.j1.menumana.menugroup.MenuGroupApis;
import com.zeroone.star.project.query.j1.menumana.menugroup.MenuGroupQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.j1.menumana.menugroup.MenuGroupNameVO;
import com.zeroone.star.project.vo.j1.menumana.menugroup.MenuGroupVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.Valid;
import java.util.List;

@RestController
@RequestMapping("/j1-manumana/menu-group")
@Api(tags = "菜单组")
public class MenuGroupController implements MenuGroupApis {

    @Resource
    private IMenuGroupService menuGroupService;
    @ApiOperation("获取菜单组名称列表")
    @Override
    @GetMapping("/list-menu-group-name/{storeType}")
    public JsonVO<List<MenuGroupNameVO>> listMenuGroupName(@ApiParam(value = "商户类型", example = "800900000003")@PathVariable("storeType") String storeType) {
        List<MenuGroupNameVO> menuGroupNames=menuGroupService.listMenuGroupName(storeType);
        return JsonVO.success(menuGroupNames);
    }


    @ApiOperation("获取菜单组列表")
    @Override
    @GetMapping("/list-menu-group")
    public JsonVO<PageDTO<MenuGroupVO>> listMenuGroup(@ModelAttribute MenuGroupQuery query) {
        PageDTO<MenuGroupVO> pageDTO = menuGroupService.listMenuGroup(query);
        return JsonVO.success(pageDTO);
    }

    @ApiOperation("添加菜单组")
    @Override
    @PostMapping("/add-menu-group")
    public JsonVO<String> addMenuGroup(@RequestBody MenuGroupDTO menuGroupDTO) {
        if(menuGroupService.addMenuGroup(menuGroupDTO)){
            return JsonVO.create(null, ResultStatus.SUCCESS);
        }else{
            return JsonVO.create(null, ResultStatus.FAIL);
        }
    }

    @ApiOperation("修改菜单组")
    @Override
    @PutMapping("/update-menu-group")
    public JsonVO<String> updateMenuGroup(@RequestBody UpdateMenuGroupDTO updateMenuGroupDTO) {
        if(menuGroupService.updateMenuGroup(updateMenuGroupDTO)){
            return JsonVO.success("修改成功");
        }
        return JsonVO.fail("修改失败");
    }

    @ApiOperation("删除菜单组")
    @Override
    @DeleteMapping("/delete-menu-group/{gid}")
    public JsonVO<String> deleteMenuGroup(@ApiParam(value = "菜单组id", example = "800201904001")@PathVariable("gid") String gid) {
        if(menuGroupService.deleteMenuGroupById(gid)){
            return JsonVO.success("删除成功");
        }
        return JsonVO.fail("删除失败");
    }
}
