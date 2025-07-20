package com.zeroone.star.datamanager.controller;

import com.zeroone.star.datamanager.entity.SStore;
import com.zeroone.star.datamanager.service.PropertyManagementService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.datamanager.CommunityMenuGroupDTO;
import com.zeroone.star.project.dto.j4.datamanager.CompanyDTO;
import com.zeroone.star.project.j4.datamanager.PropertyManagementApis;
import com.zeroone.star.project.query.j4.datamanager.CompanyQuery;
import com.zeroone.star.project.query.j4.datamanager.JoinCommunityQuery;
import com.zeroone.star.project.query.j4.datamanager.NoJoinCommunityQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.datamanager.CommunityMenuGroup;
import com.zeroone.star.project.vo.j4.datamanager.CompanyVO;
import com.zeroone.star.project.vo.j4.datamanager.JoinCommunityVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;


/**
 * @author: dashuai
 * @Description: 物业公司controller层
 */
@Api(tags = "物业公司接口")
@RestController
@RequestMapping("/j4-datamanager")
@Validated
@Slf4j
public class PropertyManagementController implements PropertyManagementApis {

    @Resource
    private PropertyManagementService propertyManagementService;


    @Override
    @ApiOperation("获取加入小区列表（条件+分页）")
    @GetMapping("/joinCommunityList")
    public JsonVO<PageDTO<JoinCommunityVO>> getJoinCommunityList(@RequestParam("pageIndex") long pageIndex, @RequestParam("pageSize") long pageSize, JoinCommunityQuery query) {
        PageDTO<JoinCommunityVO> pageDTOJsonVO = propertyManagementService.queryJoinCommunityList(pageIndex, pageSize, query);
        return JsonVO.success(pageDTOJsonVO);
    }

    @Override
    @ApiOperation("获取未加入小区列表")
    @GetMapping("/noJoinCommunityList/{communityMemberId}")
    public JsonVO<List<String>> getNoJoinCommunityList(NoJoinCommunityQuery query) {
        List<String> pageDTOJsonVO = propertyManagementService.queryNoJoinCommunityList(query);
        return JsonVO.success(pageDTOJsonVO);
    }

    @Override
    @ApiOperation("加入小区")
    @PutMapping("/addJoinCommunity")
    public JsonVO<String> addJoinCommunity(@RequestBody CommunityMenuGroupDTO dto) {
        propertyManagementService.becomeJoinCommunity(dto);
        return JsonVO.success("加入成功");
    }

    @Override
    @ApiOperation("将小区退出物业公司")
    @PutMapping("/quitJoinCommunity/{communityId}")
    public JsonVO<String> quitJoinCommunity(@PathVariable("communityId") String communityId) {
        propertyManagementService.quitJoinCommunity(communityId);
        return JsonVO.success("退出成功");
    }


    @Override
    @ApiOperation("获取小区功能")
    @GetMapping("/getCommunityMenuGroupList/{communityId}")
    public JsonVO<List<CommunityMenuGroup>> getCommunityMenuGroup(@PathVariable("communityId") String communityId) {
        List<CommunityMenuGroup> communityMenuGroup = propertyManagementService.getCommunityMenuGroup(communityId);
        return JsonVO.success(communityMenuGroup);
    }


    @Override
    @ApiOperation("修改小区功能")
    @PutMapping("/updateCommunityMenuGroup")
    public JsonVO<String> updateCommunityMenuGroup(@RequestBody CommunityMenuGroupDTO dto) {
        propertyManagementService.updateCommunityMenuGroup(dto);
        return JsonVO.success("修改成功");
    }

    @Override
    @ApiOperation("获取物业公司（条件+分页接口）")
    @GetMapping("/getCompanyList")
    public JsonVO<PageDTO<CompanyVO>> getCompanyList(CompanyQuery query){
        PageDTO<CompanyVO> result = propertyManagementService.getCompanyList(query);
        return JsonVO.success(result);
    }

    @Override
    @ApiOperation(value = "添加物业公司")
    @PostMapping(value = "/addCompany")
    public JsonVO<String> addCompany(@RequestBody CompanyDTO dto) {
        try {
            propertyManagementService.addCompany(dto);
            return JsonVO.success("添加成功");
        } catch (Exception e) {
            log.error("添加失败:{}", e.getMessage());
            return JsonVO.fail("添加失败");
        }
    }

    @Override
    @ApiOperation(value = "修改物业公司")
    @PutMapping(value = "/modifyCompany/{storeId}")
    public JsonVO<String> modifyCompany(@PathVariable String storeId, @RequestBody CompanyDTO dto) {
        try {
            SStore updatedStore = propertyManagementService.modifyCompany(dto, storeId);
            return JsonVO.success(updatedStore.toString());
        } catch (Exception e) {
            log.error("修改失败", e);
            return JsonVO.fail("修改失败");
        }
    }

    @Override
    @ApiOperation(value = "删除物业公司")
    @DeleteMapping("/updateCompany/{storeId}")
    public JsonVO<String> deleteCompany(@PathVariable String storeId) {
        propertyManagementService.deleteCompany(storeId);
        return JsonVO.success("删除成功");
    }

    @Override
    @ApiOperation(value = "限制物业登录")
    @PutMapping("/limitCompanyLogin/{storeId}/operate/{operate}")
    public JsonVO<String> limitCompanyLogin(@PathVariable String storeId, @PathVariable String operate) {
        propertyManagementService.limitCompanyLogin(storeId, operate);
        return JsonVO.success("限制成功");
    }

    @Override
    @ApiOperation(value = "重置物业公司密码")
    @PutMapping("/resetCompanyPassword/{storeId}")
    public JsonVO<String> resetCompanyPassword(@PathVariable String storeId) {
        String newPassword = propertyManagementService.resetCompanyPassword(storeId);
        return JsonVO.success(newPassword);
    }
}
