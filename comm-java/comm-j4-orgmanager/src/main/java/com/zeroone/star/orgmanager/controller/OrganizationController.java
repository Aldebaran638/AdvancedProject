package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.orgmanager.constant.OrganizationDeleteStatus;
import com.zeroone.star.orgmanager.service.*;
import com.zeroone.star.orgmanager.service.OrganizationModifyService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AssociatedStaffDTO;
import java.util.List;
import com.zeroone.star.project.dto.j4.orgmanager.AddOrganizationDTO;
import com.zeroone.star.project.dto.j4.orgmanager.ModifyOrganizationDTO;
import com.zeroone.star.project.dto.j4.orgmanager.OrgStaffDTO;
import com.zeroone.star.project.j4.orgmanager.OrganizationApis;
import com.zeroone.star.project.query.j4.orgmanager.orgmessage.AssociatedStaffQuery;
import com.zeroone.star.project.query.j4.orgmanager.orgmessage.OrgStaffQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.j4.orgmanager.ClassOrganizationVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * @Author: Alisa
 * @Description: 组织信息接口
 */
@RestController
@RequestMapping("/j4-orgmanager/organization")
@Api(tags = "组织信息接口")
public class OrganizationController implements OrganizationApis {

    @Resource
    private OrganizationService organizationService;

    @Resource
    private OrganizationInfoService organizationInfoService;

    @Resource
    private OrganizationAddService organizationAddService;

    @Resource
    private OrganizationModifyService organizationModifyService;



    @GetMapping("/get")
    @ApiOperation(value = "获取组织名称树")
    @Override
    public JsonVO<List<ClassOrganizationVO>> getOrganizationTree() throws Exception {
        List<ClassOrganizationVO> organizationTree = organizationInfoService.getOrganizationTree();
        if (organizationTree == null || organizationTree.isEmpty()) {
            return JsonVO.create(null, ResultStatus.FAIL);
        }
        return JsonVO.create(organizationTree, ResultStatus.SUCCESS);
    }

    @PostMapping("/add")
    @ApiOperation(value = "添加组织")
    @Override
    public JsonVO<String> addOrganization(@RequestBody AddOrganizationDTO addOrganizationDTO) {
        try {
            // 调用service中的添加方法
            boolean result = organizationAddService.addOrganization(addOrganizationDTO);
            if (result) {
                // 添加成功
                return JsonVO.success("组织添加成功");
            } else {
                // 添加失败
                return JsonVO.fail("组织添加失败");
            }
        } catch (Exception e) {
            // 处理异常情况
            return JsonVO.create("组织添加异常：" + e.getMessage(), ResultStatus.FAIL.getCode(), "组织添加异常");
        }
    }
    
    @PutMapping("/put")
    @ApiOperation(value = "修改组织")
    @ApiImplicitParam(name = "userId", value = "用户Id列表")
    @Override
    public JsonVO<String> modifyOrganization(@RequestBody ModifyOrganizationDTO modifyOrganizationDTO) {
        try {
            // 调用service中的修改方法
            boolean result = organizationModifyService.modifyOrganization(modifyOrganizationDTO);
            if (result) {
                // 修改成功
                return JsonVO.success("组织修改成功");
            } else {
                // 修改失败
                return JsonVO.fail("组织修改失败");
            }
        } catch (Exception e) {
            // 处理异常情况
            return JsonVO.create("组织修改异常：" + e.getMessage(), ResultStatus.FAIL.getCode(), "组织修改异常");
        }
    }

    @DeleteMapping("/delete")
    @ApiOperation(value = "删除组织")
    @ApiImplicitParam(name = "orgId",value = "组织id",example = "84202305221014333415000178",required = true)
    @Override
    public JsonVO<String> removeOrganization(String orgId) {

        OrganizationDeleteStatus status = organizationService.removeOrganization(orgId);

        try {
            switch (status) {
                case SUCCESS:
                    return JsonVO.success(status.getMsg());
                case NOT_FOUND:
                    return JsonVO.fail(status.getMsg());
                case HAS_CHILDREN:
                    return JsonVO.fail(status.getMsg());
                case FAILED:
                default:
                    return JsonVO.fail(status.getMsg());
            }
        } catch (Exception e) {
            return JsonVO.fail("删除组织异常" + e.getMessage());
        }

    }

    @GetMapping("/querystaff")
    @ApiOperation(value = "获取组织员工列表（分页+条件）")
    @Override
    public JsonVO<PageDTO<OrgStaffDTO>> queryOrgStaff(OrgStaffQuery orgStaffQuery) {

        PageDTO<OrgStaffDTO> orgStaffDTOPageDTO = organizationService.listOrganizationStaff(orgStaffQuery);
        return JsonVO.success(orgStaffDTOPageDTO);
    }

    @GetMapping("/queryassociated")
    @ApiOperation("关联员工之前要查询 （分页+条件）")
    @Override
    public JsonVO<PageDTO<AssociatedStaffDTO>> queryAllStaffs(AssociatedStaffQuery associatedStaffQuery) {
        PageDTO<AssociatedStaffDTO> associatedStaffDTOPageDTO = organizationService.listAssociatedStaff(associatedStaffQuery);

        return JsonVO.success(associatedStaffDTOPageDTO);
    }

    @PostMapping("/associatedstaffs")
    @ApiOperation("关联员工")

    @Override
    public JsonVO<String> addStaffs(@RequestParam("orgId") String orgId,
                                    @RequestBody List<String> userIds) {

        try {
            String msg = organizationService.addAssociatedStaff(orgId, userIds);
            return JsonVO.success(msg);
        } catch (Exception e) {
            return JsonVO.fail("添加员工异常"+e.getMessage());
        }

    }
}
