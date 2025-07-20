package com.zeroone.star.menumana.controller;

import com.zeroone.star.menumana.service.ICommonMenuService;
import com.zeroone.star.menumana.mapper.MsCommonMenuMapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.commonmenu.AddCommonMenuDTO;
import com.zeroone.star.project.dto.j1.menumana.commonmenu.CommonMenuDTO;
import com.zeroone.star.project.dto.j1.menumana.commonmenu.MixMenuDTO;
import com.zeroone.star.project.j1.menumana.commonmenu.CommonMenuApis;
import com.zeroone.star.project.query.j1.menumana.commonmenu.CommonMenuQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * 常用菜单控制器
 */
@RestController
@RequestMapping("/j1-menumana/commonmenu")
@Api(tags = "常用菜单")
public class CommonMenuController implements CommonMenuApis {

    @Resource
    ICommonMenuService iCommonMenuService;

    @Resource
    MsCommonMenuMapper ms;

    @ApiOperation(value = "获取常用菜单列表（条件+分页）")
    @GetMapping("/queryall")
    public JsonVO<PageDTO<CommonMenuDTO>> queryCommonMenuList(CommonMenuQuery query) {
        return JsonVO.success(iCommonMenuService.listAllCommonMenu(query));
    }

    @ApiOperation(value = "获取可选菜单下拉列表")
    @GetMapping("/queryname")
    public JsonVO<List<MixMenuDTO>> queryMixMenu() {
        return JsonVO.success(iCommonMenuService.listMixMenu());
    }

    @ApiOperation(value = "添加常用菜单")
    @PostMapping("/add")
    public JsonVO<String> addCommonMenu(@RequestBody AddCommonMenuDTO addCommonMenuDTO) {
        return JsonVO.success(iCommonMenuService.addMenu(addCommonMenuDTO));
    }

    @ApiOperation(value = "删除常用菜单")
    @ApiImplicitParam(name = "muId",value = "菜单编号",required = true)
    @PutMapping("/remove")
    public JsonVO<String> removeCommonMenu(String muId) {
        return JsonVO.success(iCommonMenuService.updateMuId(muId));
    }
}
