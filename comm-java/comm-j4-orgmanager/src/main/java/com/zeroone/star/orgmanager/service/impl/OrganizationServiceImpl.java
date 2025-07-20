package com.zeroone.star.orgmanager.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.orgmanager.constant.OrganizationDeleteStatus;
import com.zeroone.star.orgmanager.entity.UOrg;
import com.zeroone.star.orgmanager.mapper.OrganizationMapper;
import com.zeroone.star.orgmanager.mapper.OrganizationStaffMapper;
import com.zeroone.star.orgmanager.service.OrganizationService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AssociatedStaffDTO;
import com.zeroone.star.project.dto.j4.orgmanager.OrgStaffDTO;
import com.zeroone.star.project.query.j4.orgmanager.orgmessage.AssociatedStaffQuery;
import com.zeroone.star.project.query.j4.orgmanager.orgmessage.OrgStaffQuery;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;
import org.springframework.util.CollectionUtils;

import javax.annotation.Resource;
import java.util.List;

/**
 * @program: common-java
 * @description: 组织管理模块包括删除组织,获取组织员工列表,关联员工
 * @author: Altolia
 **/

@Service
@Slf4j
public class OrganizationServiceImpl implements OrganizationService {
    @Resource
     OrganizationMapper organizationMapper;

    @Resource
    OrganizationStaffMapper organizationStaffMapper;
    /**
     * 删除组织
     * @param orgId
     * @return
     */
    @Override
    public OrganizationDeleteStatus removeOrganization(String orgId) {

        UOrg uOrg = organizationMapper.selectById(orgId);

        if(uOrg == null || "1".equals(uOrg.getStatusCd())) {
            return OrganizationDeleteStatus.NOT_FOUND;
        }
        if(organizationMapper.countChildren(orgId)>0) {
            return OrganizationDeleteStatus.HAS_CHILDREN;
        }

        UOrg uOrg1 = new UOrg();
        uOrg1.setOrgId(orgId);
        uOrg1.setStatusCd("1");
        int i = organizationMapper.updateById(uOrg1);
        if(i>0) {
            log.info("删除组织成功");
            return OrganizationDeleteStatus.SUCCESS;
        }

        return OrganizationDeleteStatus.FAILED;
    }

    /**
     * 获取员工列表(分页+条件)
     * @param orgStaffQuery
     * @return
     */
    @Override
    public PageDTO<OrgStaffDTO> listOrganizationStaff(OrgStaffQuery orgStaffQuery) {

        //这里没遵循规范,实体类直接没定义,DTO字段和数据库里对应的驼峰
        Page<OrgStaffDTO> page = new Page<>(orgStaffQuery.getPageIndex(),orgStaffQuery.getPageSize());
        Page<OrgStaffDTO> orgStaff = organizationStaffMapper.getOrgStaff(page,orgStaffQuery);
        return PageDTO.create(orgStaff);
    }

    /**
     * 关联员工之前查询（分页+条件）
     * @param associatedStaffQuery
     * @return
     */
    @Override
    public PageDTO<AssociatedStaffDTO> listAssociatedStaff(AssociatedStaffQuery associatedStaffQuery) {

        Page<AssociatedStaffDTO> page = new Page<>(associatedStaffQuery.getPageIndex(),associatedStaffQuery.getPageSize());
        Page<AssociatedStaffDTO> orgStaff = organizationStaffMapper.getAocStaff(page,associatedStaffQuery);

        return PageDTO.create(orgStaff);
    }

    /**
     * 添加员工
     * @param orgId
     * @param userId
     * @return
     */
    @Override
    public String addAssociatedStaff(String orgId, List<String> userId) {
        if(CollectionUtils.isEmpty(userId)) {
            return "未传入id";
        }
        int successCount=0;
        for (String user : userId) {
            int result = organizationStaffMapper.updateStatus(
                    orgId, user, "0");

            if (result > 0) {
                successCount++;
                log.info("激活关联: orgId={}, userId={}", orgId, userId);
            } else {
                log.warn("关联未更新: orgId={}, userId={}", orgId, userId);
            }
        }
        return null;
    }
}
