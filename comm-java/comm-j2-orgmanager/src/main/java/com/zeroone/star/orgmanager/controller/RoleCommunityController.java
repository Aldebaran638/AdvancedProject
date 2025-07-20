package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.orgmanager.entity.URoleCommunity;
import com.zeroone.star.orgmanager.service.IURoleCommunityService;
import com.zeroone.star.orgmanager.service.impl.MsRoleCommunityMapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.orgmanager.role_priviledge.community.CommunityAuthApis;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.GetAssociatedRoleCommunitiesQuery;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.GetUnassociatedRoleCommunitiesQuery;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.PostRoleCommunityQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.AssociatedRoleCommunityDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.UnassociatedRoleCommunityDTO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;

@RestController
@RequestMapping("/j2-orgmanager/role/community")
@Api(tags = "组织管理-角色权限-小区授权")
public class RoleCommunityController implements CommunityAuthApis {

    @Resource
    IURoleCommunityService service;

    @Resource
    MsRoleCommunityMapper ms;

    @Transactional
    @ApiOperation(value = "新增关联")
    @PostMapping("/addRoleCommunity")
    public JsonVO<String> addRoleCommunity(@RequestBody PostRoleCommunityQuery query) {
        if (service.addRoleCommunity(query)) {
            return JsonVO.success("新增关联成功");
        }
        return JsonVO.fail(null);
    }

    @ApiOperation(value = "删除关联")
    @DeleteMapping("/deleteRoleCommunity")
    public JsonVO<String> deleteRoleCommunity(@RequestParam String rcId) {
        URoleCommunity roleCommunity = service.getById(rcId);
        if (roleCommunity == null) {
            return JsonVO.fail("找不到该关联记录");
        }
        roleCommunity.setStatusCd("1"); // 设置状态为删除
        if(service.updateById(roleCommunity)) {
            return JsonVO.success(roleCommunity.getRcId());
        }
        return JsonVO.success(null);
    }

    @ApiOperation(value = "获取已关联小区列表（条件+分页）")
    @GetMapping("/listRoleCommunity")
    public JsonVO<PageDTO<AssociatedRoleCommunityDTO>> listRoleCommunity(GetAssociatedRoleCommunitiesQuery getAssociatedRoleCommunitiesQuery) {
        // 调用服务层方法获取已关联小区列表
        return JsonVO.success(service.listRoleCommunity(getAssociatedRoleCommunitiesQuery));
    }

    @ApiOperation(value = "获取可关联小区列表（条件+分页）")
    @GetMapping("/listOrgNoCommunity")
    public JsonVO<PageDTO<UnassociatedRoleCommunityDTO>> listOrgNoCommunity(GetUnassociatedRoleCommunitiesQuery getUnassociatedRoleCommunitiesQuery) {
        return JsonVO.success(service.listOrgNoCommunity(getUnassociatedRoleCommunitiesQuery));
    }
}
