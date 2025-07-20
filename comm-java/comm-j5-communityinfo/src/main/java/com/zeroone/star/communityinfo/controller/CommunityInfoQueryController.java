package com.zeroone.star.communityinfo.controller;

import com.zeroone.star.communityinfo.service.CommunityInfoQueryService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.info.communityinfo.CommunityDTO;
import com.zeroone.star.project.j5.info.communityinfo.CommunityInfoQueryApis;
import com.zeroone.star.project.query.j5.info.communityinfo.CityAreaQuery;
import com.zeroone.star.project.query.j5.info.communityinfo.CommunityInfoQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.info.communityinfo.CityAreaVO;
import com.zeroone.star.project.vo.j5.info.communityinfo.CommunityInfoVO;
import com.zeroone.star.project.vo.j5.info.communityinfo.CommunityNameVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.Arrays;
import java.util.List;

/**
 * <p>
 * 描述：小区信息查询的控制器
 * </p>
 * @author yuezi
 * @version 1.0.0
 */
@RestController
@RequestMapping("/j5-info/community")
@Api(tags = "小区信息")
@Validated
public class CommunityInfoQueryController implements CommunityInfoQueryApis {

    @Resource
    CommunityInfoQueryService queryService;

    @ApiOperation("获取小区列表（条件+分页）")
    @GetMapping("/query")
    @Override
    public JsonVO<PageDTO<CommunityInfoVO>> queryCommunityInfoList(@Validated CommunityInfoQuery query) {
        return JsonVO.success(queryService.listCommunityInfo(query));
    }

    @ApiOperation("获取未入驻物业的小区名称列表")
    @GetMapping("/query-not-entered")
    @Override
    public JsonVO<List<CommunityNameVO>> queryNotEnteredCommunityNameList() {
        return JsonVO.success(queryService.listNotEnteredCommunityNameWithCache());
    }

    @ApiOperation("获取城市地名列表")
    @GetMapping("/query-areas")
    @Override
    public JsonVO<List<CityAreaVO>> queryCityAreas(@Validated CityAreaQuery query) {
        return JsonVO.success(queryService.listCityAreas(query));
    }
}
