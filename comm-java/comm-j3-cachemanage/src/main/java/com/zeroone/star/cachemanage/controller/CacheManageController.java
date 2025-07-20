package com.zeroone.star.cachemanage.controller;

import com.zeroone.star.cachemanage.service.CacheManagerService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.cachemanage.CacheDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.j3.cachemanage.CacheQuery;
import com.zeroone.star.project.j3.cachemanage.CacheManageApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.cachemanage.CacheVO;
import com.zeroone.star.project.vo.j3.cachemanage.CacheVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("j3-cache/cache-manage")
@Api(tags = "缓存管理")
public class CacheManageController implements CacheManageApis {
    @Autowired
    private CacheManagerService cacheManagerService;
    /**
     *
     * @param cacheQuery 输入信息和分页信息
     * @return 查询后的信息
     */
    @GetMapping("/query-caches")
    @ApiOperation(value = "获取缓存操作列表（条件+分页）")
    @Override
    public JsonVO<PageDTO<CacheVO>> queryCaches(CacheQuery cacheQuery){
        System.out.println(cacheQuery);
        PageDTO<CacheVO> caches=cacheManagerService.queryCaches(cacheQuery);
        return JsonVO.success(caches);
    }

    @PostMapping("/flush-cache")
    @ApiOperation(value = "刷新缓存")
    @Override
    public JsonVO flushCache(@RequestBody CacheDTO cacheDTO){

        return null;
    }


}
