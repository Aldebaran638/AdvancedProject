package com.zeroone.star.communityinfo.controller;

import com.zeroone.star.communityinfo.service.CommunityInfoUpdateService;
import com.zeroone.star.project.dto.j5.info.communityinfo.AddCommunityDTO;
import com.zeroone.star.project.dto.j5.info.communityinfo.CommunityDTO;
import com.zeroone.star.project.j5.info.communityinfo.CommunityInfoUpdateApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：小区信息增删改的控制器
 * </p>
 * @author 锅巴
 * @version 1.0.0
 */
@RestController
@RequestMapping("/j5-info/community")
@Api(tags = "小区信息")
@Validated
public class CommunityInfoUpdateController implements CommunityInfoUpdateApis {

    @Resource
    private CommunityInfoUpdateService service;

    @ApiOperation("添加小区")
    @PostMapping("/add-community")
    @Override
    public JsonVO<String> addCommunity(@Validated @RequestBody AddCommunityDTO addCommunityDTO) {
        return JsonVO.success(service.saveCommunity(addCommunityDTO));
    }

    @ApiOperation("修改小区")
    @PutMapping("/modify-community")
    @Override
    public JsonVO<String> modifyCommunity(@Validated @RequestBody CommunityDTO communityDTO) {
        return JsonVO.success(service.updateCommunity(communityDTO));
    }

    @ApiOperation("删除小区")
    @ApiImplicitParam(name = "communityId", value = "小区ID", required = true)
    @DeleteMapping("/remove-community/")
    @Override
    public JsonVO<String> removeCommunity(String communityId) {
        return JsonVO.success(service.removeCommunity(communityId));
    }
}
