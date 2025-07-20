package com.zeroone.star.configmanager.controller;

import com.zeroone.star.configmanager.service.ConfigManagerService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.configmanager.config.ConfigAddDTO;
import com.zeroone.star.project.dto.j2.configmanager.config.ConfigDTO;
import com.zeroone.star.project.dto.j2.configmanager.config.ConfigUpdateDTO;
import com.zeroone.star.project.j2.configmanager.ConfigManagerApis;
import com.zeroone.star.project.query.j2.configmanager.ConfigQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * 配置中心 控制器
 */
@RestController
@RequestMapping("/j2-configmanager/config")
@Api(tags = "配置管理-配置中心")
@Validated
public class ConfigManagerController implements ConfigManagerApis {

    @Resource
    private ConfigManagerService configManagerService;
    @ApiOperation(value = "获取配置列表（条件+分页）")
    @GetMapping("/query")
    @Override
    public JsonVO<PageDTO<ConfigDTO>> queryConfig(@Validated ConfigQuery query) {
        return JsonVO.success(configManagerService.listAllConfig(query));
    }


    @ApiOperation(value = "添加配置")
    @PostMapping("/add")
    @Override
    public JsonVO<String> addConfig(@Validated @RequestBody ConfigAddDTO configAddDTO) {
        String p=configManagerService.saveConfig(configAddDTO);
         if(p=="0"){
             return JsonVO.fail("添加失败");
         }else if(p=="2")
             return JsonVO.fail("配置已存在");
         return JsonVO.success("添加成功");
    }
    @ApiOperation(value = "修改配置")
    @PutMapping("/updata")
    @Override
    public JsonVO<String> updateConfig(@Validated @RequestBody ConfigUpdateDTO configUpdateDTO) {
        if(configManagerService.updateConfig(configUpdateDTO)=="0"){
            return JsonVO.fail("修改失败");
        }
        return JsonVO.success("修改成功");
    }
    @ApiOperation(value = "删除配置")
    @DeleteMapping("/delete")
    @Override
    public JsonVO<String> deleteConfig(String id) {
        if(configManagerService.deleteConfig(id)=="0"){
            return JsonVO.fail("删除失败");
        }
        return JsonVO.success("删除成功");
    }
}
