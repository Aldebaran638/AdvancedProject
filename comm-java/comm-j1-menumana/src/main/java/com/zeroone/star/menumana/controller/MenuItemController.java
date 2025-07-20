package com.zeroone.star.menumana.controller;


import com.zeroone.star.menumana.entity.MenuItem;
import com.zeroone.star.menumana.service.IMenuItemService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.AddMenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.DeleteMenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.MenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.ModifyMenuItemDTO;
import com.zeroone.star.project.j1.menumana.menuitem.MenuItemApis;
import com.zeroone.star.project.query.j1.menumana.menuitem.MenuItemQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("/j1-meunmana/menuitem")
@Api(tags = "菜单项")
@Slf4j
@Validated
public class MenuItemController implements MenuItemApis {

    /*resource*/
    @Resource
    IMenuItemService service;

    @Override
    @ApiOperation(value = "获取菜单列表（条件+分页）")
    @PostMapping("get-menulist")
    public JsonVO<PageDTO<MenuItemDTO>> queryMenuItem(@Validated @RequestBody MenuItemQuery query) {
        if(query.getPageIndex()<1 || query.getPageSize()<1){
            return JsonVO.fail(null);
        }
        return JsonVO.success(service.listAllMenuItemsPage(query));
    }

    @Override
    @ApiOperation(value = "添加菜单")
    @PostMapping("add-menu")
    public JsonVO<String> addMenuItem(@Validated @RequestBody AddMenuItemDTO menuItemDTO) {
//       if (service.addMenuItem(menuItemDTO).equals("添加成功")){
//           return JsonVO.success(menuItemDTO.getName());
//       }
//       return JsonVO.fail("添加失败");
        return service.addMenuItem(menuItemDTO);
    }

    @Override
    @ApiOperation(value = "修改菜单")
    @PostMapping("update-menu")
    public JsonVO<String> modifyMenuItem(@Validated @RequestBody ModifyMenuItemDTO menuItemDTO) {
//        if (service.modifyMenuItem(menuItemDTO).equals("修改成功")){
//            return JsonVO.success(menuItemDTO.getName());
//        }
//        return JsonVO.fail("修改失败");
        return  service.modifyMenuItem(menuItemDTO);
    }

    @Override
    @ApiOperation(value = "删除菜单")
    @DeleteMapping("del-menu")
    public JsonVO<String> deleteMenuItem(@Validated @RequestBody DeleteMenuItemDTO deleteMenuItemDTO) {
//        if (service.deleteMenuItems(deleteMenuItemDTO).equals("删除成功")){
//            return JsonVO.success("删除成功");
//        }
//        return JsonVO.fail("删除失败");
        return service.deleteMenuItem(deleteMenuItemDTO);
    }
}
