package com.zeroone.star.menumana.controller;

import com.zeroone.star.menumana.service.MenuPriviliegeTreeService;
import com.zeroone.star.project.dto.j1.menumana.menuitem.MenuPrivilegeTreeDTO;
import com.zeroone.star.project.j1.menumana.menuitem.MenuPriviliegeTreeApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/j1-manumana/meunmana")
@Api(tags = "菜单项")
@Slf4j
public class MenuPriviliegeTreeController implements MenuPriviliegeTreeApis {
    @Autowired
    private MenuPriviliegeTreeService menuPriviliegeTreeService;
    @Override
    @ApiOperation(value = "获取菜单名称树")
    @GetMapping("get-menuprivilegetree")
    public JsonVO<List<MenuPrivilegeTreeDTO>> getMenuPrivilegeTree() {
        List<MenuPrivilegeTreeDTO> menuPrivilegeTree = menuPriviliegeTreeService.getMenuPrivilegeTree();
        return JsonVO.success(menuPrivilegeTree);
    }
}
