package com.zeroone.star.orgmanager.service;

import com.zeroone.star.project.dto.j4.orgmanager.AddOrganizationDTO;

public interface OrganizationAddService {
    /**
     * 添加组织
     * @param addOrganizationDTO  包含组织ID、层级和父组织ID等信息的DTO对象
     * @return 保存后组织的VO对象，包含组织ID、层级和父组织ID
     */

    boolean addOrganization(AddOrganizationDTO addOrganizationDTO);
}
