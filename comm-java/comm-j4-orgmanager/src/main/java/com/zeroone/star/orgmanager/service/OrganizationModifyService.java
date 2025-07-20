package com.zeroone.star.orgmanager.service;

import com.zeroone.star.project.dto.j4.orgmanager.ModifyOrganizationDTO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface OrganizationModifyService {
    /**
     * 修改组织
     * 根据给定的组织ID，更新数据库中对应的组织信息，并返回更新后的组织信息
     * @param modifyOrganizationDTO 要修改的组织信息
     * @return 修改后组织的组织名称，上级组织，描述，如果组织ID不存在则返回null
     */
    boolean modifyOrganization(ModifyOrganizationDTO modifyOrganizationDTO);
}
