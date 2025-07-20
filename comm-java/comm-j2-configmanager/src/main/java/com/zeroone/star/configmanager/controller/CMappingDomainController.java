package com.zeroone.star.configmanager.controller;



import com.zeroone.star.configmanager.service.ConfigmanagerMappingService;
import com.zeroone.star.configmanager.service.ICMappingDomainService;
import com.zeroone.star.configmanager.service.impl.MsMappingDomainMapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.configmanager.mappingdomain.*;
import com.zeroone.star.project.j2.configmanager.MappingDomainApis;
import com.zeroone.star.project.query.j2.configmanager.MappingDomainQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * <p>
 *  配置项
 * </p>
 *
 * @author hubery
 * @since 2025-05-16
 */
@Api(tags = "配置管理-配置项")
@RestController
@RequestMapping("/j2-configmanager/c-mapping-domain")
public class CMappingDomainController implements MappingDomainApis {
    @Autowired
    private ICMappingDomainService service;
    @Autowired
    private MsMappingDomainMapper ms;

    private final ConfigmanagerMappingService configmanagerService;

    public CMappingDomainController(ConfigmanagerMappingService configmanagerService) {
        this.configmanagerService = configmanagerService;
    }


    /**
     * 根据传入条件分页查询配置项并排序
     * @param query 查询条件
     * @return 查询结果
     */
    @GetMapping("/query-all")
    @ApiOperation("获取配置项列表（条件+分页）")
    @Override
    public JsonVO<PageDTO<MappingDomainDTO>> queryAll(MappingDomainQuery query) {
        PageDTO<MappingDomainDTO> search = service.search(query);
        return JsonVO.success(search);
    }


    /**
     * 查询所有的配置项名称
     */
    @GetMapping("/all-domain-name")
    @ApiOperation("获取配置项名称列表")
    @Override
    public JsonVO<List<MappingDomainNameDTO>> queryAllName() {
        return JsonVO.success(service.listAllNames());
    }


    /**
     * 添加配置项
     *
     * @param addConfigDTO 添加配置项数据对象
     * @return 添加结果
     */
    @ApiOperation("添加配置项")
    @PostMapping("/add")
    @Override
    public JsonVO<Boolean> addConfig(@RequestBody AddConfigDTO addConfigDTO) {
        return JsonVO.success(configmanagerService.addConfig(addConfigDTO));
    }


    /**
     * 修改配置项
     *
     * @param configDTO 修改配置项数据对象
     * @return 修改结果
     */
    @ApiOperation("修改配置项")
    @PutMapping("/update")
    @Override
    public JsonVO<Boolean> modifyConfig(@RequestBody ConfigDTO configDTO) {
        return JsonVO.success(configmanagerService.updateById(configDTO));
    }


    /**
     * 删除配置项
     *
     * @param id 配置项编号
     * @return 删除结果
     */
    @ApiOperation("删除配置项")
    @ApiImplicitParam(name = "id", value = "配置项编号", required = true)
    @DeleteMapping("/delete")
    @Override
    public JsonVO<Boolean> removeConfig(String id) {
        return JsonVO.success(configmanagerService.removeById(id));
    }


}

