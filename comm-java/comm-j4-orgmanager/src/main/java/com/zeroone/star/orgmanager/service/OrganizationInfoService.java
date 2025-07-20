package com.zeroone.star.orgmanager.service;

import com.zeroone.star.project.vo.j4.orgmanager.ClassOrganizationVO;

import java.util.List;

public interface OrganizationInfoService {
    /**获取组织名称树
     * @return 包括组织ID、层级和父组织ID的DTO列表
     */
    List<ClassOrganizationVO> getOrganizationTree() throws Exception;
}
