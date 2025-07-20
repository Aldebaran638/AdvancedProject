package com.zeroone.star.orgmanager.service.impl;

import com.zeroone.star.orgmanager.mapper.OrganizationAddMapper;
import com.zeroone.star.orgmanager.service.OrganizationAddService;
import com.zeroone.star.project.dto.j4.orgmanager.AddOrganizationDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Service
public class OrganizationAddServiceImpl implements OrganizationAddService {
    @Resource
    OrganizationAddMapper organizationAddMapper;
    @Override
    public boolean addOrganization(AddOrganizationDTO addOrganizationDTO) {
        // 获取DTO中的参数
        String orgName = addOrganizationDTO.getOrgname();
        String parentOrgId = addOrganizationDTO.getParentOrgId();
        String description = addOrganizationDTO.getDescription();

        // 调用Mapper的添加方法
        int result = organizationAddMapper.addOrganization(orgName, parentOrgId, description);

        // 判断插入是否成功
        return result > 0;
    }
}
