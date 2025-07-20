package com.zeroone.star.orgmanager.controller;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.orgmanager.service.RelatedUnitService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgmanager.dataPrivilege.RelatedUnitAddDTO;
import com.zeroone.star.project.j2.orgmanager.data_priviledge.RelatedUnitApis;
import com.zeroone.star.project.query.j2.orgmanager.dataPrivilege.NoRelatedUnitQuery;
import com.zeroone.star.project.query.j2.orgmanager.dataPrivilege.RelatedUnitQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.orgmanager.dataPriviledge.RelatedUnitVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.apache.ibatis.annotations.Param;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.List;


@Api(tags = "组织管理-数据权限-关联单元")
@RestController
@RequestMapping("/orgmanager/data/unit")
public class RelatedUnitController implements RelatedUnitApis {
    @Autowired
    private RelatedUnitService relatedUnitService;
    @ApiOperation(value = "获取已关联单元列表（条件+分页）",notes = "根据楼栋编号，单元编号以及数据状态来查询已关联单元列表")
    @Override
    @GetMapping("/has-related-unit")
    public JsonVO<PageDTO<RelatedUnitVO>> queryRelatedUnitList(RelatedUnitQuery query) {
        // 将你的 RelatedUnitQuery 转换成 Page 对象
        Page<RelatedUnitVO> page = new Page<>(query.getPageIndex(), query.getPageSize());

        // 调用 Service 时传入 Page 和其他查询条件
        return JsonVO.success(relatedUnitService.queryRelatedUnitList(page, query));
    }

    @ApiOperation(value = "获取未关联单元列表（条件+分页）",notes = " 根据数据状态来查询未关联单元列表")
    @Override
    @GetMapping("/no-related-unit")
    public JsonVO<PageDTO<RelatedUnitVO>> queryNoRelatedUnitList(NoRelatedUnitQuery query) {
        Page<RelatedUnitVO> page = new Page<>(query.getPageIndex(), query.getPageSize());
        return JsonVO.success(relatedUnitService.queryNoRelatedUnitList(page,query));
    }


    @ApiOperation(value = "添加关联单元",notes = "根据数据权限id和单元和楼栋编号来添加关联单元")
    @Override
    @PutMapping("/add-related-unit")
    public JsonVO<String> addRelatedUnit(@RequestBody ArrayList<RelatedUnitAddDTO> relatedUnitAddDTOList ) {
        return JsonVO.success(relatedUnitService.addRelatedUnit(relatedUnitAddDTOList));
    }


    @ApiOperation(value = "删除关联单元",notes = "根据主键id来删除关联单元")
    @Override
    @DeleteMapping("/remove-related-unit")
    @ApiParam(value = "主键ID",required = true, example = "1928087619657793536")
    public JsonVO<String> removeRelatedUnit(
            String dpUnitId) {
        return JsonVO.success(relatedUnitService.removeRelatedUnit(dpUnitId));
    }
}