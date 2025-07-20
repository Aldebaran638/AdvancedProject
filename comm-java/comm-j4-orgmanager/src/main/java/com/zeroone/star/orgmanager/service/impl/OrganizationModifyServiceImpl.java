package com.zeroone.star.orgmanager.service.impl;

import com.zeroone.star.orgmanager.mapper.OrganizationModifyMapper;
import com.zeroone.star.orgmanager.service.OrganizationModifyService;
import com.zeroone.star.project.dto.j4.orgmanager.ModifyOrganizationDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Service
public class OrganizationModifyServiceImpl implements OrganizationModifyService {
    @Resource
    private OrganizationModifyMapper organizationModifyMapper;

    @Override
    public boolean modifyOrganization(ModifyOrganizationDTO modifyOrganizationDTO) {
        // 实现修改逻辑，例如通过Mapper更新数据库
        // 这里假设有一个updateOrganization方法用于更新操作
        int rowsAffected = organizationModifyMapper.modifyOrganization(modifyOrganizationDTO);
        return rowsAffected > 0;
    }
}
