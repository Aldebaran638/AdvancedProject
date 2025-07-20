package com.zeroone.star.systemmanage.controller.initcommunity;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.systemmanage.initcommunity.InitializedCommunityDTO;
import com.zeroone.star.project.j3.systemmanage.initcommunity.InitCommunityApis;
import com.zeroone.star.project.query.j3.systemmanage.initcommunity.InitializedCommunityPageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.systemmanage.service.IInitCommunityService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiImplicitParams;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("j3-system/init-community")
@Api(tags = "初始化小区")
@Validated
public class InitCommunityController implements InitCommunityApis {

    @Autowired
    IInitCommunityService service;

    /**
     * 获取小区列表（分页+条件）
     * @param query 查询小区分页数据和查询条件
     * @return 返回查询后的小区列表
     */
    @ApiOperation("获取小区列表（分页+条件）")
    @Override
    @GetMapping("/query-coummunities")
    public JsonVO<PageDTO<InitializedCommunityDTO>> queryCommunities(InitializedCommunityPageQuery query) {
        return service.listAll(query);
    }

    /**
     * 格式化数据
     * @param communityId 小区ID
     * @param password 用户密码
     * @return
     */
    @ApiOperation("格式化数据")
    @ApiImplicitParams({
            @ApiImplicitParam(name = "communityId",value = "小区ID",required = true,example = "2024021911282483"),
            @ApiImplicitParam(name = "password",value = "用户密码",required = true,example = "admin")
    })
    @Override
    @DeleteMapping("/remove-data")
    public JsonVO<String> removeData(String communityId, String password) {
        return service.removeData(communityId,password);
    }
}
