package com.zeroone.star.communitymanage.controller;

import com.zeroone.star.communitymanage.service.publicity.PublicityQueryService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.publicity.PublicityDTO;
import com.zeroone.star.project.dto.j5.community.publicity.PublicityDetailDTO;
import com.zeroone.star.project.j5.community.publicity.PublicityQueryApis;

import com.zeroone.star.project.query.j5.community.publicity.PublicityDetailQuery;
import com.zeroone.star.project.query.j5.community.publicity.PublicityQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：小区公示查询的控制器
 * </p>
 * @author 无关风月
 * @version 1.0.0
 */
@RestController
@RequestMapping("/j5-community/publicity")
@Api(tags = "小区公示")
@Validated
public class PublicityQueryController implements PublicityQueryApis {

    @Resource
    PublicityQueryService queryService;

    @ApiOperation("获取公示列表（条件+分页）")
    @GetMapping("query-publicity-list")
    @Override
    public JsonVO<PageDTO<PublicityDTO>>  queryPublicityList(@Validated PublicityQuery query) {
        return JsonVO.success(queryService.listPublicity(query));
    }

    @ApiOperation("获取公示详情")
    @GetMapping("query-publicity-detail")
    @Override
    public JsonVO<PublicityDetailDTO> queryPublicityDetail(@Validated PublicityDetailQuery query) {
        return JsonVO.success(queryService.getPublicityDetail(query));
    }
}
